
import numpy as np
import matplotlib.pyplot as plt
from math import pi
from scipy.optimize import fsolve, fmin, curve_fit
from scipy.interpolate import RegularGridInterpolator

#%% PHYSICS

g =9.81 # gravité
rho=1.18 # masse volumique air

#%% CAR DATAS
        
#masses
m_car=215
m_pilot=75
m_wheel=6.374
m=m_car+m_pilot
ms= m - 4*m_wheel #masse suspendue


w=1.575 #wheelbase
xf=0.53*w #distance centre de gravité jusqua train avant
xr= w-xf

#voies
tf=1.254
tr=1.20

#hauteur des centres de roulis et axe de roulis
h_wheel = 0.235 #hauteur de la masse non suspendue ~ rayon du pneu
h_stat=0.30 #hauteur du centre gravité en statique
hrc_f=0.115 #hauteur du centre de roulis avant
hrc_r=0.152 #hauteur du centre de roulis arrière

dh= h_stat - (xr/w)*hrc_f - (xf/w)*hrc_r # m
ha = np.cos(np.arctan((hrc_r-hrc_f)/w))*dh
#motion ratio
MR_f = 1.16
MR_r = 1.26

lt = 0.205 #largeur du pneu

#%% SUSPENSION RATES

phi_max = np.arctan(2*hrc_f/(2*lt+tf))-np.arctan(2*(hrc_f-0.05)/(2*lt+tf)) #angle de roulis max pour voiture avec aéro


KT = 80000 #tire rate N/m

b= 175.1865165354331 # 1 N/m in lbs/inch

#spring rates
Ks_f = 200*b # N/m
Ks_r = 250*b # N/m

#wheel rates
Kw_f=Ks_f/(MR_f**2) # N/m
Kw_r=Ks_r/(MR_r**2) # N/m

#Ride frequencies

Kr_f = Kw_f*KT/(Kw_f+KT)
Kr_r = Kw_r*KT/(Kw_r+KT)

Ff = np.sqrt(Kr_f/(ms*(xr/w)/2))/(2*pi)
Fr = np.sqrt(Kr_r/(ms*(xf/w)/2))/(2*pi)

#ARB rates

Qsf=Kr_f*tf**2/2 # Nm/rad #raideur en roulis avant dues au ressorts, basculeurs et pneus
Qsr=Kr_r*tr**2/2 # Nm/rad #raideur en roulis arrière dues au ressorts, basculeurs et pneus

Qs=Qsf+Qsr # Nm/rad

Qarb = 25000 # Nm/rad

RR=ms*ha/(Qarb+Qs)

MN = 0.80 # magic number répartition de raideur anti-roulis à l'avant

Qarb_f= MN*Qarb
Qarb_r= (1-MN)*Qarb

#%% Aero

#Les données aéros sont données pour Optimus
S= 1.14 #surface effective pour la déportance en m²
Cz= 2.13 #coefficient de portance

#répartition aéro
af = 0.5
ar = 0.5

#%% SUSPENSION GEOMETRY

def CAMBER_f(roll):
    poly=np.polyfit(pi/180*np.array([-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,2.5]),pi/180*np.array([2.06,1.66,1.25,0.84,0.42,0,-0.4283,-0.86,-1.30,-1.74,-2.19]),2)
    return np.polyval(poly,roll)

def CAMBER_r(roll):
    return -1.0395746*roll**2

#%% PACEJKA 5.2 Lateral Coefficients

# Continental C19 205/470 R13
# rim width = 7"
#pressure = 65 kPa

#model limitations
SA_limit=25*pi/180 #slip angle max
Fz_min,Fz_max = 230 , 1600
    
pio=65000 #pressure from .tir file

FzO=m*g/4

PCY1= +1.725E+000
PDY1= +2.733E+000
PDY2= -6.022E-001
PDY3= +4.007E+000
PEY1= -5.000E-001
PEY2= -2.000E+000
PEY3= +2.260E-001
PEY4= -3.367E-002
PKY1= -5.047E+001
PKY2= +1.923E+000
PKY3= +2.877E-001
PHY1= +0.000E+000
PHY2= +0.000E+000
PHY3= -1.810E-002
PVY1= +0.000E+000
PVY2= +0.000E+000
PVY3= -2.649E+000
PVY4= -1.058E+000
RBY1= +2.033E+001
RBY2= +8.152E+000
RBY3= -1.243E-002
RCY1= +9.317E-001
REY1= -3.982E-004
REY2= +3.077E-001
RHY1= +0.000E+000
RHY2= +0.000E+000
RVY1= +0.000E+000
RVY2= +0.000E+000
RVY3= +0.000E+000
RVY4= +0.000E+000
RVY5= +0.000E+000
RVY6= +0.000E+000
PTY1= +3.260e+000
PTY2= +2.250e+000


#%% Scaling coefficients

LFZO  = 1
LCX   = 1
LMUX  = 1
LEX   = 1
LKX   = 1
LHX   = 0
LVX   = 0
LGAX  = 1
LCY   = 0.9
LMUY  = 0.6
LEY   = 1
LKY   = 1
LHY   = 0
LVY   = 0
LGAY  = 1
LTR   = 1
LRES  = 0
LGAZ  = 1
LXAL  = 1
LYKA  = 1.1
LVYKA = 1
LS    = 1
LSGKP = 1
LSGAL = 1
LGYR  = 1
LMX   = 1
LVMX  = 0
LMY   = 1


def Fy(Fz,slip_angle,camber):
    
    Fz0_=LFZO*FzO
    
    dfz=(Fz-Fz0_)/Fz0_
    
    eps_k=0.1
    
    eps_y=0.1
    
    eps_alpha=pi/180/4
    
    Svy=Fz*(PVY1+PVY2*dfz)*LVY*LMUY + Fz*(PVY3+PVY4*dfz)*LKY*LMUY*np.sin(camber)
    
    Kya=PKY1*Fz0_*(1-PKY3*abs(np.sin(camber)))*np.sin(np.arctan(Fz/Fz0_/PKY2))*LYKA
    
    SHy=(PHY1+PHY2*dfz)*LHY - Fz*(PVY3+PVY4*dfz)*LKY*LMUY*np.sin(camber)/(Kya+eps_k)
    
    alphay=slip_angle+SHy
    
    Cy=PCY1*LCY
    
    Dy=Fz*(PDY1+PDY2*dfz)*(1-PDY3*np.sin(camber)**2)*LMUY
    
    Ey=(PEY1+PEY2*dfz)*(1-(PEY3+PEY4*np.sin(camber))*alphay/abs(alphay+eps_alpha))*LEY
    
    By=Kya/(Cy*Dy+eps_y)
    
    return Dy*np.sin(Cy*np.arctan(By*alphay-Ey*(By*alphay-np.arctan(By*alphay)))) + Svy



n_sa=50
n_Fz=50
n_camber=50

list_SA=np.linspace(-15*pi/180,15*pi/180,n_sa)
list_Fz=np.linspace(500,1400,n_Fz)
list_camber=np.linspace(-6*pi/180,+6*pi/180,n_camber)

#%% Lateral coefficient of friction tau

### tau(camber,Fz)=tau_O(camber)+beta(camber)*Fz

tau_O=[]
beta=[]

for c in list_camber:
    list_tau=[max(Fy(z,list_SA,c))/z for z in list_Fz]
    poly=np.polyfit(list_Fz,list_tau,1)
    tau_O.append(poly[1])
    beta.append(poly[0])
    
    
poly_tau_O=np.polyfit(list_camber,tau_O,2)

t2=float(poly_tau_O[0])
t1=float(poly_tau_O[1])
t0=float(poly_tau_O[2])

poly_beta=np.polyfit(list_camber,beta,2)

beta2=float(poly_beta[0])
beta1=float(poly_beta[1])
beta0=float(poly_beta[2])

def tau(Fz,c):
    return (t2*c**2+t1*c+t0+(beta2*c**2+beta1*c+beta0)*Fz)

#%% Plot
    
list_SA=np.linspace(-15*pi/180,0*pi/180,50)
list_Fz=np.linspace(500,1400,50)

plt.figure(1)

plt.clf()

plt.plot(list_Fz,tau(list_Fz,0),label='camber = 0°')
plt.plot(list_Fz,tau(list_Fz,1*pi/180),label='camber = 1°')
plt.plot(list_Fz,tau(list_Fz,2*pi/180),label='camber = 2°')
plt.plot(list_Fz,tau(list_Fz,3*pi/180),label='camber = 3°')
plt.plot(list_Fz,tau(list_Fz,4*pi/180),label='camber = 4°')
plt.ylabel('Lateral coefficient of friction')
plt.xlabel('Vertical Load (N)')
plt.grid(True)
plt.legend()


plt.figure(2)

plt.clf()

plt.plot(180/pi*list_SA,Fy(1200,list_SA,0),label='outter tire, Fz = 1200 N, camber = 0°')
#plt.plot(180/pi*list_SA,Fy(1400,list_SA,1*pi/180),label='Fz = 1400 N, camber = 1°')
#plt.plot(180/pi*list_SA,Fy(1400,list_SA,2*pi/180),label='Fz = 1400 N, camber = 2°')
#plt.plot(180/pi*list_SA,Fy(1400,list_SA,3*pi/180),label='Fz = 1400 N, camber = 3°')
#plt.plot(180/pi*list_SA,Fy(1400,list_SA,4*pi/180),label='Fz = 1400 N, camber = 4°')


plt.plot(180/pi*list_SA,Fy(130,list_SA,0),label='inner tire, Fz = 130 N, camber = 0°')
#plt.plot(180/pi*list_SA,Fy(500,list_SA,1*pi/180),label='Fz = 500 N, camber = 1°')
#plt.plot(180/pi*list_SA,Fy(500,list_SA,2*pi/180),label='Fz = 500 N, camber = 2°')
#plt.plot(180/pi*list_SA,Fy(500,list_SA,3*pi/180),label='Fz = 500 N, camber = 3°')
#plt.plot(180/pi*list_SA,Fy(500,list_SA,4*pi/180),label='Fz = 500 N, camber = 4°')

plt.ylabel('Lateral grip force (N)')
plt.xlabel('Slip angle (°)')
plt.grid(True)
plt.legend()

plt.show()
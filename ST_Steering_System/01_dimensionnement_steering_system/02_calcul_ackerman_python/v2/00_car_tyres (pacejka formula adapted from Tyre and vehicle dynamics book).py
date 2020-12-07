

import numpy as np
import matplotlib.pyplot as plt
from math import pi
from scipy.optimize import fsolve, fmin, curve_fit

#%% PHYSICS

g =9.81 # gravité
rho=1.18 # masse volumique air

def sgn(x):
    if x!=0:
        return x/abs(x)
    else:
        return 0

#%% CAR DATAS
#masses
m_car=205
m_pilot=75
m_wheel=6.374
m=m_car+m_pilot
ms= m - 4*m_wheel #masse suspendue

h_wheel = 0.235 #hauteur de la masse non suspendue ~ rayon du pneu
h_stat=0.35 #hauteur du centre gravité
hrc_f=0.115 #hauteur du centre de roulis avant
hrc_r=0.152 #hauteur du centre de roulis arrière

w=1.575 #wheelbase
xf=0.53*w #distance centre de gravité jusqua train avant
xr= w-xf

#voies
tf=1.254
tr=1.200

#motion ratio
MR_f = 1.16
MR_r = 1.26

lt = 0.205 #largeur du pneu

#%% PACEJKA 5.2 Lateral Coefficients

# Continental C19 205/470 R13
# rim width = 7"
#pressure = 65 kPa

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


list_SA=np.linspace(-15*pi/180,15*pi/180,50)
list_Fz=np.linspace(500,1400,50)


def tau(Fz,camber):
    list_SA=np.linspace(-25*pi/180,0,50)
    return max(Fy(Fz,list_SA,camber))

list_tau=[max(Fy(z,list_SA,0))/z for z in list_Fz]

#%% Plot
    
list_SA=np.linspace(-15*pi/180,15*pi/180,50)
list_Fz=np.linspace(500,1400,50)

#plt.figure(1)
#
#plt.clf()
#
#plt.plot(list_Fz,[max(Fy(z,list_SA,0))/z for z in list_Fz],label='camber = 0 °')
#plt.plot(list_Fz,[max(Fy(z,list_SA,1*pi/180))/z for z in list_Fz],label='camber = 1 °')
#plt.plot(list_Fz,[max(Fy(z,list_SA,2*pi/180))/z for z in list_Fz],label='camber = 2 °')
#plt.plot(list_Fz,[max(Fy(z,list_SA,3*pi/180))/z for z in list_Fz],label='camber = 3 °')
#plt.plot(list_Fz,[max(Fy(z,list_SA,4*pi/180))/z for z in list_Fz],label='camber = 4 °')
#
#plt.ylabel('Lateral coefficient of friction')
#plt.xlabel('Vertical Load (N)')
#plt.grid(True)
#plt.legend()


plt.figure(2)

plt.clf()
for k in range(8):
    plt.plot(180/pi*list_SA,Fy(100+k*150,list_SA,0),color='r',label='Fz = 1400 N')

plt.ylabel('Lateral grip force (N)')
plt.xlabel('Slip angle (°)')
plt.grid(True)


plt.show()
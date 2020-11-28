# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 14:33:24 2019

@author: Martin Kawczynski
"""


import numpy as np
import matplotlib.pyplot as plt
from math import pi
from scipy.optimize import fsolve, fmin, curve_fit
#PHYSICS

g =9.81 # gravité
rho=1.18 # masse volumique air

#%% CAR DATAS
#masses
m_car=215
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

l = 0.205 #largeur du pneu

#%% Aero

#Les données aéros sont données pour Optimus
S= 1.14 #surface effective pour la déportance en m²
Cz= 2.13 #coefficient de portance

#répartition aéro
af = 0.5
ar = 0.5

#%% RATES

phi = np.arctan(2*hrc_f/(2*l+tf))-np.arctan(2*(hrc_f-0.05)/(2*l+tf)) #angle de roulis max


KT = 80000 #tire rate

#spring rates
Ks_f = 175*175 # N/m
Ks_r = 250*175 # N/m

#wheel rates
Kw_f=Ks_f/(MR_f**2) # N/m
Kw_r=Ks_r/(MR_r**2) # N/m

#Ride frequencies

Kr_f = Kw_f*KT/(Kw_f+KT)
Kr_r = Kw_r*KT/(Kw_r+KT)

Ff = np.sqrt(Kr_f/m*2*(w/xr))/(2*pi)
Fr = np.sqrt(Kr_r/m*2*(w/xf))/(2*pi)

#ARB rates
RR = 0.6*pi/180/g # rad/(m/s²) # desired roll rate

cs = 1 #coeff de sécurité pour le roulis

RR=RR/cs

dh= h_stat - (xr/w)*hrc_f - (xf/w)*hrc_r # m
ha = np.cos(np.arctan((hrc_r-hrc_f)/w))*dh

Qsf=Kw_f*tf**2/2 # Nm/rad #raideur en roulis des ressors avant
Qsr=Kw_r*tr**2/2 # Nm/rad #raideur en roulis des ressors arrière
Qs=Qsf*Qsr/(Qsf+Qsr) # Nm/rad

Qarb = ms*ha/RR - Qs # Nm/rad

MN = 0.7 # magic number répartition de raideur anti-roulis à l'avant

Qarb_f= MN*Qarb
Qarb_r= (1-MN)*Qarb


#%% TIRE

corr=0.6 #scaling factor

def Fy_max(Z,camber):
    # with 65 kPa pression
    return corr*(1-(0.00082957*Z-0.02697168)*abs(camber))*(3.05-0.00042857142857142833*Z)*Z



#list_Z=np.array([500,800,1100,1400])
#list_SA=np.array([8.869,7.381,7.083,6.964])
#SA_inf_0 = 6.5
#poly_exp=np.polyfit(np.log(list_Z),np.log(list_SA-SA_inf_0),1)
#SA_0=np.exp(poly_exp[1])
#beta=poly_exp[0]
#    
#def SA_max(Z):
#    # with 65 kPa pression
#    return SA_0*np.exp(beta*Z)+SA_inf_0

SA_inf_0 = 6.9

Z_data = np.array([500,800,1100,1400])
SA_data = np.array([8.869,7.381,7.083,6.964])
poly_exp=np.polyfit(Z_data,np.log(SA_data - SA_inf_0),1)

a_0=np.exp(poly_exp[1])
b_0=poly_exp[0]

def func(Z,a,b,c):
    return a*np.exp(b*Z) + c

popt, pcov = curve_fit(func, Z_data, SA_data ,p0=[a_0,b_0,SA_inf_0],maxfev=10000)


Z_min=500

def SA_max(Z):
    [a,b,c]= popt
    if Z > Z_min:
        return func(Z,a,b,c)
    else:
        return b*a*np.exp(b*Z_min)*(Z-Z_min)+func(Z_min,a,b,c)

#%% SUSPENSION GEOMETRY

def CAMBER(roll):
    poly=np.polyfit(pi/180*np.array([-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,2.5]),pi/180*np.array([2.06,1.66,1.25,0.84,0.42,0,-0.4283,-0.86,-1.30,-1.74,-2.19]),2)
    return np.polyval(poly,roll)

#%% PLOT
    
list_Z=np.linspace(100,1600,50)


plt.figure(1)

plt.clf()

plt.plot(list_Z,Fy_max(list_Z,0*pi/180),label='camber = 0°')
plt.plot(list_Z,Fy_max(list_Z,1*pi/180),label='camber = 1°')
plt.plot(list_Z,Fy_max(list_Z,2*pi/180),label='camber = 2°')
plt.plot(list_Z,Fy_max(list_Z,3*pi/180),label='camber = 3°')
plt.plot(list_Z,Fy_max(list_Z,4*pi/180),label='camber = 4°')

plt.xlabel('Vertical Load (N)')
plt.ylabel('Tire Grip force (N)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=6, mode="expand", borderaxespad=0.)


plt.figure(2)

plt.clf()

plt.plot(list_Z,[SA_max(z) for z in list_Z],label='interpolation')
plt.plot([500,800,1100,1400],[8.869,7.381,7.083,6.964],'o',label='continental specsheet')


plt.xlabel('Vertical Load (N)')
plt.ylabel('Optimum slip angle (°)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=6, mode="expand", borderaxespad=0.)


plt.show()

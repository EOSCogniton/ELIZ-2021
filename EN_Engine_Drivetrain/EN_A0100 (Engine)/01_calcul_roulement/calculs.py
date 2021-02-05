
import numpy as np
import matplotlib.pyplot as plt
from math import pi
from scipy.optimize import fsolve, fmin, curve_fit
from scipy.interpolate import RegularGridInterpolator

#%% Materiau

Re=850*10**6

#%% Calcul cannelures flancs en développantes

C=230

def inv(x):
    return np.tan(x)-x


def stress(m,Z,gw):
    alpha=20*pi/180
    
    esv=100*10**(-6)
    
    D=m*Z
    DB=D*np.cos(alpha)
    
    DEE=m*(Z+1.8)
    DEI=m*(Z+2)
    DII=m*Z
    DIE=m*(Z-0.4)
    
    
    E=pi*m/2
    alphai=np.arccos(DB/DEE)
    wi=DEE*(E/D+inv(alpha)-inv(alphai))
    ti=pi*DEE/Z-wi
    tau_m=2*C/DB*1/(Z*gw)*1/ti
    
    S=pi*m/2
    alphaj=np.arccos(DB/DII)
    wj=DEE*(S/D+inv(alpha)-inv(alphaj))
    tj=pi*DEE/Z-wj
    tau_a= 2*C/DB*1/(Z*gw)*1/tj
    
    sigma=8*C/(Z*gw)*1/(DEE**2-DII**2)
    
    return [sigma,tau_m,tau_a]

def von_mises(sigma,tau_x,tau_y):
    return (sigma**2+3*(tau_x+tau_y)**2)**(1/2)



#%% Calcul concentration de contrainte dans la gorge de l'arbre
    

C=230 #couple moteur

T=8680*13/15 #traction de la chaîne
l=0.022 #bras de levier entre point d'application de la traction et gorge

d=0.021 #diamètre intérieur de la gorge

Mf=T*l
sigma=Mf*32/(pi*d**3)
Kf=1.6

Mt=C
tau=16*Mt/(pi*d**3)
Kt=1.5

VM=((Kf*sigma)**2+3*(Kt*tau)**2)**(1/2)

print('sigma_VM=',round(VM/1000000),'MPa')
print('coefficient de sécurité',round(Re/VM*100)/100)





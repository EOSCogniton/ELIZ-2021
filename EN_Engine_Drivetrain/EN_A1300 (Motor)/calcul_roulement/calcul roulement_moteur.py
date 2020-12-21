# -*- coding: utf-8 -*-
"""
Created on Wed Dec 16 22:03:54 2020

@author: Martin Kawczynski
"""

from math import pi
import numpy as np
import matplotlib.pyplot as plt

#%% Geometry

g = 9.81
d_PA = np.linspace(0,0.10,50)
d_AB = 0.0472

m_rotor = 6

#%% Loads

T = 230*2/0.053

ax = 1.8
ay = 1.4

Y = m_rotor*ay*g

FR_A= (1+d_PA/d_AB)*T + m_rotor*ax*g/2
FR_B= (d_PA/d_AB)*T + m_rotor*ax*g/2


#%% Roulement A

#ref 6206

def L_A(X,Y):
    C_A = 20300
    C0_A = 11200
    alpha='25°'
    e_lim=0.68
    
    if Y/X>e_lim:
        [X_A,Y_A]=[0.67,1.41]
    else:
        [X_A,Y_A]=[1,0.92]
        
    P_A=X_A*X+Y_A*Y
    L_10_A=(C_A/P_A)**3
    return L_10_A*pi*0.470/reduc/1000

#%% Roulement B

#ref 3206

def L_B(X,Y):
    C_B = 31000
    C0_B = 22200
    alpha='30°'
    e_lim=0.80
    if Y/X>e_lim:
        [X_B,Y_B]=[0.63,1.24]
    else:
        [X_B,Y_B]=[1,0.78]
        
    P_B=X_B*X+Y_B*Y
    L_10_B=(C_B/P_B)**3
    return L_10_B*pi*0.470/reduc/1000

#%% Ensemble

def L(X,Y):
    L_10 = (L_A(X,Y)**(-3/2) + L_B(X,Y)**(-3/2))**(-2/3)
    return L_10


reduc=170/53

#distance=pi*0.470*L/reduc

#print('durée de vie roulement A:',round(L_10_A*10)/10, 'millions de tours')
#print('durée de vie roulement B:',round(L_10_B*10)/10, 'millions de tours')
#print('durée de vie ensemble des roulement:',round(L_10*10)/10, 'millions de tours')
#print('durée de vie moteur:',round(distance*1000),'km parcourus par la voiture')

plt.figure(1)

plt.clf()
plt.plot(1000*np.array(d_PA),[L_A(X,Y) for X in d_PA],label='roulement A')
plt.plot(1000*np.array(d_PA),[L_B(X,Y) for X in d_PA],label='roulement B')
plt.plot(1000*np.array(d_PA),[L(X,Y) for X in d_PA],label='ensemble des roulement')
plt.xlabel('Distance du pignon au roulement A (mm)')
plt.ylabel('Durée de vie (km parcouru par la voiture)')
plt.legend()
#plt.yscale('log')
plt.grid(True)
plt.show()
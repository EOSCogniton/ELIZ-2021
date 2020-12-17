# -*- coding: utf-8 -*-
"""
Created on Wed Dec 16 22:03:54 2020

@author: Martin Kawczynski
"""

from math import pi

#%% Geometry

g = 9.81
d_PA = 0.049875
d_AB = 0.0472

m_rotor = 6

#%% Loads

F = 230*2/0.053

a = 1.4

Y = m_rotor*a*g

FR_A= (1+d_PA/d_AB)*F + m_rotor*a*g/2
FR_B= (d_PA/d_AB)*F + m_rotor*a*g/2


#%% Roulement A

#ref 6206

C_A = 20300
C0_A = 11200

alpha='25°'

e_lim=0.68

if Y/FR_A>e_lim:
    [X_A,Y_A]=[0.67,1.41]
else:
    [X_A,Y_A]=[1,0.92]
    
P_A=X_A*FR_A+Y_A*Y

L_10_A=(C_A/P_A)**3

#%% Roulement B

#ref 3206

C_B = 31000
C0_B = 22200

alpha='30°'

e_lim=0.80

if Y/FR_B>e_lim:
    [X_B,Y_B]=[0.63,1.24]
else:
    [X_B,Y_B]=[1,0.78]
    
P_B=X_B*FR_B+Y_B*Y

L_10_B=(C_B/P_B)**3

#%% Ensemble

L_10 = (L_10_A**(-3/2) + L_10_B**(-3/2))**(-2/3)

reduc=170/53

distance=pi*0.470*L_10/reduc

print('durée de vie roulement A:',round(L_10_A)*10**6, 'tours')
print('durée de vie roulement B:',round(L_10_B)*10**6, 'tours')
print('durée de vie ensemble:',round(L_10)*10**6, 'tours')
print('durée de vie ensemble:',round(distance*1000),'km parcourus par la voiture')
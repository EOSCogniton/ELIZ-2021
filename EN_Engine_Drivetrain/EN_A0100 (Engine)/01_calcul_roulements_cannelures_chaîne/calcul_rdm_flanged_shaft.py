from math import pi
import numpy as np
import matplotlib.pyplot as plt


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

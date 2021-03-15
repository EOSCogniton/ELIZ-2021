from math import *
## voir Fanchon pages 238 et suivantes

d=20e-3 #dimension du tube
b=d
a=5e-3 #epaisseur de soudure
v=d/2
F=13e3 #force
L=120e-3 #bras de levier

# Contraintes de flexion
M_f=F*L
I_uz=d**2/6*(3*b+d)
sigma_2=M_f/((sqrt(2)*a*I_uz)/v)
to_2=sigma_2

# Contraintes de cisaillement
to_1=F/(a*L)

# Contraintes de cisaillement avec traction
to_3=F/(a*sqrt(2)*L)
sigma_3=to_3

# Contraintes de Von Mises
sigma_sens_1=sqrt(sigma_2**2+3*(to_1**2+to_2**2))
sigma_sens_2=sqrt((sigma_2+sigma_3)**2+3*(to_2-to_3)**2)
print(max(sigma_sens_1,sigma_sens_2)/(10**6))

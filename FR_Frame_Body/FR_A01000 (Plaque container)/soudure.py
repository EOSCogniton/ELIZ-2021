from math import *
## voir Fanchon pages 238 et suivantes

d=3e-3 #dimension du tube carré
b=20e-3
a=3.3e-3 #epaisseur de soudure
v_carre=d/2

F=6.125e3/2 #force
L=16.4e-3 #bras de levier
rext = 28e-3 
rint = 24e-3
v_rond = rext/2
# Contraintes de flexion
M_f=F*L
I_uz_carre=d**2/6*(3*b+d)
I_uz_rond = pi*rext**3 - pi*rint**3
sigma_2_carre=M_f/((sqrt(2)*a*I_uz_carre)/v_carre)
to_2_carre=sigma_2_carre

sigma_2_rond=M_f/((sqrt(2)*a*I_uz_rond)/v_rond)
to_2_rond=sigma_2_rond
# Contraintes de cisaillement
to_1=F/(a*L)

# Contraintes de cisaillement avec traction
to_3=F/(a*sqrt(2)*L)
sigma_3=to_3

# Contraintes de Von Mises
sigma_sens_1_carre=sqrt(sigma_2_carre**2+3*(to_1**2+to_2_carre**2))
sigma_sens_2_carre=sqrt((sigma_2_carre+sigma_3)**2+3*(to_2_carre-to_3)**2)
print(max(sigma_sens_1_carre,sigma_sens_2_carre)/(10**6))

sigma_sens_1_rond=sqrt(sigma_2_rond**2+3*(to_1**2+to_2_rond**2))
sigma_sens_2_rond=sqrt((sigma_2_rond+sigma_3)**2+3*(to_2_rond-to_3)**2)
print(max(sigma_sens_1_rond,sigma_sens_2_rond)/(10**6))

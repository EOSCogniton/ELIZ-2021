
#%% ###### REAR SLIP ANGLE ######

psi_min=-8*pi/180
psi_max=+8*pi/180

v_min=1
v_max=26

n_psi=200
n_v=200

list_psi=np.linspace(psi_min,psi_max,n_psi)
list_v=np.linspace(1,v_max,n_v)

def rear_slip_angle(R):
    
    diff_grip_r= lambda v,psi: Fy(LOAD_ro(v,R),np.arctan((R*np.sin(psi)-xr)/(R*np.cos(psi)+tr/2)),CAMBER_r(RR*v**2/R))+Fy(LOAD_ri(v,R),np.arctan((R*np.sin(psi)-xr)/(R*np.cos(psi)-tr/2)),CAMBER_r(RR*v**2/R)) - (xf/w)*m*v**2/R
    
    res_v=[]
    res_PSI=[]
    epsilon=0.01
    for psi in list_psi:
        for v in list_v:
            if abs(diff_grip_r(v,psi))<epsilon*(xf/w)*m*v**2/R:
                res_v.append(v)
                res_PSI.append(psi)
    
    return res_PSI[res_v.index(max(res_v))]

    

#%% Approximation linéaire fonction
    
r_min=3.8
r_max=28
n_r=50

list_r=[r_max-(r_max-r_min)*np.cos(k/n_r*pi/2) for k in range(n_r)]
list_PSI=[]

for i in range(len(list_r)):
    list_PSI.append(rear_slip_angle(list_r[i]))



plt.clf()
plt.plot(list_r,np.array(list_PSI)*180/pi,'.')
#plt.plot(list_r,np.array(list_psi_positif)*180/pi,'.',label='avec PSI positif')
plt.ylabel('Angle entre le châssis et la tangente au virage (°)')
plt.xlabel('Rayon du virage (m)')
#plt.legend()
plt.grid(True)

plt.show()

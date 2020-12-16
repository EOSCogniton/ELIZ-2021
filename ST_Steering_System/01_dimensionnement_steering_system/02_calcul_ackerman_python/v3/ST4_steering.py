

#%% RESOLUTION

parallel= True
    

def balance(r):

    theta_ro=np.arctan(-xr/(r+tr/2))
    theta_ri=np.arctan(-xr/(r-tr/2))
    theta_r=np.arctan(-xr/r)
        
    def grip(a):
        
        Fz_fo=LOAD_fo(a,r)
        Fz_fi=max(0,LOAD_fi(a,r))
        Fz_ro=LOAD_ro(a,r)
        Fz_ri=max(0,LOAD_ri(a,r))
        
        alpha_fo=SA_optimum(Fz_fo)
        
        alpha_fi=0
        if parallel:
            alpha_fi=alpha_fo
        else:
            alpha_fi=SA_optimum(Fz_fi)
        
        Fy_fo=Fy(Fz_fo,alpha_fo,CAMBER_f(RR*a))
        Fy_fi=Fy(Fz_fi,alpha_fi,-CAMBER_f(RR*a))
        Fy_ro=Fy(Fz_ro,theta_ro,CAMBER_r(RR*a))
        Fy_ri=Fy(Fz_ri,theta_ri,-CAMBER_r(RR*a))
        
        SIGMA=Fy_fo+Fy_fi+Fy_ro+Fy_ri-m*a
        
        return SIGMA
    
    
    amax = fsolve(grip,g)[0]
    SA_fo=SA_optimum(LOAD_fo(amax,r))
    SA_fi=SA_optimum(LOAD_fi(amax,r))

    Fz_fo=LOAD_fo(amax,r)
    Fz_fi=max(0,LOAD_fi(amax,r))
    Fz_ro=LOAD_ro(amax,r)
    Fz_ri=max(0,LOAD_ri(amax,r))
    
    Fy_fo=Fy(Fz_fo,SA_optimum(Fz_fo),CAMBER_f(RR*amax))
    Fy_fi=Fy(Fz_fi,SA_optimum(Fz_fo),-CAMBER_f(RR*amax))
    Fy_ro=Fy(Fz_ro,theta_ro,CAMBER_r(RR*amax))
    Fy_ri=Fy(Fz_ri,theta_ri,-CAMBER_r(RR*amax))
    
    alpha_fo=SA_fo
    alpha_fi=0
    if parallel:
        alpha_fi=alpha_fo
    else:
        alpha_fi=SA_optimum(Fz_fi)
    
    dF_rolling_resistance= 0.02*((Fz_fo-Fz_fi)*tf+(Fz_ro-Fz_ri)*tr)/w
    dF_tyre_drag= (Fz_fo-Fz_fi)*amax/g*(np.sin(alpha_fo + np.arctan(xf/(r+tf/2)))+np.sin(alpha_fi + np.arctan(xf/(r-tf/2)))+np.sin(np.arctan(-xr/(r+tr/2)))+np.sin(np.arctan(-xr/(r-tr/2))))/2*tf/w
    dF_self_aligning_torque=0
    drive_force=abs(-amax*m/2*(np.sin(abs(theta_ro-theta_r))+np.sin(abs(theta_ri-theta_r))) + 2*(Fz_fo*np.sin(alpha_fo)+Fz_fi*np.sin(alpha_fi))+0.02*m*g)
    required_rear_grip=np.sqrt(drive_force**2+(Fy_ro+Fy_ri)**2)
    
    return [SA_fo,SA_fi,amax,dF_rolling_resistance,dF_tyre_drag,dF_self_aligning_torque,drive_force,Fy_fo+Fy_fi,Fy_ro+Fy_ri]



def steering_angle_o(r):
    return 1*abs(balance(r)[0]) + np.arctan(xf/(r+tf/2))

def steering_angle_i(r):
    return 1*abs(balance(r)[1]) + np.arctan(xf/(r-tf/2))




#%% PLOT

r_min=2
r_max=30
n_r=50

radius=np.array([r_max-(r_max-r_min)*np.cos(k/n_r*pi/2) for k in range(n_r)])

safo=np.array([balance(r)[0] for r in radius])
safi=np.array([balance(r)[1] for r in radius])

accel_max=np.array([balance(r)[2] for r in radius])
rolling_resistance=np.array([balance(r)[3] for r in radius])
tyre_drag=np.array([balance(r)[4] for r in radius])
self_aligning_torque=np.array([balance(r)[5] for r in radius])

drive_force=np.array([balance(r)[6] for r in radius])


basic_front_grip=np.array([balance(r)[7] for r in radius])
basic_rear_grip=np.array([balance(r)[8] for r in radius])

adjusted_front_grip=np.array([balance(r)[7] for r in radius])-rolling_resistance-tyre_drag-self_aligning_torque
adjusted_rear_grip=np.array([np.sqrt(balance(r)[8]**2+balance(r)[6]**2) for r in radius])+rolling_resistance+tyre_drag+self_aligning_torque

thetao=np.array([steering_angle_o(r) for r in radius])
thetai=np.array([steering_angle_i(r) for r in radius])


ackerman_classic=np.array([np.arctan((1/(tf/w+1/np.tan(theta)))) for theta in thetai])
ackerman_advanced=np.array([np.arctan((1/(tf/xf+1/np.tan(theta)))) for theta in thetai]) #desired geometry without slip angles

plt.figure(1)

plt.clf()
plt.plot(radius,180/pi*safo,label='front outter tire')
plt.plot(radius,180/pi*safi,label='front inner tire')
plt.xlabel('Turning radius (m)')
plt.ylabel('Optimum slip angle (°)')
plt.grid(True)
plt.legend()

plt.figure(2)

plt.clf()
plt.plot(radius,180/pi*thetao,label='front outter tire')
plt.plot(radius,180/pi*thetai,label='front inner tire')
plt.xlabel('Turning radius (m)')
plt.ylabel('Steering angle (°)')
plt.grid(True)
plt.legend()

plt.figure(3)
plt.clf()
plt.plot(180/pi*thetai,180/pi*thetai,label='parallel')
plt.plot(180/pi*thetai,180/pi*ackerman_classic,label='classic ackerman')
plt.plot(180/pi*thetai,180/pi*ackerman_advanced,label='true ackermann')
plt.plot(180/pi*thetai,180/pi*thetao,label='desired geometry')
plt.legend()
plt.xlabel('Inner steering angle (°)')
plt.ylabel('Outter steering angle (°)')
plt.grid(True)

plt.figure(4)
plt.clf()
plt.plot(radius,accel_max/g)
plt.xlabel('Turning radius (m)')
plt.ylabel('Maximum lateral aceleration (g)')
plt.grid(True)

plt.show()

plt.figure(5)
plt.clf()
plt.plot(radius,rolling_resistance,label='rolling resistance')
plt.plot(radius,tyre_drag,label='tyre drag')
#plt.plot(radius,self_aligning_torque,label='self aligning torque')
plt.xlabel('Turning radius (m)')
plt.ylabel('Change in grip (N)')
plt.legend()
plt.grid(True)

plt.show()

plt.figure(6)
plt.clf()
plt.plot(radius,drive_force)
plt.xlabel('Turning radius (m)')
plt.ylabel('Drive force (N)')
plt.grid(True)
plt.legend()

plt.show()

plt.figure(7)
plt.clf()
plt.plot(radius,basic_front_grip,label='non ajustée')
plt.plot(radius,adjusted_front_grip,label='ajustée')
plt.xlabel('Turning radius (m)')
plt.ylabel('Front Grip force (N)')
plt.grid(True)
plt.legend()

plt.show()

plt.figure(8)
plt.clf()
plt.plot(radius,basic_rear_grip,label='non ajustée')
plt.plot(radius,adjusted_rear_grip,label='ajustée')
plt.xlabel('Turning radius (m)')
plt.ylabel('Rear Grip force (N)')
plt.grid(True)
plt.legend()

plt.show()
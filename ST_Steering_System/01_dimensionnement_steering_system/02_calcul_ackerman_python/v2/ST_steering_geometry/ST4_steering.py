

#%% RESOLUTION
    

def slip_angles(r):
    def grip(a):
        
        Fz_fo=LOAD_fo(a,r)
        Fz_fi=max(0,LOAD_fi(a,r))
        Fz_ro=LOAD_ro(a,r)
        Fz_ri=max(0,LOAD_ri(a,r))
        
        theta_ro=np.arctan(-xr/(r+tr/2))
        theta_ri=np.arctan(-xr/(r-tr/2))
        
        Fy_fo=Fy(Fz_fo,SA_optimum(Fz_fo),CAMBER_f(RR*a))
        Fy_fi=Fy(Fz_fi,SA_optimum(Fz_fi),-CAMBER_f(RR*a))
        Fy_ro=Fy(Fz_ro,theta_ro,CAMBER_r(RR*a))
        Fy_ri=Fy(Fz_ri,theta_ri,-CAMBER_r(RR*a))
        
        SIGMA=Fy_fo+Fy_fi+Fy_ro+Fy_ri-m*a
        
        return SIGMA
    
    amax = fsolve(grip,g)[0]
    SA_fo=SA_optimum(LOAD_fo(amax,r))
    SA_fi=SA_optimum(LOAD_fi(amax,r))
    return [SA_fo,SA_fi,amax]



def steering_angle_o(r):
    return 1*abs(slip_angles(r)[0]) + np.arctan(xf/(r+tf/2))

def steering_angle_i(r):
    return 1*abs(slip_angles(r)[1]) + np.arctan(xf/(r-tf/2))

#%% PLOT

r_min=2
r_max=50
n_r=50

radius=np.array([r_max-(r_max-r_min)*np.cos(k/n_r*pi/2) for k in range(n_r)])

safo=np.array([slip_angles(r)[0] for r in radius])
safi=np.array([slip_angles(r)[1] for r in radius])

accel_max=np.array([slip_angles(r)[2] for r in radius])

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
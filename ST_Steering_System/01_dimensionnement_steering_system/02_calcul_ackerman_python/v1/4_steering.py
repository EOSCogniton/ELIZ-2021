

#%% RESOLUTION
    

def slip_angles(r):
    def grip(a):
        return GRIP_f(a,r) + GRIP_r(a,r) - m*a
    
    amax = fsolve(grip,g)
    SA_fe=SA_max(LOAD_fe(amax,r))
    SA_fi=SA_max(LOAD_fi(amax,r))
    return [SA_fe[0],SA_fi[0]]

q=xf/w

def steering_angle_e(r):
    return 0.95*slip_angles(r)[0] + np.arctan(w*q/(r+tf/2))*180/pi

def steering_angle_i(r):
    return 0.95*slip_angles(r)[1] + np.arctan(w*q/(r-tf/2))*180/pi

#%% PLOT

radius=np.linspace(5,50,200)
safe=[slip_angles(r)[0] for r in radius]
safi=[slip_angles(r)[1] for r in radius]

thetae=[steering_angle_e(r) for r in radius]
thetai=[steering_angle_i(r) for r in radius]


ackerman_classic=[180/pi*np.arctan((1/(tf/w+1/np.tan(theta*pi/180)))) for theta in thetai]
ackerman_advanced=[180/pi*np.arctan((1/(tf/xf+1/np.tan(theta*pi/180)))) for theta in thetai] #desired geometry without slip angles

plt.figure(1)

plt.clf()
plt.plot(radius,safe,label='front exterior tire')
plt.plot(radius,safi,label='front interior tire')
plt.xlabel('Corner radius (m)')
plt.ylabel('Optimum slip angle (°)')
plt.grid(True)
plt.legend()

plt.figure(2)

plt.clf()
plt.plot(radius,thetae,label='front exterior tire')
plt.plot(radius,thetai,label='front interior tire')
plt.xlabel('Corner radius (m)')
plt.ylabel('Steering angle (°)')
plt.grid(True)
plt.legend()

plt.figure(3)
plt.clf()
plt.plot(thetai,thetai,label='parallel')
plt.plot(thetai,ackerman_classic,label='classic ackerman')
plt.plot(thetai,ackerman_advanced,label='true ackermann')
plt.plot(thetai,thetae,label='desired geometry')
plt.legend()
plt.xlabel('Interior steering angle (°)')
plt.ylabel('Exterior steering angle (°)')
plt.grid(True)

#plt.figure(4)
#plt.clf()
#plt.plot(thetai,thetai/np.arctan(w/(w/np.tan(thetae)-tf)),label='parallel')
#plt.legend()
#plt.xlabel('Interior steering angle (°)')
#plt.ylabel('Ackerman Percentage')
#plt.grid(True)

plt.show()
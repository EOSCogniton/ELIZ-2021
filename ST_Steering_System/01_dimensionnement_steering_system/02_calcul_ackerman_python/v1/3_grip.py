
RR=ms*ha/Qs

def GRIP_fe(ay,R_corner):
    return Fy_max(LOAD_fe(ay,R_corner),CAMBER(RR*ay))

def GRIP_fi(ay,R_corner):
    return Fy_max(LOAD_fi(ay,R_corner),CAMBER(RR*ay))

def GRIP_re(ay,R_corner):
    return Fy_max(LOAD_re(ay,R_corner),CAMBER(RR*ay))

def GRIP_ri(ay,R_corner):
    return Fy_max(LOAD_ri(ay,R_corner),CAMBER(RR*ay))


def GRIP_f(ay,R_corner):
    return GRIP_fe(ay,R_corner)+GRIP_fi(ay,R_corner)

def GRIP_r(ay,R_corner):
    return GRIP_re(ay,R_corner)+GRIP_ri(ay,R_corner)


#%% PLOT
    


R_corner = 8.3

ay=np.linspace(1,1.8,50)
r=np.linspace(3,20,50)
AY, R = np.meshgrid(ay, r)

Ff = GRIP_fe(AY*g,R)+GRIP_fi(AY*g,R)
Fr = GRIP_re(AY*g,R)+GRIP_ri(AY*g,R)

Ffreq = m*AY*g*(xr/w)
Frreq = m*AY*g*(xf/w)

gripf=GRIP_fe(ay*g,R_corner)+GRIP_fi(ay*g,R_corner)
gripr=GRIP_re(ay*g,R_corner)+GRIP_ri(ay*g,R_corner)

#grip = gripr + gripf


plt.figure(1)

plt.clf()

plt.plot(ay,gripf,label='front Fy max',color='blue',linestyle='solid')
plt.plot(ay,m*ay*g*(xr/w),label='required front Fy',color='blue',linestyle='dashed')

plt.plot(ay,gripr,label='rear Fy max',color='red',linestyle='solid')
plt.plot(ay,m*ay*g*(xf/w),label='required rear Fy',color='red',linestyle='dashed')


plt.legend(loc='upper left',borderaxespad=0.1)
plt.xlabel('Lateral acceleration (g)')
plt.ylabel('Lateral force (N)')
plt.grid(True)



plt.figure(2)

plt.clf()

plt.plot(ay,GRIP_fe(ay*g,R_corner),label='front exterior grip')
plt.plot(ay,GRIP_fi(ay*g,R_corner),label='front interior grip')
plt.plot(ay,GRIP_re(ay*g,R_corner),label='rear exterior grip')
plt.plot(ay,GRIP_ri(ay*g,R_corner),label='rear interior grip')

plt.xlabel('Acceleration (g)')
plt.ylabel('Grip force (N)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=2, mode="expand", borderaxespad=0.)


#plt.figure(3)

#plt.clf()
#cont=plt.contour(AY, R, Ff-Ffreq,10)
#plt.clabel(cont)
#plt.xlabel('Lateral acceleration (g)')
#plt.ylabel('Corner radius (m)')
#
#plt.figure(4)
#
#plt.clf()
#cont=plt.contour(AY, R, Fr-Frreq,10)
#plt.clabel(cont)
#plt.xlabel('Lateral acceleration (g)')
#plt.ylabel('Corner radius (m)')
#
#plt.figure(5)
#
#plt.clf()
#cont=plt.contour(AY, R, Fr+Ff-Frreq-Ffreq,10)
#plt.clabel(cont)
#plt.xlabel('Lateral acceleration (g)')
#plt.ylabel('Corner radius (m)')
#plt.grid(True)

plt.show()

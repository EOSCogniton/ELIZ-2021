list_sa=np.linspace(-SA_limit,0,100)

def GRIP_fo(ay,R_corner):
    Fz=LOAD_fo(ay,R_corner)
    c=CAMBER_f(RR*ay)
    return tau(Fz,c)*Fz

def GRIP_fi(ay,R_corner):
    Fz=LOAD_fi(ay,R_corner)
    c=CAMBER_f(RR*ay)
    return tau(Fz,c)*Fz

def GRIP_ro(ay,R_corner):
    Fz=LOAD_ro(ay,R_corner)
    c=CAMBER_r(RR*ay)
    return tau(Fz,c)*Fz

def GRIP_ri(ay,R_corner):
    Fz=LOAD_ri(ay,R_corner)
    c=CAMBER_r(RR*ay)
    return tau(Fz,c)*Fz


#def GRIP_f(ay,R_corner):
#    return GRIP_fe(ay,R_corner)+GRIP_fi(ay,R_corner)
#
#def GRIP_r(ay,R_corner):
#    return GRIP_re(ay,R_corner)+GRIP_ri(ay,R_corner)


#%% PLOT
    
R_corner = 15.25/2+(lt+max(tf,tr))/2

ay=np.linspace(1,1.8,100)
r=np.linspace(3,50,50)
AY, R = np.meshgrid(ay, r)



Gf=[GRIP_fo(a*g,R_corner)+GRIP_fi(a*g,R_corner) for a in ay]


plt.figure(1)

plt.clf()

plt.plot(ay,GRIP_fo(ay*g,R_corner)+GRIP_fi(ay*g,R_corner),label='front Fy max',color='blue',linestyle='solid')
plt.plot(ay,m*ay*g*(xr/w),label='required front Fy',color='blue',linestyle='dashed')

plt.plot(ay,GRIP_ro(ay*g,R_corner)+GRIP_ri(ay*g,R_corner),label='rear Fy max',color='red',linestyle='solid')
plt.plot(ay,m*ay*g*(xf/w),label='required rear Fy',color='red',linestyle='dashed')


plt.legend()
plt.xlabel('Lateral acceleration (g)')
plt.ylabel('Lateral force (N)')
plt.grid(True)



plt.figure(2)

plt.clf()

plt.plot(ay,GRIP_fo(ay*g,R_corner),label='front exterior grip')
plt.plot(ay,GRIP_fi(ay*g,R_corner),label='front interior grip')
plt.plot(ay,GRIP_ro(ay*g,R_corner),label='rear exterior grip')
plt.plot(ay,GRIP_ri(ay*g,R_corner),label='rear interior grip')

plt.xlabel('Acceleration (g)')
plt.ylabel('Grip force (N)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=2, mode="expand", borderaxespad=0.)

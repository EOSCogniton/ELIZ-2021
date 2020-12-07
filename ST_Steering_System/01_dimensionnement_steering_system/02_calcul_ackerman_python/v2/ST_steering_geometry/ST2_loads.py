
def LATERAL_LOAD_TRANSFER_f(ay):
    du = 2*m_wheel*ay*h_wheel/tf
    ds = (xr/w)*ms*ay*(hrc_f/tf)
    dr = ms*ay*(ha/tf)*(Kr_f+2*Qarb_f/tf)/(Kr_f+Kr_r+2*(Qarb_f+Qarb_r)/tf)
    return du + ds + dr


def LATERAL_LOAD_TRANSFER_r(ay):
    du = 2*m_wheel*ay*h_wheel/tr
    ds = (xf/w)*ms*ay*(hrc_r/tr)
    dr = ms*ay*(ha/tr)*(Kr_r+2*Qarb_r/tr)/(Kr_f+Kr_r+2*(Qarb_f+Qarb_r)/tr)
    return du + ds + dr


def LOAD_fo(ay,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*ay*R_corner + LATERAL_LOAD_TRANSFER_f(ay)

def LOAD_fi(ay,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*ay*R_corner - LATERAL_LOAD_TRANSFER_f(ay)

def LOAD_ro(ay,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*ay*R_corner + LATERAL_LOAD_TRANSFER_r(ay)

def LOAD_ri(ay,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*ay*R_corner - LATERAL_LOAD_TRANSFER_r(ay)


#%% PLOT
    

ay = np.linspace(1.2,1.6,30)
R_corner=0


plt.clf()

plt.plot(ay,LOAD_fo(ay*g,R_corner),label='front exterior load')
plt.plot(ay,LOAD_fi(ay*g,R_corner),label='front interior load')
plt.plot(ay,LOAD_ro(ay*g,R_corner),label='rear exterior load')
plt.plot(ay,LOAD_ri(ay*g,R_corner),label='rear interior load')

plt.xlabel('Acceleration (g)')
plt.ylabel('Vertical load (N)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=2, mode="expand", borderaxespad=0.)


def LATERAL_LOAD_TRANSFER_f(ay,R_corner):
    du = 2*m_wheel*ay*h_wheel/tf
    ds = (xr/w)*ms*ay*(hrc_f/tf)
    dr = ms*ay*(ha/tf)*(Kw_f+2*Qarb_f/tf)/(Kw_f+Kw_r+2*(Qarb_f+Qarb_r)/tf)
    return du + ds + dr


def LATERAL_LOAD_TRANSFER_r(ay,R_corner):
    du = 2*m_wheel*ay*h_wheel/tr
    ds = (xf/w)*ms*ay*(hrc_r/tr)
    dr = ms*ay*(ha/tr)*(Kw_r+2*Qarb_r/tr)/(Kw_f+Kw_r+2*(Qarb_f+Qarb_r)/tr)
    return du + ds + dr

def LOAD_fe(ay,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*ay*R_corner + LATERAL_LOAD_TRANSFER_f(ay,R_corner)

def LOAD_fi(ay,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*ay*R_corner - LATERAL_LOAD_TRANSFER_f(ay,R_corner)

def LOAD_re(ay,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*ay*R_corner + LATERAL_LOAD_TRANSFER_r(ay,R_corner)

def LOAD_ri(ay,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*ay*R_corner - LATERAL_LOAD_TRANSFER_r(ay,R_corner)


#%% PLOT
    

ay = np.linspace(1,1.8,30)
R_corner=40

plt.clf()

plt.plot(ay,LOAD_fe(ay*g,R_corner),label='front exterior load')
plt.plot(ay,LOAD_fi(ay*g,R_corner),label='front interior load')
plt.plot(ay,LOAD_re(ay*g,R_corner),label='rear exterior load')
plt.plot(ay,LOAD_ri(ay*g,R_corner),label='rear interior load')

plt.xlabel('Acceleration (g)')
plt.ylabel('Vertical load (N)')
plt.grid(True)
plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc='lower left', ncol=2, mode="expand", borderaxespad=0.)


def LATERAL_LOAD_TRANSFER_f(v,R_corner):
    du = 2*m_wheel*v**2/R_corner*h_wheel/tf
    ds = (xr/w)*ms*v**2/R_corner*(hrc_f/tf)
    dr = ms*v**2/R_corner*(ha/tf)*(Kr_f+2*Qarb_f/tf)/(Kr_f+Kr_r+2*(Qarb_f+Qarb_r)/tf)
    return du + ds + dr


def LATERAL_LOAD_TRANSFER_r(v,R_corner):
    du = 2*m_wheel*v**2/R_corner*h_wheel/tr
    ds = (xf/w)*ms*v**2/R_corner*(hrc_r/tr)
    dr = ms*v**2/R_corner*(ha/tr)*(Kr_r+2*Qarb_r/tr)/(Kr_f+Kw_r+2*(Qarb_f+Qarb_r)/tr)
    return du + ds + dr

def LOAD_fo(v,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*v**2 + LATERAL_LOAD_TRANSFER_f(v,R_corner)

def LOAD_fi(v,R_corner):
    return m*g*(xr/w)/2 + 0.5*af*0.5*Cz*rho*S*v**2 - LATERAL_LOAD_TRANSFER_f(v,R_corner)

def LOAD_ro(v,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*v**2 + LATERAL_LOAD_TRANSFER_r(v,R_corner)

def LOAD_ri(v,R_corner):
    return m*g*(xf/w)/2 + 0.5*ar*0.5*Cz*rho*S*v**2 - LATERAL_LOAD_TRANSFER_r(v,R_corner)


#%% PLOT
    


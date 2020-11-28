

df=50

r_min=2
r_max=30
n_r=100

list_r=np.array([r_max-(r_max-r_min)*np.cos(k/n_r*pi/2) for k in range(n_r)])

psi_min=-4*pi/180
psi_max=+4*pi/180
n_psi=50

list_psi=np.linspace(psi_min,psi_max,n_psi)

v_min=1
v_max=24
n_v=150

list_v=np.linspace(v_min,v_max,n_v)


res_v_initial=[]
res_v=[]

res_r=[]

res_psi=[]
res_psi_initial=[]

SA_inn=[]
SA_out=[]

delta_inn=[]
delta_out=[]

jacking=False

for r in list_r:
    for v in list_v:
        
        psi=0
        
        Fz_fo=LOAD_fo(v,r)
        Fz_fi=max(0,LOAD_fi(v,r))
        Fz_ro=LOAD_ro(v,r)
        Fz_ri=max(0,LOAD_ri(v,r))
        
        theta_ro=np.arctan((r*np.sin(psi)-xr)/(r*np.cos(psi)+tr/2))
        theta_ri=np.arctan((r*np.sin(psi)-xr)/(r*np.cos(psi)-tr/2))
        
#        if Fz_fi<0 or Fz_ri<0:
#            jacking=True
        
        Fy_fo=Fy(Fz_fo,SA_optimum(Fz_fo),CAMBER_f(RR*v**2/r))
        Fy_fi=Fy(Fz_fi,SA_optimum(Fz_fi),-CAMBER_f(RR*v**2/r))
        Fy_ro=Fy(Fz_ro,theta_ro,CAMBER_r(RR*v**2/r))
        Fy_ri=Fy(Fz_ri,theta_ri,-CAMBER_r(RR*v**2/r))
        
        SIGMA=Fy_fo+Fy_fi+Fy_ro+Fy_ri-m*v**2/r
        
        if abs(SIGMA)<df:
            if not(jacking):
                res_v.append(v)
                res_r.append(r)
                SA_inn.append(SA_optimum(LOAD_fi(v,r)))
                SA_out.append(SA_optimum(LOAD_fo(v,r)))
                delta_inn.append(abs(SA_optimum(LOAD_fi(v,r)))+np.arctan((r*np.sin(psi)+xf)/(r*np.cos(psi)-tr/2)))
                delta_out.append(abs(SA_optimum(LOAD_fo(v,r)))+np.arctan((r*np.sin(psi)+xf)/(r*np.cos(psi)+tr/2)))

#for r in list_r:
#    
#    def diff_grip(arg):
#        
#        [v,psi]=arg
#    
#        Fz_fo=LOAD_fo(v,r)
#        Fz_fi=LOAD_fi(v,r)
#        Fz_ro=LOAD_ro(v,r)
#        Fz_ri=LOAD_ri(v,r)
#        
#        theta_ro=np.arctan((-r*np.sin(psi)-xr)/(r*np.cos(psi)+tr/2))
#        theta_ri=np.arctan((-r*np.sin(psi)-xr)/(r*np.cos(psi)-tr/2))
#        
#        
#        Fy_fo=Fy(Fz_fo,SA_optimum(Fz_fo),CAMBER_f(RR*v**2/r))
#        Fy_fi=Fy(Fz_fi,SA_optimum(Fz_fi),-CAMBER_f(RR*v**2/r))
#        Fy_ro=Fy(Fz_ro,theta_ro,CAMBER_r(RR*v**2/r))
#        Fy_ri=Fy(Fz_ri,theta_ri,CAMBER_r(-RR*v**2/r))
#        
#        return [Fy_fo+Fy_fi+Fy_ro+Fy_ri-np.cos(psi)*m*v**2/r,0]
#        
#    for psi_0 in list_psi:
#        res_v_initial.append(fsolve(diff_grip,x0=[np.sqrt(15*r),psi_0])[0])
#        res_psi_initial.append(fsolve(diff_grip,x0=[np.sqrt(15*r),psi_0])[1])
#    
#    res_v.append(max(res_v_initial))
#    res_psi.append(res_psi_initial[res_v_initial.index(max(res_v_initial))])
    
    
    
    
    
plt.figure(1)
plt.clf()
plt.plot(res_r,3.6*np.array(res_v),'.')
plt.grid(True)
plt.xlabel('rayon (m)')
plt.ylabel('v (km/h)')

#plt.figure(2)
#plt.clf()
#plt.plot(res_r,180/pi*np.array(res_psi),'.')
#plt.grid(True)
#plt.xlabel('rayon (m)')
#plt.ylabel('psi (°)')

plt.figure(3)
plt.clf()
plt.plot(res_r,180/pi*np.array(SA_inn),'.',label='inner tire')
plt.plot(res_r,180/pi*np.array(SA_out),'.',label='outter tire')
plt.grid(True)
plt.xlabel('rayon (m)')
plt.ylabel('optimum slip angle (°)')

plt.figure(4)
plt.clf()
plt.plot(res_r,180/pi*np.array(delta_inn),'.',label='inner tire')
plt.plot(res_r,180/pi*np.array(delta_out),'.',label='outter tire')
plt.grid(True)
plt.legend()
plt.xlabel('rayon (m)')
plt.ylabel('steering angle (°)')


ackerman_classic=[np.arctan((1/(tf/w+1/np.tan(delta)))) for delta in delta_inn]
ackerman_advanced=[np.arctan((1/(tf/xf+1/np.tan(delta)))) for delta in delta_inn] #desired geometry without slip angles


plt.figure(5)
plt.clf()
plt.plot(180/pi*np.array(delta_inn),180/pi*np.array(delta_inn),'.',label='parallel')
plt.plot(180/pi*np.array(delta_inn),180/pi*np.array(ackerman_classic),'.',label='classic ackerman')
plt.plot(180/pi*np.array(delta_inn),180/pi*np.array(ackerman_advanced),'.',label='true ackermann')
plt.plot(180/pi*np.array(delta_inn),180/pi*np.array(delta_out),'.',label='desired geometry')
plt.legend()
plt.xlabel('Inner steering angle (°)')
plt.ylabel('Outter steering angle (°)')
plt.grid(True)
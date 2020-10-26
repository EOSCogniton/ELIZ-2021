function resu=C_max()
sf=f_C_al() ;
a = 0.5*(0:20) ;
dz = -250 : 250 ;
rd = 197+562+dz ;
rg = 197+562-dz ;
K = zeros(1,21) ;
for i=1:21
    L=zeros(1,501) ;
    for j=1:501
        L(j) = sf(a(i),rd(j)) + sf(a(i),rg(j)) ;
    end
    K(i) = max(L) ;
end
resu = max(K) ;

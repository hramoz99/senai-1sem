en
conf t
hostname RT-01


!Interface do Departamento de ADM
int g0/0
ip add 192.168.0.1 255.255.255.128
description GATEWAY ADM
no shutdown


!Interface do Departamento de RH
int g1/0
ip add 192.168.0.129 255.255.255.224 
description GATEWAY RH
no shutdown


!Interface do Departamento de FIN
int g2/0
ip add 192.168.0.161 255.255.255.224
description GATEWAY FIN
no shutdown


!Interface do Departamento da DIR
int g3/0
ip add 192.168.0.193 255.255.255.240
description GATEWAY DIR
no shutdown


!Interface do Departamento de TI
int g4/0
ip add 192.168.0.209 255.255.255.248
description GATEWAY TI
no shutdown


!Salvar as configurações (tela de enable)
end
wr


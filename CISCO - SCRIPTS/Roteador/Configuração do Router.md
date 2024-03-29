# Roteador 

#### Nome do Host, Enable Secret, Banner
```
en
configure t
hostname RT-01
line console 0
password TI*Marte2077
login
exit
enable secret SenhaMarciana7702
service password-encryption
banner motd "ACESSO AUTORIZADO APENAS PARA O DEPARTAMENTO DE TI DA COLONIA MARCIANA!"
```

#### Usuário e Senha Local
```
username suporte-marte privilege 15 secret suporte@123
```

#### Nome de Domínio
```
ip domain-name coloniamarciana.local
```

#### Chave de Criptografia 
```
crypto key generate rsa general-key modulus 1024
```

#### Linhas VTY e Console
```
line vty 0 15
transport input SSH
login local
line con 0
login local
end
```

#### Ativar Interface
```
conf t
int g0/0
no shutdown
```

#### Atrelar o endereço a uma sub-interface - IPv4
```
int g0/0.10
encapsulation dot1q 10
ip add 192.168.0.1 255.255.255.128
description GATEWAY VLAN 10
int g0/0.20
encapsulation dot1q 20
ip add 192.168.0.129 255.255.255.224
description GATEWAY VLAN 20
int g0/0.30
encapsulation dot1q 30
ip add 192.168.0.161 255.255.255.224
description GATEWAY VLAN 30
int g0/0.40
encapsulation dot1q 40
ip add 192.168.0.193 255.255.255.240
description GATEWAY VLAN 40
int g0/0.50
encapsulation dot1q 50
ip add 192.168.0.209 255.255.255.240
description GATEWAY VLAN 50
int g0/0.60
encapsulation dot1q 60
ip add 192.168.0.225 255.255.255.240
description GATEWAY VLAN 60
end
conf t
int s0/0/0
ip add 200.100.0.1 255.255.255.252
no shutdown
end
```

#### Rota Padrão de roteamento
```
conf t
ip route 0.0.0.0 0.0.0.0 200.100.0.2
```

#### Atrelar o endereço Ip a um sub-interface - IPv6
```
ipv6 unicast-routing
int g0/0.10
encapsulation dot1q 10
ipv6 add 2001:db8:cafe:1::1/64
ipv6 add fe80::1 link-local
description GATEWAY VLAN 10 


int g0/0.20
encapsulation dot1q 20
ipv6 add 2001:db8:cafe:2::1/64
ipv6 add fe80::1 link-local
description GATEWAY VLAN 20

int g0/0.30
encapsulation dot1q 30
ipv6 add 2001:db8:cafe:3::1/64
ipv6 add fe80::1 link-local
description GATEWAY VLAN 30


int g0/0.40
encapsulation dot1q 40
ipv6 add 2001:db8:cafe:4::1/64
ipv6 add fe80::1 link-local
description GATEWAY VLAN 40


int g0/0.50
encapsulation dot1q 50
ipv6 add 2001:db8:cafe:5::1/64
ipv6 add fe80::1 link-local
description GATEWAY VLAN 50
end
conf t
int s0/0/0
ipv6 add 2000:200:100::1/64
no shutdown
end
```

#### Rota Padrão de roteamento
```
conf t
ipv6 route ::/0 2000:200:100::2
```

#### Salvar as configurações
```
wr
```







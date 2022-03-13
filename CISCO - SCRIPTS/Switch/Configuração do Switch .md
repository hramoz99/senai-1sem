# Switch 

#### Nome do Host, Enable Secret, Banner
 ```
en
conf t
hostname SW-X
line console 0
password TI*MARCIANA
login
exit
enable secret SenhaMarciana7702
service password-encryption
banner motd "ACESSO AUTORIZADO APENAS PARA O DEPARTAMENTO DE TI DA COLONIA MARCIANA!"
```

#### Usuário e senha LOCAL
```
username suporte-marte privilege 15 secret suporte@123
```

#### Nome de DOMÍNIO
```
ip domain-name coloniamarciana.local
```

#### Chave de Criptografia
```
crypto key generate rsa general-key modulus 1024
```
#### Linhas  VTY e Console 
```
line vty 0 15
transport input SSH
login local
line con 0
login local
end
```

#### Criação de VLANS
```
conf t
vlan 50
name SERVIDORES
vlan 60
name GERENCIAMENTO
exit
```

#### Atrelar as VLANS a uma interface FASTETHERNET - ACCESS
```
int range f0/1-2
switchport mode access
switchport access vlan 50
int f0/3
switchport mode access
switchport access vlan 60
exit
```

#### Atrelar as VLANS a uma interface GIGAETHERNET -  TRUNK
```
int G0/1
switchport mode trunk
switchport trunk native vlan 99
switchport trunk allowed vlan 10,20,30,40,50,60,99
int range f0/21-24
switchport mode trunk
switchport trunk native vlan 99
switchport trunk allowed vlan 10,20,30,40,50,60,99
end
```

#### Atrelar o endereço  IP a uma interface - IPv4
```
configure terminal
int vlan 60
ip add 192.168.0.X 255.255.255.240
no shutdown
end
```
#### Desativarr as interfaces
```
conf t
int range f0/4-19
int g0/2
shutdown
end
```
#### Salvar as configurações
```
wr
```






!Nome do host, Enable secret e Banner
en
conf t
hostname SW-X
line console 0
password TI*Marte2077
login
exit
enable secret SenhaMarciana7702
service password-encryption
banner motd "ACESSO AUTORIZADO APENAS PARA O DEPARTAMENTO DE TI DA COLONIA MARCIANA!"


!Usuário e senha local
username suporte-marte privilege 15 secret suporte@123

!Nome de dominio
ip domain-name coloniamarciana.local


!Chave de criptografia
crypto key generate rsa general-key modulus 1024

!Linhas VTY e Console
line vty 0 15
transport input SSH
login local
line con 0
login local
end

!Criacao das VLANs
conf t
vlan 50
name SERVIDORES
vlan 60
name GERENCIAMENTO
exit


!Atrelar as Vlans a uma interface FastEthernet (access)
int range f0/1-2
switchport mode access
switchport access vlan 50
int f0/3
switchport mode access
switchport access vlan 60
exit


!Atrelar a Vlan a uma interface FastEthernet (trunk)
int G0/1
switchport mode trunk
switchport trunk native vlan 99
switchport trunk allowed vlan 10,20,30,40,50,60,99
int range f0/21-24
switchport mode trunk
switchport trunk native vlan 99
switchport trunk allowed vlan 10,20,30,40,50,60,99
end


!Atrelar o endereço ip a uma interface (IPv4)
conf t
int vlan 60
ip add 192.168.0.X 255.255.255.240
no shutdown
end

!Desativar as interfaces
conf t
int range f0/4-19
int g0/2
shutdown
end

!Salvar as configurações (tela de enable)
wr







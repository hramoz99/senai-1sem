# Roteamento Estático

#### Atrelar o endereço IP a uma Rota Estática
```
en
conf t
int s0/0/0
ip add 200.100.0.1 255.255.255.252
no shutdown
exit
```

#### Rota de Roteamento
```
ip route 172.16.0.0 255.255.0.0 200.100.0.2
```

#### Rota Padrão de Roteamento
```
ip route 0.0.0.0 0.0.0.0 150.200.0.2
end
```

#### Salvar as Configurações
```
wr
```

###  IPv4

#### Nome do  ROUTER
```
en
conf t
hostname RT-02
```


#### Habilitar o ROUTER para IPv6
```
ipv6 unicast-routing
```


#### Atrelar o endereço IPv6 a uma interface GIGAETHERNET 
```
int g0/0
ipv6 add 2001:db8:faca:1::1/64
ipv6 add fe80::1 link-local
no shutdown
```


#### Atrelar o endereço IP a uma rota Estática 
```
int s0/0/0
ipv6 add 2001:db8:faca:2::2/64
no shutdown
exit
```

#### Tabela de Roteamento IPv6
```
ipv6 route 2001:db8:faca:0::/64 2001:db8:faca:2::1
```




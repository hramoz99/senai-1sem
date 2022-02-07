
# Configurações Básicas

#### Nome do Host 
```
en
conf t
hostname S2
```


#### Senhas de Login e Enable Secret 
```
line console 0
password cisco
login
exit
enable secret class
service password-encryption
```

#### Banner
```
banner motd "Somente Acesso Autorizado. Infratores sofrerão as consequências da lei."
```

#### Salvar as Configurações 
```
wr
```

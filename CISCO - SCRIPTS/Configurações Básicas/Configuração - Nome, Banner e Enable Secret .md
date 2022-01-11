#### NOME DO HOST
```
en
conf t
hostname S2
```


#### SENHAS DE LOGIN E ENABLE SECRET 
```
line console 0
password cisco
login
exit
enable secret class
service password-encryption
```

#### BANNER
```
banner motd "Somente Acesso Autorizado. Infratores sofrerão as consequências da lei."
```

#### SALVAR AS CONFIGURAÇÕES 
```
wr
```

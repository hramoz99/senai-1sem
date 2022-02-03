#### NOME DO HOST
```
en
conf t
hostname RT-01
```


#### ENDEREÇO IP
```
int g0/0
ip address 172.16.0.1 255.255.0.0
no shutdown
exit
```

#### NOMDE DE DOMÍNIO 
```
ip domain-name aula41.local
```

#### CHAVE DE CRIPTOGRAFIA 
```
crypto key generate rsa general-key modulus 1024
```

#### NOME DO USUÁRIO LOCAL
```
username suporte privilege 15 secret suporte@123
```

#### CONFIGURAÇÃO NAS LINHAS VTY 
```
line vty 0 15
transport input ssh
login local
exit
```

#### SENHA DA ENABLE SECRET 
```
enable secret SenhaSecreta
```


#### SALVAR CONFIGURAÇÕES - TELA ENABLE
```
end
wr
```

**OBS: Acessar SSH no prompt de comando**
> Para ter acesso remoto é necessário uma senha de enable

C:\ssh -l [nome-do-usuário] [endereço-ip]


# Acesso Remoto - SSH

#### Nome do Host 
```
en
conf t
hostname RT-01
```


#### Endereço IP
```
int g0/0
ip address 172.16.0.1 255.255.0.0
no shutdown
exit
```

#### Nome de Domínio 
```
ip domain-name aula41.local
```

#### Chave de criptografia
```
crypto key generate rsa general-key modulus 1024
```

#### Nome do Usuário Local 
```
username suporte privilege 15 secret suporte@123
```

#### Configuração nas linhas TTY 
```
line vty 0 15
transport input ssh
login local
exit
```

#### Senhas da Enable Secret
```
enable secret SenhaSecreta
```


#### Salvar as configurações - TELA ENABLE
```
end
wr
```

**OBS: Acessar SSH no prompt de comando**
> Para ter acesso remoto é necessário uma senha de enable

C:\ssh -l [nome-do-usuário] [endereço-ip]


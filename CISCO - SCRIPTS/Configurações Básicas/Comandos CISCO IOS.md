# COMANDOS CISCOS


#### Entrar em modo PRIVILEGIADO 
```
>enable
```

#### Tela de confguração do equipamento
```
#configure terminal
```

#### Mostrar as configurações que estão salvas
```
#show startup-config
```

#### Ver o resumo das interfaces 
```
#show ip interface brief
```

#### Trocar o nome do equipamento
```
(config)#hostname <nome>
```

#### Configurar o Banner
```
(config)#banner motd "<texto>"
```

#### Destravar o terminal 
```
Ctrl+Shift+6
```

#### Configurar senha da console 
```
(config)#line console 0
(config-line)#password <senha>
(config-line)#login
```

#### Configurar Senha Secret
```
(config)#enable secret <senha>
```

#### Verificar as configurações
```
#show running-config
```

#### Ativar o serviço de criptografia 
```
(config)#service password-encryption
```

#### Desfazer configurações no IOS
```
Colocar "no" na frente do comando
```

#### Desativar uma interface
```
(config)#interface <nome>
(config-if)#shutdown
```
 
#### Desativar múltiplas interfaces simultaneamente 
```
(config)#interface range <intervalo>
(config-if-range)#shutdown
```

#### Ver resumo das interfaces  
```
#show ip interface brief
```

#### Salvar as configurações
```
#wr
```

#### Resetar o equipamento
```
#write erase
```

#### Colocar IP em uma interface _
```
(config)#interface <nome>
(config-if)#ip address <ip> <mascara>
(config-if)#no shutdown
```

#### Colocar descrição em uma interface
```
(config)#interface <nome>
(config)#description <descricao>
```

## Configurar Acesso SSH nas VTY

#### Definir o nome de Domínio 
```
(config)#ip domain-name <nome-do-domínio>
```

#### Gerar chave de Criptografia   
```
(config)#crypto key generate rsa general-keys modulus <nº-de-bits-da-chave>
```

#### Criar usuário no dispositivo 
```
(config)#username <nome-do-usuário> privilege <1-15> secret <senha>
```

#### Ativar o SSH nas linhas de VTY 
```
(config)#line vty 0 15
(config-line)#transport input ssh
(config-line)#login local
```

#### Configurar a VTY para utilizar Telnet
```
(config)#line vty 0 15
(config-line)#password <senha>
(config-line)#login
```

#### Ativar login na CONSOLE
```
(config)#line console 0
(config-line)#login local
```

#### Ver arquivos na memória FLASH
```
#dir flash
```

#### Ver arquivos na memória NVRAM
```
#dir nvram
```

#### Mostrar as configurações que estão ativas                
```
#show run
```

#### Mostrar as configurações que estão salvas               
```
#show startup-config
```

#### Mostrar o resumo das interfaces 
```
#show ip interface brief (IPv4)
#show ipv6 interface brief (IPv6)
```

#### Mostrar a tabela Mac do SWITCH
```
#show mac-address-table (IOS 12.2)
#show mac address-table dynamic (IOS 15.0)
```

#### Exibir a tabela de Roteamento
```
#show ip route
```

#### Exibir um resumo das VLANS e interfaces atreladas 
```
#show vlan brief
```

#### Exibir informações sobre uma VLAN específica
```
#show vlan id [id-da-vlan] ou show vlan name [nome-da-vlan]
```

#### Exibir informações relacioandas a VLAN em uma interface específica
```
#show interface [id-da-interface] switchport
```

#### Acesso Remoto - SSH
```
C:/ ssh -l [endereço-ip]
```

#### Desativar Paginação (--MORE--)
```	
#terminal length 0
```

#### Desativar as mensagens de ERRO na tela 
```	
(config)#no logging console
```

### Configurações EXCLUSIVAS para Roteador  

#### Visualizar tabela de roteamento 
```
#show ip route
```

#### Configurar Sub-Interface             
```
(config)#interface <nome-da-subinterface-com-a-vlan>
(config-subif)#encapsulation dot1q <nº-da-vlan>
(config-subif)#ip address <ip> <máscara>
```

#### Ativar Roteamento IPv6
```
(config)#ipv6 unicast-routing
```
#### Inserir IPv6 a uma interface 
```
(config)#interface <nome-da-interface>
(config-if)#ipv6 address <endereço>/<prefixo>
```

#### Rota Estática
```
(config)#ip route <id-da-rede-de-destino> <máscara-da-rede> <ip-do-roteador-que conhece-a-rede>
```

### Configurações EXCLUSIVAS para o Switch

#### Criar uma VLAN
```
(config)#vlan <nº-da-vlan>
(config-vlan)#name <nome-da-vlan>
```

#### Atrelar uma interface a uma VLAN 
```
(config)#interface <nome-da-interface>
(config-if)#switchport mode access
(config-if)#switchport access vlan 10
```

#### Verificar as configurações da VLAN
```
#show vlan brief
```

#### Configurar uma interface para MODO TRUNK 
```
(config)#interface <nome-da-interface>
(config-if)#switchport mode trunk
```

#### Configurar a VLAN Nativa na interface TRUNK
```	
(config)#interface <nome-da-interface>
(config-if)#switchport trunk native vlan <nº-da-vlan-nativa>
```

#### Liberar as VLANS na interface TRUNK 
```
(config)#interface <nome-da-interface>
(config-if)#switchport trunk allowed vlan <lista de vlans separadas por VÍRGULAS>
```
       
#### Configurar IP - SEM SWITCH
```
(config)#interface vlan 90
(config-if)#ip address <endereço> <máscara>
```


## RESETAR O ROUTER E O SWITCH

#### Resetar o Switch
	
```	
1) Conectar o cabo Rollover

2) Verificar a porta de comunicação (COM1)
      Windows+R
      devmgmt.msc
3) Conectar o cabo de energia e ligar o Switch
	
4) Abrir o Putty e selecionar a opção 'Serial'. Inserir a opção COM1 e clicar no botão 'Open'

5) Esperar o Switch ligar completamente (Vai aparecer a tela '>' OU vai pedir para entrar no modo de configuração guiado [yes/no] OU o equipamento vai pedir uma senha caso já esteja configurado)
      Obs: Caso a tela do Putty fique muito tempo parada, aperte a tecla Enter

6) Após o Switch ligar completamente, aperte e segure o botão MODE até que os dois primeiros LEDs fiquem Laranja e solte.
	
7) Espere o Switch reiniciar e verifique se o reset funcionou

Resetar o Router
1) Abrir o Putty e conectar no Roteador com o equipamento DESLIGADO

2) Ligar o Roteador e pressionar diversas vezes o atalho "Ctrl+Pause Break", até aparecer o texto "rommon 1>"

3) Digitar os seguintes comandos NESSA SEQUÊNCIA:
       confreg 0x2142
       reset

4) Espera o roteador reiniciar e verifique se o Roteador está no registrador correto (0x2142)
      #show version

5) Salvar as configurações de fábrica na startup-config
      #write memory
	  ou
      #wr

6)Voltar para o registrador padrão (0x2102)
      #configure terminal
      (config)#config-register 0x2102

7)Reiniciar o equipamento
	(config)#exit
	#reload
Responder "YES" para as perguntas!
```

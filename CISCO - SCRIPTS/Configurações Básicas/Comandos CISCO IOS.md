# Comandos cisco

### CONFIGURAÇÕES INICIAIS 

#### ENTRA EM MODO EXEC PRIVILEGIADO 
```
>enable
```

#### TELA DE CONFIGURAÇÃO DO EQUIPAMENTO 
```
#configure terminal
```

#### MOSTRAR AS CONFIGURAÇÕES QUE ESTÃO SALVAS NO EQUIPAMENTO
```
#show startup-config
```

#### VER O RESUMO DAS INTERFACES 
```
#show ip interface brief
```

#### TROCAR O NOME DO EQUIPAMENTO
```
(config)#hostname <nome>
```

#### CONFIGURAR UM BANNER 
```
(config)#banner motd "<texto>"
```

#### DESTRAVAR O TERMINAL 
```
Ctrl+Shift+6
```

#### CONFIGURAR SENHA DA CONSOLE
```
(config)#line console 0
(config-line)#password <senha>
(config-line)#login
```

#### CONFIGURAR SENHA 
```
(config)#enable secret <senha>
```

#### VERIFICAR AS CONFIGURAÇÕES NO EQUIPAMENTO
```
#show running-config
```

#### ATIVAR O SERVIÇO DE CRIPTOGRAFIA 
```
(config)#service password-encryption
```

#### IOS DESFAZER CONFIGURAÇÃO NO IOS
```
Colocar "no" na frente do comando
```

#### DESATIVAR UMA INTERFACE
```
(config)#interface <nome>
(config-if)#shutdown
```
 
#### DESATIVAR VÁRIAS INTERFACES DE UMA VEZ 
```
(config)#interface range <intervalo>
(config-if-range)#shutdown
```

#### VER RESUMO DAS INTERFACES 
```
#show ip interface brief
```

#### SALVAR AS CONFIGURAÇÕES 
```
#wr
```

#### RESETAR EQUIPAMENTO 
```
#write erase
```

#### COLOCAR IP EM UMA INTERFACE 
```
(config)#interface <nome>
(config-if)#ip address <ip> <mascara>
(config-if)#no shutdown
```

#### COLOCAR DESCRIÇÃO EM UMA INTERFACE 
```
(config)#interface <nome>
(config)#description <descricao>
```

#### CONFIGURAR O SSH NAS VTY
```
!Definir o nome do domínio
(config)#ip domain-name <nome-do-domínio>
```

#### GERAR A CHAVE DE CRIPTOGRAFIA 
```
(config)#crypto key generate rsa general-keys modulus <nº-de-bits-da-chave>
```

#### CRIAR USUÁRIO NO DISPOSITIVO 
```
(config)#username <nome-do-usuário> privilege <1-15> secret <senha>
```

#### ATIVAR O SSH NAS LINHAS DE VTY 
```
(config)#line vty 0 15
(config-line)#transport input ssh
(config-line)#login local
```

#### CONFIGURAR A VTY PARA USAR TELNET
```
(config)#line vty 0 15
(config-line)#password <senha>
(config-line)#login
```

#### ATIVAR LOGIN CONSOLE 
```
(config)#line console 0
(config-line)#login local
```

#### VER ARQUIVOS NA MEMÓRIA FLASH
```
#dir flash
```

#### VER ARQUIVOS NA MEMÓRIA NVRAM
```
#dir nvram
```

#### MOSTRAR AS CONFIGURAÇÕES QUE ESTÃO ATIVAS NO EQUIPAMENTO 
```
#show run
```

#### MOSTRAR AS CONFIGURAÇÕES QUE ESTÃO SALVAS NO EQUIPAMENTO
```
#show startup-config
```

#### MOSTRAR RESUMO DAS INTERFACES DO EQUIPAMENTO 
```
#show ip interface brief (IPv4)
#show ipv6 interface brief (IPv6)
```

#### MOSTRAR A TABELA MAC DO SWITCH 
```
#show mac-address-table (IOS 12.2)
#show mac address-table dynamic (IOS 15.0)
```

#### EXIBIR A TABELA DE ROTEAMENTO 
```
#show ip route
```

#### EXIBIR UM RESUMO DAS VLANS PRESENTES NO DISPOSITIVO E AS INTERFACES ATRELADAS NAS VLANS 
```
#show vlan brief
```

#### EXIBIR INFORMAÇÕES SOBRE UMA VLAN ESPECÍFICA 
```
#show vlan id [id-da-vlan] ou show vlan name [nome-da-vlan]
```

#### EXIBIR INFORMAÇÕES RELACIONADAS A VLAN EM UMA INTERFACE ESPECÍFICA
```
#show interface [id-da-interface] switchport
```

#### ACESSO REMOTO
```
C:/ ssh -l [endereço-ip]
```

#### DESATIVAR PAGINAÇÃO (--MORE--)
```	
#terminal length 0
```

#### DESATIVAR AS MENSAGENS DE ERRO NA TELA 
```	
(config)#no logging console
```

### CONFIGURAÇÕES EXCLUSIVAS PARA O ROTEADOR

#### VISUALIZAR TABELA DE ROTEAMENTO 
```
#show ip route
```

#### CONFIGURAR SUBINTERFACE - SEM ROTEADOR 
```
(config)#interface <nome-da-subinterface-com-a-vlan>
(config-subif)#encapsulation dot1q <nº-da-vlan>
(config-subif)#ip address <ip> <máscara>
```

#### ATIVAR ROTEAMENTO IPv6
```
(config)#ipv6 unicast-routing
```
#### INSERIR IPv6 A UMA INTERFACE 
```
(config)#interface <nome-da-interface>
(config-if)#ipv6 address <endereço>/<prefixo>
```

#### ROTA ESTÁTICA 
```
(config)#ip route <id-da-rede-de-destino> <máscara-da-rede> <ip-do-roteador-que conhece-a-rede>
```

### CONFIGURAÇÕES EXCLUSIVAS PARA O SWITCH

#### CRIAR UMA VLAN 
```
(config)#vlan <nº-da-vlan>
(config-vlan)#name <nome-da-vlan>
```

#### ATRELAR UMA INTERFACE A UMA VLAN 
```
(config)#interface <nome-da-interface>
(config-if)#switchport mode access
(config-if)#switchport access vlan 10
```

#### VERIFICAR AS CONFIGURAÇÕES DA VLAN
```
#show vlan brief
```

#### CONFIGURAR UMA INTERFACE PARA MODO TRUNK 
```
(config)#interface <nome-da-interface>
(config-if)#switchport mode trunk
```

#### CONFFIGURAR VLAN NATIVA NA INTERFACE TRUNK 
```	
(config)#interface <nome-da-interface>
(config-if)#switchport trunk native vlan <nº-da-vlan-nativa>
```

#### LIBERAR AS VLANS NA INTERFACE TRUNK 
```
(config)#interface <nome-da-interface>
(config-if)#switchport trunk allowed vlan <lista de vlans separadas por VÍRGULAS>
```
       
#### CONFIGURAR IP - SEM SWITCH
```
(config)#interface vlan 90
(config-if)#ip address <endereço> <máscara>
```


### RESETAR O ROUTER E O SWITCH

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

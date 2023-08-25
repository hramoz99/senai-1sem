# Legacy

#### INTERFACE DO DEPARTAMENTO - ADM 
```
int g0/0
ip add 192.168.0.1 255.255.255.128
description GATEWAY ADM
no shutdown
```

#### INTERFACE DO DEPARTAMENTO - RH
```
int g1/0
ip add 192.168.0.129 255.255.255.224 
description GATEWAY RH
no shutdown
```

#### INTERFACE DO DEPARTAMENTO - FIN 
```
int g2/0
ip add 192.168.0.161 255.255.255.224
description GATEWAY FIN
no shutdown
```

#### INTERFACE DO DEPARTAMENTO - DIR 
```
int g3/0
ip add 192.168.0.193 255.255.255.240
description GATEWAY DIR
no shutdown
```

#### INTERFACE DO DEPARTAMENTO - TI 
```
int g4/0
ip add 192.168.0.209 255.255.255.248
description GATEWAY TI
no shutdown
```

#### SALVAR AS CONFIGURAÇÕES 
```
end
wr
```

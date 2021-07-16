/*
Nome do desenvolvedor: Lucas Cabral
Versão: 0.1
Data de criação: 22/01/2021
Última manutenção: 23/01/2021

Este programa realiza: desenvolvido para efetuar a leitura de uma variável 'temperatura', verificando o valor contido nela, piscando assim
um dos leds.
LED VERDE - Temperatura menor ou igual a 25º
LED AMARELO - Temperatura maior que 25°C E menor ou igual a 70°C
LED VERMELHO - Temperatura maior que 70°C

*/ 

//NÃO ALTERAR------------------------------------------------------------------------------------------------
float temperatura; //Variável que vai amarmazenar a informações sobre a temperatura do sensor
int pinoAnalogico0 = 0;
//NÃO ALTERAR------------------------------------------------------------------------------------------------

//Declarar as váriaveis definindo assim seus respectivos pinos
int ledverde=2;
int ledamarelo=3;
int ledvermelho=4;
int chave=13;

void setup() {
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  Serial.begin(9600); //Inicia o monitor Serial
  pinMode(A0,INPUT); //Define o pino A0 como entrada
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  
  pinMode(chave, INPUT_PULLUP); // Variável "chave" (Pino 13) como entrada, variando em HIGH (ligado) ou LOW (desligado)
 
  pinMode(ledverde, OUTPUT); // Definir o Pino 2 como Saída
  pinMode(ledamarelo, OUTPUT); // Definir o Pino 3 como Saída
  pinMode(ledvermelho, OUTPUT); // Definir o Pino 4 como Saída
}

void loop() {
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  temperatura = ((analogRead(pinoAnalogico0) * (5.0/1024))-0.5)/0.01; //Executa a leitura da temperatura e armazena na variável 'temperatura'
  
  //Exibe no Monitor Serial a temperatura do Rack
  Serial.print("A temperatura do Rack esta em: "); 
  Serial.print(temperatura);
  Serial.print(char(176));
  Serial.println("C");
  delay(1000); //Aguarde 1 segundo
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  
  int estado = digitalRead(chave); // Verifica qual o estado atual da chave
  
  // Verifica se o estado da chave está em HIGH
  if (estado == HIGH){

    // Verifica se a temperatura é menor ou igual à 25°C, piscando assim o "ledverde" em um intervalo de 0.5seg
    if(temperatura<=25)
    {
      digitalWrite(ledverde, HIGH);
      delay(500);
      digitalWrite(ledverde, LOW);
      delay(500);
    }
    
    // Verifica se a temperatura é maior que 25°C E menor ou igual a 70°C, piscando assim o "ledamarelo" em um intervalo de 0.5seg
    if(temperatura>25 && temperatura<=70)
    {
      digitalWrite(ledamarelo, HIGH);
      delay(500);
      digitalWrite(ledamarelo, LOW);
      delay(500);

    }

    // Verifica se a temperatura é maior que 70°C, piscando assim o "ledvermelho" em um intervalo de 0.5seg
    if(temperatura>70)
    {
      digitalWrite(ledvermelho, HIGH);
      delay(500);
      digitalWrite(ledvermelho, LOW);
      delay(500);
    }
    
  
  }
    

}
/*
Nome do desenvolvedor: Lucas Cabral
Versão: 0.1
Data de criação: 19/01/2021
Última manutenção: 19/01/2021

Este programa realiza: desenvolvido para efetuar a leitura de uma variável 'temperatura', verificando o valor contido nela, piscando assim
um dos leds.
LED VERDE - Temperatura menor ou igual a 25º
LED AMARELO - Temperatura maior que 25°C E menor ou igual a 70°C
LED VERMELHO - Temperatura maior que 70°C

*/ 

float temperatura;

void setup() 
{
    pinMode(2, OUTPUT); // Definir o Pino 2 como Saída
    pinMode(3, OUTPUT); // Definir o Pino 3 como Saída
    pinMode(4, OUTPUT); // Definir o Pino 4 como Saída

    Serial.begin(9600); // Inicia o Monitor de Serial
}

void loop() 
{
  // Defina os valores para as variáveis.
  temperatura = 71;
  
  // Exibe no Monitor Serial o valor para temperatura 
  Serial.print("A temperatura encontrada foi de: ");
  delay(1000);
  Serial.print(temperatura);
  Serial.print(" graus Celsius");
  delay(1000);
  Serial.println(" ");
  
  // Verifica se a temperatura está abaixo de 25°C
  if (temperatura <=25) {
  Serial.print("A temperatura e considerada ideal!");
  Serial.println(" ");
  Serial.println(" ");
  // Pisca o LED Verde com um intervalo de 0,5 segundos
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
  // Verifica se a temperatura está entre 25°C e 70°C
  if (temperatura >25 && temperatura <=70) {
  Serial.print("A temperatura e considerada um pouco acima do ideal!");
  Serial.println(" ");
  Serial.println(" ");
  // Pisca o LED Amarelo com um intervalo de 0,5 segundos
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  delay(500); 
}
  // Verifica se a temperatura está acima de 70°C
  if (temperatura >70) {
  Serial.print("A temperatura e considerada muito acima do ideal!");
  Serial.println(" ");
  Serial.println(" ");
  // Pisca o LED Vermelho com um intervalo de 0,5 segundos  
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(500); 
}
  delay(1000);
}
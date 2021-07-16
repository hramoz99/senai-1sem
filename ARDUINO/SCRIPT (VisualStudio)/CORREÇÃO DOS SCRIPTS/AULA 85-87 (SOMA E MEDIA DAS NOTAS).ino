/*

Data de criação: 20/01/2021
Última manutenção: 20/01/2021

Este programa realiza: efetua o cálculo da média de duas notas. É validado se o aluno está Aprovado (caso a nota seja maior ou igual 5) 
ou se está Reprovado (caso a nota seja menor que 5). Se o aluno for Aprovado, um LED VERDE irá piscar, exibindo uma mensagem no Monitor
Serial ("Você foi aprovado!"). Caso o aluno seja Reprovado, um LED VERMELHO irá piscar, exibindo uma mensagem no Monitor Serial
("Você foi reprovado!"). 
Obs: Nota <5 e >=7 irá piscar um LED AMARELO, na qual o aluno ficará de recuperação.

*/


float n1,n2,soma,media; //Declara as variáveis utilizadas no programa

void setup(){
	
	pinMode(2, OUTPUT); //Define o Pino 2 como saída [LED VERMELHO]
	pinMode(3, OUTPUT); //Define o Pino 3 como saída [LED VERDE]
    pinMode(4, OUTPUT); //Define o Pino 4 como saída [LED AMARELO]
  
  Serial.begin(9600); //Inicia o Monitor Serial

}

void loop(){       
  
  //Define a Nota1 e a Nota2 do Aluno
  n1 = 6;
  n2 = 6;

  //Realiza a soma das notas e o cálculo de Média
	soma = n1+n2;
	media = soma/2;
  
  //Exibe a Soma e a Média das Notas
  Serial.println(" ");
  Serial.print("A soma das notas e: ");
  Serial.println(soma);
  Serial.print("A media das notas e: ");
  Serial.println(media);
  
  
  //Verifica se a nota é maior ou igual a 5, caso seja verdadeiro o LED VERDE deve ser ligado, se for falso o LED VERMELHO deve ser ligado
  if (media>7) {
    Serial.println("Voce foi aprovado!");
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);

  } 
  if (media>=5 & media<7) {
    Serial.println("Voce esta de recuperacao!");
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    delay(500);    
  
  }
  if (media<5) {
    Serial.println("Voce foi reprovado!");
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
  }
   
}

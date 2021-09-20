SOMA DA MÉDIA

Cálculo da médio
Nota maior que 5 = Mensagem "Você foi aprovado" (LED_Verde_Pisca) 

Nota menor que 5 = Mensagem "Você foi reprovado" (LED_ Vermelho_Pisca)

Obs: Nota entre 5 e 7, o aluno fica de recuperação (LED_Amarelo).


 float n1,n2,soma,media; //Declara as variáveis utilizadas no programa

 void setup(){
    pinMode(2, OUTPUT); //Definir o Pino 2 como saída [LED VERMELHO]

    pinMode(3, OUTPUT); //Definir o Pino 3 como saída [LED VERDE]

    pinMode(4, OUTPUT); //Definir o Pino 4 como saída [LED AMARELO]
  
  Serial.begin(9600); //Iniciar o Monitor Serial

}

 void loop(){       
  
//Definir a Nota1 e a Nota2 do Aluno
  n1 = 6;

  n2 = 6;

//Realizar a soma das notas e o cálculo de Média
    soma = n1+n2;

    media = soma/2;
  
//Exibir a Soma e a Média das Notas
  Serial.println(" ");

  Serial.print("A soma das notas e: ");

  Serial.println(soma);

  Serial.print("A media das notas e: ");

  Serial.println(media);
  
  
//Verificar se a nota é maior ou igual a 5, caso seja verdadeiro o LED VERDE deve ser ligado, se for falso o LED VERMELHO deve ser ligado
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
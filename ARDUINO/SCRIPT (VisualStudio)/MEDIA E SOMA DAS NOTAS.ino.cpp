/*

Nome do desenvolvedor: Lucas Cabral
Versão: 0.1
Data de criação: 20/01/2021
Última manutenção: 20/01/2021

Este programa realiza: efetua o cálculo da média de duas notas. É validado se o aluno está Aprovado (caso a nota seja maior ou igual 5) 
ou se está Reprovado (caso a nota seja menor que 5). Se o aluno for Aprovado, um LED VERDE irá piscar, exibindo uma mensagem no Monitor
Serial ("Você foi aprovado!"). Caso o aluno seja Reprovado, um LED VERMELHO irá piscar, exibindo uma mensagem no Monitor Serial
("Você foi reprovado!").

*/

float n1, n2, soma, media; // Variáveis do programa

void setup () {

    Serial.begin(9600); // Inicia o Monitor Serial
    pinMode(2, OUTPUT); // Definir o Pino 2 como Saída
    pinMode(3, OUTPUT); // Definir o Pino 3 como Saída
}

void loop () {

    // Define o valor para a variável n1 (primeira nota) e a exibe no Monitor Serial
    n1 = 8,5;
    Serial.print("- Primeira nota: ");
    delay(1000);
    Serial.print(n1);
    delay(1000);
    Serial.println(" ");

    // Define o valor para a variável n2 (segunda nota) e a exibe no Monitor Serial
    n2 = 3,0;
    Serial.print("- Segunda nota: ");
    delay(1000);
    Serial.print(n2);
    delay(1000);   
    Serial.println(" ");

    // Executa a soma das notas e a exibe no Monitor Serial
    soma = n1 + n2;
    Serial.print("- Soma das notas: ");
    delay(1000);
    Serial.print(soma);
    delay(1000);
    Serial.println(" ");

    // Executa a média das notas e a exibe no Monitor Serial
    media = soma/2;
    Serial.print("- Media entre as notas: ");
    delay(1000);
    Serial.print(media);
    delay(1000);
    Serial.println(" ");
    Serial.println(" ");

    // Verifica se a nota foi inferior a 5 
    if (media<=5 ) {
    Serial.print("Voce foi reprovado!"); // Mensagem exibida no Monitor Serial
    Serial.println(" ");
    Serial.println(" ");
    
    // Pisca o led em um intervalo de 0.5seg
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
}
    // Caso a nota seja maior que 5 
    else {
    Serial.print("Voce foi aprovado!"); // Mensagem exibida no Monitor Serial
    Serial.println(" "); 
    Serial.println(" ");

    // Pisca o led em um intervalo de 0.5seg
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
}
    delay(3000);    
}

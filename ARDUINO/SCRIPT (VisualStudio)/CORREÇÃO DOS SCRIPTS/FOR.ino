int pedverde = 9;
int pedvermelho = 8;
int carroverde = 12;
int carroamarelo = 11;
int carrovermelho = 10;

void setup()
{
    pinMode(pedverde, OUTPUT);
    pinMode(pedvermelho, OUTPUT);
    pinMode(carroverde, OUTPUT);
    pinMode(carroamarelo, OUTPUT);
    pinMode(carrovermelho, OUTPUT);

    digitalWrite(carroverde, HIGH);
    digitalWrite(carroamarelo, LOW);
    digitalWrite(carrovermelho, LOW);

    digitalWrite(pedverde, LOW);
    digitalWrite(pedvermelho, HIGH);   
}

void loop()
{
    //Farol vermelho
    digitalWrite(carroverde, HIGH);
    digitalWrite(pedvermelho, HIGH);
    delay(5000);

    //Farol amarelo
    digitalWrite(carroverde, LOW);
    digitalWrite(carroamarelo, HIGH);
    delay(3000);

    //Farol verde
    digitalWrite(carroamarelo, LOW);
    digitalWrite(carrovermelho, HIGH);
    digitalWrite(pedvermelho, LOW);
    digitalWrite(pedverde, HIGH);
    delay(5000);

    digitalWrite(pedverde, LOW);

    for(int x=0; x<0; x++);
    {
        digitalWrite(pedvermelho,HIGH);
        delay(350);
        digitalWrite(pedvermelho,LOW);
        delay(350);
    }
    digitalWrite(carrovermelho,LOW);


}
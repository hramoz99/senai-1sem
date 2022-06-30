CARRO DE CONTROLE REMOTO 

//Variáveis Globais*******************************
//Portas usados para o controle do Driver de Motor
char DIR_Latch  = 12;                           //
char DIR_SER    = 8;                            //
char DIR_CLK    = 4;                            //
                                                //
char PWM_M1     =  11;                          //
char PWM_M2     =  3;                           //
char PWM_M3     =  5;                           //
char PWM_M4     =  6;                           //
//------------------------------------------------

//Porta usada para o Sensor-----------------------
char sensor     = 9;                            //
//------------------------------------------------

//Variáveis de Estado*****************************
char estado     = 0;                            //
char estado_mov = 0;                            //
//------------------------------------------------

//Variáveis de Temporização***********************
unsigned long  tempo_arma = 0;                  //
unsigned long  tempo_mov = 0;                   //
//------------------------------------------------

int valor_b = 0;

//Variáveis de recebimento de dados serial********
int data_by_serial = 0;                         //
//------------------------------------------------



//Função para acionamento individual de motor***************
//Valor M: Especifica o motor, 1 = motor 1                //
//2 = motor 2, 3 = motor 3 e 4 = motor 4                  //
//Valor S: Especifica o sentido de rotação, por ser       //
//1 ou 2                                                  //
//Valor M_P: Especifica a potência do motor, seu          //
//valor pode ser de 0 (potência mínima) até 255 (         //
//potência máxima                                         //
void aciona_motor_b(int M, int S, int M_P){               //
  char i = 0;                                             //
  int valor_b_temp = 0;                                   //
                                                          //
  if (M == 1){                                            //
    analogWrite(PWM_M1, M_P);                             //
    valor_b = valor_b & 0b11110011;                       //
    if (S == 1){                                          //
      valor_b = valor_b | 0b00000100;}                    //
          else{                                           //
            if (S == 2){                                  //
            valor_b = valor_b | 0b00001000;}}}            //
                                                          //
  if (M == 2){                                            //
    analogWrite(PWM_M2, M_P);                             //
    valor_b = valor_b & 0b11101101;                       //
    if (S == 1){                                          //
      valor_b = valor_b | 0b00000010;}                    //
          else{                                           //
            if (S == 2){                                  //
            valor_b = valor_b | 0b00010000;}}}            //
                                                          //
  if (M == 3){                                            //
    analogWrite(PWM_M3, M_P);                             //
    valor_b = valor_b & 0b10111110;                       //
    if (S == 1){                                          //
      valor_b = valor_b | 0b00000001;}                    //
          else{                                           //
            if (S == 2){                                  //
            valor_b = valor_b | 0b01000000;}}}            //
                                                          // 
  if (M == 4){                                            //
    analogWrite(PWM_M4, M_P);                             //
    valor_b = valor_b & 0b01011111;                       //
    if (S == 1){                                          //
      valor_b = valor_b | 0b00100000;}                    //
          else{                                           //
            if (S == 2){                                  //
            valor_b = valor_b | 0b10000000;}}}            //
                                                          //
  valor_b_temp = valor_b;                                 //         
  for (i = 0; i <= 7; i++){                               //
    analogWrite(DIR_SER, LOW);                            //
    if ((valor_b_temp & 0b10000000) == 128){              //
      digitalWrite(DIR_SER, HIGH);}                       //
      delay(1);                                           //
      digitalWrite(DIR_CLK, HIGH);                        //
      delay(1);                                           //
      digitalWrite(DIR_CLK, LOW);                         //
      valor_b_temp = valor_b_temp * 2;}                   //
                                                          //
  digitalWrite(DIR_Latch, HIGH);                          //
  delay(1);                                               //
  digitalWrite(DIR_Latch, LOW);}                          //
//----------------------------------------------------------

//Função para tratamento de dado recebido pelo bluetooth**********
void Trata_serial(void){                                        //
  estado_mov = 1;  //Sinaliza que um movimento foi ordenado     //
  
  Serial.println(data_by_serial);
                                                                //
  if (data_by_serial == 'w'){  //Se o dado recebido é w         //
    aciona_motor_b(3, 1, 255); //Aciona motor 3 para direita    //
    aciona_motor_b(4, 1, 255);}//Aciona motor 4 para direita    //
                                                                //
  if (data_by_serial == 's'){  //Se o dado recebido é w         //
    aciona_motor_b(3, 2, 255); //Aciona motor 3 para esquerda   //
    aciona_motor_b(4, 2, 255);}//Aciona motor 4 para esquerda   //
                                                                //
  if (data_by_serial == 'a'){                                   //
    aciona_motor_b(3, 2, 255);                                  //
    aciona_motor_b(4, 1, 255);}                                 //
                                                                //
  if (data_by_serial == 'd'){                                   //
    aciona_motor_b(3, 1, 255);                                  //
    aciona_motor_b(4, 2, 255);}                                 //
                                                                //
  if (data_by_serial == 'q'){                                   //
    aciona_motor_b(3, 0, 0); //Para motor 3                     //
    aciona_motor_b(4, 0, 0);}//Para motor 4                     //
                                                                //
  tempo_mov = millis();}                                        //
//----------------------------------------------------------------

//Função para configuração inicial do mcrocontrolador*************
void setup(){
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  
  pinMode(PWM_M1, OUTPUT);  //Define a porta 11, pois, PWM_M1 = 11, como saída
  pinMode(PWM_M2, OUTPUT);
  pinMode(PWM_M3, OUTPUT);
  pinMode(PWM_M4, OUTPUT);
  
  analogWrite(PWM_M1, 0);  //Escreve "0" na saída PWM_M1, esta saída define a potência aplicada ao motor 1, logo motor inicializa parado
  analogWrite(PWM_M2, 0);
  analogWrite(PWM_M3, 0);
  analogWrite(PWM_M4, 0);
  
  pinMode(DIR_SER, OUTPUT);
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DIR_Latch, OUTPUT);
  
  digitalWrite(DIR_SER, LOW);    //Inicializa a saída DIR_SER, porta "8" do arduino, pois, DIR_SER = 8 em 0 (também dito nível lógico baixo ou 0)
  digitalWrite(DIR_CLK, LOW);
  digitalWrite(DIR_Latch, LOW);
  
  pinMode(sensor, INPUT_PULLUP);  //Define a porta 9, pois, sensor = 9, como entrada
  
  Serial.begin(9600);  //Configura a comunicação serial com o módulo Bluetooth
  Serial.println("TESTE");
}
//----------------------------------------------------------------

//Função principal do programa*************
void loop (){

//Estre trecho verifica se algum dado foi recebido pela serial
  if( Serial.available()){    //Se algum dado foi recebido pela serial
    data_by_serial = Serial.read();  //Salva o dado na veriável data_by_serial
    Serial.write(data_by_serial);  //Devolve o dado recebido
    if ((data_by_serial == 'a') || (data_by_serial == 'd') || (data_by_serial == 'w') || (data_by_serial == 's') || (data_by_serial == 'q')){  //Se o dado recebido corresponde à: a, d, w, s ou q
      Trata_serial ();}}  //Aciona os motores para executar o movimento associado ao dado 

//Este trecho interrope o acionamento dos motores de movimentação após 400 ms sem recebimento de um novo dado pelo bluetooth
  if ((estado_mov == 1) && ((millis() - tempo_mov) >= 400)){  //Se os motores estão se movimentando devido à um dado recebido (estado_mov == 1) e se este movimento já esta acontecendo a mais de 400 milissegondos
     aciona_motor_b(3, 0, 0);//Para motor 3
     aciona_motor_b(4, 0, 0);//Para motor 4
     estado_mov = 0;}  //Desfaz a sinalização que indica que um movimento foi ordenado

//-------------------------------------------------------------------
//Inicia acionamento da arma
  if ((digitalRead(sensor) == 0 )&& (estado == 0)){  //Se o sensor da arma foi aciondo (digitalRead(sensor) == 0) e se a arma não estava acionado nem sendo acionada (estado == 1) nem esperando para ser desacionada (estado == 2) nem sendo desacionada (estado == 3)
    Serial.write('A');
    estado = 1;  //Indica que a arma está sendo acionada (estado == 1);
    tempo_arma = millis();  //Reseta o tempo de acionamento da arma
    aciona_motor_b(1, 1, 225);  //Aciona motor 1 para direita
    aciona_motor_b(2, 1, 225);} //Aciona motor 2 para direita
    
//Finaliza acionamento da arma
  if ((estado == 1) && ((millis() - tempo_arma) >= 100)){  //Se a arma está sendo acionada (estado == 1) e o tempo de acionamento é maior ou igual a 900ms
    Serial.write('B');
    estado = 2;  //Indica que a arma está sendo desacionada (estado == 2);
    tempo_arma = millis();  //Reseta o tempo de acionamento da arma
    aciona_motor_b(1, 0, 0);  //Para motor 1
    aciona_motor_b(2, 0, 0);} //Para motor 2

//Inicia recolhimento da arma
  if ((estado == 2) && ((millis() - tempo_arma) >= 12500)){  //Se a arma está esperando para ser desacionada (estado == 2) e o tempo de acionamento é maior ou igual a 14000ms
    Serial.write('C');
    estado = 3;  //Indica que a arma está sendo desacionada (estado == 3);
    tempo_arma = millis();  //Reseta o tempo de acionamento da arma
    aciona_motor_b(1, 2, 200);  //Aciona motor 1 para esquerda
    aciona_motor_b(2, 2, 200);}  //Aciona motor 2 para esquerda
    
//Finaliza recolhimento da arma
  if ((estado == 3) && ((millis() - tempo_arma) >= 150)){  //Se a arma está sendo desacionada (estado == 3) e o tempo de desacionamento é maior ou igual a 900ms
    Serial.write('D');
    estado = 0;  //Indica que a arma parada e pronta para ser acionada novamente (estado == 0);
    aciona_motor_b(1, 0, 0);  //Para motor 1
    aciona_motor_b(2, 0, 0);} //Para motor 2
//-------------------------------------------------------------------
  
  
}
  

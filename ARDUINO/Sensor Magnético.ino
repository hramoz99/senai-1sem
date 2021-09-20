SENSOR MAGNÉTICO
  
  int pino2 = 2; 
  bool estado_sensor;

 void setup() {
  pinMode(pino2, INPUT_PULLUP);

  Serial.begin(9600);

}

 void loop() {
  estado_sensor = digitalRead(pino2);

  if (estado_sensor == HIGH) {
    Serial.println("RACK ABERTO");

    delay(1000);
  }
  else {
    Serial.println ("RACK FECHADO");

    delay (1000);
  }
  

}
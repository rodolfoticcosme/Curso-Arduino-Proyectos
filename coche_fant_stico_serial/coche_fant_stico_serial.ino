int pinArray[] = {2, 3, 4, 5, 6};
int count = 0;
int timer = 100;

void setup() {
  // we make all the declarations at once
  Serial.begin(9600);
  for (count = 0; count < 5; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  timer = lee_serial();
  Serial.println(timer);
  for (count = 0; count < 5; count++) {
    timer = lee_serial();
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  for (count = 4; count >= 0; count--) {
    timer = lee_serial();
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
}

int lee_serial() {

  if (Serial.available() > 0) {
    Serial.println("leo...");
    String leido = "";
    do {
      char caracter_leido;
      delay(5);
      caracter_leido = Serial.read();
      leido += caracter_leido;
    }  while (Serial.available() > 0);

    return (leido.toInt());

    Serial.println("He leido la cadena: \"" + leido + "\"");
  }
  else
    return timer;
}

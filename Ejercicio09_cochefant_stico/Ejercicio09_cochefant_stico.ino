/* Knight Rider 2
   --------------
   Reducing the amount of code using for(;;).
   (cleft) 2005 K3, Malmo University
   @author: David Cuartielles
   @hardware: David Cuartielles, Aaron Hallborg
   @modified by: aprendiendoarduino
*/

int pinArray[] = {2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 100;
String leido = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Introduce una cadena de texto: ");
  // we make all the declarations at once
  for (count = 0; count < 6; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  //timer = analogRead(A0);  //El valor leido por analog read es el temporizador
  
  int timer = leido.toInt();
  //coche_fantastico();
  for (count = 0; count < 6; count++) {
    //timer = analogRead(A0);
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  for (count = 5; count >= 0; count--) {
    timer = analogRead(A0);
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  
  if (Serial.available() > 0) {
    leido = ""; //vacio lo leido
    do {
      char caracter_leido;
      delay(5);
      caracter_leido = Serial.read();
      leido += caracter_leido;
    }  while (Serial.available() > 0);

    Serial.println("He leido la cadena: \"" + leido + "\"");
    Serial.println(timer);
  //cantidad_luz();
}}



/*void cantidad_luz()
{
  int sensibilidad=0;
  for (magnitud=0; magnitud
  
  }*/
/*void coche_fantastico()
{
  for (count = 0; count < 6; count++) {
    timer = analogRead(A0);
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  for (count = 5; count >= 0; count--) {
    timer = analogRead(A0);
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
}*/

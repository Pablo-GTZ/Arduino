int A,B,C,S;

void setup() {
  pinMode(5, OUTPUT); //A
  pinMode(6, OUTPUT); //B
  pinMode(7, OUTPUT); //C
  pinMode(9, INPUT);  //S
  Serial.begin(9600);
}

void loop() {
  Serial.println("A B C S");
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7); 
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  A = digitalRead(5);
  B = digitalRead(6);
  C = digitalRead(7);
  S = digitalRead(9);
  Serial.print(A);
  Serial.print(" ");
  Serial.print(B);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(S);
  Serial.println(" "); //Valor de la salida
  delay(2000);

  Serial.println(""); //ultimo

}

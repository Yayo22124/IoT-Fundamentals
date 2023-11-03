long valor;
int leduno = 7;
int leddos = 6;
int ledtres = 5;
int pwmValue = map(valor, 0, 1023, 0, 255);
void setup() {
  Serial.begin(9600);
  Serial.println("Inicio de sketch - valores potenciometro");
}
void loop() {
  valor = analogRead(A0);
  delay(1);

  if (valor > 150) {
    digitalWrite(leduno, HIGH);
  } else {
    digitalWrite(leduno, LOW);
  }
  if (valor > 300) {
    digitalWrite(leddos, HIGH);
  } else {
    digitalWrite(leddos, LOW);
  }
  if (valor > 450) {
    digitalWrite(ledtres, HIGH);
  } else {
    digitalWrite(ledtres, LOW);
  }

  analogWrite(leduno, pwmValue);
  analogWrite(leddos, pwmValue);
  analogWrite(ledtres, pwmValue);
}
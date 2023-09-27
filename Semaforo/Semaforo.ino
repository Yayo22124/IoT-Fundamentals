const int ledGreen = 9;
const int ledYellow = 10;
const int ledRed = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  //  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledGreen, HIGH);
  delay(5000);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
  delay(5000);
  digitalWrite(ledRed, LOW);
}

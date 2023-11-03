const int ldrPin = A0;   // Pin analógico donde está conectado el LDR
const int trigPin = 7;   // Pin Trig del sensor HC-SR04
const int echoPin = 6;   // Pin Echo del sensor HC-SR04
const int ledPin = 9;

int ldrValue;            // Variable para almacenar la lectura del LDR

void setup() {
  Serial.begin(9600);   // Inicia la comunicación serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin); // Lee el valor del LDR (mayor valor indica menos luz)

  // Si la lectura del LDR es baja (indicando menos luz), algo está cerca
  if (ldrValue < 10) {
    Serial.println("¡Algo está cerca según el LDR!");
    digitalWrite(ledPin, HIGH);  // Enciende el LED en el pin 13
  } else {
    Serial.println("No hay nada cerca según el LDR.");
    digitalWrite(ledPin, LOW);   // Apaga el LED en el pin 13
  }

}

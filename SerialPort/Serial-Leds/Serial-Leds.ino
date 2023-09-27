
const int ledVerde = 9;
const int ledAmarillo = 10;
const int ledRojo = 11;
char valor;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  Serial.begin(9600); // Iniciamos conexión al monitor serial por el puerto 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) { // Evaluar sí el monitor serial está activo
    valor = Serial.read(); // Establecemos que valor es igual a la lectura 
    Serial.println(valor);

    if (valor == 'A') { // Encender led A-marillo
      digitalWrite(ledAmarillo, HIGH);
    } else if (valor == 'a') {
      digitalWrite(ledAmarillo, LOW);
    }
    
    if (valor == 'R') { // Encender led R-ojo
      digitalWrite(ledRojo, HIGH);
    } else if (valor == 'r') {
      digitalWrite(ledRojo, LOW);
    }

    if (valor == 'V') { Encender led V-erde
      digitalWrite(ledVerde, HIGH);
    } else if (valor == 'v') {
      digitalWrite(ledVerde, LOW);
    }
  }
}

const int buttonPin = 2;  // Pin donde está conectado el botón
const int segmentPins[7] = {3, 4, 5, 6, 7, 8, 9};  // Pines de control de segmento

int buttonState = 0;  // Variable para almacenar el estado del botón
int count = 0;  // Variable para almacenar el número actual a mostrar

// Definir los segmentos necesarios para mostrar cada número (0-9)
const byte numbers[10] = {
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110   // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);  // Configurar pines de segmento como salida
  }
  pinMode(buttonPin, INPUT);  // Configurar pin del botón como entrada
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Leer el estado del botón

  if (buttonState == HIGH) {
    // Incrementar el contador y mostrar el número en el display
    count = (count + 1) % 10;
    displayNumber(count);
    delay(300);  // Esperar para evitar lecturas múltiples por rebotes
  }
}

void displayNumber(int num) {
  // Mostrar el número en el display de 7 segmentos
  for (int i = 0; i < 7; i++) {
    // Encender o apagar el segmento según la configuración del número
    if (bitRead(numbers[num], i) == 1) {
      digitalWrite(segmentPins[i], HIGH);
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }
}

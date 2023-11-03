/* 
  ################ Carrito Dos Motores DC ################
  * Este código de Arduino está pensado para funcionar con 
    las placas compatibles con el IDE de Arduino, el 
    principal objetivo es:

    - Lograr mover un carrito de dos motores DC por medio 
      de un controlador L495D.

    -Sígueme en:
        ~GitHub: https://github.com/Yayo44544
        ~GitLab: https://gitlab.com/Yayo44544
  #########################################################
*/

/*
  ----- Conexión de Pines:
    *D5 - IN5 *D5 - IN5
    *D4 - IN4 *D4 - IN4
*/
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1); // RX, TX
int motorSpeed = 255; // Velocidad del motor (0 a 255)

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  bluetoothSerial.begin(9600); // Iniciar la comunicación con el módulo Bluetooth
}

char command;

void loop() {
  // Control mediante Bluetooth
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    switch (command) {
      case 'F':
        avanza();
        break;
      case 'B':
        retrocede();
        break;
      case 'L':
        giraIzquierda();
        break;
      case 'R':
        giraDerecha();
        break;
      case 'D':
        detener();
        break;
    }
  }
}

void giraDerecha() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void avanza() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}

void giraIzquierda() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
}

void retrocede() {
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
}

void detener() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}


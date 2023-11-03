#include <IRremote.hpp>

/* 
  ################ Carrito Dos Motores DC ################
  * Este código de Arduino está pensado para funcionar con 
    las placas compatibles con el IDE de Arduino, el 
    principal objetivo es:

    - Lograr mover un carrito de dos motores DC por medio 
      de un controlador L293D.

    -Sígueme en:
        ~GitHub: https://github.com/Yayo22124
        ~GitLab: https://gitlab.com/Yayo22124
  #########################################################
*/

/*
  ----- Conexión de Pines:
    *D1 - IN1 *D3 - IN3
    *D2 - IN2 *D4 - IN4
*/

#define IR_RECEIVE_PIN 10

int motorSpeed = 255;  // Velocidad del motor (0 a 255)

void setup() {
  // Inicializar el IR Receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // Inicializar los motores apagados
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  if (IrReceiver.decode()) {
    value=IrReceiver.decodedIRData.decodedRawData,HEX;
  }

  if (value=="4261527296") {

  }
}

void giraDerecha() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void avanza() {
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
}

void giraIzquierda() {
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
}

void retrocede() {
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
}

void detener() {
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

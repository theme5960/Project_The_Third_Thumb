#include <Servo.h>

Servo servo1;
Servo servo2;

// Pinos
const int PRESSAO_ESQ = A0;
const int PRESSAO_DIR = A1;

const int SERVO1_PIN = 9;
const int SERVO2_PIN = 10;

// Posição inicial
const int POSICAO_INICIAL = 90;

void setup() {
  Serial.begin(9600);

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  servo1.write(POSICAO_INICIAL);
  servo2.write(POSICAO_INICIAL);
}

void loop() {
  // Ler as placas de pressão
  int esquerda = analogRead(PRESSAO_ESQ);
  int direita = analogRead(PRESSAO_DIR);

  // Transformar pressão em movimento
  int movimento1 = map(esquerda, 0, 1023, 0, 180);
  int movimento2 = map(direita, 0, 1023, 0, 180);

  // Limitar os servos
  movimento1 = constrain(movimento1, 0, 180);
  movimento2 = constrain(movimento2, 0, 180);

  // Mover os servos
  servo1.write(movimento1);
  servo2.write(movimento2);

  // Mostrar os valores no Monitor Serial
  Serial.print("Pe esquerdo: ");
  Serial.print(esquerda);

  Serial.print(" | Servo 1: ");
  Serial.print(movimento1);

  Serial.print(" || Pe direito: ");
  Serial.print(direita);

  Serial.print(" | Servo 2: ");
  Serial.println(movimento2);

  delay(20);
}

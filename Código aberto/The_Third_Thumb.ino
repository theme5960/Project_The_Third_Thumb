#include <Servo.h>
#include <SoftwareSerial.h>

// ======================================================
// THE THIRD THUMB
// Projeto de Lua
// Arduino Uno
// ======================================================

// -------------------- SENSORES ------------------------

const int SENSOR_PE_ESQUERDO = A0;
const int SENSOR_PE_DIREITO  = A1;

// -------------------- SERVOS --------------------------

const int SERVO_ESQUERDO_PIN = 9;
const int SERVO_DIREITO_PIN  = 10;

Servo servoEsquerdo;
Servo servoDireito;

// -------------------- BLUETOOTH -----------------------
// Arduino RX = D2
// Arduino TX = D3

SoftwareSerial bluetooth(2, 3);

// -------------------- LIMITES DOS SERVOS --------------
// Comece com limites pequenos para testar o mecanismo.

const int SERVO_MIN = 0;
const int SERVO_MAX = 90;

// -------------------- CALIBRAÇÃO ----------------------
// Valores iniciais.
// Ajuste de acordo com os seus sensores.

const int PRESSAO_MIN = 0;
const int PRESSAO_MAX = 1023;

// -------------------- CONTROLE ------------------------

int valorEsquerdo = 0;
int valorDireito = 0;

int anguloEsquerdo = 0;
int anguloDireito = 0;

// ======================================================
// SETUP
// ======================================================

void setup() {

  // Inicializa comunicação USB
  Serial.begin(9600);

  // Inicializa Bluetooth
  bluetooth.begin(9600);

  // Configura sensores
  pinMode(SENSOR_PE_ESQUERDO, INPUT);
  pinMode(SENSOR_PE_DIREITO, INPUT);

  // Conecta os servos
  servoEsquerdo.attach(SERVO_ESQUERDO_PIN);
  servoDireito.attach(SERVO_DIREITO_PIN);

  // Posição inicial
  servoEsquerdo.write(0);
  servoDireito.write(0);

  delay(1000);

  Serial.println("=================================");
  Serial.println("THE THIRD THUMB");
  Serial.println("Projeto de Lua");
  Serial.println("Sistema iniciado!");
  Serial.println("=================================");

  bluetooth.println("THE THIRD THUMB");
  bluetooth.println("Sistema iniciado!");
}

// ======================================================
// LOOP
// ======================================================

void loop() {

  // Lê os sensores
  valorEsquerdo = analogRead(SENSOR_PE_ESQUERDO);
  valorDireito  = analogRead(SENSOR_PE_DIREITO);

  // Converte pressão em ângulo
  anguloEsquerdo = map(
    valorEsquerdo,
    PRESSAO_MIN,
    PRESSAO_MAX,
    SERVO_MIN,
    SERVO_MAX
  );

  anguloDireito = map(
    valorDireito,
    PRESSAO_MIN,
    PRESSAO_MAX,
    SERVO_MIN,
    SERVO_MAX
  );

  // Garante que os servos não ultrapassem os limites
  anguloEsquerdo = constrain(
    anguloEsquerdo,
    SERVO_MIN,
    SERVO_MAX
  );

  anguloDireito = constrain(
    anguloDireito,
    SERVO_MIN,
    SERVO_MAX
  );

  // Move os servos
  servoEsquerdo.write(anguloEsquerdo);
  servoDireito.write(anguloDireito);

  // Envia informações pelo monitor serial
  Serial.print("PE ESQUERDO: ");
  Serial.print(valorEsquerdo);

  Serial.print(" | PE DIREITO: ");
  Serial.print(valorDireito);

  Serial.print(" | SERVO 1: ");
  Serial.print(anguloEsquerdo);

  Serial.print(" | SERVO 2: ");
  Serial.println(anguloDireito);

  // Envia informações pelo Bluetooth
  bluetooth.print("L:");
  bluetooth.print(valorEsquerdo);

  bluetooth.print(" R:");
  bluetooth.print(valorDireito);

  bluetooth.print(" S1:");
  bluetooth.print(anguloEsquerdo);

  bluetooth.print(" S2:");
  bluetooth.println(anguloDireito);

  delay(30);
}

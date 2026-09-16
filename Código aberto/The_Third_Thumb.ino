#include <Servo.h>

// Criação dos objetos para controlar os motores
Servo servo1;
Servo servo2;

// --- CONFIGURAÇÃO DE PINOS ---
const int PRESSAO_ESQ = A0; // Sensor do pé esquerdo (Entrada Analógica)
const int PRESSAO_DIR = A1; // Sensor do pé direito (Entrada Analógica)

const int SERVO1_PIN = 9;   // Motor 1 - Movimento Principal (Pino Digital PWM)
const int SERVO2_PIN = 10;  // Motor 2 - Rotação Lateral (Pino Digital PWM)

// --- CONFIGURAÇÃO DE LIMITES DE SEGURANÇA ---
// Altere os valores MIN e MAX abaixo se precisar que o dedo abra ou feche mais.
// Evite usar 0 e 180 direto para não forçar as linhas de pesca e as peças de PLA.
const int ANGULO_MIN = 30;       // Limite mínimo de rotação do motor
const int ANGULO_MAX = 150;      // Limite máximo de rotação do motor
const int POSICAO_INICIAL = 90;  // Posição centralizada ao ligar o Arduino

void setup() {
  // Inicializa a comunicação com o computador (Monitor Serial)
  Serial.begin(9600);

  // Vincula os motores aos pinos do Arduino
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  // Move os motores para a posição inicial de segurança
  servo1.write(POSICAO_INICIAL);
  servo2.write(POSICAO_INICIAL);
}

void loop() {
  // 1. Lê a pressão das placas dos pés (retorna um valor entre 0 e 1023)
  int esquerda = analogRead(PRESSAO_ESQ);
  int direita = analogRead(PRESSAO_DIR);

  // 2. Converte a pressão do pé em ângulo de movimento para o motor
  int movimento1 = map(esquerda, 0, 1023, ANGULO_MIN, ANGULO_MAX);
  int movimento2 = map(direita, 0, 1023, ANGULO_MIN, ANGULO_MAX);

  // 3. Garante matematicamente que o motor nunca passe dos limites estipulados
  movimento1 = constrain(movimento1, ANGULO_MIN, ANGULO_MAX);
  movimento2 = constrain(movimento2, ANGULO_MIN, ANGULO_MAX);

  // 4. Envia o comando de movimento para os servomotores do pulso
  servo1.write(movimento1);
  servo2.write(movimento2);

  // 5. Exibe os dados no computador para ajudar você na calibração
  Serial.print("Pe esquerdo (Sensor): ");
  Serial.print(esquerda);
  Serial.print(" -> Angulo Servo 1: ");
  Serial.print(movimento1);

  Serial.print("  |  Pe direito (Sensor): ");
  Serial.print(direita);
  Serial.print(" -> Angulo Servo 2: ");
  Serial.println(movimento2);

  // Pequena pausa de 20ms para o motor responder fisicamente e evitar trepidações
  delay(20);
}

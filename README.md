# Third Thumb Portátil

Projeto de um terceiro polegar portátil controlado por sensores de pressão nos pés.

## Materiais

### Eletrônica

- 1x Arduino Uno
- 2x sensores de pressão
- 2x servomotores
- 1x módulo Bluetooth
- Fios jumper
- Fonte de alimentação adequada para os servomotores

### Peças 3D

#### PLA

Imprimir 1 unidade de cada:

```text
caseBase.STL
caseMid.STL
fingerBase.STL
fingerMid.STL
fingerTip.STL
fingerHolster.STL
fingerDualAxisHinge.STL
```

Total: 7 peças em PLA.

#### TPU

Imprimir 1 unidade de cada:

```text
servoWheel.STL
servoWheel2.STL
```

Total: 2 peças em TPU.

## Total de peças

```text
7 peças PLA
2 peças TPU

Total: 9 peças
```

## Montagem

### 1. Estrutura principal

Monte:

```text
caseBase.STL
caseMid.STL
```

### 2. Mecanismo do dedo

Monte:

```text
fingerBase.STL
      ↓
fingerDualAxisHinge.STL
      ↓
fingerMid.STL
      ↓
fingerTip.STL
```

### 3. Suporte

Instale:

```text
fingerHolster.STL
```

### 4. Servomotores

O projeto utiliza 2 servomotores.

Use:

```text
servoWheel.STL
servoWheel2.STL
```

### 5. Nylon

Utilize fios de nylon de pesca para transmitir o movimento dos servomotores para o mecanismo.

```text
Servomotor
    ↓
Roda do servo
    ↓
Nylon de pesca
    ↓
Mecanismo
    ↓
Movimento do dedo
```

O nylon deve ficar firme, mas não excessivamente tensionado.

## Sensores de pressão

O projeto utiliza 2 sensores de pressão.

```text
Sensor esquerdo → A0
Sensor direito  → A1
```

## Arduino Uno

O Arduino Uno é o controlador principal.

```text
Pressão do pé
      ↓
Sensor de pressão
      ↓
Arduino Uno
      ↓
Controle
      ↓
Servomotor
      ↓
Nylon
      ↓
Movimento do dedo
```

## Conexões

| Componente | Arduino |
|---|---|
| Sensor esquerdo | A0 |
| Sensor direito | A1 |
| Servo 1 | D9 |
| Servo 2 | D10 |

## Bluetooth

O módulo Bluetooth permite comunicação sem fio.

Uma configuração possível:

```text
Bluetooth TX → Arduino RX
Bluetooth RX → Arduino TX
Bluetooth GND → Arduino GND
Bluetooth VCC → alimentação adequada
```

A ligação exata depende do módulo Bluetooth utilizado.

## Primeiro teste

Antes de utilizar o dispositivo:

1. Ligue o Arduino.
2. Verifique os sensores.
3. Teste os dois servomotores.
4. Teste o Bluetooth.
5. Verifique as articulações.
6. Instale o nylon.
7. Pressione o sensor esquerdo.
8. Verifique o Servo 1.
9. Pressione o sensor direito.
10. Verifique o Servo 2.

## Calibração

Pode ser necessário ajustar:

- Pressão mínima
- Pressão máxima
- Sensibilidade
- Posição inicial do servo
- Posição final do servo
- Velocidade do servo
- Limites mecânicos

## Segurança

- Teste o mecanismo antes de colocá-lo no corpo.
- Não force as articulações.
- Não deixe o nylon excessivamente tensionado.
- Não bloqueie o movimento dos servos.
- Utilize alimentação adequada.
- Verifique as conexões antes de ligar.
- Desligue a alimentação antes de mexer na parte elétrica.

## Estrutura do repositório

```text
Project_The_Third_Thumb/
│
├── README.md
│
├── Arduino/
│   └── ThirdThumb.ino
│
├── STL/
│   ├── PLA/
│   │   ├── caseBase.STL
│   │   ├── caseMid.STL
│   │   ├── fingerBase.STL
│   │   ├── fingerMid.STL
│   │   ├── fingerTip.STL
│   │   ├── fingerHolster.STL
│   │   └── fingerDualAxisHinge.STL
│   │
│   └── TPU/
│       ├── servoWheel.STL
│       └── servoWheel2.STL
│
└── images/
```

## Lista completa

| Item | Quantidade |
|---|---:|
| Arduino Uno | 1 |
| Sensor de pressão | 2 |
| Servomotor | 2 |
| Módulo Bluetooth | 1 |
| Nylon de pesca | Conforme necessário |
| Peças PLA | 7 |
| Peças TPU | 2 |

## Tecnologias

- Arduino Uno
- Sensores de pressão
- Servomotores
- Bluetooth
- Impressão 3D
- PLA
- TPU
- Nylon de pesca

## Objetivo

O objetivo do Third Thumb Portátil é criar um mecanismo portátil capaz de transformar a pressão detectada pelos pés em movimentos mecânicos controlados.

## Criador

**Third Thumb Portátil**

Criado por **Lua**.

## Status

**Em desenvolvimento.**

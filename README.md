Third Thumb — Projeto de Lua

Um projeto de dedo robótico portátil, controlado por sensores de pressão nos pés e comunicação Bluetooth.

Importante: As peças 3D deste projeto são próprias e foram feitas para este projeto. Este projeto não é uma cópia das peças de outro projeto. O projeto de referência foi usado apenas como inspiração para a ideia e para os materiais mecânicos utilizados.

Sobre o projeto

O projeto utiliza um dedo mecânico portátil com 2 servomotores, controlado por um Arduino Uno.

O movimento é controlado através de 2 sensores de pressão, sendo:

1 sensor de pressão no pé esquerdo

1 sensor de pressão no pé direito

Os comandos dos sensores são enviados para o sistema por Bluetooth, permitindo que o projeto seja utilizado sem ficar preso a um computador.

Portabilidade

O Third Thumb foi projetado para ser portátil.

Os componentes eletrônicos podem ser colocados em uma estrutura compacta e levados junto com o usuário.

O sistema utiliza:

Arduino Uno

Bluetooth

Alimentação portátil adequada

2 sensores de pressão

2 servomotores

Peças 3D

Fios de nylon de pesca

A alimentação portátil permite utilizar o mecanismo sem precisar permanecer conectado a um computador.

MateriaisEletrônica

Arduino Uno

2 servomotores

2 sensores/placas de pressão

1 módulo Bluetooth

Fios para conexão

Fonte de alimentação portátil adequada

Protoboard, se necessário

Materiais mecânicos

Peças impressas em 3D

Fios de nylon de pesca

Velcro

Parafusos e fixadores necessários

Peças 3D

As peças estão divididas entre PLA e TPU.

PLA

caseBase.STL

caseMid.STL

fingerBase.STL

fingerMid.STL

fingerTip.STL

fingerHolster.STL

fingerDualAxisHinge.STL

TPU

servoWheel.STL

servoWheel2.STL

Total

9 peças STL

7 peças em PLA

2 peças em TPU

Estrutura das pastasThirdThumb/ │ ├── README.md │ ├── 3D/ │ ├── PLA/ │ │ ├── caseBase.STL │ │ ├── caseMid.STL │ │ ├── fingerBase.STL │ │ ├── fingerMid.STL │ │ ├── fingerTip.STL │ │ ├── fingerHolster.STL │ │ └── fingerDualAxisHinge.STL │ │ │ └── TPU/ │ ├── servoWheel.STL │ └── servoWheel2.STL │ └── Arduino/ Como montar do zero1. Montagem da eletrônica

Primeiro monte toda a eletrônica antes de instalar as peças no dedo.

Você precisará de:

Arduino Uno

2 sensores de pressão

módulo Bluetooth

2 servomotores

fios

alimentação portátil adequada

2. Sensores de pressão

Instale um sensor em cada pé:

Pé esquerdo → Sensor de pressão 1 Pé direito → Sensor de pressão 2 

Os sensores serão usados para controlar os movimentos do dedo.

3. Bluetooth

O módulo Bluetooth será utilizado para a comunicação do sistema.

A comunicação será:

Sensores ↓ Arduino Uno ↓ Bluetooth ↓ Sistema de controle 4. Alimentação portátil

Para tornar o Third Thumb portátil, utilize uma fonte de alimentação portátil adequada para o Arduino e os servomotores.

A alimentação deve ser capaz de fornecer corrente suficiente para os dois servomotores.

Alimentação portátil ↓ Arduino Uno ↓ 2 servomotores 

O GND da alimentação dos servos deve estar em comum com o GND do Arduino.

5. Servomotores

Instale os dois servomotores no mecanismo.

Servo 1 → movimento 1 Servo 2 → movimento 2 

As rodas utilizadas nos servos são:

servoWheel

servoWheel2

6. Fios de nylon

Utilize fios de nylon de pesca para transmitir o movimento dos servomotores para as articulações do dedo.

Os fios devem ficar firmes, mas não excessivamente tensionados.

7. Montagem das peças

Monte as peças na seguinte ordem:

caseBase

caseMid

Instale os servomotores.

Instale servoWheel.

Instale servoWheel2.

Monte fingerBase.

Monte fingerMid.

Monte fingerTip.

Instale fingerDualAxisHinge.

Instale fingerHolster.

Passe os fios de nylon.

Prenda os fios às partes correspondentes.

8. Instalação dos sensores

Depois de montar o mecanismo, coloque:

Sensor 1 → pé esquerdo Sensor 2 → pé direito 

Os sensores devem ficar em uma posição confortável e firme.

9. Montagem portátil

Organize o Arduino, Bluetooth e a alimentação portátil em uma estrutura que possa ser carregada junto ao mecanismo.

O objetivo é evitar que o projeto precise ficar conectado a um computador durante o uso.

Third Thumb │ ┌─────┴─────┐ │ Eletrônica│ │ portátil │ └─────┬─────┘ │ Bluetooth │ Sensores nos pés 10. Testes

Antes de usar o mecanismo:

Ligue o Arduino.

Teste o sensor esquerdo.

Teste o sensor direito.

Teste o Bluetooth.

Teste o Servo 1.

Teste o Servo 2.

Teste os dois sensores juntos.

Verifique os fios de nylon.

Teste a alimentação portátil.

Teste o movimento do dedo lentamente.

FuncionamentoPé esquerdo Pé direito ↓ ↓ Sensor de pressão Sensor de pressão └─────────────┬─────────────┘ ↓ Arduino Uno ↓ Bluetooth ↓ 2 servomotores ↓ Fios de nylon ↓ Dedo mecânico Segurança

Não aplique força excessiva nos servomotores.

Não deixe os fios de nylon excessivamente tensionados.

Verifique as conexões antes de ligar o sistema.

Não force o mecanismo quando estiver travado.

Faça os primeiros testes lentamente.

Mantenha os componentes eletrônicos protegidos.

Utilize uma alimentação portátil adequada aos componentes.

Problemas comunsO servo não se movimenta

Verifique:

alimentação;

conexão do servo;

Arduino;

comunicação Bluetooth.

O sensor não responde

Verifique:

conexão do sensor;

alimentação;

calibração;

comunicação.

O dedo se movimenta pouco

Verifique:

tensão do fio de nylon;

posição da roda do servo;

articulações;

curso do servomotor.

O dedo trava

Verifique:

alinhamento das peças;

tensão dos fios;

articulações;

posição dos servomotores.

Criador

Lua

Projeto desenvolvido por Lua.


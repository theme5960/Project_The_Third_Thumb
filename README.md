The Third Thumb — Peças, Eletrônica e MontagemSobre o projeto

O The Third Thumb é um projeto de dedo robótico vestível desenvolvido por Luã.

As peças 3D presentes neste repositório são peças próprias deste projeto, desenvolvidas para a montagem do The Third Thumb. Elas não são apresentadas como peças do projeto de outra pessoa.

O projeto teve como referência de conceito um projeto público de Third Thumb disponível no GitHub, mas esta versão possui adaptações próprias, principalmente na eletrônica e no sistema de controle.

Importante: referência ou inspiração não significa que as peças deste projeto sejam cópias das peças do projeto de referência.

Materiais

Esta lista utiliza como base os materiais mecânicos e de montagem do projeto de referência, com as adaptações necessárias para esta versão.

Eletrônica

1× Arduino Uno

2× Servomotores de 180°

2× Placas/sensores de pressão

1 placa de pressão para cada servo

1× Protoboard

Fios para conexão

Jumpers macho/fêmea, conforme necessário

Resistores para os circuitos dos sensores de pressão

1× cabo USB para o Arduino

Alimentação adequada para os servomotores

Alterações em relação ao projeto de referência

Nesta versão:

Raspberry Pi Pico → Arduino Uno

e os sensores utilizados originalmente no projeto de referência são substituídos por:

Sensores ECG → 2 placas/sensores de pressão

Cada placa de pressão será utilizada como entrada para controlar um dos dois servomotores.

Peças impressas em 3D

As peças abaixo fazem parte do conjunto atual deste projeto.

PLAPeçaQuantidadecaseBase.STL1caseMid.STL1fingerBase.STL1fingerMid.STL1fingerTip.STL1fingerHolster.STL1fingerDualAxisHinge.STL1

Total: 7 peças em PLA

TPUPeçaQuantidadeservoWheel.STL1servoWheel2.STL1

Total: 2 peças em TPU

Total de peças 3D

9 peças impressas

Essas são as peças incluídas no pacote atual deste projeto. Não confundir esta lista com a lista de peças 3D do projeto de referência.

Materiais mecânicos

Linha de pesca de nylon

Tubo transparente para guiar a linha

Velcro

Parafusos pequenos

Porcas, se necessárias para a montagem

Ferramentas para montagem

Alicate

Cortador de fios

Furadeira manual de precisão, se necessária

Ferro de solda, caso seja necessário soldar conexões

Pistola de ar quente, caso seja necessária para acabamento dos materiais

Álcool isopropílico para limpeza das peças

Lubrificante adequado para partes mecânicas, quando necessário

Como funciona

O Third Thumb possui um mecanismo de dedo robótico conectado a dois servomotores.

Os servomotores funcionam como os "músculos" do sistema.

A linha de pesca de nylon funciona como um "tendão".

Quando um servo gira, ele enrola ou puxa a linha de nylon. Essa força é transmitida pelo caminho da linha até o dedo, fazendo o mecanismo se movimentar.

O tubo transparente serve como guia para a linha, ajudando a manter o caminho definido.

O sistema possui dois servos para controlar movimentos diferentes do mecanismo.

Sistema de pressão

A versão deste projeto utiliza duas placas/sensores de pressão.

A ideia é:

Placa de pressão 1 ↓ Arduino Uno ↓ Servo 1 ↓ Movimento do dedo 

e:

Placa de pressão 2 ↓ Arduino Uno ↓ Servo 2 ↓ Movimento do dedo 

Assim, cada sensor de pressão pode ser associado a um dos servomotores.

Quanto maior ou menor for a pressão detectada, o Arduino pode interpretar essa alteração e modificar a posição do servo.

Montagem mecânica1. Imprima as peças

Imprima todas as peças do diretório 3D.

Separe:

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

Verifique cada peça antes da montagem.

As partes móveis devem conseguir se movimentar sem excesso de atrito.

2. Monte o dedo

A montagem do dedo utiliza:

fingerBase ↓ fingerMid ↓ fingerTip 

As partes são conectadas mecanicamente para formar o dedo.

A peça:

fingerDualAxisHinge.STL

é utilizada na articulação de dois eixos.

O:

fingerHolster.STL

serve para sustentar/conectar o conjunto do dedo à estrutura.

3. Monte a estrutura

Utilize:

caseBase.STL

como parte principal da estrutura.

Depois encaixe:

caseMid.STL

de acordo com a montagem mecânica do projeto.

Verifique se os componentes ficam firmes antes de instalar os servos.

4. Instale os servomotores

Instale os dois servomotores na estrutura.

Cada servo recebe uma roda:

Servo 1 → servoWheel.STL

Servo 2 → servoWheel2.STL

As rodas fazem a conexão mecânica entre os servos e as linhas de nylon.

5. Instale a linha de nylon

Passe a linha de pesca de nylon pelo caminho mecânico previsto para o dedo.

A linha deve passar pelo tubo-guia.

O princípio é:

SERVO │ │ enrola/puxa ▼ Roda do servo │ │ linha de nylon ▼ Tubo-guia │ ▼ Articulação │ ▼ Dedo 

Quando o servo gira, a roda movimenta a linha.

A linha então exerce força sobre o mecanismo do dedo.

Importante

Não deixe a linha excessivamente esticada.

Também não deixe folga excessiva.

O objetivo é encontrar uma tensão que permita o movimento sem travar o mecanismo.

6. Instale o velcro

O velcro serve para prender a estrutura ao local onde o dispositivo será utilizado.

A fixação deve ficar firme, mas não deve apertar excessivamente.

Montagem eletrônica

A arquitetura básica é:

┌──────────────┐ Pressão 1 ───►│ │───► Servo 1 Pressão 2 ───►│ Arduino Uno │───► Servo 2 │ │ └──────────────┘ 

Os sensores fornecem sinais ao Arduino.

O Arduino interpreta esses sinais e controla os servos.

Alimentação dos servos

Os servomotores podem consumir bastante corrente, principalmente durante movimentos ou quando encontram resistência.

Por isso, não é recomendado alimentar os dois servos diretamente pelo pino de 5 V do Arduino Uno.

Uma arquitetura mais segura é:

┌──────────────┐ USB ────────────►│ Arduino Uno │ └──────┬───────┘ │ Sinais │ ┌─────┴─────┐ ▼ ▼ Servo 1 Servo 2 ▲ ▲ │ │ └─────┬─────┘ │ Fonte adequada dos servos 

O GND da alimentação dos servos e o GND do Arduino devem estar em comum para que os sinais de controle tenham uma referência correta.

A fonte utilizada para os servos deve ser adequada à tensão e à corrente exigidas pelos modelos escolhidos.

Sensores de pressão

Cada sensor precisa ser conectado ao Arduino de acordo com o tipo de placa/sensor utilizado.

Uma configuração possível é:

Sensor de pressão 1 → A0 Sensor de pressão 2 → A1 

Os valores lidos em A0 e A1 podem então ser convertidos em posições dos servos.

O circuito exato depende do modelo das placas/sensores de pressão. Não existe um único esquema elétrico válido para todos os sensores.

Exemplo de organização dos pinos

Uma organização possível para esta versão:

FunçãoArduino UnoSensor de pressão 1A0Sensor de pressão 2A1Servo 1D9Servo 2D10GNDGNDAlimentação dos sensoresconforme o sensor

Os pinos podem ser alterados no código caso seja necessário.

Teste antes da montagem completa

Antes de colocar o dispositivo no corpo, faça os testes sobre uma mesa.

Teste 1 — Arduino

Conecte o Arduino ao computador e confirme que ele está funcionando.

Teste 2 — sensores

Abra o monitor serial e observe os valores dos dois sensores.

Pressione cada sensor individualmente.

Verifique se os valores mudam.

Teste 3 — servos

Teste cada servo separadamente.

Comece com movimentos pequenos.

Por exemplo:

90° → 80° → 90° → 100° → 90° 

Observe se existe algum travamento.

Teste 4 — linha

Com o servo desligado, verifique se a linha consegue deslizar pelo tubo.

Teste 5 — mecanismo

Depois de confirmar que tudo funciona individualmente, conecte a linha aos servos e ao dedo.

Faça movimentos lentos.

Calibração

Os sensores de pressão podem apresentar valores diferentes mesmo quando não estão sendo pressionados.

Por isso, é necessário realizar uma calibração.

Um processo básico é:

Ligue o Arduino.

Não pressione os sensores.

Observe os valores.

Pressione levemente cada sensor.

Observe o valor mínimo e máximo.

Defina no código uma faixa de funcionamento.

Teste novamente.

A posição do servo pode então ser calculada a partir da pressão detectada.

Cuidados com a linha de nylon

A linha é uma parte importante do mecanismo.

Se estiver:

Muito frouxa:

o servo gira sem movimentar corretamente o dedo;

existe atraso no movimento.

Muito apertada:

o servo pode ficar sobrecarregado;

o mecanismo pode travar;

as peças podem sofrer esforço desnecessário.

Faça a regulagem aos poucos.

Segurança

Este é um projeto experimental de robótica vestível.

Não é um dispositivo médico.

Durante os testes:

teste primeiro fora do corpo;

mantenha os dedos longe das partes móveis;

não force o mecanismo;

não aperte excessivamente o velcro;

pare o teste se houver dor, dormência ou desconforto;

desligue a alimentação antes de fazer manutenção;

verifique se há peças 3D quebradas ou rachadas;

não deixe o servo pressionar uma articulação contra um limite mecânico;

não deixe fios ou linhas presos nas partes móveis.

O projeto deve ser utilizado somente de maneira controlada e responsável.

Problemas comunsO servo não se movimenta

Verifique:

alimentação;

GND comum;

sinal do servo;

conexão do Arduino;

código;

tensão da fonte.

O servo treme

Possíveis causas:

alimentação insuficiente;

ruído no sinal;

conexão ruim;

mecanismo oferecendo resistência;

linha excessivamente tensionada.

O dedo não se movimenta

Verifique:

linha de nylon;

tubo-guia;

roda do servo;

articulação;

alinhamento das peças;

tensão da linha.

O sensor não responde

Verifique:

alimentação;

GND;

conexão do sinal;

resistor utilizado;

tipo específico do sensor;

valores observados no monitor serial.

Estrutura do projetoThe_Third_Thumb/ │ ├── 3D/ │ ├── PLA/ │ │ ├── caseBase.STL │ │ ├── caseMid.STL │ │ ├── fingerBase.STL │ │ ├── fingerMid.STL │ │ ├── fingerTip.STL │ │ ├── fingerHolster.STL │ │ └── fingerDualAxisHinge.STL │ │ │ └── TPU/ │ ├── servoWheel.STL │ └── servoWheel2.STL │ ├── Código aberto/ │ └── código do Arduino │ └── README.md Referência

Este projeto utiliza como referência de conceito o projeto público Third Thumb Project, disponível no GitHub.

A referência foi utilizada para estudar a ideia geral de um terceiro polegar robótico vestível e seu sistema mecânico.

Entretanto, as peças 3D deste repositório pertencem a este projeto e foram desenvolvidas para esta versão.

A eletrônica também foi adaptada:

Projeto de referência Raspberry Pi Pico + 2 sensores ECG ↓ Esta versão Arduino Uno + 2 sensores/placas de pressão + 2 servomotores 

Referência original:
https://github.com/laxmangordon/Third-Thumb-Project

Créditos

Projeto: The Third Thumb
Desenvolvimento e adaptação: Luã

As peças 3D deste repositório fazem parte deste projeto.

A ideia geral foi estudada a partir de projetos públicos de Third Thumb, mas esta versão possui sua própria organização, peças e adaptação eletrônica.

Licença

Consulte o arquivo de licença deste repositório para saber como o projeto pode ser utilizado, modificado e redistribuído.

Status

Projeto em desenvolvimento.

A montagem pode ser atualizada conforme novos testes mecânicos e eletrônicos forem realizados.


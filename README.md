Projeto Torreta com Servos e Joystick
Este projeto Arduino controla uma torreta robótica com movimentos nos eixos X, Y  e Z usando um joystick. O código lê os valores do joystick para mover os servos e a serial é usada para monitorar os dados.

2. Componentes Necessários
Liste todo o hardware necessário para que alguém possa replicar seu projeto.

1 x Placa Arduino (Uno ou similar)

3 x Servos (SG90 ou MG996R)

1 x Joystick Analógico

Fios jumpers

Protoboard (opcional)

3. Diagrama de Conexões
Descreva como os componentes estão conectados. Se você tiver uma imagem do seu circuito, coloque-a aqui! Isso é a parte mais importante para a pessoa que for usar seu código.

Joystick:

VCC -> +5V

GND -> GND

VRx (movimento horizontal) -> Pino Analógico A0

VRy (movimento vertical) -> Pino Analógico A1
VRz (movimento de profundidade) -> Pino Analógico A2

SW (botão do joystick) -> Pino Digital 12 (opcional, se você for usá-lo)

Servos:

ServoX (movimento horizontal) -> Pino Digital 9

ServoY (movimento vertical) -> Pino Digital 10
ServoZ (movimento de profundidade) -> Pino Digital 11

4. Código e Bibliotecas
Mencione as bibliotecas necessárias para o seu código.

O projeto usa a biblioteca padrão Servo.h, que já vem instalada na Arduino IDE.

5. Como Usar
Explique os passos para compilar e fazer o upload do código.

Conecte os componentes como no diagrama acima.

Abra o arquivo .ino na Arduino IDE.

Certifique-se de que a placa e a porta serial estão selecionadas corretamente.

Faça o upload do código para a sua placa Arduino.

Abra o monitor serial para ver os valores de depuração e testar os movimentos.

Arduino Laser Turret

Este projeto implementa uma torreta controlada por potenciômetros com laser e disparo simulado por servo motor.
Ele utiliza dois potenciômetros para controlar a posição X e Y da torreta (movimento horizontal e vertical), além de um botão que aciona o disparo.

📌 Funcionalidades

Controle do eixo X e eixo Y da torreta com potenciômetros analógicos.

Acionamento de um laser para mira.

Botão de disparo que move o servo de gatilho simulando o tiro.

Envio de valores de posição pelo Serial Monitor para depuração.

🔧 Hardware Necessário

Arduino UNO (ou compatível)

2 × Potenciômetros (controle X e Y)

1 × Botão

1 × Módulo Laser

3 × Servos (eixo X, eixo Y e gatilho/disparo)

Jumpers e protoboard

🗂️ Ligações
Componente	Pino Arduino
Potenciômetro X	A0
Potenciômetro Y	A1
Botão Disparo	D13
Laser	D8
Servo X	D9
Servo Y	D10
Servo Disparo	D11
📜 Dependências

As seguintes bibliotecas devem estar instaladas na IDE Arduino:

Servo
 (nativa)

Button
https://docs.arduino.cc/libraries/button/
▶️ Como Usar

Monte o circuito conforme a tabela de ligações.

Carregue o código no Arduino.

Abra o Serial Monitor em 9600 baud para acompanhar os valores X e Y.

Use os potenciômetros para mover a torreta.

Pressione o botão para disparar (servo do gatilho se movimenta).

🔍 Lógica de Funcionamento

Os valores analógicos dos potenciômetros (0–1023) são mapeados para ângulos compatíveis com os servos:

Eixo X → 30° a 150°

Eixo Y → 0° a 180°

O botão é monitorado via biblioteca Button.

Ao pressionar o botão, o servo de disparo move de posição de repouso (90°) até posição de disparo (180°) e retorna.

O laser é ligado permanentemente na inicialização (digitalWrite(laser_pin, HIGH)).

📷 Exemplo de Aplicação

Esse código pode ser utilizado para:

Protótipos de torretas com laser educativo.

Projetos de robótica maker.

Demonstração de controle de múltiplos servos.
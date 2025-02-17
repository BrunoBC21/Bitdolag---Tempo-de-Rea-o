Jogo de Tempo de Reação - Raspberry Pi Pico

Introdução

Este projeto implementa um jogo de tempo de reação utilizando a placa Raspberry Pi Pico com um display OLED e dois botões físicos. O jogo mede o tempo de reação do jogador ao pressionar um botão após um sinal visual. O tempo é exibido no display OLED e pode ser repetido quantas vezes o usuário desejar.

Componentes Utilizados

Raspberry Pi Pico

Display OLED (128x64, protocolo I2C)

2 Botões físicos (A e B)

Resistores de pull-up internos para os botões

Mapeamento de Pinos

Componente

Função

GPIO

Botão A

Iniciar o jogo

10

Botão B

Registrar tempo de reação

11

OLED - SDA

Dados I2C

4

OLED - SCL

Clock I2C

5

Conexões

Botões: Conectados aos pinos GPIO 10 e 11 com resistores de pull-up internos ativados.

Display OLED: Utiliza comunicação I2C nos pinos 4 (SDA) e 5 (SCL).

Funcionamento do Sistema

1. Inicialização:

Configura os pinos de entrada e saída.

Inicializa a comunicação I2C para o display OLED.

Apaga qualquer informação anterior do display.

2. Operação:

O botão A inicia o jogo e exibe "Prepare-se..." no display.

Após um breve tempo de espera, o sistema inicia a contagem.

O botão B deve ser pressionado o mais rápido possível.

O tempo de reação é calculado e exibido no display OLED.

3. Feedback Visual:

O display OLED exibe o tempo de reação em milissegundos.

4. Reinicialização:

Após exibir o tempo de reação, o jogo reinicia automaticamente após 2 segundos.

Exemplo de Saída no Display OLED

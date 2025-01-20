# Controle de LEDs e Buzzer via UART - Grupo 1 - Subgrupo 0

# Introdução

## Este projeto implementa um sistema de controle de LEDs e um buzzer utilizando um Raspberry Pi Pico W. A interação ocorre por meio da comunicação UART, permitindo o controle remoto dos LEDs e do buzzer por meio de comandos enviados pelo terminal.

# Uso

Conecte a placa de desenvolvimento BitDogLab ao computador via USB.

Compile e carregue o código na placa utilizando a ferramenta apropriada. Caso  estiver usando o Wokwi, abra o projeto na plataforma ou diretamente no VSCode com a extensão Wokwi após a compilação do projeto(o JSON com o diagrama está incluído no repositório assim como o toml).

Utilize um terminal serial para enviar comandos via UART e controlar os LEDs e o buzzer(PuTTY).

O comportamento programado será executado conforme os comandos enviados.

# Funcionamento

Os seguintes comandos podem ser enviados via UART para interagir com os LEDs e o buzzer:

G: Liga o LED verde e desliga os demais.

B: Liga o LED azul e desliga os demais.

R: Liga o LED vermelho e desliga os demais.

W: Liga todos os LEDs simultaneamente (luz branca).

O: Desliga todos os LEDs.

Z: Aciona o buzzer por 2 segundos.

# Link para o vídeo ensaio

https://drive.google.com/drive/folders/1L8PFrXdCPgNFTQCX-3Q9AspSMQoiaW8p?usp=sharing


# Responsáveis pelas tarefas

Alex Rodrigo: Criação do repositório, gestão e revisão do projeto e README.

Maria Celiane: Circuito simulado (Wokwi).

Péricles Alcântara: Controle dos LEDs azul e vermelho ao mesmo tempo.

Júlia Galindo: Controle do buzzer e gravação do vídeo.

Laerte Chaves: Implementação da comunicação UART.

Gabriel Oliveira: Implementação do controle do buzzer.

Jeová Cosme: Integração dos LEDs com os comandos UART.

Gabriel Menezes: Implementação do comportamento dos LEDs.

Todos os integrantes do grupo participaram ativamente na construção do código, especialmente nas reuniões via Meet. No entanto, os integrantes Naiane Santos e Victor Henrick não participaram das atividades do projeto.


# README - Semáforo com LED RGB

## Descrição
Este projeto implementa um semáforo utilizando um LED RGB conectado aos GPIOs 11, 12 e 13, simulando a sequência de cores de um semáforo (vermelho, amarelo e verde). A troca de estados é controlada por um temporizador com atraso de 3 segundos (3.000 ms). Durante a execução, uma mensagem é impressa na porta serial a cada segundo (1.000 ms).

## Requisitos
- Plataforma de desenvolvimento compatível com a Ferramenta Educacional BitDogLab
- LED RGB conectado aos GPIOs 11, 12 e 13
- Temporizador configurado para controle do semáforo
- Interface serial para exibição de mensagens

## Funcionamento
1. O LED RGB inicia na cor vermelha.
2. Após 3 segundos, muda para amarelo.
3. Após mais 3 segundos, muda para verde.
4. O ciclo se repete continuamente.
5. A cada segundo, uma mensagem é enviada pela porta serial.

## Implementação
- A mudança de estado do LED RGB é realizada dentro da função de call-back do temporizador (repeating_timer_callback()).
- O loop principal (while) exibe mensagens na serial a cada 1 segundo (1.000 ms).

## GPIOs Utilizados
- **GPIO 11** - Canal de cor Vermelha do LED RGB
- **GPIO 12** - Canal de cor Amarela do LED RGB
- **GPIO 13** - Canal de cor Verde do LED RGB

## Como Executar
1. Conecte o LED RGB corretamente aos pinos indicados.
2. Compile e carregue o código na placa.
3. Observe a mudança de cores do LED RGB conforme a lógica do semáforo.
4. Acompanhe as mensagens enviadas pela porta serial.

## Autor
Projeto desenvolvido como parte da atividade educacional com a Ferramenta BitDogLab.


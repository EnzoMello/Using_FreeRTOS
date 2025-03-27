# Sistema de Monitoramento Simples com 3 Tarefas - FreeRTOS

Este repositório contém uma aplicação embarcada simples utilizando o FreeRTOS para realizar o monitoramento de um sistema com sensores. A aplicação simula o comportamento de um sistema de monitoramento utilizando três tarefas principais: uma para ler o estado de um botão, outra para processar esse estado e, finalmente, uma para controlar um LED.

## Tecnologias Detalhadas

### O que é o FreeRTOS?
O **FreeRTOS** (Free Real-Time Operating System) é um sistema operacional de tempo real (RTOS) open-source projetado para ser utilizado em microcontroladores e sistemas embarcados. Ele fornece um gerenciamento eficiente de múltiplas tarefas simultâneas, permitindo que o desenvolvedor crie sistemas complexos sem sobrecarregar os recursos limitados de hardware.

- **Multitarefa**: O FreeRTOS permite que várias tarefas (threads) sejam executadas em paralelo, permitindo um controle eficiente de processos e recursos, com a garantia de que as tarefas sejam realizadas dentro de prazos específicos.
- **Tempo Real**: O FreeRTOS é otimizado para sistemas que exigem resposta rápida e previsível, como sistemas embarcados e dispositivos de controle.
- **Eficiência**: Possui uma baixa pegada de memória e processador, o que o torna adequado para microcontroladores com recursos limitados.
- **Sincronização de Tarefas**: Oferece mecanismos como semáforos, filas e mutexes para sincronização entre tarefas, garantindo comunicação eficiente e controle de acesso a recursos compartilhados.

Em um sistema embarcado, o FreeRTOS gerencia diferentes processos simultâneos, garantindo que o sistema funcione de maneira eficiente e previsível. Ele é ideal para dispositivos com requisitos rigorosos de tempo, como sensores, atuadores e dispositivos de controle.

## Descrição do Sistema

O sistema de monitoramento simples é composto por três tarefas que simulam o comportamento de um sistema com sensores, como um botão e um LED. As tarefas cooperam entre si, executando funções específicas, como ler o estado do botão e controlar o LED.

### Tarefa 1: Leitura do Botão
A primeira tarefa simula a leitura de um botão. Ela é executada periodicamente, a cada **100ms**. Quando executada, ela verifica o estado do botão e envia esse estado para a próxima tarefa (Tarefa 2).

### Tarefa 2: Processamento do Botão
Esta tarefa recebe o estado do botão enviado pela Tarefa 1. Caso o botão esteja pressionado (simulado por uma variável), ela aciona a próxima tarefa (Tarefa 3). Caso contrário, ela aguarda o próximo ciclo de leitura.

### Tarefa 3: Controle do LED
A Tarefa 3 controla o LED (simulado como uma variável ou saída digital). Se a Tarefa 2 indicar que o botão foi pressionado, a Tarefa 3 acende o LED. Caso contrário, o LED é apagado.

## Detalhamento da Implementação

### Definição de Variáveis
O sistema utiliza variáveis para armazenar o estado do botão e do LED. Além disso, é usada uma **fila** para compartilhar o estado entre as tarefas, permitindo que elas se comuniquem e cooperem de maneira eficiente.

### Criação das Tarefas no FreeRTOS
1. **Tarefa 1**: Leitura do botão - Com uma prioridade baixa, executada periodicamente a cada **100ms**.
2. **Tarefa 2**: Processamento e decisão - Executada dependendo do estado do botão.
3. **Tarefa 3**: Controle do LED - Executada somente quando acionada pela Tarefa 2.

### Sincronização entre as Tarefas
Para permitir a comunicação entre as tarefas, é utilizada uma **fila**. A Tarefa 2 envia um sinal para a Tarefa 3 quando detecta o estado do botão (pressionado ou não). Esse mecanismo de sincronização garante que as tarefas trabalhem de maneira cooperativa.

## Como Executar

1. Clone o repositório:
    ```bash
    git clone https://github.com/EnzoMello/Using_FreeRTOS.git
    ```

2. Compile e carregue o código para o microcontrolador RP2040 utilizando o ambiente de desenvolvimento compatível com o FreeRTOS.

3. Monitore o estado do LED de acordo com o botão simulado, verificando se a lógica das tarefas está funcionando corretamente.

## Conclusão

Este projeto demonstra como o FreeRTOS pode ser utilizado para criar um sistema simples de multitarefa, onde diferentes tarefas cooperam para realizar uma função comum. O uso do FreeRTOS torna o sistema mais modular, escalável e eficiente, permitindo a execução de múltiplas tarefas de forma sincronizada em um ambiente de hardware restrito.

### Links úteis
1. **Vídeo do Youtube**: [Acesso](https://youtu.be/1XSsnJAEhRQ)
2. **Documento da atividade**: [Acesso](https://docs.google.com/document/d/1_wCkQJVf29yPwbY7FyBJqBMYHgU7HUSakIjI6QraWNs/edit?usp=sharing)

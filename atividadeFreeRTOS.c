#include <stdio.h>
#include "pico/stdlib.h" // Biblioteca padrão Raspberry Pi Pico
#include "FreeRTOS.h" // Bblioteca principal do FreeRTOS
#include "task.h" // Biblioteca para gerenciar tarefas no FreeRTOS
#include "queue.h" // Biblioteca para manipular filas no FreeRTOS

// Definando pinagem dos componentes e tempo de debounce do botão
#define BUTTON_PIN 5  
#define LED_PIN 13    
#define DEBOUNCE_TIME_MS 50 

QueueHandle_t buttonQueue; // Fila para armazenar o estado do botão

/**
 * Função para ler o estado do botão e enviar para fila 
 * */
void vButtonReadTask(void *pvParameters) {
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Ativa pull-up interno

    // Variáveis para evitar o bouncing
    bool lastButtonState = false; 
    bool stableButtonState = false;

    for (;;) {
        bool currentButtonState = !gpio_get(BUTTON_PIN); // Lê o estado atual (invertido por causa do pull-up)

        // Se o estado mudou, aguarde para verificar se permanece estável
        if (currentButtonState != lastButtonState) {
            vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_TIME_MS));

            // Verifica novamente o estado após o tempo de debounce
            if (currentButtonState == !gpio_get(BUTTON_PIN)) {
                stableButtonState = currentButtonState; 
                xQueueSend(buttonQueue, &stableButtonState, portMAX_DELAY); 
            }
        }
        lastButtonState = currentButtonState;
        vTaskDelay(pdMS_TO_TICKS(10)); 
    }
}

/**
 * @brief Função para capturar o estado do botão enviado para fila e ativar uma reação vinda do LED 
 */
void vButtonProcessTask(void *pvParameters) {
    bool buttonState;

    for (;;) {
        if (xQueueReceive(buttonQueue, &buttonState, portMAX_DELAY)) { 
            gpio_put(LED_PIN, buttonState); 
        }
    }
}

/**
 * @brief Função para inicializar o LED
 */
void setup_led() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

int main() {
    stdio_init_all();
    
   setup_led();

    // Criando a fila para comunicação entre as tarefas
    buttonQueue = xQueueCreate(5, sizeof(bool));

    // Criando as tarefas 1 e 2 na atividade
    xTaskCreate(vButtonReadTask, "Button Read", 128, NULL, 1, NULL);
    xTaskCreate(vButtonProcessTask, "Button Process", 128, NULL, 2, NULL);

    // Inicia o scheduler do FreeRTOS, para trabalhar com multitarefa
    vTaskStartScheduler();

}

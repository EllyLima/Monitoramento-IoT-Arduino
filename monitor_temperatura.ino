/*
 * PROJETO: Monitor de Temperatura e Umidade com Alerta Visual
 * AUTORA: Elly Lima
 * DESCRIÇÃO:
 * Este código lê dados de um sensor de temperatura (DHT11).
 * - Se a temperatura estiver abaixo de 28°C (agradável), acende o LED Verde.
 * - Se passar de 28°C (alerta de calor), apaga o verde e acende o LED Vermelho.
 * O monitor serial exibe as leituras em tempo real.
 */

// Inclui a biblioteca necessária para o sensor DHT
#include "DHT.h"

// --- CONFIGURAÇÃO DOS PINOS (HARDWARE) ---
#define DHTPIN 2     // O pino digital onde o sensor está conectado
#define DHTTYPE DHT11   // Define o modelo do sensor (DHT11 é o azulzinho comum)

// Define onde os LEDs estão conectados
const int ledVerde = 8;
const int ledVermelho = 9;

// Inicializa o sensor com as configurações acima
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // --- Esta parte roda apenas uma vez quando liga o Arduino ---

  Serial.begin(9600); // Inicia a comunicação para mostrar dados na tela do PC
  Serial.println("Iniciando monitoramento...");

  dht.begin(); // Liga o sensor

  // Define que os pinos dos LEDs são saídas de energia
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  // --- Esta parte roda repetidamente para sempre ---

  delay(2000); // Espera 2 segundos entre cada leitura

  // Lê a temperatura em Celsius
  float temperatura = dht.readTemperature();

  // Verifica se o sensor falhou
  if (isnan(temperatura)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return; // Tenta de novo na próxima volta
  }

  // Mostra a temperatura atual no monitor serial
  Serial.print("Temperatura Atual: ");
  Serial.print(temperatura);
  Serial.println(" *C");

  // --- LÓGICA DE DECISÃO (O "CÉREBRO" DO PROJETO) ---
  // Se a temperatura for maior que 28 graus, é considerado "Alerta de Calor"
  if (temperatura > 28) {
    digitalWrite(ledVermelho, HIGH); // Liga o LED vermelho
    digitalWrite(ledVerde, LOW);     // Desliga o LED verde
    Serial.println("-> Status: ALERTA DE CALOR");
  } 
  else {
    // Se não for maior que 28, está agradável
    digitalWrite(ledVerde, HIGH);    // Liga o LED verde
    digitalWrite(ledVermelho, LOW);  // Desliga o LED vermelho
    Serial.println("-> Status: Normal");
  }
  Serial.println("-----------------------");
}

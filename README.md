# Monitoramento de Temperatura IoT com Alerta Visual 🌡️

Este projeto é um protótipo de IoT desenvolvido para monitorar a temperatura ambiente e fornecer feedback visual imediato.

## 🎯 Objetivo

Demonstrar a integração entre software (lógica C++) e hardware (sensores e atuadores) utilizando a plataforma Arduino. O sistema lê a temperatura a cada 2 segundos e aciona um alerta luminoso caso o ambiente ultrapasse um limite de segurança predefinido em 28°C.

## 🛠️ Hardware Utilizado

* Placa Arduino Uno genêrica
* Sensor de Temperatura e Umidade DHT11
* 1 LED Vermelho (Alerta)
* 1 LED Verde (Status Normal)
* Resistores e Jumpers

## ⚙️ Como Funciona na lógica

O código, escrito em C++, segue esta lógica:
1.  O Arduino inicializa o sensor.
2.  Entra em um loop contínuo de leitura a cada 2 segundos.
3.  **Condicional IF/ELSE:** Verifica a temperatura lida.
    * **SE** temperatura > 28°C: Acende o LED Vermelho e apaga o Verde.
    * **SENÃO**: Mantém o LED Verde aceso e o Vermelho apagado.

## 📂 Arquivos

* `monitor_temperatura.ino`: O código fonte principal para carregar na placa Arduino.

---
*Desenvolvido por Elly Lima como parte de estudos práticos em IoT nas aulas de Oficina de Projetos da Sansumg Ocean.*

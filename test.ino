#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("Iniciando NRF24L01...");

    if (!radio.begin()) {
        Serial.println("⚠️ ERROR: No se detectó el NRF24L01. Revisa las conexiones.");
        while (1);  // Detener el código si no se detecta el módulo
    }

    Serial.println("✅ NRF24L01 detectado correctamente.");

    // Mostrar detalles de la configuración
    radio.printDetails();
}

void loop() {
    // No hace nada en loop, solo muestra la info en setup()
}

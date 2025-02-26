#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);
const byte direccion[6] = "00001";  // Debe ser la misma que el emisor

void setup() {
    Serial.begin(115200);
    radio.begin();
    radio.openReadingPipe(0, direccion);  // Configurar dirección de recepción
    radio.setPALevel(RF24_PA_LOW);
    radio.startListening();  // Configurar como receptor

    Serial.println("Receptor listo...");
}

void loop() {
    if (radio.available()) {
        char mensaje[32] = "";  // Buffer para almacenar el mensaje
        radio.read(&mensaje, sizeof(mensaje));  // Leer el mensaje

        Serial.print("Mensaje recibido: ");
        Serial.println(mensaje);
    }
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);
const byte direccion[6] = "00001";  // Dirección del canal

void setup() {
    Serial.begin(115200);
    radio.begin();
    radio.openWritingPipe(direccion);  // Configura la dirección de transmisión
    radio.setPALevel(RF24_PA_LOW);     // Nivel de potencia bajo
    radio.stopListening();             // Configura como transmisor

    Serial.println("Emisor listo...");
}

void loop() {
    const char texto[] = "Hola desde ESP32!";
    Serial.print("Enviando: ");
    Serial.println(texto);

    bool enviado = radio.write(&texto, sizeof(texto));  // Enviar mensaje

    if (enviado) {
        //Serial.println("Mensaje enviado con éxito!");
    } else {
        Serial.println("Error en el envío.");
    }

}

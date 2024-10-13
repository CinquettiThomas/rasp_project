#include <wiringPi.h>

#define LED_PIN 0  // Definisci il pin dove è collegato il LED (GPIO 17 corrisponde a wiringPi pin 0)

int main(void) {
    // Inizializza la libreria WiringPi
    if (wiringPiSetup() == -1) {
        return 1; // Esce in caso di errore di inizializzazione
    }

    // Imposta il pin come uscita
    pinMode(LED_PIN, OUTPUT);

    // Accende il LED
    digitalWrite(LED_PIN, HIGH);

    // Mantiene il LED acceso per 5 secondi
    delay(5000);

    // Spegne il LED
    digitalWrite(LED_PIN, LOW);

    return 0;
}

#include <wiringPi.h>
#include <stdio.h>  // Per usare getchar()

#define LED_PIN 0  // Definisci il pin dove è collegato il LED (GPIO 17 corrisponde a wiringPi pin 0)

int main(void) {
    // Inizializza la libreria WiringPi
    if (wiringPiSetup() == -1) {
        return 1; // Esce in caso di errore di inizializzazione
    }

    // Imposta il pin come uscita
    pinMode(LED_PIN, OUTPUT);

    printf("Premi un tasto qualsiasi per fermare il lampeggio del LED...\n");

    // Ciclo che fa lampeggiare il LED fino a quando non viene premuto un tasto
    while (!kbhit()) {
        // Accende il LED
        digitalWrite(LED_PIN, HIGH);
        delay(500);  // Mantiene il LED acceso per 500 millisecondi (mezzo secondo)

        // Spegne il LED
        digitalWrite(LED_PIN, LOW);
        delay(500);  // Mantiene il LED spento per 500 millisecondi
    }

    // Spegne il LED prima di terminare
    digitalWrite(LED_PIN, LOW);
    printf("Lampeggio terminato. LED spento.\n");

    return 0;
}

// Funzione per verificare se è stato premuto un tasto
int kbhit(void) {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

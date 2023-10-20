#include <Arduino.h>
#include "Sensor.hpp"

// Créez une instance du capteur HM330X
HM330X hm330x;

void setup() {
    Serial.begin(9600);
    // Initialisez le capteur
    HM330XErrorCodes initResult = hm330x.init();
    if (initResult != NO_ERROR) {
        Serial.println("Erreur lors de l'initialisation du capteur.");
        while (1); // Arrêtez le programme en cas d'erreur
    }
}

/*void loop() {
    uint8_t sensorData[29]; // Tableau pour stocker les données lues par le capteur
    HM330XErrorCodes readResult = hm330x.read_sensor_value(sensorData, 29);

    if (readResult == NO_ERROR) {
        // Les données ont été lues avec succès, vous pouvez les utiliser ici.
        // Par exemple, affichez-les via la communication série (Serial).
        for (int i = 0; i < 29; i++) {
            Serial.print(sensorData[i], HEX); // Afficher les données en format hexadécimal
            Serial.print(" ");
        }
        Serial.println(); // Aller à la ligne
    } else {
        Serial.println("Erreur lors de la lecture du capteur.");
    }

    delay(1000); // Attendez une seconde entre les lectures (ajustez selon vos besoins)
}*/
void loop() {
    uint8_t sensorData[29]; // Tableau pour stocker les données lues par le capteur
    HM330XErrorCodes readResult = hm330x.read_sensor_value(sensorData, 29);

    if (readResult == NO_ERROR) {
        // Les données ont été lues avec succès, vous pouvez les utiliser ici.

        Serial.println("Données du capteur de qualité de l'air :");
        Serial.print("PM1.0 en µg/m³ : ");
        Serial.println((uint16_t(sensorData[0]) << 8) | sensorData[1]);

        Serial.print("PM2.5 en µg/m³ : ");
        Serial.println((uint16_t(sensorData[2]) << 8) | sensorData[3]);

        Serial.print("PM10 en µg/m³ : ");
        Serial.println((uint16_t(sensorData[4]) << 8) | sensorData[5]);

        // Ajoutez d'autres données si nécessaire

        Serial.println(); // Aller à la ligne
    } else {
        Serial.println("Erreur lors de la lecture du capteur.");
    }

    delay(1000); // Attendez une seconde entre les lectures (ajustez selon vos besoins)
}
#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <global.h>

#ifndef PAYLOD_H
#define PAYLOD_H

void payloadSetup()
{

    Serial.begin(115200);

    Serial.print(F("[LoRa] Initializing ... "));

    LoRa.setPins(pin_cs, pin_reset, pin_dio0);

    if (!LoRa.begin(915E6))
    { // Set frequency to 915 MHz
        Serial.println(F("Failed to initialize LoRa!"));
        while (true)
            ; // Halt if initialization fails
    }

    // LoRa.setSyncWord(syncword);
    LoRa.setCodingRate4(codingRate);
    LoRa.setSpreadingFactor(spreadingFactor);
    LoRa.setSignalBandwidth(bandwidth);
    LoRa.setTxPower(txPower);

    Serial.println(F("LoRa init success!"));
}
void payloadLoop()
{

    Serial.print(F("[LoRa] Transmitting packet ... "));

    LoRa.beginPacket();
    char output[50];
    sprintf(output, "Counter: %d", counter++);
    LoRa.print(output);
    LoRa.endPacket();

    Serial.println(F(" success!"));

    delay(1000); // Wait before transmitting again
}

#endif
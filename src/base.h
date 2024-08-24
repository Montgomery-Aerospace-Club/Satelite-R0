#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <global.h>

#ifndef BASE_H
#define BASE_H

void baseSetup()
{
    Serial.begin(9600);
    while (!Serial)
        ;

    LoRa.setPins(pin_cs, pin_reset, pin_dio0);

    Serial.println("LoRa Receiver Test");

    if (!LoRa.begin(915E6))
    {
        Serial.println("Starting LoRa failed!");
        while (1)
            ;
    }

    LoRa.setSyncWord(syncword);
    LoRa.setCodingRate4(7);
    LoRa.setSpreadingFactor(spreadingFactor);
    LoRa.setSignalBandwidth(bandwidth);

    Serial.println("LoRa Receiver ready");
}

void baseLoop()
{
    int packetSize = LoRa.parsePacket();
    if (packetSize)
    {
        Serial.print("Received '");

        while (LoRa.available())
        {
            Serial.print((char)LoRa.read());
        }

        Serial.print("' with RSSI ");
        Serial.println(LoRa.packetRssi());
    }
}
#endif

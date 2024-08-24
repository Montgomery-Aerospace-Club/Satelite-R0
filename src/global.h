#ifndef GLOBAL_H
#define GLOBAL_H

int counter = 0;

const int pin_cs = 10;   // Chip Select
const int pin_reset = 3; // Reset
const int pin_dio0 = 2;  // Digital I/O 0

const int syncword = 2314;
const int codingRate = 8;
const int spreadingFactor = 7;
const int bandwidth = 62.5E3;
const int txPower = 10; // between -3 and 17dbm

#endif
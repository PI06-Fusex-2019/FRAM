#ifndef FRAM_H
#define FRAM_H

#include <SPI.h>
#include <Arduino.h>

//Configuration des pins
#define FRAM_CS  10
#define FRAM_SCK 13
#define FRAM_MISO 12
#define FRAM_MOSI 11

//Codes de commandes de la FRAM
#define WRITE_en 0b00000110 //autorise l'ecriture
#define WRITE_dis 0b00000100 //enleve l'autorisation d'ecriture
#define READ_stat 0b00000101 
#define WRITE_stat 0b00000001
#define READ 0b00000011
#define WRITE 0b00000010
#define get_ID  0b10011111 //donne les ID de la FRAM

#define emptybyte 0b00000000

void setupFRAM();
bool checkID();

// void writeonFRAM(); //Alors ça va être un peu chiant à faire ça, ça dépend de la taille des infos 
// void writeOnFile(); //Ca va dépendre de comment on code l'info

void ereasedFRAM();
#endif
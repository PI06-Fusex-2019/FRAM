#include "FRAM.h"


byte ID1(5),ID2(5),ID3(5),data(5);

//Initialisation des pins de commande et de traitement des données
void setupFRAM()
{

  pinMode(FRAM_MISO, OUTPUT);
  pinMode(FRAM_MOSI, INPUT);
  pinMode(FRAM_SCK,OUTPUT);
  pinMode(FRAM_CS, OUTPUT);    
  digitalWrite(FRAM_CS,HIGH);
}

//On vérifie si on detecte le bon composant
bool checkID()
{
    digitalWrite(FRAM_CS,LOW); //Permet une instruction
    SPI.begin();

    SPI.transfer(get_ID);
    ID1 = SPI.transfer(emptybyte);
    ID2 = SPI.transfer(emptybyte);
    ID3 = SPI.transfer(emptybyte);

    SPI.end();
    digitalWrite(FRAM_CS,HIGH);

    return (ID1==0b10101110 && ID2==0b10000011 && ID==0b00011010)
}
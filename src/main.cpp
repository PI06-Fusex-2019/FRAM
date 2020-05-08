#include <Arduino.h>
#include <SPI.h>
#include "FRAM.h"



void setup(void) {

  Serial.begin(9600);
  while(!Serial){} //permet une stabilisation de la liaison
  Serial.println("Initialisation de la FRAM");
  setupFRAM();
  Serial.println("C'est bon !");

  if (checkID())
  {
    Serial.println("Erreur, communication non établit");
    while(1)
  }
  Serial.println("Communication établit");

//////////////////////////////////////////////////////////////////////////////////////////////////
  //Comment écrire
//  SPI.begin();
  //SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
//  digitalWrite(FRAM_CS,LOW);
//  SPI.transfer(WRITE_en);
//  SPI.transfer(/*addresse où l'on veut écrire 1/4*/);
//  SPI.transfer(/*addresse où l'on veut écrire 2/4*/);
//  SPI.transfer(/*addresse où l'on veut écrire 3/4*/);
//  SPI.transfer(/*addresse où l'on veut écrire 4/4*/);
//  SPI.transfer(/*donnée que je veux écrire, */);
// On peut écrire autant que l'on veut tant qu'on a pas fait la commande suivante (attention à ne pas écraser de donnée déjà existante):
//  digitalWrite(FRAM_CS,HIGH);
//  SPI.transfer(WRITE_dis);
//  SPI.end();
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
  //Comment lire
//   SPI.begin();
//   digitalWrite(FRAM_CS,LOW)
//   SPI.transfer(READ);
//   SPI.transfer(/*addresse de la donnée voulu 1/4*/);
//   SPI.transfer(/*addresse de la donnée voulu 2/4*/);
//   SPI.transfer(/*addresse de la donnée voulu 3/4*/);
//   SPI.transfer(/*addresse de la donnée voulu 4/4*/);
//   /*octet où stocker l'info*/=SPI.transfer(emptybyte);
  //On peut lire autant d'octet que l'on veut tant qu'on pose fait pas la commande suivante (attention la lecture peut revenir au debut et continuer à l'infini)
//   digitalWrite(FRAM_CS,HIGH);
/////////////////////////////////////////////////////////////////////////////////////////////////////:


}


void loop()
{
}
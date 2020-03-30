#include <Arduino.h>
#include <SPI.h>

//Configuration des pins
uint8_t FRAM_CS = 10;
uint8_t FRAM_SCK= 13;
uint8_t FRAM_MISO = 12;
uint8_t FRAM_MOSI = 11;

//Codes de commandes de la FRAM
const byte WRITE_en = 0b00000110; //autorise l'ecriture
const byte WRITE_dis = 0b00000100; //enleve l'autorisation d'ecriture
const byte READ_stat = 0b00000101; 
const byte WRITE_stat = 0b00000001;
const byte READ = 0b00000011;
const byte WRITE = 0b00000010;
const byte get_ID = 0b10011111; //donne les ID de la FRAM

const byte emptybyte = 0b00000000;
byte clr;

byte ID1(5),ID2(5),ID3(5),data(4);


void setup(void) {

  Serial.begin(9600);
  while(!Serial){} //permet une stabilisation de la liaison


  //Initialisation des pins de commande et de traitement des données
  pinMode(FRAM_MISO, OUTPUT);
  pinMode(FRAM_MOSI, INPUT);
  pinMode(FRAM_SCK,OUTPUT);
  pinMode(FRAM_CS, OUTPUT);
  digitalWrite(FRAM_CS,HIGH);

  pinMode(3, OUTPUT);

  digitalWrite(3, HIGH);
  
  //Initailisation de la communiation
  SPI.begin();
  //SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  digitalWrite(FRAM_CS, LOW);
  
  SPI.transfer(get_ID);
  
  ID1 = SPI.transfer(emptybyte);
  ID2 = SPI.transfer(emptybyte);
  ID3 = SPI.transfer(emptybyte);
  SPI.end(); //sans ça la communication serie ne passe pas

  
  Serial.println("test");
  Serial.println(ID1);
  Serial.println(ID2);
  Serial.println(ID3);

}


void loop()
{
}
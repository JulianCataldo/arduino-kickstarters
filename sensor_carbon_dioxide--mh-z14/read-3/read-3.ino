

//5V de l'arduino => pin HV du convertisseur et sur la pin 15 (V+) de la sonde
//3,3V de l'arduino => pin LV du convertisseur
//GND de l'arduino => sur les 2 pins GND du convertisseur + sur la pin n°2 (V-) de la sonde
//Analog 0 de l'arduino => pin TX0 (coté HV) du convertisseur
//Analog 1 de l'arduino => pin RXI (coté HV) du convertisseur
//TXI du convertisseur (coté LV) => pin n°13 de la sonde (T)
//RX0 du convertisseur (coté LV) => pin n°14 de la sonde (R)

#include <SoftwareSerial.h>

SoftwareSerial mySerial (A0, A1); // RX, TX,  //respectivement réception & émission

byte cmd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
char reponse[9];

void setup ()
{
// Lancer la connexion série au PC
Serial.begin (9600);
// Lancer la connexion série pour le MH-Z14
mySerial.begin (9600);
}

void loop()
{
  // Ping CO2, lire, répondre et de traduire en PPM
  mySerial.write(cmd,9);
  mySerial.readBytes(reponse, 9);
  int poidsFort = (int) reponse[2];
  int poidsFaible = (int) reponse[3];
  int ppm = (256*poidsFort)+poidsFaible;

   // Affichage du résultat
  Serial.print("PPM ");
  Serial.println(ppm);
  // délais de 2 secondes entre chaque lecture
  delay(2000);
}

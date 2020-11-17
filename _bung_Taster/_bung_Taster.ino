/*
   Funktion:        Taster 1 soll einen Zähler hochzählen Taster 2 soll den selben Taster runterzählen
   Programierer:    Eric Junker
   letzte Änderung: 17.11.2020
   Version:         1.0
   Hardware:        PIN 10 -> Taster EINS
                    PIN 11 -> Taster ZWEI
*/


#include <OneButton.h>

OneButton tasterEins(10, true);
OneButton tasterZwei(11, true);
int zaehler = 0;
bool zaehlerRauf = false;
bool zaehlerRunter = false;


void setup()
{
  tasterEins.attachClick(TasterEins_Funktion);                    //Funktionsaufruf Taster EINS
  tasterZwei.attachClick(TasterZwei_Funktion);                    //Funkrionsaufruf Taster ZWEI
  Serial.begin(9600);

}

void loop()
{
  tasterEins.tick();
  delay(10);
  tasterZwei.tick();
  delay(10);
  //Bei Tastendruck von Taster EINS wird der Zähler hochgezählt und ausgegeben
  if (zaehlerRauf == true)                                                               
  {
    zaehler++;
    zaehlerRauf = false;
    Serial.print("Zähler:");
    Serial.println(zaehler);
  }
  //Bei Tastendruck von Taster ZWEI wird der Zähler runtergezählt und ausgegeben
  if (zaehlerRunter == true)
  {
    zaehler--;
    zaehlerRunter = false;
    Serial.print("Zähler:");
    Serial.println(zaehler);
  }


}

void TasterEins_Funktion()
{
  zaehlerRauf = true;
}

void TasterZwei_Funktion()
{
  zaehlerRunter = true;
}

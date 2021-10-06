#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);
int okuma = true;
int sayac = 0;
int sayac2 = 0;
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
void loop()
{
  if (rfid.isCard()) {
    if (okuma == true) {


      Serial.println("Bu kart: ");




      if (rfid.readCardSerial() > 0) {
        Serial.println(" ");
        Serial.println("Kart numarası: ");
        Serial.print(rfid.serNum[0], DEC);
        Serial.print(" , ");
        Serial.print(rfid.serNum[1], DEC);
        Serial.print(" , ");
        Serial.print(rfid.serNum[2], DEC);
        Serial.print(" , ");
        Serial.print(rfid.serNum[3], DEC);
        Serial.print(" , ");
        Serial.print(rfid.serNum[4], DEC);
        Serial.println(" ");
        if (rfid.serNum[0] == 217 && // A öğrencisinin kartı
            rfid.serNum[1] == 38 &&
            rfid.serNum[2] == 170 &&
            rfid.serNum[3] == 71 &&
            rfid.serNum[4] == 18) {
          
          sayac++;
          Serial.println(sayac);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          if (sayac == 1) {

            delay(100);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
          }
          if (sayac == 2) {

            delay(100);
            digitalWrite(5, HIGH);
            delay(100);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
          }
          if (sayac >= 3) {

            delay(100);
            digitalWrite(5, HIGH);
            delay(100);
            digitalWrite(6, HIGH);
            delay(100);
            digitalWrite(7, HIGH);
            Serial.println("Bu gunluk hakkiniz bitmistir");
          }
          delay(1000);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
        }
      }
      if (rfid.serNum[0] == 218 && // B öğrencisinin kartı
          rfid.serNum[1] == 32 &&
          rfid.serNum[2] == 235 &&
          rfid.serNum[3] == 129 &&
          rfid.serNum[4] == 144) {

        sayac2++;
        Serial.println(sayac2);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        if (sayac2 == 1) {

          delay(100);
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
        }
        if (sayac2 == 2) {

          delay(100);
          digitalWrite(5, HIGH);
          delay(100);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
        }
        if (sayac2 >= 3) {
          sayac2 = 3;
          delay(100);
          digitalWrite(5, HIGH);
          delay(100);
          digitalWrite(6, HIGH);
          delay(100);
          digitalWrite(7, HIGH);
          Serial.println("Bu gunluk hakkiniz bitmistir");
        }
        delay(1000);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);


      }



      rfid.halt();
      okuma = false;
    }
  }

  if (rfid.isCard() == false) {

    okuma = true;

  }


  delay(500);
}

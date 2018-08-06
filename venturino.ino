#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_BMP2802.h>

// using I2C
//Adafruit_BMP280 bme;
Adafruit_BMP280 bme;
Adafruit_BMP2802 bme2;

long x=0;
long i=0;

void setup()
{
  Serial.begin(9600);
  if (!bme.begin())
  {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
  if (!bme2.begin())
  {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}

  void loop()
{
    x=0;
    i=0;
    while(i<50){
      x=x+bme.readPressure();
      i++;
    }
    Serial.print(x/50.0);
    Serial.print("\t");
    x=0;
    i=0;
    while(i<50){
      x=x+bme2.readPressure();
      i++;
    }
    
    // Abaixo encontra-se a linha de impressão da pressão do segundo sensor. 
    //O valor +13 deve ser modificado para mais ou menos caso inicialmente as pressões não estejam aproximadamente iguais. 
    //Este valor funciona como uma espécie de normalização das pressões devido ás diferenças entre os sensores.
    
    Serial.println((x/50.0)-57);
    delay(50);
}

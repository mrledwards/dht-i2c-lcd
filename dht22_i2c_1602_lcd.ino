#include <Wire.h>
#include <LCD.h>

#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd (0x3f,2,1,0,4,5,6,7); // Initialize a single i2c LCD
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
  lcd.begin(16,2); //16 by 2 character display
  dht.begin();
}

void loop()
{
  delay(1000);
 // lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp: " );
  lcd.print(t);
  lcd.print("*C ");
}

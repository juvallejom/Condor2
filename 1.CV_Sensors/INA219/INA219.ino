#include  
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Adafruit_INA219 ina219;

float shuntvoltage = 0;
float busvoltage = 0;
float current_mA = 0;
float loadvoltage = 0;
float potencia = 0;
float energia = 0;

void setup(void) 
{
  lcd.begin(16, 2);
  ina219.begin();
}

void loop(void) 
{
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = (ina219.getCurrent_mA() * 0.966);
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  lcd.setCursor(0,0);
  lcd.print(loadvoltage); lcd.print("V");
  lcd.setCursor(7,0);
  lcd.print(current_mA); lcd.print("mA");
  potencia = loadvoltage * current_mA;
  lcd.setCursor(0,1);
  lcd.print(potencia / 1000); lcd.print("W");
  energia = energia + (potencia / 3600);
  lcd.setCursor(7,1);
  lcd.print(energia / 1000); lcd.print("Wh");
  delay(1000);
  lcd.clear();
}
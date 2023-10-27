#include <Wire.h>
#include <Adafruit_INA219.h>

//Adafruit_INA219 ina219; //DEFAULT 0x040
Adafruit_INA219 ina219_B(0x040);// Dirección I2C del INA219 (1000000)-0x40 en Hexadecimal


void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("HOLA!!!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219_B.begin()) {
    Serial.println("Falla en localizar el modulo INA219");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  Serial.println("Las meedidas son :  ...");
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219_B.getShuntVoltage_mV();
  busvoltage = ina219_B.getBusVoltage_V();
  current_mA = ina219_B.getCurrent_mA();
  power_mW = ina219_B.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.print(" V.....");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.print(" mV...");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.print(" V...");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.print(" mA...");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.print(" mW");
  Serial.println("");

  delay(2);
}

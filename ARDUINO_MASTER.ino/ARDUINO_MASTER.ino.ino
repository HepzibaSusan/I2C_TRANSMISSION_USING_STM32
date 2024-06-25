#include <Wire.h>

#define STM32_SLAVE_ADDRESS 0x12
#define buffersize 6

void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
}

void loop() {
  uint8_t dataToSend[buffersize] = {1, 2, 4, 7, 3, 0}; 
  Wire.beginTransmission(STM32_SLAVE_ADDRESS); // Start I2C transmission to STM32
  Wire.write(dataToSend, buffersize); // Send the data
  uint8_t result=Wire.endTransmission(); // End the transmission and get status
  
  if(result==0)
  {
  Serial.println("Data sent to STM32 slave");
  }
  else
  {
    Serial.print("Couldn't deliver data to STM32 Slave");
  }
  delay(1000); // Wait for a second before sending the next data again
}
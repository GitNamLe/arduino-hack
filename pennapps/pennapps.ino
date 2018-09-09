#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;



void setup() {
  // put your setup code here, to run once:

 lcd.begin(16, 2);

  lcd.setRGB(colorR, colorG, colorB); 
 // Print a message to the LCD.


Serial.begin(9600);

}

void loop() {
  
  //int val = 0;
  // put your main code here, to run repeatedly:
int sensorValue=analogRead(A0);
Serial.println(sensorValue);
if(sensorValue==1023){
  
  printText();
  
  lcd.clear();
}

delay(1800);

}

void printText(){
 // if(Serial.available()>0){
 //int ans = Serial.read();
 //lcd.print(ans);
 String x = Serial.readString();
   lcd.println(" Welcome! room id: "+x);
   for (int positionCounter = 0; positionCounter < 7; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(700);
   }

   
   
   Serial.println(x);

     
    delay(10000);
  
  
 
}
//}

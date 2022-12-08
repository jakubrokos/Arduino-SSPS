#include <LiquidCrystal_I2C.h>

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  //lcd.setCursor(2,0);
  //lcd.print("Hello World");

  //lcd.setCursor(2,1);
  //lcd.print("BEN?");

}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("SUS");
  delay(2000);
  
  lcd.setCursor(2, 0);
  lcd.print("SUSSY BAKY");
  delay(2000);
  lcd.clear();
}


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo servo;
int angle = 10;

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 

  servo.attach(3);
  servo.write(angle);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {

  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);


  if (mapX > 500) {
    angle = servo.read();
    servo.write(angle + 5);
    Serial.println(angle);
    delay(15);
  }
  else if (mapX < -500) {
    angle = servo.read();
    servo.write(angle - 5);
    Serial.println(angle);
    delay(15);
  }

  lcd.setCursor(0, 0);
  lcd.print("X:");
  //Serial.println(mapX);
  lcd.print(2, 0);
  lcd.print(mapX);

  lcd.setCursor(8, 0);
  lcd.print("Y:");
  lcd.print(11, 0);
  lcd.print(mapY);

  lcd.setCursor(0, 1);
  lcd.print("button:");
  lcd.setCursor(8, 1);
  lcd.print(SW_state);

  delay(100);
  lcd.clear();


}

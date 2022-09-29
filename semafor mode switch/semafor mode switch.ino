#define POTENTIOMETER_PIN A0
int buttonPress = 0;
bool buttonState = true;
const int buttonPin = 7;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  //cte buttonPin
  buttonState = digitalRead(buttonPin);
  
  //meni buttonState
  if (buttonPress == 1) {
    if (buttonState == true){
      buttonState = false;
    }
    if(buttonState == false){
      buttonState = true;
    }
  }
  if (buttonState == 1)
  {
    //blikani
    digitalWrite(12, HIGH);   
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(12, LOW);

    digitalWrite(11, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(11, LOW);

    digitalWrite(10, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));
    digitalWrite(10, LOW);

    digitalWrite(11, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(11, LOW);
  } else {
    //normalni semafor
  }
  //vypisuje
  Serial.println(buttonState);
  Serial.println(analogRead(POTENTIOMETER_PIN));
  delay(100);



}

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
  
  //čte buttonPin
  buttonPress = digitalRead(buttonPin);
  
  //meni buttonState
  if (buttonPress == 1) {
    buttonState =!buttonState;
  }
  Serial.println(buttonState);
  if (buttonState == true)
  {
    //blikání

    //red
    digitalWrite(12, HIGH);   
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(12, LOW);

    //yellow
    digitalWrite(11, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(11, LOW);

    //green
    digitalWrite(10, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));
    digitalWrite(10, LOW);

    //yellow
    digitalWrite(11, HIGH);
    delay(analogRead(POTENTIOMETER_PIN));              
    digitalWrite(11, LOW);
  } else {
    //normalní semafor

    //red + yellow
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(11, HIGH);
    delay(1000);              
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);

    //only green
    digitalWrite(10, HIGH);
    delay(2000);              
    digitalWrite(10, LOW);

    //only yellow
    digitalWrite(11, HIGH);
    delay(1000);
    digitalWrite(11, LOW);

  }

  //vypisuje buttonState a hodnotu potenciometru
  Serial.println(buttonState);
  Serial.println(analogRead(POTENTIOMETER_PIN));
  delay(100);
}

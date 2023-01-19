int VRx = A0;
int VRy = A1;
int SW = 3;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

int odpoved_uziatel() {
  return 2;

}

void otazka(){
  Serial.println("Kdo je pachatel ???????");
  Serial.println("A: Jarda B: Jarda C: Jarda D: Jarda");
  int spravna_odpoved = 2;
  Serial.println(SW_state);
  while(SW_state != LOW);{  
    Serial.println("v loopu");    
    if (odpoved_uziatel() == spravna_odpoved) {
      Serial.println("sprave");
    }
    SW_state = digitalRead(SW);
  }
}

void loop() {

  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  otazka();
  
  if (mapX < -500) {
  digitalWrite (9,HIGH);
  } else {
  digitalWrite (9, LOW);
  }
  
  if (mapX > 500) {
  digitalWrite (8, HIGH);
  } else {
  digitalWrite (8,LOW);
  }

  if (mapY < -500) {
  digitalWrite (6,HIGH);
  }else{
    digitalWrite (6, LOW);
  }

  if (mapY > 500){
    digitalWrite (7, HIGH);
  }else{
    digitalWrite (7, LOW);
  }

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);


  
}
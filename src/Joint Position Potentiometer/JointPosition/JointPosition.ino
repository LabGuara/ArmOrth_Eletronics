
#define POTENTIOMETER 15

int maxAngle_Deg = 120;
int minAngle_Deg = 0;

int minPotValue=0;
int maxPotValue=4095;

bool calibrated = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  
  if(calibrated == false){
    delay(5000);
    calibratePosition();
  }
  Serial.println(map(analogRead(POTENTIOMETER),minPotValue, maxPotValue, 0, 120));
  delay(100);
}

void calibratePosition(){
  Serial.println("Set to maximum extension...");
  delay(5000);  //Start 5 second countdown
  minPotValue = analogRead(POTENTIOMETER);

  Serial.println("Set to maximum contraction...");
  delay(5000);
  maxPotValue = analogRead(POTENTIOMETER);

  calibrated = true;
}

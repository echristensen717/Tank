char command;
String string;
int pwm1 = 10;
int dir1 = A1;
int pwm2 = 11;
int dir2 = A2;
bool motor1forward = false;
bool motor2forward = false;
bool motor1reverse = false;
bool motor2reverse = false;
bool motor1turn = false;
bool motor2turn = false;

  void setup()
  {
    Serial.begin(9600);
    pinMode(pwm1, OUTPUT);
    pinMode(dir1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(dir2, OUTPUT);
    
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(100);
    }
    
    if(string == "TL")
    {
        if(motor2turn == true && motor1forward == true){
          digitalWrite(pwm2, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm1, LOW);
          motor2turn = false;
          motor1forward = false;
        }
        if(motor2forward == true){
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
        }
        if(motor2reverse == true){
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
        }
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, 20);
        analogWrite(pwm1, 20);
        delay(100);
        analogWrite(pwm2, 40);
        analogWrite(pwm1, 40);
        delay(100);
        analogWrite(pwm2, 60);
        delay(100);
        analogWrite(pwm2, 80);
        delay(100);
        analogWrite(pwm2, 100);
        delay(100);
        analogWrite(pwm2, 150);
        delay(100);
        analogWrite(pwm2, 200);
        delay(100); 
        analogWrite(pwm2, 250);
        motor1reverse = false;
        motor2reverse = false;
        motor2forward = true;
        motor1forward = true;
        motor1turn = true;
        motor2turn = false;
    }
    
    if(string =="TD")
    {
        if(motor1forward == true && motor2forward == true){
          rampDownBothMotors();  
          digitalWrite(pwm2, LOW);
          digitalWrite(pwm1, LOW);
          motor2forward = false;
          motor1forward = false;
        }
        if(motor1turn == true && motor2forward == true){
          digitalWrite(pwm1, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
          motor1turn = false;
          motor2forward = false;
        }
        if(motor2turn == true && motor1forward == true){
          digitalWrite(pwm2, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm1, LOW);
          motor2turn = false;
          motor1forward = false;
        }
        if(motor1forward == true){
          rampDownMotorOne();
          digitalWrite(pwm1, LOW);
        }
        if(motor2forward == true){
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
        }
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2, LOW);
        analogWrite(pwm2, 20);
        analogWrite(pwm1, 20);
        delay(100);
        analogWrite(pwm2, 40);
        analogWrite(pwm1, 40);
        delay(100);
        analogWrite(pwm2, 60);
        analogWrite(pwm1, 60);
        delay(100);
        analogWrite(pwm2, 80);
        analogWrite(pwm1, 80);
        delay(100);
        analogWrite(pwm2, 100);
        analogWrite(pwm1, 100);
        delay(100);
        analogWrite(pwm2, 150);
        analogWrite(pwm1, 150);
        delay(100);
        analogWrite(pwm2, 200);
        analogWrite(pwm1, 200);
        delay(100);
        analogWrite(pwm2, 250); 
        analogWrite(pwm1, 250);
        motor1reverse = true;
        motor2reverse = true;
        motor2forward = false;
        motor1forward = false;
        motor1turn = false;
        motor2turn = false;
        
    }
    if(string == "TF")
    {
        if(motor1reverse == true && motor2reverse == true){
          rampDownBothMotors();
          digitalWrite(pwm2, LOW);
          digitalWrite(pwm1, LOW);
          motor1reverse = false;
          motor2reverse = false;
        }
        if(motor1turn == true && motor2forward == true){
          digitalWrite(pwm1, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
          motor1turn = false;
          motor2forward = false;
        }
        if(motor2turn == true && motor1forward == true){
          digitalWrite(pwm2, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm1, LOW);
          motor2turn = false;
          motor1forward = false;
        }
        if(motor1reverse == true){
          rampDownMotorOne();
          digitalWrite(pwm1, LOW);
        }
        if(motor2reverse == true){
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
        }
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, 20);
        analogWrite(pwm1, 20);
        delay(100);
        analogWrite(pwm2, 40);
        analogWrite(pwm1, 40);
        delay(100);
        analogWrite(pwm2, 60);
        analogWrite(pwm1, 60);
        delay(100);
        analogWrite(pwm2, 80);
        analogWrite(pwm1, 80);
        delay(100);
        analogWrite(pwm2, 100);
        analogWrite(pwm1, 100);
        delay(100);
        analogWrite(pwm2, 150);
        analogWrite(pwm1, 150);
        delay(100);
        analogWrite(pwm2, 200);
        analogWrite(pwm1, 200);
        delay(100);
        analogWrite(pwm2, 250); 
        analogWrite(pwm1, 250);
        motor1reverse = false;
        motor2reverse = false;
        motor2forward = true;
        motor1forward = true;
        motor1turn = false;
        motor2turn = false;
    }
    if(string == "TR")
    {
        if(motor1turn == true && motor2forward == true){
          digitalWrite(pwm1, LOW);
          rampDownMotorTwo();
          digitalWrite(pwm2, LOW);
          motor1turn = false;
          motor2forward = false;
        }
        if(motor1forward == true){
          rampDownMotorOne();
          digitalWrite(pwm1, LOW);
        }
        if(motor1reverse == true){
          rampDownMotorOne();
          digitalWrite(pwm1, LOW);
        }
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwm2, 20);
        analogWrite(pwm1, 20);
        delay(100);
        analogWrite(pwm2, 40);
        analogWrite(pwm1, 40);
        delay(100);
        analogWrite(pwm1, 60);
        delay(100);
        analogWrite(pwm1, 80);
        delay(100);
        analogWrite(pwm1, 100);
        delay(100);
        analogWrite(pwm1, 150);
        delay(100);
        analogWrite(pwm1, 200);
        delay(100); 
        analogWrite(pwm1, 250);
        motor1reverse = false;
        motor2reverse = false;
        motor2forward = true;
        motor1forward = true;
        motor1turn = false;
        motor2turn = true;
    }
    if(string == "TK")
    {
        digitalWrite(pwm1, LOW);
        digitalWrite(pwm2, LOW);
        motor1reverse = false;
        motor2reverse = false;
        motor2forward = false;
        motor1forward = false;
        motor1turn = false;
        motor2turn = false;
    }
    }
 }

void rampDownMotorOne()
{
  //this function will ramp down motor one
  analogWrite(pwm1, 250);
  delay(100);
  analogWrite(pwm1, 230);
  delay(100);
  analogWrite(pwm1, 210);
  delay(100);
  analogWrite(pwm1, 180);
  delay(100);
  analogWrite(pwm1, 150);
  delay(100);
  analogWrite(pwm1, 100);
  delay(100);
  analogWrite(pwm1, 50);
  delay(100);
  digitalWrite(pwm1, LOW);
}
void rampDownMotorTwo()
{
  //this function will ramp down motor one
  analogWrite(pwm2, 250);
  delay(100);
  analogWrite(pwm2, 230);
  delay(100);
  analogWrite(pwm2, 210);
  delay(100);
  analogWrite(pwm2, 180);
  delay(100);
  analogWrite(pwm2, 150);
  delay(100);
  analogWrite(pwm2, 100);
  delay(100);
  analogWrite(pwm2, 50);
  delay(100);
  digitalWrite(pwm2, LOW);
}
void rampUpBothMotors(){
  analogWrite(pwm2, 20);
  analogWrite(pwm1, 20);
  delay(100);
  analogWrite(pwm2, 40);
  analogWrite(pwm1, 40);
  delay(100);
  analogWrite(pwm2, 60);
  analogWrite(pwm1, 60);
  delay(100);
  analogWrite(pwm2, 80);
  analogWrite(pwm1, 80);
  delay(100);
  analogWrite(pwm2, 100);
  analogWrite(pwm1, 100);
  delay(100);
  analogWrite(pwm2, 150);
  analogWrite(pwm1, 150);
  delay(100);
  analogWrite(pwm2, 200);
  analogWrite(pwm1, 200);
  delay(100);
  analogWrite(pwm2, 250); 
  analogWrite(pwm1, 250);
}
void rampDownBothMotors(){
  analogWrite(pwm2, 250);
  analogWrite(pwm1, 250);
  delay(100);
  analogWrite(pwm2, 230);
  analogWrite(pwm1, 230);
  delay(100);
  analogWrite(pwm2, 210);
  analogWrite(pwm1, 210);
  delay(100);
  analogWrite(pwm2, 180);
  analogWrite(pwm1, 180);
  delay(100);
  analogWrite(pwm2, 150);
  analogWrite(pwm1, 150);
  delay(100);
  analogWrite(pwm2, 100);
  analogWrite(pwm1, 100);
  delay(100);
  analogWrite(pwm2, 50);
  analogWrite(pwm1, 50);
  delay(100);
  digitalWrite(pwm2, LOW); 
  digitalWrite(pwm1, LOW);
}

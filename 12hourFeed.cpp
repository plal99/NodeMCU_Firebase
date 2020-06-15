
Servo motor;  // create motor object to control a motor 
                // a maximum of eight motor objects can be created 
 
int pos = 0;    // variable to store the motor position 

long FISHFEEDER = 43200000; // 12 hours between feeding
long endtime; 
long now;

void setup() 
{ 
 
  motor.attach(9);  // attaches the motor on pin 9 to the motor object 
  
  motor.write(0);
  delay(15);
  
}
 
void loop() 
{ 
  now = millis();
  endtime = now + FISHFEEDER;
  
  while(now < endtime) {
   motor.write(0);
   delay(20000);
   now = millis();   
  }
  

  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    motor.write(pos);              // tell motor to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the motor to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    motor.write(pos);              // tell motor to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the motor to reach the position 
  } 
}

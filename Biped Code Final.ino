#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
/*Servo R_Hip_U;     // Right hip upper motor / topmost motor
Servo R_Hip_L;     // Right hip lower motor
Servo R_Knee;      // Right knee motor
Servo R_Ankle_U;   // Right ankle upper motor
Servo R_Ankle_L;   // Right ankle lower motor / lowermost motor

Servo L_Hip_U;     //  Left hip upper motor / topmost motor
Servo L_Hip_L;     // Left hip lower motor
Servo L_Knee;      // Left knee motor
Servo L_Ankle_U;   // Left ankle upper motor
Servo L_Ankle_L;   // Left ankle lower motor / lowermost motor*/


#define SERVOMAX 665
#define SERVOMIN 127
/*#define USMIN  600
#define USMAX  2400*/
#define SERVO_FREQ 60


//inital values / sets the inital positions
int RHU=70 , RHL=100 ,RK=45 ,RAU=102 ,RAL=91;
int LHU=80 , LHL=75 ,LK=130 ,LAU=60 ,LAL=90;


// variables
int degree;
int i,a;
int rhu,rhl,rk,rau,ral; // right hip upper , right hip lower , right knee ,right ankle upper, right ankle lower
int lhu,lhl,lk,lau,lal; //left hip upper , left hip lower , left knee ,left ankle upper, left ankle lower


void setup() {
 //Serial.begin(9600);
 pwm.begin();
 pwm.setPWMFreq(SERVO_FREQ);


delay(2000);


 set();

delay(1000);

lean(17);
delay(1000);

move2(27);
delay(1000);
move3(30);
delay(1000);
move31(8);
delay(1000);
move32(10);
delay(1000);
lean(-10);
delay(1000);
move4(10);
delay(1000);
move5(25);
delay(1000);
lean(-17);
delay(1000);
//news(35);
////delay(100);
////ayush(30);
//lean(-6);
//delay(1000);

//namee(25);
//movelast(35);
tryt(6);//lean
tryt4(15);  //leap motor move
//
tryt2(42);
//////com(25);
lean(19);
//tryt(-7);
tryt5(25); 
delay(100);
//balance
//set();

}

void tryt5(int angle){
  for(i=0;i<abs(angle);i++)
 {
  lhl++;
  rhl--;
  write();
  delay(100);
  }
  
  }

void tryt4(int angle){
  for(i=0;i<abs(angle);i++)
 {
 lhu--;
  write();
  delay(10);
  }
  
  }
void tryt3(int angle){
  
  for(i=0;i<abs(angle);i++)
 {
  ral--;
  rhu++;
  write();
  delay(100);
  }
  }
void tryt2(int angle)
{
  for(i=0;i<abs(angle);i++)
 {
  if(i<36){
  lhl--;}
  
  lau++;
  
  write();
  delay(50);
  }
  }

void tryt(int angle)
{
  for(i=0;i<abs(angle);i++)
 {
  ral++;
  rhu--;
  write();
  delay(100);
  }
  }
void com(int angle){
//  lean2(4);
  for(i=0;i<abs(angle);i++)
 {
//  lhl--;
//  lau++;
//  //lean2((float)i/10);
//
  if(i<9){  
  lk++;}
  lhl--;
//  lk--;
  
  write();
  delay(150);
  }
  
  }
void set()          // sets the inital angles
{
 rhu=RHU;
 rhl=RHL;
 rk=RK;
 rau=RAU;
 ral=RAL;
 lhu=LHU;
 lhl=LHL;
 lk=LK;
 lau=LAU;
 lal=LAL;
 write();
 
}

void write()
{
 pwm.setPWM(14,0,angletopulse(rhu));
 pwm.setPWM(7,0,angletopulse(rhl));
 pwm.setPWM(8,0,angletopulse(rk));
 pwm.setPWM(13,0,angletopulse(rau));
 pwm.setPWM(10,0,angletopulse(ral));

 pwm.setPWM(1,0,angletopulse(lhu));
 pwm.setPWM(2,0,angletopulse(lhl));
 pwm.setPWM(3,0,angletopulse(lk));
 pwm.setPWM(12,0,angletopulse(lau));
 pwm.setPWM(6,0,angletopulse(lal));
}

void loop()    //// looped
{
 /* delay(4000);
set();

delay(1000);

lean(17);
delay(1000);

move2(27);
delay(1000);
move3(30);
delay(1000);
move31(8);
delay(1000);
move32(10);
delay(1000);
lean(-10);
delay(1000);
move4(10);
delay(1000);
move5(20);
delay(1000);
lean(-8);*/
//delay(1000);
//move5(20);
//delay(1000);
//move6(20);
//move61(10);
//delay(1000);
//lean(-8);
//delay(1000);
//move5(20);
//
//delay(1000);


 set();

delay(1000);

lean(17);
delay(1000);

move2(27);
delay(1000);
move3(30);
delay(1000);
move31(8);
delay(1000);
move32(10);
delay(1000);
lean(-10);
delay(1000);
move4(10);
delay(1000);
move5(25);
delay(1000);
lean(-17);
delay(1000);
//news(35);
////delay(100);
////ayush(30);
//lean(-6);
//delay(1000);

//namee(25);
//movelast(35);
tryt(6);//lean
tryt4(15);  //leap motor move
//
tryt2(42);
//////com(25);
lean(19);
//tryt(-7);
tryt5(25); 
delay(100);
//balance
//

}



/////////////////////////////////
int angletopulse(int degree)  // converts the angle 'degree' to pulse
{
 int pulse=map(degree, 0, 180, SERVOMIN, SERVOMAX);
 return pulse;
}
////////////////////////////////
void lean(int angle) //lean leg
{if(angle>0)
{
  for(i=0;i<abs(angle);i++)
 {
   lhu++;
   rhu++;
   lal--;
   ral--;
    write();
   delay(100);
  }
} 

else
{
  for(i=0;i<abs(angle);i++)
 {
   lhu--;
   rhu--;
   lal++;
   ral++;
    write();
   delay(100);
  }
} 
}

void move2(int angle) //Move the right leg forward
{
 for(i=0;i<abs(angle);i++)
 {
   if(i<8)
    rhl+=2;
   else
    rhl++;

   if(i<7)
    rau-=2;
   else
    rau--;

  rk--;
  if(i<5)
  {
    lk--;
  }
  if(i<9)
  lhl++;


   write();
   delay(50);

 }
}

void movelast(int angle)
{
 for(i=0;i<abs(angle);i++)
 {
   if(i<8)
    lhl--;
   else
    lhl--;

   if(i<20){
    lau--;}

  lk++;
  if(i<10)
  {
    rk--;
  }
  if(i<9)
  rhl--;


   write();
   delay(50);

 }
}
void news(int angle)
{
 for(i=0;i<abs(angle);i++)
 {
  if(i<10)
  {lau++;
  lk--;
  }
  rk++;
  write();
   delay(50);
 }
}

void ayush(int angle)
{for(i=0;i<abs(angle);i++)
{
  lhl++;
  rhl--;
  if(i<20)
  rk--;
  



  write();
   delay(50);
  }
}

void namee(int angle)
{for(i=0;i<abs(angle);i++)
{
    lhl--;
    lk--;
    lau+=2;
   write();
   delay(200);
}

}
void move3(int angle)// place it on ground
{
  for(i=0;i<abs(angle);i++)
  {if(i<5)
    rk++;
    else
    {rk++;}
    if(i<8)     
    ral--;
   /* if(i<5)
    rau--;
    else
    rau--;*/
    delay(25);
    write();
  }
}
void move31(int angle)
{
  for(i=0;i<abs(angle);i++)
  {ral++;
  delay(100);
  write();
  }
}

void move32(int angle)
{
  for(i=0;i<abs(angle);i++)
  { if(i<5)
    rau--;
    if(i<5)
    lk++;
    if(i<10)
    lau--;
    delay(50);
    write();
    
  }

  
}

void move4(int angle)  // back to initial position
{
for(i=0;i<abs(angle);i++)
{
   rhl--;
   rk++;
   
   delay(100);
   write();
  }


}



void move5(int angle)
{

  for(i=0;i<abs(angle);i++)
 {
 if(i<15)
  lhl--;
 
 if(i<20)
   lk--;
 if(i<25)
   rk++;
 
   
  

   write();
   delay(50);
  
}
}

void move6(int angle)
{
  for(i=0;i<abs(angle);i++)
 {
  lal--;
  if(i<10)
  lk--;
  delay(50);
  lau++;
  delay(100);
  write();
  }
  
}
void move61(int angle)
{
for(i=0;i<abs(angle);i++)
 {
  lk++;
  rk-=2;
  
  delay(100);
  write();
 
  
  
  }
  
}

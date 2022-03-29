int motor = 8;
int temp=0;
int i=0;
int ack=7;
char str[15];
void setup()
{
Serial.begin(9600);
pinMode(ack,INPUT);
pinMode(motor,OUTPUT);
digitalWrite(motor,LOW);
delay(20000);
delay(20000);
Serial.println("AT+CNMI=2,2,0,0,0");
delay(1000);
Serial.println("AT+CMGF=1");
delay(500);
Serial.println("AT+CMGS=\"+919909177985\"\r"); // Replace x with mobile number
delay(1000);
Serial.println("HELLO! System is ready to receive commands.");// The SMS text you want to send
delay(100);
Serial.println((char)26); // ASCII code of CTRL+Z
delay(1000);
}
void loop()
{
if(temp==1)
{
check();
temp=0;
i=0;
delay(1000);
}
}
void serialEvent()
{
while(Serial.available())
{
if(Serial.find("/"))
{
delay(1000);
while (Serial.available())
{
char inChar=Serial.read();
str[i++]=inChar;
if(inChar=='/')
{
temp=1;
return;
}
}
}
}
}
void check()
{
if(!(strncmp(str,"motor on",8)))
{
digitalWrite(motor,HIGH);
delay(5000);
if(digitalRead(ack)==0)
{
Serial.println("AT+CMGS=\"+919909177985\"\r"); // Replace x with mobile number
delay(1000);
Serial.println("Motor Activated");// The SMS text you want to send
delay(100);
Serial.println((char)26); // ASCII code of CTRL+Z
delay(1000);
}
}
else if(!(strncmp(str,"motor off",9)))
{
digitalWrite(motor,LOW);
delay(5000);
if(digitalRead(ack)==0)
{
Serial.println("AT+CMGS=\"+919909177985\"\r"); // Replace x with mobile number
delay(1000);
Serial.println("Motor deactivated");// The SMS text you want to send
delay(100);
Serial.println((char)26); // ASCII code of CTRL+Z
delay(1000);
}
}
else if(!(strncmp(str,"test",4)))
{
Serial.println("AT+CMGS=\"+919909177985\"\r"); // Replace x with mobile number
delay(1000);
Serial.println("The System is Working Fine.");// The SMS text you want to send
delay(100);
Serial.println((char)26); // ASCII code of CTRL+Z
delay(1000);
}
}

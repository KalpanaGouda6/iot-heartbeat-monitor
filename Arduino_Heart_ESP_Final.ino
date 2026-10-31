#include <SoftwareSerial.h>
SoftwareSerial esp8266(2,3);
#define serialCommunicationSpeed 9600
#define DEBUG true

int led = 13;
int in = 8;
int Reset = 6;
int start = 7;
int count = 0, i = 0, k = 0, rate = 0;

unsigned long time2, time1;
unsigned long time;

byte heart[8] =
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup()
{
  pinMode(in, INPUT);
  pinMode(led, OUTPUT);
  pinMode(Reset, INPUT);
  pinMode(start, INPUT);
  digitalWrite(led, LOW);
  digitalWrite(Reset, HIGH);
  digitalWrite(start, HIGH);
  delay(1000);
  Serial.begin(serialCommunicationSpeed);
  esp8266.begin(serialCommunicationSpeed);
  InitWifiModule();
}

void loop()
{
  //-------------------------------------------------
  if(!(digitalRead(start)))
  {
    for(int j=1;j<=3;j++)
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      delay(1000);
    }

    k=0;

    while(k<5)
    {
      if(digitalRead(in))
      {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);

        if(k==0)
          time1=millis();
{
    while(esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }
  if(debug)
  {
    Serial.print(response);
  }
  return response;
}

void InitWifiModule()
{
  sendData("AT+RST\r\n", 2000, DEBUG);
  delay(5000);
  sendData("AT+CWMODE=1\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CWJAP=\"YOUR_WIFI_NAME\",\"YOUR_WIFI_PASSWORD\"\r\n", 9000, DEBUG);
  delay(9000);
  sendData("AT+CIPMUX=1\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CIPSERVER=1,80\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CIFSR\r\n", 1500, DEBUG);
  delay(1500);
}
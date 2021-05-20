
#define BLYNK_PRINT Serial


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "YourAuthToken";
char ssid[] = "";
char pass[] = "";

float moisture0;
float moisture1;
float moistureavg;
BlynkTimer timer;

void readdata()
{
  moisture0 = analogRead(A0);
  moisture1 = analogRead(A1);
  Blynk.virtualWrite(V0, moisture0);
  Blynk.virtualWrite(V1, moisture1);
  moistureavg = ( moisture0 + moisture1 )/2
}

void setup()
{

  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass, "vxjblynk.duckdns.com", 8080);
  timer.setInterval(1000L, readdata); //push data every 1 sec
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

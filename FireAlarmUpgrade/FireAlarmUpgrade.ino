#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11;
int temp_read = 7;
int sound_trigger = 13;
int buttonNew;
int buttonOld = 1;
int buttonPin = 2;
float sensor_signal;
bool alarmMuted = false;
DHT HT(temp_read, DHT11);
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);
  HT.begin();
  pinMode(sound_trigger, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_signal = HT.readTemperature();
  if(sensor_signal > 31)
  {
    if(alarmMuted == false)
    {
      digitalWrite(sound_trigger, HIGH);
    }
    else
    {
      digitalWrite(sound_trigger, LOW);
    }
  }
  else
  {
    digitalWrite(sound_trigger, LOW);
    alarmMuted = false;
  }
  Serial.println(sensor_signal);
  buttonNew = digitalRead(buttonPin);
  if(buttonNew==0 && buttonOld == 1 )
  {
    
    alarmMuted = true;
    digitalWrite(sound_trigger, LOW);
    delay(5000);
  }
  buttonOld = buttonNew;
  

}

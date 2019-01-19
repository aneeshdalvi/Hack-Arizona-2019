//int analogPin = 0;   // potentiometer connected to analog pin 3
//int val = 0;  
int led_green = 5;  // LED connected to digital pin 9
int led_red = 3;// variable to store the read value

void setup()
{
  pinMode(led_green, OUTPUT);   // sets the pin as output
  pinMode(led_red, OUTPUT);
  Serial.begin(74880);
}

void loop()
{
  int val = analogRead(0);
  analogWrite(led_green, val / 4);
  Serial.print(val);
  Serial.print("\n");
  int val2 = 687 - val;
  analogWrite(led_red, val2 / 4);
}

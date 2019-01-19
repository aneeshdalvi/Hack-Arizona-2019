#include <SoftwareSerial.h>
#include <TinyGPS.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, 4);

TinyGPS gps;
SoftwareSerial ss(3, 2);



void setup()
{
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1,1);

  display.display();
  
  Serial.begin(115200);

  ss.begin(9600);
}

void loop()
{
  display.clearDisplay();
  display.setCursor(1,1);
  float flat, flon;
  unsigned long age;

  Serial.println(gps.satellites());
  gps.f_get_position(&flat, &flon, &age);
  display.print("Satellites: "); display.println(gps.satellites());
  display.print("HDOP: "); display.println(gps.hdop());
  Serial.println(gps.hdop());
  display.print("Lat "); display.println(flat);
  Serial.println(flat);
  display.print("Lon: "); display.println(flon);
  Serial.println(flon);
  display.print("Alt: "); display.println(gps.f_altitude());
  display.display();
 
  smartdelay(1000);
}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

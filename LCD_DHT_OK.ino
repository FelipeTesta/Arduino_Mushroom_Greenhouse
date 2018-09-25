#include "U8glib.h"
#include <dht.h>

U8GLIB_ST7920_128X64_1X u8g( 6, //E
                             5, //R/W
                             4, //RS
                             3); //RST

dht DHT;
#define DHT22_PIN 7

char temp_string[5];
char hum_string[5];
float temp_float;
float hum_float;

void draw(void) {
  
  int chk = DHT.read22(DHT22_PIN);
  
  Serial.print("Temperatura: ");
  Serial.println(DHT.temperature);
  Serial.print("Humididade: ");
  Serial.println(DHT.humidity);
  
  temp_float = (DHT.temperature);
  hum_float = (DHT.humidity);
  
  u8g.drawStr( 0, 10, "Temperatura:");
  dtostrf(temp_float, 3, 1, temp_string);
  u8g.drawStr( 95, 10, temp_string);
  u8g.drawStr( 0, 30, "Humidade:");
  dtostrf(hum_float, 3, 1, hum_string);
  u8g.drawStr( 95, 30, hum_string);
}

void setup(void)
{
  u8g.setFont(u8g_font_8x13);
  Serial.begin(9600);
}

void loop(void)
{
  u8g.firstPage();  
  do
  {
    draw();
    delay(2000);
  }
  while( u8g.nextPage() );
  
}


int moistureLevel = 0;
int moistPercentage = 0;
#include "U8glib.h"
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);
const int motorPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, LOW);
  moistureLevel = analogRead(A0);
  moistPercentage = map(moistureLevel, 0, 1023, 100, 0);
  Serial.println(moistureLevel);
  draw();
  delay(2000);
  while (moistPercentage <= 85){
  Serial.println("*");
  digitalWrite(motorPin, HIGH);
  Serial.println("ggb");
  moistureLevel = analogRead(A0);
  moistPercentage = map(moistureLevel, 0, 1023, 100, 0);
  draw();
  delay(2000);
  }
  
}

void draw(void) {
  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);
  oled.firstPage();
  do {

    // Print s  trings
    oled.drawStr(0, 13, (String(moistPercentage) + "%").c_str());
  } while (oled.nextPage());
}

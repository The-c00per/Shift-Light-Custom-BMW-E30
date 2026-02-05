#include <Adafruit_NeoPixel.h>

#define PIN_RPM      34    
#define PIN_LED      2     
#define NUM_LEDS     9     

Adafruit_NeoPixel strip(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);
volatile int pulseCount = 0;
unsigned long lastMillis = 0;

void IRAM_ATTR countPulse() {
  pulseCount++;
}

void setup() {
  strip.begin();
  strip.setBrightness(150);
  strip.show(); 
  pinMode(PIN_RPM, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(PIN_RPM), countPulse, RISING);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= 100) {
    float rpm = (pulseCount * 200.0); // Calcul pour BMW E30
    pulseCount = 0;
    lastMillis = currentMillis;

    if (rpm > 6600) { // Mode Rupteur
      static bool flash = false;
      flash = !flash;
      for (int i=0; i<NUM_LEDS; i++) strip.setPixelColor(i, flash ? strip.Color(255,0,0) : 0);
    } else {
      for (int i = 0; i < NUM_LEDS; i++) {
        int seuil = 1200 + (i * 550); 
        if (rpm > seuil) {
          if (i < 5) strip.setPixelColor(i, strip.Color(0, 255, 0));       // 5 VERTES
          else if (i == 5) strip.setPixelColor(i, strip.Color(255, 150, 0)); // 1 JAUNE
          else strip.setPixelColor(i, strip.Color(255, 0, 0));             // 3 ROUGES
        } else {
          strip.setPixelColor(i, 0);
        }
      }
    }
    strip.show();
  }
}
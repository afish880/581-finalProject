#include <FastLED.h>

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    5
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    25
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  60


void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

uint8_t gHue = 170; 
int currentIndex = NUM_LEDS;
  
void loop()
{
  run();
  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND);
}

void run()
{
  fadeToBlackBy( leds, NUM_LEDS, 70);
  currentIndex--;
  if (currentIndex < 0) {
    currentIndex = NUM_LEDS;
  }
  int pos = currentIndex;
  leds[pos] += CHSV( gHue, 255, 192);
  delay(20);
}

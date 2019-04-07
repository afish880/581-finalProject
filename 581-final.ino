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

const int buttonPin = 3;
int buttonState = 0;
int prevButtonState = 0;

void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(115200);
}

long inputDelay = 500;
unsigned long lastClickTime = 0;

int prevState = LOW;
bool isRunning = false;

uint8_t gHue = 170; 

void loop()
{
  buttonState = digitalRead(buttonPin);
  bool isEnoughDelay = millis() > lastClickTime + inputDelay;   
  if (buttonState == HIGH && prevState == LOW && isEnoughDelay) {
 
    if (isRunning == false) {
      isRunning = true;
    } else {
      hide();
      isRunning = false;
    }
    lastClickTime = millis();
  }

  prevState = buttonState;

  if (isRunning) {
    run();
  }
    
  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND);
}

int currentIndex = NUM_LEDS;
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

void hide() {
  for(int i= 0; i< NUM_LEDS; i++) {
    leds[i] = CHSV(0,0,0);
  }
}

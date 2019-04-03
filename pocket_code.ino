#include <FastLED.h>

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    5
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    24
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          75
#define FRAMES_PER_SECOND   60

const int buttonPin = 3;     // the number of the pushbutton pin
int buttonState = 0;

const int pressurePin_1 = 6;
int pressureState_1 = 0;

const int pressurePin_2 = 8;
int pressureState_2 = 0;

void setup() {
//  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
 
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  Serial.begin(115200);
}


// List of patterns to cycle through.  Each is defined as a separate function below.
//typedef void (*SimplePatternList[])();
//SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };
//SimplePatternList gPatterns = { count };


uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

unsigned long inputDelay = 500;
//unsigned long dimDelay = ledLength/255;

unsigned long baseLEDBrightness = 200;
unsigned long lastLEDValue = baseLEDBrightness;

bool motionOff = true;

unsigned long sum = 0;
//const int buttonPin = A6;
  
void loop()
{
  pressureState_1 = digitalRead(pressurePin_1);
  Serial.println(pressureState_1);

   pressureState_2 = digitalRead(pressurePin_2);
  Serial.println(pressureState_2);
  
if (pressureState_2 == HIGH) {
     Serial.println("PRESSURE TWO !!!!!!!");
  }


if (pressureState_1 == HIGH) {
     Serial.println("PRESSURE ONE !!!!!!!");
  }

  
  if (pressureState_1 == HIGH && pressureState_2 == HIGH) {
      Serial.println("PRESSURE BOOOOOOOOTTTTTHHHHHH!");
        Serial.println("PRESSURE BOOOOOOOOTTTTTHHHHHH!");
          Serial.println("PRESSURE BOOOOOOOOTTTTTHHHHHH!");
            Serial.println("PRESSURE BOOOOOOOOTTTTTHHHHHH!");
              Serial.println("PRESSURE BOOOOOOOOTTTTTHHHHHH!");
  }
}

#include <Morse.h>

Morse morse(13);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
morse.dot();morse.dot();morse.dot();
morse.dash();morse.dash();morse.dash();
morse.dot();morse.dot();morse.dot();
delay(3000);
}

#include "sam.h"
#define LED_PIN 20
#define INPUT_PIN 10 

void setup() {

 PM->APBBMASK.reg |= PM_APBBMASK_PORT;
 PORT->Group[0].DIRSET.reg = (1 << LED_PIN);
 PORT->Group[0].DIRCLR.reg = (1 << INPUT_PIN);

}

void loop() {

 PORT->Group[0].OUTSET.reg = (1 << LED_PIN);
 delay(500);
 
 PORT->Group[0].OUTCLR.reg = (1 << LED_PIN);
 delay(500);

}

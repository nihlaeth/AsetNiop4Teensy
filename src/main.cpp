/*
Copyright 2015 Stichting Humanity4all
*/

#ifdef ENERGIA
  #include "Energia.h"
#else
  #include "Arduino.h"
#endif

#ifndef LED_PIN
  // Most Arduino boards already have a LED attached to pin 13 on the board itself
  #define LED_PIN 13
#endif

#define BOUNCE_LOCK_OUT
#include <Bounce2.h>
#include <queue>

#include "./globals.h"
#include "./switchboard/machine.h"
#include "./switchboard/typedefs.h"
#include "./switchevent/switchevent.h"

#define DEBUG

Bounce debugkey;
std::queue<switch_event_n::SwitchEvent> switch_event_queue;
std::queue<switch_board_n::protokey_event_t> protokey_event_queue;

switch_board_n::Machine switch_machine;

void setup() {
    pinMode(LED_PIN, OUTPUT);     // set pin as output
    // our meager debug key - just so we know it's doing something
    pinMode(0, INPUT_PULLUP);
    debugkey.attach(0);
    debugkey.interval(10);

    int pinsToUse[N_SWITCHES]={1, 2, 3, 4};
    for (int i=0; i < N_SWITCHES; i++) {
        int pin = pinsToUse[i];
        pinMode(pin, INPUT_PULLUP);
    }
}

void loop() {

    // check if it's responding at all
    if (debugkey.update()) {
        if (debugkey.read() == 0) digitalWrite(LED_PIN, HIGH); // pressed
        if (debugkey.read() == 1) digitalWrite(LED_PIN, LOW);  // released
    }
}

/*
Copyright 2015 Stichting Humanity4all
*/

#ifndef SRC_TRANSLATIONSERVICE_MACHINESTATE_H_
#define SRC_TRANSLATIONSERVICE_MACHINESTATE_H_

#include "./machine.h"
#include "./typedefs.h"
#include "../switchevent/switchevent.h"

namespace translation_service {

class Machine;

class AbstractState {
 public:
    virtual void process_key_event(
        Machine machine,
        switch_event::SwitchEvent switch_event,
        is_chord,
        reset);
 private:
    key_t keyMap[N_SWITCHES][N_SWITCHES];
};

} // namespace translation_service

#endif // SRC_TRANSLATIONSERVICE_MACHINESTATE_H_

/*
Copyright 2015 Stichting Humanity4all
*/

#ifndef SRC_SWITCHBOARD_MACHINESTATES_H_
#define SRC_SWITCHBOARD_MACHINESTATES_H_

#include <stdexcept>
#include "../globals.h"
#include "./machine.h"
#include "./typedefs.h"
#include "../switchevent/switchevent.h"

namespace switch_board_n {

class Machine;

class AbstractState {
 public:
    virtual protokey_event_t press(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual protokey_event_t release(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual ~AbstractState();
};

class Idle : public AbstractState {
 public:
    virtual protokey_event_t press(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual protokey_event_t release(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual ~Idle();
};

class OneSwitch : public AbstractState {
 public:
    virtual protokey_event_t press(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual protokey_event_t release(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual ~OneSwitch();
};

class TwoSwitch : public AbstractState {
 public:
    virtual protokey_event_t press(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual protokey_event_t release(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual ~TwoSwitch();
};

class ManySwitch : public AbstractState {
 public:
    virtual protokey_event_t press(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual protokey_event_t release(
        Machine& machine,
        switch_event_n::SwitchEvent switch_event);
    virtual ~ManySwitch();
};


} // namespace switch_board_n





#endif // SRC_SWITCHBOARD_MACHINESTATES_H_

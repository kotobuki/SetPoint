#include <string.h>
#include "SetPoint.h"

SetPoint::SetPoint() {
  _threshold = 0;
  _hysteresis = 0;
  _lastState = -1;
  _risingEdgeEventHandler = NULL;
  _fallingEdgeEventHandler = NULL;
}

void SetPoint::begin(int threshold, int hysteresis) {
  _threshold = threshold;
  _hysteresis = hysteresis;
}

void SetPoint::attach(int command, eventHandlerFunction eventHandler) {
  switch (command) {
    case RISING_EDGE:
      _risingEdgeEventHandler = eventHandler;
      break;
    case FALLING_EDGE:
      _fallingEdgeEventHandler = eventHandler;
      break;
  }
}

void SetPoint::update(int value) {
  int state = _lastState;
  if (value < (_threshold - _hysteresis)) {
    state = 0;
  } else if (value > (_threshold + _hysteresis)) {
    state = 1;
  }
  
  if ((_lastState == 0) && (state != 0)) {
    if (_risingEdgeEventHandler != NULL) {
      (*_risingEdgeEventHandler)();
    }
  } else if ((_lastState != 0) && (state == 0)) {
    if (_fallingEdgeEventHandler != NULL) {
      (*_fallingEdgeEventHandler)();
    }
  }
  
  _lastState = state;
}

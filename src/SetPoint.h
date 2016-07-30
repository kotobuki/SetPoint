#ifndef SET_POINT_H
#define SET_POINT_H

#define RISING_EDGE (0)
#define FALLING_EDGE (1)

extern "C" {
  typedef void (*eventHandlerFunction)(void);
}

class SetPoint {
public:
  SetPoint(void);
  
  void begin(int threshold, int hysteresis);
  void attach(int command, eventHandlerFunction eventHandler);
  void update(int value);
  
private:
  int _threshold;
  int _hysteresis;
  int _lastState;
  
  eventHandlerFunction _risingEdgeEventHandler;
  eventHandlerFunction _fallingEdgeEventHandler;
};

#endif

#include "DRV8825_mbed.h"
 
DRV8825::DRV8825(PinName direction, PinName step, PinName activation, int minPeriodMillis): _dir(direction), _step(step), _activation(activation) {
    _minPeriod = minPeriodMillis;
    _activation = 1;
}
 
void DRV8825::reset(PinName limit, int direction) {
    DigitalIn stepperReset(limit);
    stepperReset.mode(PullUp);
    _dir = direction;
    while(!stepperReset) {
        doStep();
        wait_ms(_minPeriod);
    }
}
 
void DRV8825::setGoal(int numStep, int direction, int periodMillis) {
    _currentStep = numStep * 2;
    _dir = direction;
    if (periodMillis < _minPeriod) {
        _currentPeriod = _minPeriod;
    } else {
        _currentPeriod = periodMillis;
    }
}
 
void DRV8825::update(int currentMillis) {
    if (currentMillis >= _lastMillis+_currentPeriod) {
        doStep();
        _currentStep--;
        _lastMillis = currentMillis;
    }
}
 
int DRV8825::isMoveComplete() {
    return (_currentStep == 0);
}
 
void DRV8825::doStep() {
    _step = !_step;
}

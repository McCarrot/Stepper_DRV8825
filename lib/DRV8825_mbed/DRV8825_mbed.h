/* 
 * DRV8825 Stepper Motor Driver
 * Step Motor Control Library via DRV8825 
 * */
 
#ifndef MBED_DRV8825_H
#define MBED_DRV8825_H
 
#include "mbed.h"
 
class DRV8825
{
 
public:
 
    /** Instantiation of a stepper motor controller
     *
     * @param pin direction DIR pin
     * @param pin step STEP pin
     * @param pin activation FAULT pin
     * @param int minPeriodMillis Minimum time in ms between two steps
     */
    DRV8825(PinName direction, PinName step, PinName activation, int minPeriodMillis);
 
    /** Rotates the engine in one direction until the limit switch is activated
     *
     * @param pin limit Pin in PULL-UP end of race
     * @param int direction Direction of rotation of the motor
     */
    void reset(PinName limit, int direction);
 
    /** Set the number of steps, the direction and the time between two steps in ms of the motor
     *
     * @param int numStep the number of steps
     * @param int direction Direction of rotation of the motor
     * @param int periodMillis The time in ms between two steps
     */
    void setGoal(int numStep, int direction, int periodMillis);
 
    /** When the movement is not finished, to call all the time to update the engine
     *
     * @param int currentMillis the number of ms current (to manage with a timer in the hand)
     */
    void update(int currentMillis);
 
    /** Lets know if there is a movement in progress */
    int isMoveComplete();
 
private:
 
    DigitalOut _dir;
    DigitalOut _step;
    DigitalOut _activation;
    int _minPeriod;
    int _currentStep;
    int _currentPeriod;
    int _lastMillis;
 
    void doStep();
 
};
 
#endif
       
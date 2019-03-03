#include <mbed.h>
#include <DRV8825_mbed.h>

#define MIN_STEP_PERIOD_MS 20

DigitalOut myled(LED1);

/* M0, M1, M2 used to set micro-step size
 *  M0  M1  M2  Microstep resolution
 *  0   0   0   Full
 *  1   0   0   Half
 *  0   1   0   1/4
 *  1   1   0   1/8
 *  0   0   1   1/16
 *  1   0   1   1/32
 *  0   1   1   1/32
 *  1   1   1   1/32
 * */
DigitalOut M0(p30);
DigitalOut M1(p29);
DigitalOut M2(p28);

/* Limit switches for stepper */
DigitalIn LimLeft(p23, PullDown);       //Må endres til pullup og kobles om
DigitalIn LimRight(p22, PullDown);

/* Initialization of DRV8825 controlboard */
DRV8825 Stepper1(p26, p27, p25, MIN_STEP_PERIOD_MS);

int main() {
    // Set full step
    M0 = 0;
    M1 = 0;
    M2 = 0;

    while(1) {
        // put your main code here, to run repeatedly:
        myled = 1;
        wait(0.4);
        myled = 0;
        wait(0.2);
    }
}
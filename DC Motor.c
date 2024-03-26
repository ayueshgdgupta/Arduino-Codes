//Rotate DC motor forward and reverse at full speed (nospeed control)


/* This program will rotate DC motor forward for 5 sec then stop for 2 sec and again rotate motor
reverse for 5 sec, stop for 2 sec continuously */


#include<DC_Motor.h>
DC_Motormotor(8, 12);

voidsetup()
{
}

void loop()
{
motor.forward();
delay(5000);
motor.stop_motor();
delay(2000);
motor.reverse();
delay(5000);
motor.stop_motor();
delay(2000);
}




// (2)Rotate DC motor forward and reverse at set speed (with speed control)


/* This program will rotate DC motor forward for 5 sec at 40%speed then stop for 2 sec and again
rotate motor reverse for 5 sec at 80% speed continuously */

#include<DC_Motor.h>
DC_Motor motor2(9, 10, 1);

voidsetup()
{
}

void loop()
{
motor2.set_speed(40);
motor2.forward_with_set_speed();
delay(5000);
motor2.motor_speed_zero();
delay(2000);
motor2.set_speed(80);
motor2.reverse_with_set_speed();
delay(5000);
motor2.motor_speed_zero();
delay(2000);
} 







// (3)Apply jog to motor in both direction with and without speed control 

/* This program applies jog to two different DC motors and it applies jog to 1st motor in full speed in
both direction and then provides jog to 2nd motor with 80%speed in reverse direction and 30% speed in
forward direction */


#include<DC_Motor.h>
DC_Motor motor(8, 12);
DC_Motor motor2(9, 10, 1);

voidsetup()
{
}

voidloop()
{
motor.jogg_full_speed(1);
motor.jogg_full_speed(0);
motor2.jogg_set_speed(0, 80);
motor2.jogg_set_speed(1, 30);
} 






// (4) Apply soft start and smooth stop to motor

#include<DC_Motor.h>
DC_Motor motor2(9, 10, 1);
voidsetup()
{
}
voidloop()
{
motor2.soft_start(1, 90, 10);
delay(3000);
motor2.smooth_stop(5);
motor2.soft_start(0, 50, 6);
delay(3000);
motor2.smooth_stop(3);
} 

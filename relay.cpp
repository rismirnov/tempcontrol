#include "relay.h"

Relay::Relay()
{

}

void Relay::control(float y) {
   float error = y - value;

   if(fabsf(error) > CONTROL_PRECISION * value ) {
       if(error > 0) {
           motor->drive(1);
       }
   }
   motor->drive(0);
}

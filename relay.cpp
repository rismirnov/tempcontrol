#include "relay.h"

Relay::Relay()
{

}

void Relay::control(float y) {
   float error = y - m_value;

   if(fabsf(error) > m_deadband) {
       if(error > 0) {
           m_motor->drive(1);
       }
   }
   m_motor->drive(0);
}

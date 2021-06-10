#include "mbed.h"
AnalogIn Ain(A6);
int main() {
  float V=0;
  BusOut LED(D2,D3,D4,D5,D6,D10,D11,D12);
  DigitalOut Led(D11);
  LED=0;
  thread_sleep_for(200);
  LED=1;
  thread_sleep_for(200);
  LED=3;
  thread_sleep_for(200);
  LED=7;
  thread_sleep_for(200);
  LED=15;
  thread_sleep_for(200);
  LED=31;
  thread_sleep_for(200);
  LED=63;
  thread_sleep_for(200);
  LED=127;
  thread_sleep_for(200);
  LED=255;
  thread_sleep_for(200);
  while(1) {
    V=Ain*3.3;
    if (V<0.95)
    {
      LED=0;
    }
    else
    {
      if (V< 1.05)
      {
        LED=1;
      }
      else
      {
        if (V<1.15)
        {
          LED=3;
        }
        else
        {
          if (V<1.25)
          {
            LED=7;
          }
          else
          {
            if(V<1.35)
            {
              LED=15;
            }
            else
            {
              if(V<1.45)
              {
                LED=31;
              }
              else
              {
                if(V<1.55)
                {
                  LED=63;
                }
                else
                {
                  if(V<1.65)
                  {
                    LED=127;
                  }
                  else
                  {
                    LED=255;
                  }                  
                }
              }
            }
          }
        }
      }
    }
  }
}
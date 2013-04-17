#include "WProgram.h"
#include "ardlang.h"
#include "user_functions.h"
int pin128 = 13;
void setup ()
{
  pinMode(pin128, OUTPUT);
}
void repeat290 ();
void repeat290 ()
{
  set(pin128, (2 + ((50 * 250) / 100)));
  wait(100);
  set(pin128, LOW);
  wait(40);
}
int main ()
{
  init();
  Serial.begin(9600);
  setup();
  char input_array [16];
  int i = 0;
  while ( true )
    {
      while ( (Serial.available() > 0) )
        {
          input_array[i] = Serial.read();
          i++;
        }
      if((input_array[(i - 1)] == '~'))
        {
          int j;
          i = 0;
        }
      repeat290();
    }
  return(0);
}
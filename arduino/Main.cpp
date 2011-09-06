#include "WProgram.h"
#include "ardlang.h"
#include "user_functions.h"
int pin118 = 13;
void setup ()
{
  pinMode(pin118, OUTPUT);
}
void repeat1500 ();
void repeat1500 ()
{
  set(pin118, HIGH);
  wait(300);
  set(pin118, LOW);
  wait(400);
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
      repeat1500();
    }
  return(0);
}
#include "WProgram.h"
#include "ardlang.h"
#include "user_functions.h"
int ledPin7 = 11;
void setup ()
{
  pinMode(ledPin7, OUTPUT);
}
void repeat390 ();
void repeat390 ()
{
  int fadeValue14;
  for ( fadeValue14 = (2 + ((0 * 250) / 100)) ; (fadeValue14 <= (2 + ((100 * 250) / 100))) ; fadeValue14 = (fadeValue14 + 1) )
    {
      set(ledPin7, fadeValue14);
      wait(10);
    }
  int fadeValue15;
  for ( fadeValue15 = (2 + ((100 * 250) / 100)) ; (fadeValue15 >= (2 + ((0 * 250) / 100))) ; fadeValue15 = (fadeValue15 + -1) )
    {
      set(ledPin7, fadeValue15);
      wait(10);
    }
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
      repeat390();
    }
  return(0);
}
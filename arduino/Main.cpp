#include "WProgram.h"
#include "ardlang.h"
#include "user_functions.h"
int ledPin23 = 11;
void setup ()
{
  pinMode(ledPin23, OUTPUT);
}
void repeat230 ();
void repeat230 ()
{
  int fadeValue46;
  for ( fadeValue46 = (2 + ((0 * 250) / 100)) ; (fadeValue46 <= (2 + ((100 * 250) / 100))) ; fadeValue46 = (fadeValue46 + 1) )
    {
      set(ledPin23, fadeValue46);
      wait(500);
    }
  int fadeValue47;
  for ( fadeValue47 = (2 + ((100 * 250) / 100)) ; (fadeValue47 >= (2 + ((0 * 250) / 100))) ; fadeValue47 = (fadeValue47 + -1) )
    {
      set(ledPin23, fadeValue47);
      wait(500);
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
      repeat230();
    }
  return(0);
}
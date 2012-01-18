#include "WProgram.h"
#include "ardlang.h"
#include "user_functions.h"
int led14 = 2;
int led24 = 3;
int led34 = 4;
int led44 = 5;
int led54 = 6;
int led64 = 7;
int led74 = 8;
int led84 = 9;
void setup ()
{
  pinMode(led14, OUTPUT);
  pinMode(led24, OUTPUT);
  pinMode(led34, OUTPUT);
  pinMode(led44, OUTPUT);
  pinMode(led54, OUTPUT);
  pinMode(led64, OUTPUT);
  pinMode(led74, OUTPUT);
  pinMode(led84, OUTPUT);
}
void oddeven ();
void leftright ();
void oddeven ()
{
  int i17;
  for ( i17 = 1 ; (i17 <= 10) ; i17 = (i17 + 1) )
    {
      set(led14, HIGH);
      set(led24, LOW);
      set(led34, HIGH);
      set(led44, LOW);
      set(led54, HIGH);
      set(led64, LOW);
      set(led74, HIGH);
      set(led84, LOW);
      wait(200);
      set(led14, HIGH);
      set(led24, LOW);
      set(led34, HIGH);
      set(led44, LOW);
      set(led54, HIGH);
      set(led64, LOW);
      set(led74, HIGH);
      set(led84, LOW);
      wait(200);
    }
}
void leftright ()
{
  int i18;
  for ( i18 = 1 ; (i18 <= 10) ; i18 = (i18 + 1) )
    {
      set(led14, HIGH);
      set(led24, HIGH);
      set(led34, HIGH);
      set(led44, HIGH);
      set(led54, LOW);
      set(led64, LOW);
      set(led74, LOW);
      set(led84, LOW);
      wait(200);
      set(led14, LOW);
      set(led24, LOW);
      set(led34, LOW);
      set(led44, LOW);
      set(led54, HIGH);
      set(led64, HIGH);
      set(led74, HIGH);
      set(led84, HIGH);
      wait(200);
      int bla4 = 5;
    }
}
int main ()
{
  init();
  Serial.begin(9600);
  setup();
  char input_array [16];
  int i = 0;
  char oddeven_string [] = "oddeven";
  char leftright_string [] = "leftright";
  while ( true )
    {
      bool oddeven_bool = true;
      bool leftright_bool = true;
      while ( (Serial.available() > 0) )
        {
          input_array[i] = Serial.read();
          i++;
        }
      if((input_array[(i - 1)] == '~'))
        {
          int j;
          if(((i - 1) == 7))
            {
              for ( j = 0 ; (j < 7) ; j++ )
                {
                  if((input_array[j] != oddeven_string[j]))
                    {
                      oddeven_bool = false;
                      break ;
                    }
                }
            }
          else
            {
              oddeven_bool = false;
            }
          if(oddeven_bool)
            {
              oddeven();
            }
          if(((i - 1) == 9))
            {
              for ( j = 0 ; (j < 9) ; j++ )
                {
                  if((input_array[j] != leftright_string[j]))
                    {
                      leftright_bool = false;
                      break ;
                    }
                }
            }
          else
            {
              leftright_bool = false;
            }
          if(leftright_bool)
            {
              leftright();
            }
          i = 0;
        }
    }
  return(0);
}
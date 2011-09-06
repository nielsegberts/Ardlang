#include "WProgram.h"
#include "ardlang.h"
int mahal = 13;
void setup ()
{
  pinMode(mahal, OUTPUT);
}
void aan ();
void uit ();
void doeEensKnipperenDan ();
void aan ()
{
  set(mahal, HIGH);
}
void uit ()
{
  set(mahal, LOW);
}
void doeEensKnipperenDan ()
{
  int teller;
  for ( teller = 1 ; (teller <= 5) ; teller = (teller + 1) )
    {
      wait(100);
      set(mahal, HIGH);
      wait(100);
      set(mahal, LOW);
    }
}
int main ()
{
  init();
  Serial.begin(9600);
  setup();
  char hallo_string [] = "hallo";
  char uit_string [] = "uit";
  char doeEensKnipperenDan_string [] = "doeEensKnipperenDan";
  while ( true )
    {
      char inputArray[16];
      int i = 0;
      bool hallo_bool = true;
      bool uit_bool = true;
      bool doeEensKnipperenDan_bool = true;
      
      while ( (Serial.available() > 0) )
        {
	  input_array[i] = Serial.read();
	  i++;
	}

      if (input_array[i-1] == '~') {
	int j;

	if (i-1 == 5) {	
		for (j=0;j<5;j++) {
			if (input_array[j] != hallo_string[j]) {
				hallo_bool = false;
				break;
			}
		}
	}
	if (hallo_bool) {
		doeEensKnipperenDan();
	}
	i=0;
      }
	
     
    }
  return(0);
}

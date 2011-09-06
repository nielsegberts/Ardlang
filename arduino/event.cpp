#include "WProgram.h"
#include "ardlang.h"
void setup ()
{
}
void hallo_event ();
void hallo_event ()
{
  set(13,HIGH);
}
int main ()
{
  init();
  Serial.begin(9600);
  setup();
  void (*event1)(void);
  event1 = hallo_event;
  while ( true )
    {
	int n_events;
	int possible_events[n_events];
	char event1[] = "Hallo";
	char event2[] = "Ja";
	for (int i=0;i<2;i++) {
		possible_events = 1;
	}
	int inByte = 0;
	int i=0;
	while (Serial.available() > 0) {
		inByte = Serial.read();
		if (inByte == '\n') {
/*			if (possible_events[i] == 0) {
				call event i
			}*/
			break;
		}
		if (i > 5) {
			event1 = false;
		}
		if (event1 && inByte != event1[i]) {
			event1 = false;
		}
		
/*		if (inByte != event2[i] || i > 2) {
			possible_events = 0;
		}*/
		i++;
	}

    }
  return(0);
}


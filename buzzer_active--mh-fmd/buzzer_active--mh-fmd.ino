/*Example Code for YL-44 Active buzzer
  Connect Vcc to 5 volts
  Connect Gnd to Gnd
  Connect I/O to pin 3 */


int buzzer = 3 ;// connect the I/O pin on the buzzer to this


void setup ()
{
  pinMode (buzzer, OUTPUT) ;
}
void loop ()
{
  unsigned char i, j ;// define variables
  while (1)
  {
    for (i = 0; i < 3; i++)
    {
      digitalWrite (buzzer, LOW) ; // Turn buzzer ON
      delay (350) ;// Delay 1ms
      digitalWrite (buzzer, HIGH) ;// turn buzzer OFF
      delay (700) ;// delay ms
    }
    delay (300) ;// delay 2ms
    for (i = 0; i < 16; i++) // new frequency
    {
      digitalWrite (buzzer, LOW) ;// turn buzzer ON
      delay (60) ;// delay 2ms
      digitalWrite (buzzer, HIGH) ;// turn buzzer OFF
      delay (600) ;// delay 2ms
      digitalWrite (buzzer, LOW) ;// turn buzzer ON
      delay (8) ;// delay 2ms
      digitalWrite (buzzer, HIGH) ;// turn buzzer OFF
      delay (300) ;// delay 2ms
    }
    for (i = 0; i < 80; i++) // new frequency
    {
      digitalWrite (buzzer, LOW) ;// turn buzzer ON
      delay (2) ;// delay 2ms
      digitalWrite (buzzer, HIGH) ;// turn buzzer OFF
      delay (110) ;// delay 2ms
    }
     delay (300) ;// delay 2ms

  }
}


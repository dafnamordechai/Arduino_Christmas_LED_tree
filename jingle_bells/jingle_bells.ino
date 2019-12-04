const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880; 

const unsigned int first_notes[]  = {e, e, e, e, e, e, e, g, c, d, e};
const unsigned int sec_notes[]    = {f, f, f, f, f, e, 
                                     e, e, e, e,
                                     d, d, e, d, g};
const unsigned int third_notes[]  = {f, f, f, f, f, e, e, e, e, g, g, f, d, c };
const unsigned int first_dur[]    = {250, 250, 500, 
                                    250, 250, 500, 
                                    250, 250, 350, 100, 
                                    1000};
const unsigned int sec_dur[]      = {250, 250, 300, 250, 
                                    250, 250, 250, 250, 
                                    250, 250, 250, 250, 
                                    250, 500, 500};
const unsigned int third_dur[]    = {250, 250, 250, 250, 
                                    250, 250, 250, 125, 125, 
                                    250, 250, 250, 250, 
                                    1000 };
                                
// Leds
int counter = 0;
int buzzerPin = 9;
int GreenLEDs = 11; 
int RedLEDs_1 = 10;  
int RedLEDs_2 = 12;   
int OrangeLED = 13;                     
     
void buzzer_and_leds_setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(GreenLEDs, OUTPUT);
  pinMode(RedLEDs_1, OUTPUT);
  pinMode(RedLEDs_2, OUTPUT);
  pinMode(OrangeLED, OUTPUT);
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (Serial.available()) {}
  buzzer_and_leds_setup();
}

void loop()
{
  // Play Jingle Bells
  play_song(first_notes, first_dur, sizeof(first_notes)/sizeof(int));
  play_song(sec_notes,   sec_dur,   sizeof(sec_notes)/sizeof(int));
  play_song(first_notes, first_dur, sizeof(first_notes)/sizeof(int));
  play_song(third_notes, third_dur, sizeof(third_notes)/sizeof(int));
  delay(1000);
}

void play_song(int notes[], unsigned int duration[], unsigned int arr_size)
{
  for (int i=0; i<arr_size; i++)
  {
    beep(notes[i], duration[i]);
  }
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
  digitalWrite(GreenLEDs, HIGH);
  //Play different LED depending on value of 'counter'
  if(counter % 5 == 0)
  {
    digitalWrite(RedLEDs_1, HIGH);
    delay(duration);
    digitalWrite(RedLEDs_1, LOW);
  }
  else if (counter % 5 == 1)
  {
    digitalWrite(RedLEDs_2, HIGH);
    delay(duration);
  }
  else if (counter % 5 == 2)
  {
    digitalWrite(OrangeLED, HIGH);
    delay(duration);
  }
  else if (counter % 5 == 3)
  {
    digitalWrite(RedLEDs_1, HIGH);
    delay(duration);
  }
  else
  {
    delay(duration);
    digitalWrite(OrangeLED, LOW);
    digitalWrite(RedLEDs_2, LOW);
    digitalWrite(RedLEDs_1, LOW);
  }
  
  digitalWrite(GreenLEDs, LOW);
  //Stop tone on buzzerPin
  noTone(buzzerPin);
  
  //Increment counter
  counter++;
}

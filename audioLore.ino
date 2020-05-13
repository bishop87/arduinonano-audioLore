#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
 
TMRpcm tmrpcm;   // create an object for use in this sketch
int SW1; 
int SW2;
int SW3;
int SW4;
int SW5;
int SW6;
boolean debounce1=true;
boolean debounce2=true;
boolean debounce3=true;
boolean debounce4=true;
boolean debounce5=true;
boolean debounce6=true;

void setup(){
  Serial.begin(9600);
  
  pinMode(14,INPUT_PULLUP);  //Define A0 as digital input.
  pinMode(15,INPUT_PULLUP);  //Define A1 as digital input. 
  pinMode(16,INPUT_PULLUP);  //Define A2 as digital input.
  pinMode(17,INPUT_PULLUP);  //Define A3 as digital input.
  pinMode(18,INPUT_PULLUP);  //Define A4 as digital input.
  pinMode(19,INPUT_PULLUP);  //Define A5 as digital input.
  pinMode(5,OUTPUT);  
  pinMode(6,OUTPUT);  
  pinMode(7,OUTPUT);  
  pinMode(8,OUTPUT);  
  tmrpcm.speakerPin = 9;
  
  if (!SD.begin(SD_ChipSelectPin)) { 
    Serial.println("SD fail");
    return;
  }
  tmrpcm.quality(1);
  tmrpcm.setVolume(5);
  tmrpcm.play("start.WAV"); 
}

char *songs[] = { "1.WAV","2.WAV","3.WAV","4.WAV","5.WAV","6.WAV","7.WAV"};
int song = 0;

void loop(){  
  SW1=digitalRead(14); //clacson volante
  SW2=digitalRead(15); //leva
  SW3=digitalRead(16);
  SW4=digitalRead(17);
  SW5=digitalRead(18);
  SW6=digitalRead(19);
  
  if (SW1 == LOW && debounce1 == true) 
  { 
    debounce1 = false;
    
    Serial.println(song);
    tmrpcm.play(songs[song]);

    if(song >= 6) song = 0;
    else song++;
    
  } else if(SW2 == LOW && debounce2 == true)
  { 
    debounce2 = false;
    tmrpcm.play("gear.WAV");
  } else if(SW3 == LOW && debounce3 == true)
  { 
    debounce3 = false;
    digitalWrite(5, HIGH);
    tmrpcm.play("1.WAV");
  } else if(SW4 == LOW && debounce4 == true)
  { 
    debounce4 = false;
    digitalWrite(6, HIGH);
    tmrpcm.play("2.WAV");
  } else if(SW5 == LOW && debounce5 == true)
  {
    debounce5 = false; 
    digitalWrite(7, HIGH);
    tmrpcm.play("3.WAV");
  } else if(SW6 == LOW && debounce6 == true)
  {
    debounce6 = false; 
    digitalWrite(8, HIGH);
    tmrpcm.play("4.WAV");
    
  }

  if(tmrpcm.isPlaying()==0){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  
  if (SW1 == HIGH) debounce1=true;
  if (SW2 == HIGH) debounce2=true;
  if (SW3 == HIGH) debounce3=true;
  if (SW4 == HIGH) debounce4=true;
  if (SW5 == HIGH) debounce5=true;
  if (SW6 == HIGH) debounce6=true;


}

/************************************************* ************************************************** ******
* OPEN-SMART Rich UNO R3 Lesson 16: Touch control MP3
NOTE!!! First of all you should download the voice resources from our google drive:
https://drive.google.com/drive/folders/0B6uNNXJ2z4CxaXFpakMxR0p1Unc?usp=sharing

Then unzip it and find the 01 and 02 folder and put them into your TF card (should not larger than 32GB). 

* You can learn how to use the 4-channel touch sensor to control the MP3, 
* such as play / pause / next song / previous song operations.
*
* The following functions are available:

* touch.get(); // return is the touch area corresponding Arduino pin number, if not then return -1
* touch.getLongPress(); // return long press the corresponding Arduino pin number, if not return -1

/--------basic operations---------------/
mp3.play();
mp3.pause();
mp3.nextSong();
mp3.previousSong();
mp3.volumeUp();
mp3.volumeDown();
mp3.forward();    //fast forward
mp3.rewind();     //fast rewind
mp3.stopPlay();  
mp3.stopInject(); //when you inject a song, this operation can stop it and come back to the song befor you inject
mp3.singleCycle();//it can be set to cycle play the currently playing song 
mp3.allCycle();   //to cycle play all the songs in the TF card
/--------------------------------/

mp3.playWithIndex(int8_t index);//play the song according to the physical index of song in the TF card

mp3.injectWithIndex(int8_t index);//inject a song according to the physical index of song in the TF card when it is playing song.

mp3.setVolume(int8_t vol);//vol is 0~0x1e, 30 adjustable level

mp3.playWithFileName(int8_t directory, int8_t file);//play a song according to the folder name and prefix of its file name
                                                            //foler name must be 01 02 03...09 10...99
                                                            //prefix of file name must be 001...009 010...099

mp3.playWithVolume(int8_t index, int8_t volume);//play the song according to the physical index of song in the TF card and the volume set

mp3.cyclePlay(int16_t index);//single cycle play a song according to the physical index of song in the TF

mp3.playCombine(int16_t folderAndIndex[], int8_t number);//play combination of the songs with its folder name and physical index
      //folderAndIndex: high 8bit is folder name(01 02 ...09 10 11...99) , low 8bit is index of the song
      //number is how many songs you want to play combination

************************************************** **************************************************/

#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTouchSensor.h"
#include "RichUNOMP3.h"

#define MP3_RX 7
#define MP3_TX 8
MP3 mp3(MP3_RX, MP3_TX);

#define TOUCH_OUT1 3//out1-TCH1 area corresponds to play song operation
#define TOUCH_OUT2 4//out2-TCH2 area corresponds to pause operation
#define TOUCH_OUT3 5//out3-TCH3 area corresponds to next song operation
#define TOUCH_OUT4 6//out4-TCH4 area corresponds to previous song operation
TouchSensor touch(TOUCH_OUT1,TOUCH_OUT2, TOUCH_OUT3,TOUCH_OUT4);


int8_t volume = 0x1a;//0~0x1e (30 adjustable level)
int8_t folderName = 0x01;//folder name must be 01 02 03 04 ...
int8_t fileName = 0x01; // prefix of file name must be 001xxx 002xxx 003xxx 004xxx ...

void setup()
{
  mp3.setVolume(volume);
  delay(50);//you should wait for >=50ms between two commands
  mp3.playWithFileName(folderName,fileName);
  delay(50);
}

void loop()
{
  int button;
  button = touch.get();
  if(button != -1)// there is a touch
  {
    delay(10);
	if(button == touch.get())// Check again if there is a touch
	{
	  switch(button)
	  {
	    case TOUCH_OUT1: mp3.play();break;//touch TCH1 area 
		case TOUCH_OUT2: mp3.pause();break;//touch TCH2 area 
		case TOUCH_OUT3: mp3.nextSong();
						 break;//touch TCH3 area
		case TOUCH_OUT4: mp3.previousSong();
		                 break;//touch TCH4 area
		default: break;
	  }
	}
	while(button == touch.get());//Wait for the button to be released
  }
  delay(50);//
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/

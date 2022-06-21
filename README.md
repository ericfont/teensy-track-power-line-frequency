# teensy-track-power-line-frequency
a simple test program to measure the frequency of the AC power

[Example circuit for input pins 22 & 23](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAWwosgoFMBaMMAKACURttCRieueAFjxRRg2tmhVaM6AnYgUeEZhSKUgxRjW0IhWjtEx5AJ07dFCfhbAYeu+HBYB5cz1tCw7u0YUDFym6cCIa04iAMktJGcixm-h5BfKJgjpAsAGYBKtpBqpxq0rAoLOJUgthqzGp4XorhEgD6eI2QjeLELQitsPBkhFYo3UyNrGUReLpgahoGDeDNre2QnY0ocj2O02gYkNjTw2Bro43YLEA):

![image](https://user-images.githubusercontent.com/6502474/174726806-e0d2db54-ada4-48da-bfef-c0aeaaab3b4f.png)

real measurement of the pin in blue on an oscilloscope:

![16557915647504183367485745986408](https://user-images.githubusercontent.com/6502474/174727906-110cbb21-c84c-4f8a-8ec3-8e6cf594aff9.jpg)

and my breadboard uses a -3.3V power rail in white which is generated uskng a 7660 IC with those big electrolytic capacitors.  I'm using the metal plates which come from the back of the breadboard to gather the 60Hz power line signal, via parasitic (in this case useful) capacitance with the wall power lines:

![16557917376291756917279469647811](https://user-images.githubusercontent.com/6502474/174728317-a37479c3-8505-4e1e-8053-e6855d5dec34.jpg)

BTW, I'm using Teensy 4.1's interal 100k ohm pull-up resistor, so I only need to use one other 100k ohm resistor for each 2n7000.

Every second this program will output the percent difference from 60 Hz, measured on pin 22 and measured on pin 23.  This can be averaged and put into a chart in a spreadsheet editor:

![image](https://user-images.githubusercontent.com/6502474/174726759-041743dc-8ca8-48f1-9d19-d7685479f18f.png)

You can simultaneously watch the output of the program while viewing http://fnetpublic.utk.edu/frequencymap.html which shows the realtime status of the power grid frequency. They were in agreement for me (my teensy output produces the output quicker than that webpage can, so the webpage naturally lagged).

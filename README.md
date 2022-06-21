# teensy-track-power-line-frequency
a simple test program to measure the frequency of the AC power

[Example circuit for input pins 22 & 23](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAWwosgoFMBaMMAKACURttCRieueAFjxRRg2tmhVaM6AnYgUeEZhSKUgxRjW0IhWjtEx5AJ07dFCfhbAYeu+HBYB5cz1tCw7u0YUDFym6cCIa04iAMktJGcixm-h5BfKJgjpAsAGYBKtpBqpxq0rAoLOJUgthqzGp4XorhEgD6eI2QjeLELQitsPBkhFYo3UyNrGUReLpgahoGDeDNre2QnY0ocj2O02gYkNjTw2Bro43YLEA):

![image](https://user-images.githubusercontent.com/6502474/174726806-e0d2db54-ada4-48da-bfef-c0aeaaab3b4f.png)

Every second this program will output the percent difference from 60 Hz, measured on pin 22 and measured on pin 23.  This can be averaged and put into a chart in a spreadsheet editor:

![image](https://user-images.githubusercontent.com/6502474/174726759-041743dc-8ca8-48f1-9d19-d7685479f18f.png)

You can simultaneously watch the output of the program while viewing http://fnetpublic.utk.edu/frequencymap.html which shows the realtime status of the power grid frequency.

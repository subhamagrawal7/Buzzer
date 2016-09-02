## import the serial library
import serial





## Boolean variable that will represent 
## whether or not the arduino is connected
connected = False

## establish connection to the serial port that your arduino 
## is connected to.

locations=['/dev/ttyACM0','/dev/ttyACM1','/dev/ttyACM2','/dev/ttyACM3','/dev/ttyACM4','/dev/ttyACM5','/dev/ttyACM6','/dev/ttyACM7','/dev/ttyACM8','/dev/ttyACM9']

for device in locations:
    try:
        print "Trying...",device
        ser = serial.Serial(device, 9600)
        break
    except:
        print "Failed to connect on",device

## loop until the arduino tells us it is ready
while not connected:
    #serin = ser.read()
	print("Conneccted")
	connected = True

## open text file to store the current 
##gps co-ordinates received from the rover    
## read serial data from arduino and 
## write it to the text file 'position.txt'
while 1:
    if ser.inWaiting():
        x=ser.readline()
        print(x) 
	text_file = open("data_trial.txt", 'w')
	text_file.write(x)
	text_file.close()


	
	text_file = open("data_trial.txt", 'r+')

	res = text_file.read()
	text_file.close()
	

	
	print(res)
	
	t = 0
	while t < 999999:
		t+=1 



## close the serial connection and text file

ser.close()

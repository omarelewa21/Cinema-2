import serial

ser = serial.Serial()
ser.baudrate = 9600
ser.port = "COM9"
ser.open()
ser.write(1111)

#print(int.from_bytes(output, byteorder='big'))

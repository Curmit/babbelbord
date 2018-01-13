import processing.serial.*; // use serial port libraries
Serial myPort; // make a fresh serial port
void setup()
{
  println(Serial.list()); // show the available serial ports
  myPort = new Serial(this, Serial.list()[1], 9600); // open port 0 in the list
  //at 9600 Baud
}
void draw()
{
  if (myPort.available()>0) { // when there is incoming serial data
    print((char)myPort.read()); // output data to the text console
  }
}
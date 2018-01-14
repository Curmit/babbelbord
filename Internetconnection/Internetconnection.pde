import processing.serial.*; // use serial port libraries
import processing.net.*; 
import http.requests.*;

int category;
Serial myPort; // make a fresh serial port
void setup()
{
  println(Serial.list()); // show the available serial ports
  myPort = new Serial(this, Serial.list()[1], 9600); // open port 0 in the list
}
void draw()
{
  while (myPort.available() > 0) {
    String inBuffer = myPort.readString();   
    if (inBuffer != null) {
      postRequest(inBuffer.trim());
    }
  }
}

void postRequest(String message) {
  PostRequest post = new PostRequest("https://babbelbord.herokuapp.com/api/category/");
  post.addHeader("Content-Type", "application/json");
  post.addJson("{\"name\": \"" + message + "\"}");
  post.send();
  System.out.println("Reponse Content:" + post.getContent() + "\n");
  System.out.println("Reponse Content-Length Header: " + post.getHeader("Content-Length"));
}
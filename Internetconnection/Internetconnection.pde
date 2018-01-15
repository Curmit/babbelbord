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
  //postRequest("Both pawns are at gaan");
  while (myPort.available() > 0) {
    String inBuffer = myPort.readString();   
    if (inBuffer != null) {
      String inBuffer2 = inBuffer.trim();
      postRequest(inBuffer2);  // I tried to remove the .trim() function, seemed like it was cutting the String! Check!
    }
  }
}

void postRequest(String message) {
  PostRequest post = new PostRequest("https://babbelbord.herokuapp.com/api/category/");
  post.addHeader("Content-Type", "application/json");

  if (message.equals("Familie") || 
    message.equals("Liefde") || 
    message.equals("Tienertijd") || 
    message.equals("Kindertijd") || 
    message.equals("Hobby")) {
    post.addJson("{\"name\": \"" + message + "\"}");
  } else {
    post.addJson("{\"special\": \"" + message + "\"}");
  }  

  post.send();
  System.out.println("Response Status Code:" + post.getStatusCodeHTTP());
  System.out.println("Response Content:" + post.getContent());
  System.out.println("Response Content-Length Header: " + post.getHeader("Content-Length") + "\n");
}
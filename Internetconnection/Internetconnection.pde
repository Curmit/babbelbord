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
      postRequest(inBuffer);  // I tried to remove the .trim() function, seemed like it was cutting the String! Check!
    }
  }
}

void postRequest(String message) {
  PostRequest post = new PostRequest("https://babbelbord.herokuapp.com/api/category/");
  post.addHeader("Content-Type", "application/json");
  
  if(message.equals("Familie") || 
    message.equals("Liefde") || 
    message.equals("Tienertijd") || 
    message.equals("Kindertijd") || 
    message.equals("Hobby")){
    post.addJson("{\"name\": \"" + message + "\"}");
  } else if(
    message.equals("Het is je geluksdag er gebeurt niks") ||
    message.equals("Ga terug naar je vorige kleurvak") ||
    message.equals("Verwijder een verdiende kleurkaart") ||
    message.equals("Geef de laast verdiende kaart aan de vorige speler")){
    post.addJson("{\"special\": \"" + message + "\"}");
  } else {
    post.addJson("{\"error\": \"" + message + "\"}");
  }
  
  post.send();
  System.out.println("Response Content:" + post.getContent() + "\n");
  System.out.println("Response Content-Length Header: " + post.getHeader("Content-Length"));
}
import processing.serial.*; // use serial port libraries
import processing.net.*; 
import http.requests.*;

int category;
String saveCategory;
Serial myPort; // make a fresh serial port
int statusCode;
String oldBuffer;
boolean firstContact = false;
String val;



void setup()
{
  println(Serial.list()); // show the available serial ports
  myPort = new Serial(this, Serial.list()[1], 9600); // open port 0 in the list
  myPort.bufferUntil('\n');
}
void draw()
{

  while (myPort.available() > 0) {
    String inBuffer = myPort.readString();  
    println(inBuffer);
    if (inBuffer != null) {

      // TODOCHECK LENGTH OF STRING 
      println("Stringlength :" + inBuffer.length());
      String inBuffer2 = inBuffer.trim();
      postRequest(inBuffer2, 0); 

      println(statusCode); // status code returned from post request
        }
      }
    }


    //void serialEvent( Serial myPort) {
    //  //put the incoming data into a String - 
    //  //the '\n' is our end delimiter indicating the end of a complete packet
    //  val = myPort.readStringUntil('\n');
    //  //make sure our data isn't empty before continuing
    //  if (val != null) {
    //    //trim whitespace and formatting characters (like carriage return)
    //    val = trim(val);
    //    println(val);

    //    //look for our 'A' string to start the handshake
    //    //if it's there, clear the buffer, and send a request for data
    //    if (firstContact == false) {
    //      if (val.equals("A")) {
    //        myPort.clear();
    //        firstContact = true;
    //        myPort.write("A");
    //        println("contact");
    //      }
    //    } else { //if we've already established contact, keep getting and parsing data
    //      println(val);
    //      println("Stringlength :" + val.length());
    //      postRequest(val); 
    //      if (statusCode == 200 ){
    //         myPort.write('G'); //Perfect! GOOD
    //      } 
    //        myPort.write('B');// BAd request

    //    }
    //  }
    //}









    void postRequest(String message, int i) {
      PostRequest post = new PostRequest("https://babbelbord.herokuapp.com/api/category/");
      post.addHeader("Content-Type", "application/json");
      saveCategory = message;
      
      System.out.println("Data recieved");

      if (message.equals("Familie") || 
        message.equals("Liefde") || 
        message.equals("Tienertijd") || 
        message.equals("Kindertijd") || 
        message.equals("Hobby")) {
        post.addJson("{\"name\": \"" + message + "\"}");
      } else {
        post.addJson("{\"special\": \"" + message + "\"}");
      }  


      System.out.println(message);
      System.out.println("Posting to server");
      post.send();
      //IF ERROR MESSAGE (HTTP  CODE RESENT DATA
      statusCode = post.getStatusCodeHTTP();
      
      System.out.println(statusCode);
      
      if(i<50){
        statusCode = 404;
      }
      
      if(statusCode == 404 && i< 999){
        postRequest(saveCategory, i++);
      }
      System.out.println(statusCode + "  "  + "Loop: " + i);
      System.out.println("Response Status Code:" + statusCode );
      System.out.println("Response Content:" + post.getContent());

      System.out.println("Response Content-Length Header: " + post.getHeader("Content-Length") + "\n");
    }
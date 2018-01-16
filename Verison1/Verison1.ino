
//row1:White-cable: Gaan,familie, liefde, Het is je gelukdsag, tienertijd
//row2:           :Kindertijd,Hobby,Familie,Liefde,Ga terug naar je vorige kleurvak
//row3:           :Tienertijd,Kindertijd,Hobby,Familie,Liefde
//row4:           :Verwijder een verdiende kleurkaart,Tienertijd,Kindertijd,Hobby,Familie
//row5:           :Liefde,Geef de laast verdiende kaart aan de vorige speler,Tienertijd,Kindertijd,Hobby





//row 1:
//------/  ----/ ----/ ------/  ---/  -----
//row2  |       |     |       |     |
//------/  ----/ ----/ ------/  ---/  -----
//row3  |       |     |       |     |
//------/  ----/ ----/ ------/  ---/  -----
//row 4 |       |     |       |     |
//------/  ----/ ----/ ------/  ---/  -----
//row5  |       |     |       |     |
//------/  ----/ ----/ ------/  ---/  -----
//      |       |     |       |     |
//      col1    col2   col 3   col4  col 5


// Babbelboard
// Global variables
#define DELAY 2000
#define CHECKRIGHT 4000


// Multiple demensional array representing positions on the babbel board

// pins for inputs and outputs
int row[6] = {0, 25, 23, 22, 52, 53};
int column[6] = {0, 50, 48, 46, 44, 42};

//Counters for the buttons and time
int count = 0;// counter for how many time has passed
int count2 = 0; // counter for the button
int Interval; // Timer for interval
int start = 0; // Counting when pawn is at start

//Used for analysing the data, all the arrays start at 1
int DataNew[6][6] = { 0 };//  Used to save the most updated changes on the board
int DataOld[6][6] = { 0 }; // Used to save the position if the pawn is placed
int CheckData[6][6] = { 0 }; // To check former position witht he new position
int FinalCheck[6][6] = { 0 };// Save the final position and map to category
String category;// Category sent to server
int statusCode = 0;// a variable to read incoming serial data into

//Categories
String OldCategory = {};

void setup() {
  //columns for inputs
  pinMode(42, INPUT);
  pinMode(44, INPUT);
  pinMode(46, INPUT);
  pinMode(48, INPUT);
  pinMode(50, INPUT);


  // row/ outputs
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);

  // just for testing rows
  digitalWrite(52, HIGH);
  digitalWrite(53, HIGH);
  digitalWrite(25, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);

  Serial.begin(9600);
 

}




//    if (statusCode == 404 ||  statusCode == 400 ) {
//      Serial.println(OldCategory);
//
//    }
//    else {
//      Serial.println("Arduino" + statusCode);
//      // Read position and sent position
//    }

void loop() {
  readPosition();
}




















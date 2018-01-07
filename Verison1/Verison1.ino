


//row 1:White: start,familie, liefde, Het is je gelukdsag, tienertijd
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
#define DELAY 1000


// Multiple demensional array representing positions on board
int row[6] = {0, 25, 23, 22, 52, 53};
int column[6] = {0, 50, 48, 46, 44, 42};
int count = 0;
int count2=0;
int DataOld[6][6] = { 0 }; // Zero is not used,
int DataNew[6][6] = { 0 };
int CheckData[6][6] = { 0 }; //Final positions
int FinalCheck[6][6] = { 0 };
int Interval;
String category;
String oldCategory;

void setup() {
  pinMode(42, INPUT);
  pinMode(44, INPUT);
  pinMode(46, INPUT);
  pinMode(48, INPUT);
  pinMode(50, INPUT);

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
  //Serial.println("1:\t2:\t3:\t4:\t5:");
}

void loop() {
  readPosition();


}






















//Positions get read from the board in DataNew and saved later DataOld.This data is compared, if the
//old positions are still the same as befor. If the positions is not changed after a certain time the positions is detected
//and sent to the wifi connection. After this processboth the DateNew and DataOld are reset

// Reads dataNew

void readPosition() {
  // put your main code here, to run repeatedly:
  int temp[5] = {0};

  for (int i = 1; i < 6; i++) {// Outputs(rows)
    digitalWrite(row[i], HIGH);
    for (int j = 1; j < 6; j++) { // Inputs(column)
      DataNew[i][j] = digitalRead(column[j]);
    }
    digitalWrite(row[i], LOW);
  }
 
}


void printPositions(){
for (int i = 1; i < 6; i++) {// Outputs(rows)
    for (int j = 1; j < 6; j++) { // Inputs(column)
      Serial.print(i);
      Serial.print(DataNew[i][j]);
    }
    Serial.println();
  }
 delay(1000);
 Serial.println();
  
}


// Compare position before saving

void saveOldPosition() {



}



void TimeCheck() {
  Serial.println("checkie checkkie");

}

void ResetPositions() {


}

void ifSamePosition() {


}




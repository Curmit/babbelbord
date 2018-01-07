//Positions get read from the board in DataNew and saved later DataOld.This data is compared, if the
//old positions are still the same as befor. If the positions is not changed after a certain time the positions is detected
//and sent to the wifi connection. After this processboth the DateNew and DataOld are reset

// Reads dataNew



int CompareFormerPositionWithNewPosition() {
  //Check if data equal
  int locations = 0;// amount of locations
  count2 = 0;
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      if ( DataOld[i][j] == CheckData[i][j]) {
        count2++;
        //Serial.println("grrrrrr");
      }
      CheckData[i][j] = DataOld[i][j];
      if ( DataOld[i][j] == HIGH) {
        locations++;
        //Serial.println("Hi I am here");
      }
    }
  }
  return locations;
}

void IntervalCheck( int locations) {


  // Interval moet nog een positie krijgen en gedefinieerd worden

  if (count2 == 25)// Because of 25 positions
    //0,1,2
  {
    // Timer for intervals
    if (Interval < DELAY && locations > 0)// Milisecond for checking
    {
      Interval++;
    }
    if (Interval == DELAY) {

      Serial.println(locations);

      //If pawns are on the same position
      if (locations == 1) {
        PositionToNewCategory();
        memcpy(FinalCheck, CheckData, sizeof(CheckData));

      }

      if (locations == 2) {

        for (int i = 1; i < 6; i++) {
          for (int j = 1; j < 6; j++) {
            if ( FinalCheck[i][j] != CheckData[i][j]) {
              FinalCheck[i][j] = HIGH;

            }
            else
            {
              if (CheckData[i][j] == HIGH)
              {
                FinalCheck[i][j] = LOW;
              }
            }
          }
        }

        PositionToNewCategory();

      }


      Interval = DELAY + 1; // Random getal dat groter is dan DELAY om hem maar 1 keer te laten doen
    }
  }
  else
  {
    Interval = 0;
  }
}


void resetData() {
  int EmptyArray[6][6] = {0};
  memcpy(DataOld, EmptyArray, sizeof(EmptyArray));

}


// Compare position before saving
void compareOldandNewPos(int i, int j) {
  DataOld[i][j] = DataOld[i][j] | DataNew[i][j];// COMPARE OLD AND NEW POSITIONS

}

void TimeCheck() {
  int locations;
  //How many locations do I have?
  locations = CompareFormerPositionWithNewPosition();
  //Serial.print(locations);
  //Serial.println(count2);

  IntervalCheck( locations);

}



void readPosition() {
  for (int i = 1; i < 6; i++) {// Outputs(rows)
    digitalWrite(row[i], HIGH);
    for (int j = 1; j < 6; j++) { // Inputs(column)
      DataNew[i][j] = digitalRead(column[j]);
      compareOldandNewPos(i, j);
    }
    digitalWrite(row[i], LOW);

  }
  count = count + 1;
  if (count = 20000) {// If he checked N times of the board, let him check if the interval is the same
    count = 0;
    // Serial.println("Horay, we checked the board");



    TimeCheck();
    resetData();
  }

}


void printNewData() {
  Serial.println("New position");
  for (int i = 1; i < 6; i++) {// Outputs(rows)
    Serial.print(i);
    for (int j = 1; j < 6; j++) { // Inputs(column)
      Serial.print(DataNew[i][j]);
    }
    Serial.println();
  }

  Serial.println(" 12345");
  Serial.println();
  delay(3000);

}




void printOldData() {
  Serial.println("Old position");
  for (int i = 1; i < 6; i++) {// Outputs(rows)
    Serial.print(i);
    for (int j = 1; j < 6; j++) { // Inputs(column)
      Serial.print(DataOld[i][j]);
    }
    Serial.println();
  }

  Serial.println(" 12345");
  Serial.println();
  delay(3000);
}



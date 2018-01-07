//Here is the the position to the fitting category and sent to the server

//Uses global variable CHECK

void DataToPosition() {





}

void PrintPosition() {


}

//TODO: Replace DataNew[][]
//TODO: UPDATE STRING OLD CATEGORY AND NEW CATEGORY, Such that i can sent the old category and new category
void PositionToNewCategory(){

  for (int i = 1; i < 6; i++) {// Outputs(rows)
    for (int j = 1; j < 6; j++) { // Inputs(column)
      if (FinalCheck[i][j] == HIGH) {
        switch (i) {
          case 1:
            switch (j) {
              case (1):
                Serial.println("Start");
                break;
              case (2):
                Serial.println("Familie");
                break;
              case (3):
                Serial.println("Liefde");
                break;
              case (4):
                Serial.println("Het is je geluksdag er gebeurt niks");
                break;
              case (5):
                Serial.println("Tienertijd");
                break;

            }
            break;
          case 2:
            switch (j) {
              case (1):
                Serial.println("Kindertijd");
                break;
              case (2):
                Serial.println("Hobby");
                break;
              case (3):
                Serial.println("Familie");
                break;
              case (4):
                Serial.println("Liefde");
                break;
              case (5):
                Serial.println("Ga terug naar je vorige kleurvak");
                break;

            }
            break;



          case 3:
            switch (j) {
              case (1):
                Serial.println("Tienertijd");
                break;
              case (2):
                Serial.println("Kindertijd");
                break;
              case (3):
                Serial.println("Hobby");
                break;
              case (4):
                Serial.println("Familie");
                break;
              case (5):
                Serial.println("Liefde");
                break;

            }
            break;

          case 4:
            switch (j) {
              case (1):
                Serial.println("Verwijder een verdiende kleurkaart ");
                break;
              case (2):
                Serial.println("Tienertijd");
                break;
              case (3):
                Serial.println("Kindertijd");
                break;
              case (4):
                Serial.println("Hobby");
                break;
              case (5):
                Serial.println("Familie");
                break;

            }
            break;
          case 5:
            switch (j) {
              case (1):
                Serial.println("Liefde ");
                break;
              case (2):
                Serial.println("Geef de laast verdiende kaart aan de vorige speler");
                break;
              case (3):
                Serial.println("Tienertijd");
                break;
              case (4):
                Serial.println("Kindertijd");
                break;
              case (5):
                Serial.println("Hobby");
                break;

            }
            break;
        }

      }
    }
  }
}


void PrintCategory(int x, int y) {


}

void SendDataToServer() {


}




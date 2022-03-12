#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_NUM_CEREALS = 100;

struct cereal{
  enum {MAX_NAME_LEN=100};
  char name[MAX_NAME_LEN];
  double calories;
  double gramsofProtein;
  double gramsofFat;
  double gramsofSodium;
  double gramsofFiber;
  double gramsofCarbs;
  double gramsofSugar;
  double cupsPerServing;
  cereal();
};

cereal::cereal(){
  for(int index = 0; index < MAX_NUM_CEREALS; index++){
    name[index]=0;
  }
  calories = 0;
  gramsofProtein = 0;
  gramsofFat = 0;
  gramsofSodium = 0;
  gramsofFiber = 0;
  gramsofCarbs = 0;
  gramsofSugar = 0;
  cupsPerServing = 0;
}

void printCereal(ostream &out, cereal cerealList){
    out << cerealList.name << ";";
    out << cerealList.calories << ";";
    out << cerealList.gramsofProtein << ";";
    out << cerealList.gramsofFat << ";";
    out << cerealList.gramsofSodium << ";";
    out << cerealList.gramsofFiber << ";";
    out << cerealList.gramsofCarbs << ";";
    out << cerealList.gramsofSugar << ";";
    out << cerealList.cupsPerServing << endl;
}

void printArrayToScreen(cereal cerealList[], int numCereals) {
    for (int index = 0; index < numCereals; index++) {
        cout << "Index " << index << ": ";
        printCereal(cout, cerealList[index]);
    }
}

void printArrayToFile(const char fileName[], cereal cerealList[], int numCereals) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCereals; index++) {
        printCereal(outFile, cerealList[index]);
    }
}

cereal readCereal(ifstream &inFile){
    cereal singleCereal; 
    inFile.get(singleCereal.name, cereal::MAX_NAME_LEN, ';');
    inFile.ignore(100,';');
    inFile >> singleCereal.calories;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofProtein;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofFat;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofSodium;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofFiber;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofCarbs;
    inFile.ignore(100,';');
    inFile >> singleCereal.gramsofSugar;
    inFile.ignore(100,';');
    inFile >> singleCereal.cupsPerServing;
    inFile.ignore(100,'\n');

    return singleCereal;
}

int readCerealData(cereal cerealList[]){
ifstream cerealFile("cereal.txt");
    int numCereals = 0;
    while(cerealFile.peek() != EOF && numCereals < MAX_NUM_CEREALS) {
        cerealList[numCereals] = readCereal(cerealFile);
        numCereals++;
    }
    return numCereals;
  //returns how many cereals are read.
  }
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

double readDouble(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

void addCereal(cereal cerealList[], int index){
      cout << "Enter the name of the cereal you want to add:" << endl;
      cin.ignore(11,'\n'); cin.getline(cerealList[index].name,cereal::MAX_NAME_LEN);
      cerealList[index].calories = readDouble("Enter the amount of calories: ");
      cerealList[index].gramsofProtein = readDouble("Enter the grams of protein: ");
      cerealList[index].gramsofFat = readDouble("Enter the grams of fat: ");
      cerealList[index].gramsofSodium = readDouble("Enter the grams of sodium: ");
      cerealList[index].gramsofFiber = readDouble("Enter the grams of fiber: ");
      cerealList[index].gramsofCarbs = readDouble("Enter the grams of carbs: ");
      cerealList[index].gramsofSugar = readDouble("Enter the grams of sugar: ");
      cerealList[index].cupsPerServing = readDouble("Enter the amount of cups per serving: ");
      //cin.ignore(11,'\n');
      return;
        }


void removeCereal(cereal cerealList[], int numCereals){
  int removeIndex = 0;
  do{
  removeIndex = readInt("Enter an index to remove: ");
    for(int index = removeIndex; index < numCereals - 1; index++){
    cerealList[index] = cerealList[index + 1];
  }
}
while(removeIndex < 0 && removeIndex >= 100);
}

void printbyCalories(cereal cerealList[], int numCereals){
  for(int index = 0; index < numCereals; index++){
  if (cerealList[index].calories >= 100){
      printCereal(cout, cerealList[index]);
    }
    }
}

void returnMenu(cereal cerealList[], int numCereals){
  int userInput = 0;  
  while(userInput !=7){
      cout << "Choose a number option to continue or type quit." << endl;
      cout << "1. Reload database from the file." << endl;
      cout << "2. Print database." << endl;
      cout << "3. Add a new entry." << endl;
      cout << "4. Remove an entry." << endl;
      cout << "5. Print all cereals with less than an amount of calories." << endl;
      cout << "6. Save database to the file." << endl;
      cout << "7. Quit" << endl;
      cin >> userInput;

    if(userInput == 1){
    numCereals = readCerealData(cerealList);
    }
    if(userInput == 2){
    printArrayToScreen(cerealList, numCereals);  
    }
    if(userInput == 3){
      if(numCereals < 100){
        addCereal(cerealList, numCereals);
        numCereals++;
        }
      else{
        cout << "The database is full!" << endl;
        }
    }
    if(userInput == 4){
    removeCereal(cerealList, numCereals);  
      numCereals--;
    }
    if(userInput == 5){
    printbyCalories(cerealList, numCereals);  
    }
    if(userInput == 6){
    printArrayToFile("cereal1.txt", cerealList, numCereals);  
    }
    if(userInput == 7){
      cout << "You decided to quit.";
      break;
        }
}
  }



int main(){
  cereal cerealList[MAX_NUM_CEREALS];
  int numCereals = readCerealData(cerealList);

  
//readCerealData(cerealList);
returnMenu(cerealList, numCereals);
  
}
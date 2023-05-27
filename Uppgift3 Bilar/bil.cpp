#include "bil.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

vector<Cars> carlist;

void printCars(vector<Cars> carlist2) {
    for (Cars C : carlist2) {
        cout << C.regnr << " " << C.arsmodell << " " << C.marke << " " << C.servicedatum << " " << C.hyrpris << endl;
    }
}

void clearCar(vector<Cars>&carlist) {
    carlist.clear();
    
}
void addCar(vector<Cars>& carlist) {
    Cars car;
    cout << "Registreringsnummer: ";
    cin >> car.regnr;
    // Check if the car already exists in the list
    for (Cars existingCar : carlist) {
        if (existingCar.regnr == car.regnr) {
            cout << "En bil med detta registreringsnummer finns redan i listan." << endl;
            return;
        }
    }
    cout << "Arsmodell: ";
    cin >> car.arsmodell;
    cout << "Marke: ";
    cin >> car.marke;
    cout << "Servicedatum (YYYY-MM-DD): ";
    cin >> car.servicedatum;
    cout << "Hyrpris: ";
    cin >> car.hyrpris;
    carlist.push_back(car);
    cout << "Bilen har lagts till i listan." << endl;
}

void deleteCar() {
    vector<Cars>tempdeletecars;
    ifstream file("bilregister.txt");
    Cars tempdelete;
    string tempregnr;
    while (file >> tempdelete.regnr >> tempdelete.arsmodell >> tempdelete.marke >> tempdelete.servicedatum >> tempdelete.hyrpris) {
        tempdeletecars.push_back(tempdelete);
    }
    cout << "Ange vilket registreringsnummer på bil du vill ta bort: ";
    cin >> tempregnr;
    auto it = std::find_if(tempdeletecars.begin(), tempdeletecars.end(), [&](Cars& c) {return c.regnr == tempregnr;});
    if (it != tempdeletecars.end()) {
        tempdeletecars.erase(it);
        cout << "Tar bort bilen från registret";
    }
    else {
        cout << "Bilen kan inte hittas i registret";
    }
    ofstream outfile("bilregister.txt"); // overwrite the register with the updated vector
    for (Cars car : tempdeletecars) {
        outfile << car.regnr << " " << car.arsmodell << " " << car.marke << " " << car.servicedatum << " " << car.hyrpris << endl;
    }
    outfile.close();
}


void showCars() {
    vector<Cars>tempcars;
    Cars temp;
    ifstream file("bilregister.txt");
    while (file >> temp.regnr >> temp.arsmodell >> temp.marke >> temp.servicedatum >> temp.hyrpris) {
        tempcars.push_back(temp);
    }
    printCars(tempcars);
}

void saveCars(vector<Cars> carlist2) {
    Cars car;
    ofstream file("bilregister.txt", ios::app); // append to not overwrite in the register
    for (Cars car : carlist2) {
        file << car.regnr << " " << car.arsmodell << " " << car.marke << " " << car.servicedatum << " " << car.hyrpris << endl;
    } 
    file.close();
    clearCar(carlist);
}

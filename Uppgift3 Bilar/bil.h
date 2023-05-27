#pragma once
#include <string>
#include <iostream>
#ifndef BIL_H
#define BIL_H

#include <iostream>
#include <vector>
using namespace std;

class Cars {
public:
    string regnr;
    int arsmodell;
    string marke;
    string servicedatum;
    int hyrpris;
};

void setWesternEuropeanCodePage();

void addCar(vector<Cars>& carlist);
void showCars();
void saveCars(vector<Cars> carlist);
void printCars(vector<Cars> carlist);
void deleteCar();
#endif

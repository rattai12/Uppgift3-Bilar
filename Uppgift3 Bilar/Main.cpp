#include <iostream>
#include "bil.h"
#include <fstream>
#include <vector>
#include <windows.h>


extern vector<Cars> carlist;
using namespace std;

void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}


int main() {

	setWesternEuropeanCodePage();

    while (true) {

        
        
        cout << "1. Lista bilar" << endl;
        cout << "2. Lägg till ny bil" << endl;
        cout << "3. Ta bort bil" << endl;
		cout << "4. Spara bilar till registret" << endl;
        
		cout << "Alternativ: ";
		int menyval;
        cin >> menyval;

        switch (menyval)

        {

		case 1: {

			cout << "Menyval 1 \n Lista alla bilar" << endl;
			showCars();


		}break;
        case 2: {
			cout << "Menyval 2 \n Lägg till bil";
			addCar(carlist);
            }
              
			  break;


        case 3: {
            cout << "Menyval 3 \n Ta bort bil" << endl;
            deleteCar();
            }
              
			  break;
        case 4: {
			cout << "Menyval 4 \n Spara bilar" << endl;
			saveCars(carlist);
		}
	}
	


}
	


	
	
	return 0;
}


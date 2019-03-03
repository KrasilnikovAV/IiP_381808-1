#include <iostream>
#include <fstream>
#include <cstdbool>
#include "Decimal.h"


using namespace std;

int main() {
	Decimal a, b, c;
	cout << "Zdravstvuyte Sergey Nikolaevich. YA dolzhen byl delat' 5 zadachu, no vy \nrazreshili mne sdelat' 6. V uslovii trebovalos' hranit' chisla v massive, \nno eto ne udobno i nakladyvaet ogranicheniya po maksimal'noy dline. YA reshil \nispol'zovat' VECTOR i v hode programmy modificirovat' ego dlinu po \nneobhodimosti. Dlinu v takom sluchai hranit' ne obyazatel'no." << endl << endl;
	cout << "Vvedite 2 chisla lyuboy dlinny: ";
	cin >> a >> b;
	c = a + b;
	cout << "sum: " << c << endl << endl;
	c = a - b;
	cout << "raznost: " << c << "    //Esli raznost' ravna 0, znachit pervoe chislo men'she vtorogo" << endl << endl;
	cout << "a > b = " << (a > b) << endl;
	cout << "a < b = " << (a < b) << endl;
	cout << "a >= b = " << (a >= b) << endl;
	cout << "a <= b = " << (a <= b) << endl;
	cout << "a == b = " << (a == b) << endl;
	cout << "a != b = " << (a > b) << endl;
	getchar();
	getchar();
	return 0;
}
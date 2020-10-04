#include "GeneralPlayer.h"
#include "OrcPlayer.h"
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
//以下已包含在GeneralPlayer.h
//#include <iostream>
//#include <cstdlib>
//using namespace std;

int main() {

	GeneralPlayer G1;
	GeneralPlayer G2(3);
	GeneralPlayer G3(5, "AAA");
	GeneralPlayer G4(G3);
	GeneralPlayer G5(7, "BBB");

	cout << "G1: ";
	G1.display();

	/*測試設定經驗值使否成功升降級並重設成該等級屬性(set- & levelUp/levelDown- functions)
	G1.setExp(500);
	cout << "G1: ";
	G1.display();
	G1.setHP(10);
	cout << "G1: ";
	G1.display();
	G1.setMP(-1);
	cout << "G1: ";
	G1.display();*/

	/*測試增減經驗值使否成功升降級並重設成該等級屬性(increase- & set- & levelUp/levelDown- functions)
	G1.increaseExp(500);
	cout << "G1: ";
	G1.display();
	G1.increaseExp(-300);
	cout << "G1: ";
	G1.display();
	G1.increaseExp(-300);
	cout << "G1: ";
	G1.display();*/

	/*測試增減HP和MP
	G1.increaseHP(-30);
	cout << "G1: ";
	G1.display();
	G1.increaseHP(-300);
	cout << "G1: ";
	G1.display();
	G1.increaseHP(77);
	cout << "G1: ";
	G1.display();
	G1.increaseMP(-30);
	cout << "G1: ";
	G1.display();
	G1.increaseMP(-300);
	cout << "G1: ";
	G1.display();
	G1.increaseMP(33);
	cout << "G1: ";
	G1.display();*/

	/*測試constructor
	cout << "G2: ";
	G2.display();
	cout << "G3: ";
	G3.display();
	cout << "G4: ";
	G4.display();
	cout << "G5: ";
	G5.display();*/



	cout << "--------------------------------------------------------------------------------------------------------------------\n\n";

	OrcPlayer O1;
	OrcPlayer O2(3);
	OrcPlayer O3(5, "BBB");

	cout << "O1: ";
	O1.display();

	/*測試增減經驗值使否成功升降級並重設成該等級屬性
	O1.increaseExp(500);
	cout << "O1: ";
	O1.display();
	O1.increaseExp(-300);
	cout << "O1: ";
	O1.display();
	O1.increaseExp(-300);
	cout << "O1: ";
	O1.display();*/

	/*測試增減HP和MP
	O1.increaseHP(-30);
	cout << "O1: ";
	O1.display();
	O1.increaseHP(-300);
	cout << "O1: ";
	O1.display();
	O1.increaseHP(77);
	cout << "O1: ";
	O1.display();
	O1.increaseMP(-30);
	cout << "O1: ";
	O1.display();
	O1.increaseMP(-300);
	cout << "O1: ";
	O1.display();
	O1.increaseMP(33);
	cout << "O1: ";
	O1.display();*/

	/*測試constructor
	cout << "O2: ";
	O2.display();
	cout << "O3: ";
	O3.display();*/



	cout << "--------------------------------------------------------------------------------------------------------------------\n\n";

	KnightPlayer K1;
	KnightPlayer K2(3);
	KnightPlayer K3(5, "CCC–");

	cout << "K1: ";
	K1.display();

	/*測試增減經驗值使否成功升降級並重設成該等級屬性
	K1.increaseExp(500);
	cout << "K1: ";
	K1.display();
	K1.increaseExp(-300);
	cout << "K1: ";
	K1.display();
	K1.increaseExp(-300);
	cout << "K1: ";
	K1.display();*/

	/*測試增減HP和MP
	K1.increaseHP(-30);
	cout << "K1: ";
	K1.display();
	K1.increaseHP(-300);
	cout << "K1: ";
	K1.display();
	K1.increaseHP(77);
	cout << "K1: ";
	K1.display();
	K1.increaseMP(-30);
	cout << "K1: ";
	K1.display();
	K1.increaseMP(-300);
	cout << "K1: ";
	K1.display();
	K1.increaseMP(33);
	cout << "K1: ";
	K1.display();*/

	/*測試constructor
	cout << "K2: ";
	K2.display();
	cout << "K3: ";
	K3.display();*/



	cout << "--------------------------------------------------------------------------------------------------------------------\n\n";

	MagicianPlayer M1;
	MagicianPlayer M2(3);
	MagicianPlayer M3(5, "DDD");

	cout << "M1: ";
	M1.display();

	/*測試增減經驗值使否成功升降級並重設成該等級屬性
	M1.increaseExp(500);
	cout << "M1: ";
	M1.display();
	M1.increaseExp(-300);
	cout << "M1: ";
	M1.display();
	M1.increaseExp(-300);
	cout << "M1: ";
	M1.display();*/

	/*測試增減HP和MP
	M1.increaseHP(-30);
	cout << "M1: ";
	M1.display();
	M1.increaseHP(-300);
	cout << "M1: ";
	M1.display();
	M1.increaseHP(77);
	cout << "M1: ";
	M1.display();
	M1.increaseMP(-30);
	cout << "M1: ";
	M1.display();
	M1.increaseMP(-300);
	cout << "M1: ";
	M1.display();
	M1.increaseMP(33);
	cout << "M1: ";
	M1.display();*/

	/*測試constructor
	cout << "M2: ";
	M2.display();
	cout << "M3: ";
	M3.display();*/



	system("pause");
	return 0;
}
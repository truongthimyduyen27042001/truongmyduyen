#include "Function.h"
#include <iostream>
using namespace std;
void Function::Menu(StudentAccess& s) {
	cout << "MENU" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "|1.Student					|" << endl;
	cout << "|2.Staff			|" << endl;
	cout << "|3. contract			|" << endl;
	cout << "|4. Bill				|" << endl;
	cout << "|5. Room				|" << endl;
	cout << "|6. Thoat chuong trinh			|" << endl;
	cout << "------------------------------------------------------------------" << endl;
	int choose;
	cout << "Nhap lua chon cua ban : ";
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "Ban da lua chon bang Student" << endl;
		s.Init();
		s.Show();
		cout << "Ban co muon nhap bang hay khong ?" << endl;
		cout << "Nhap them : " << endl;
		s.Insert();
		s.Show();
		
		s.Close();
		break;

	case 2:
		cout << "Ban da lua chon Staff " << endl;
		break;
	case 3:
		cout << "Ban da lua chon Contract " << endl;
		break;
	case 4:
		cout << "Ban da lua chon Bill " << endl;
		break;
	case 5:
		cout << "Ban da lua chon Room " << endl;
		break;
	case 6:
		cout << "Ban da lua chon thoat chuong trinh " << endl;
		break;
	default:
		cout << "Ban nhap sai lenh!" << endl;
		break;
	}

}

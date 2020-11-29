#include "StudentAccess.h"
#include "Connect.h"
#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;
void StudentAccess::Select(Student*& s) {

	//output
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";

	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle,(SQLCHAR*)L"SELECT * FROM SINHVIEN", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
	
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char id[10];
		char name[50];
		char birth[50];
		char address[50];
		char number[50];
		int i = 0;
		while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
			SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
			SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);

			SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &birth, sizeof(birth), NULL);

			SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);

			SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &number, sizeof(number), NULL);
			
			Student* temp = new Student(id, name, birth, address, number);
			*(s + i) = *temp;
			i++;

		}
	}
	SQLCancel(SQLStatementHandle);

}
void StudentAccess::Insert() {
	string result = "INSERT INTO SINHVIEN VALUES( ";
	Student s;
	s.setStudent();
	result += s.insertQuerr();
	const char* SQLQuery = result.c_str();
	cout << SQLQuery << endl;
	Connect c;
	c.ExecuteDB(...);
	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "Loi khong the thuc hien duoc!" << endl;
		


	}
	else {
		cout << "Them Thanh Cong!" << endl;
		
	}
	SQLCancel(SQLStatementHandle);

}
void StudentAccess::Update() {
	//khai baos con trỏ biến Student , đổ hết dữ liệu từ sql qua bên mảng Student
	//tìm kiếm theo msv , 
	//update theo kiểu thứ mình muốn/ hàm countrow() thực hiện biến đếm thay vì show
	/*string msvchance;
	cout << "Nhap msv ban muon thay doi : ";
	cin.getline( msvchance);
	Student* prt = new Student[countrown];
	Select(prt);
	for (int i = 0; i < count..; i++) {
		if (choose == *(prt + i).msv) {
			cout << "Lua chonj thong tin ban muon thay doi!";

		}
	}*/
	return;
}
void StudentAccess::Delete() {
	return; 
}
void StudentAccess::Show() {
	//----thuc hien mo khoa 






	//if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)L"SELECT * FROM SINHVIEN", SQL_NTS)) {
	//	// Executes a preparable statement
	//	cout << "Loi khong the thuc hien duoc O HAM SHOW!" << endl;
	//}
	//else {
	//	char ID[10], name[20], birth[14], address[30], number[14];
	//	int i = 0;
	//	SQLINTEGER PtrSQLVersion;


	//	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
	//		// Fetches the next rowset of data from the resulthttps://scontent.fdad3-2.fna.fbcdn.net/v/t1.15752-9/127009530_713146689638372_5379688347519019394_n.png?_nc_cat=101&ccb=2&_nc_sid=ae9488&_nc_ohc=rDfQb_edneAAX8bgiTQ&_nc_ht=scontent.fdad3-2.fna&oh=ae1420082cb06f9f42d665ca5cf78299&oe=5FE3A911
	//		SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &ID, sizeof(ID), &PtrSQLVersion);
	//		SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &name, sizeof(name), NULL);
	//		SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &birth, sizeof(birth), NULL);
	//		SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &address, sizeof(address), NULL);
	//		SQLGetData(SQLStatementHandle, 5, SQL_CHAR, &number, sizeof(number), NULL);
	//		cout << setw(10) << left << ID << setw(20) << name << setw(15) << birth << setw(20) << address << setw(14) << number << endl;

	//		++i;
	//		if (i == MAX_ROW_SHOW) break;


	//	}

	//}
	//SQLCancel(SQLStatementHandle);

	//if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)L"SELECT * FROM SINHVIEN", SQL_NTS)) {
	//	// Executes a preparable statement
	///*	showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);*/
	//	cout << "Loi o ham show " << endl;
	//}
	char SQLQuery[] = "SELECT * FROM SINHVIEN";
	if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		// Executes a preparable statement
	/*	showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);*/
		cout << "Loi o ham show ";
	}


	else {
		cout << "Thuc hien duoc ham show"<<endl;
		char id[30], name[70], birth[14], address[50], number[20];
		int i = 0;
		cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|\t\t\t\t DANH SACH SINH VIEN KY TUC XA DA NANG					        	   |" << endl;
		cout << "+-----------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|" << setw(20) << left << "   Ma Sinh Vien    " << "|" << setw(30) << "    \tTen Sinh Vien" << "|" << setw(12) << "\tNgay Sinh" << "|" << setw(25) << "\tDia Chi" << "|" << setw(15) << "\tSo Dien Thoai" << endl;

		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;

		while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
			cout << "|";
			// Fetches the next rowset of data from the result
			SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
			SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);

			SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &birth, sizeof(birth), NULL);

			SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);

			SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &number, sizeof(number), NULL);


			// Retrieves data for a single column in the result set
			cout << "     " << setw(15) << left << id << "|    " << setw(30) << name << "|    " << setw(12) << birth << "|   " << setw(25) << address << "  |  " << setw(15) << number << "|" << endl;
			++i;
			if (i == MAX_ROW_SHOW) break;
		}
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;

	}

	SQLCancel(SQLStatementHandle);


}


//Gồm 3 tầng : tầng 1 (connect), tầng 2 (dataaccess) , tầng 3(student,studentaccess)

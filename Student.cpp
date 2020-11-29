#include "Student.h"
#include <iostream>
#include <stdio.h>
using namespace std;
#include <string>
#include <Windows.h>
#include <conio.h>
Student::Student() {
	strcpy_s(this->ID, " ");
	strcpy_s(this->name, " ");
	strcpy_s(this->birth, " ");
	strcpy_s(this->address, " ");
	strcpy_s(this->number, "  ");

}
Student::Student(char* id, char* name, char* birth, char* address, char* number) {
	strcpy_s(this->ID, 10, id);
	strcpy_s(this->name, 30, name);
	strcpy_s(this->birth, 20, birth);
	strcpy_s(this->address, 30, address);
	strcpy_s(this->number, 20, number);
}
Student::~Student() {

}
//char* Student::getID() {
//	return this->ID;
//}
//char* Student::getName() {
//	return this->name;
//}
//char* Student::getBirth() {
//	return this->birth;
//}
//char* Student::getAddress() {
//	return this->address;
//}
//char* Student::getNumberr() {
//	return this->number;
//}
//void Student::setID(char* id) {
//	strcpy_s(this->ID, 10, id);
//}
//void Student::setName(char* name) {
//		strcpy_s(this->name, 30, name);
//}
//void Student::setBirth(char* birth) {
//	strcpy_s(this->birth, 30, birth);
//}
//void Student::setAddress(char* address) {
//	strcpy_s(this->address, 30, address);
//}
//void Student::setNumberr(char* number) {
//	strcpy_s(this->number, 20, number);
//}
void Student::setStudent() {

	cout << "NHAP THONG TIN SINH VIEN" << endl;
	getchar();
	cout << "Insert ID : ";

	//cin.ignore();
	cin.getline(ID, 30);
	
	cout << "Insert Name : ";

	//cin.ignore();
	cin.getline(name, 30);
	cout << "Insert Birth: ";

	
	//cin.ignore();
	cin.getline(birth, 30);
	cout << "Insert Address : ";
	
	//cin.ignore();
	cin.getline(address, 30);
	cout << "Insert Number : ";

	//cin.ignore();
	cin.getline(number, 30);

}
string Student::insertQuerr() {
	string querry;
	string id(this->ID);
	string name(this->name);
	string birth(this->birth);
	string address(this->address);
	string number(this->number);
	querry = "'" + id + "','" + name + "','" + birth + "','" + address + "','" + number + "')";
	return querry;
}

// 03-01-SoftUniPopulation.cpp : Defines the entry point for the console application.
//
//#include "Person.cpp"
//#include "Student.cpp"
//#include "Faculty.cpp"
//#include "GuestFaculty.cpp"
//#include "stdafx.h"

#include "stdio.h"
#include <cstdlib>

#include<iostream>
#include <string>

//  get initial user input as a number 1-6
int FrontMenu() {

	//lets give them the options
	std::cout << "Welcome to SoftUni personel files" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Select your options:" << std::endl;
	std::cout << "1 - Get data for student with ID (0 – 6553)" << std::endl;
	std::cout << "2 - Get data for teacher with ID (0 – 6553)" << std::endl;
	std::cout << "3 - Get data for guest teacher with ID (0 – 6553)" << std::endl;
	std::cout << "4 - Add data for new student " << std::endl;
	std::cout << "5 - Add data for new teacher " << std::endl;
	std::cout << "6 - Add data for new guest teacher " << std::endl;
	
	std::string userChoice;	
    getline(std::cin, userChoice);

	int choice=0; // = atoi(userChoice.c_str());	

	if (userChoice=="1"|| userChoice == "2" || userChoice == "3" || userChoice == "4" || userChoice == "5" || userChoice == "6"  )
	{
		choice = atoi(userChoice.c_str());
		std::cout << "you have seleted " << choice << std::endl;
		return choice;
	}

	else {
		std::system("cls");
		std::cout<<"You have invalid input. Please make one of the choices below" << std::endl;
		userChoice.clear();
		std::cout << std::endl;
		//there is a bug in the int conversion after an invalid input.
		FrontMenu();
	}

}

//  based on user input, call relative fuction
void FrontMenuSwitch(int n)
{
	
	switch (n)
	{
	case 1:
		//call GetStudentInfo()
		std::system("cls");
		std::cout << "getting student info! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		break;
	case 2:
		std::system("cls");
		std::cout << "getting teacher info! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		//call GetFacultyInfo()
		break;
	case 3:
		std::system("cls");
		std::cout << "getting guest teacher info! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		//call GetGuestFacultyInfo()
		break;
	case 4:
		std::system("cls");
		std::cout << "lets add a new student! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		//call AddNewStudent()
		break;
	case 5:
		std::system("cls");
		std::cout << "lets add a new teacher! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		//call AddNewFaculty()
		break;
	case 6:
		std::system("cls");
		std::cout << "lets add a new guest teacher! Must finish writing this!" << std::endl;
		std::cout << std::endl;
		//call AddNewGuestFaculty()
		break;

	default:
		break;
	}
}

int main()
{
	int a = FrontMenu();
	std::cout << "you have seleted "<< a << std::endl;
	FrontMenuSwitch(a);

	return 0;
}



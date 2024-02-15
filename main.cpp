#include<iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

const int max_capacity = 40;
string pass = "welcome";
string password = "";
char choice;
const Cars car;

class Cars
{
public:		
	string manufacturer[max_capacity] = { "BMW", "BMW", "BMW", "Mercedes", "Audi", "Toyota", "Hyunday", "Peugeot" };
	string model[max_capacity] = { "X5", "530i", "320xd", "S500", "A3", "Corolla", "SantaFE", "308" };
	string color[max_capacity] = { "black", "grey", "black", "black", "white", "grey", "white", "grey" };
	string fuel[max_capacity] = { "diesel", "petrol", "diesel", "petrol", "petrol", "diesel", "diesel", "diesel" };
	string miles[max_capacity] = { "130000", "34000", "160000", "70000", "200000", "90000", "140000", "200000" };
	string year[max_capacity] = { "2016", "2020", "2017", "2018", "2012", "2019", "2021", "2008" };
	string price[max_capacity] = { "200", "180", "120", "240", "80", "100", "120", "60" };
};

void displayCar()
{
	cout << "\n\n\n\n";
	cout << setw(85) << "---------------------------------------------" << endl;
	cout << setw(80) << "Available Cars for Rent" << endl;
	cout << setw(85) << "---------------------------------------------" << endl;
	int num = (int)choice;
	cout << setw(85) << "Model: " << car.manufacter[num] << "\t\t" << car.model[num] << endl;
	cout << setw(85) << "Year: " << car.year[num] << "\tYear: " << car.color[num] << endl;
	cout << setw(85) << "Fuel: " << car.fuel[num] << "\tMiles: " << car.miles[num] << endl;
	cout << setw(85) << "Price: " << car.price[num] << endl;
}

void menu()
{
	cout << "\n\n\n\n";
	cout << setw(85) << "---------------------------------------------" << endl;
	cout << setw(80) << "Available Cars for Rent" << endl;
	cout << setw(85) << "---------------------------------------------" << endl;
	for (int i = 0; i < max_capacity; i++)
	{
		cout << setw(70) << "*Enter " << i << ": " << car.manufacturer[i] << " " << car.model[i] << " ," << car.year[i] << endl;
	}
	cout << setw(70) << "*Enter \"e\" to exit" << endl;
	cout << "\n\n\n";
	cout << setw(45) << "Please enter your choice: ";
	cin >> choice;
	if (choice != 'e')
	{
		cout << setw(75) << "Exiting..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		exit(1);
	}
	else
	{
		displayCar();
	}
}

void passCheck()
{
	char ch;
	ch = getchar();
	while (ch != 13)
	{
		password.push_back(ch);
		cout << "*";
		ch = getchar();
	}
}

void login()
{
	cout << "\n\n\n\n";
	cout << setw(80) << "Welcome to Georgi's Car Rental System" << endl;
	cout << setw(85) <<"---------------------------------------------" << endl;
	cout << setw(80) << "Enter your password to continue: " << endl;
	passCheck();
	while (password != pass)
	{
		cout << "\t\t The entered password is incorrect!" << endl;
		cout << "\t\t TPlease enter your password again: " << endl;
		passCheck();
	}
	cout << "\t\t Loading..." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");
}

int main()
{
	displayCar();
	login();
	return 0;
}
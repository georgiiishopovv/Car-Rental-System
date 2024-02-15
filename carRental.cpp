#include<iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <fstream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <thread>

using namespace cv;
using namespace std;

const int max_capacity = 8;
string pass = "welcome";

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

void photo(char choice)
{
	string temp = "C:/Users/Georgi/Desktop/OpenCV/Projects/";
	string path;
	Mat img;
	switch (choice)
	{
	case '0':
		path = temp + "bmwx5.jpg";
		break;
	case '1':
		path = temp + "bmw530.jpg";
		break;
	case '2':
		path = temp + "bmw320.jpg";
		break;
	case '3':
		path = temp + "s500.jpg";
		break;
	case '4':
		path = temp + "a3.jpg";
		break;
	case '5':
		path = temp + "corolla.jpg";
		break;
	case '6':
		path = temp + "santafe.jpg";
		break;
	case '7':
		path = temp + "peugeot308.jpg";
		break;
	}
	img = imread(path);
	namedWindow("Image", WINDOW_NORMAL);
	resizeWindow("Image", 700, 400);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int relativeX = screenWidth - 700;
	int relativeY = screenHeight - 480;

	moveWindow("Image", relativeX, relativeY);
	setWindowProperty("Image", WND_PROP_TOPMOST, 1);

	imshow("Image", img);
	waitKey(0);
}

void finalise()
{
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << setw(100) << "Thank you, your booking has been processed successfully!" << endl;
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n" << endl;
}

void snapshot()
{
	VideoCapture video(0);
	CascadeClassifier detect;
	bool faceDetected = false;
	const int FPS = 30;
	const int DURATION = 2;
	const int FRAME_THRESHOLD = FPS * DURATION;
	int frameCount = 0;
	Rect detectedFace;
	detect.load("band.xml");
	Mat imeg;
	Mat faceSnap;
	int count;

	while (true)
	{
		video.read(imeg);
		vector<Rect> faces;
		detect.detectMultiScale(imeg, faces, 1.3, 5);
		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(imeg, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			detectedFace = faces[i];
			frameCount++;
			rectangle(imeg, Point(0, 0), Point(650, 80), Scalar(50, 50, 200), FILLED);
			putText(imeg, "Face Detection in Progress", Point(75, 40), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 1);
		}
		if (frameCount >= FRAME_THRESHOLD)
		{
			Mat faceSnap = imeg(detectedFace);
			time_t now = time(0);
			string timestamp = to_string(now);
			string filename = "C:/Users/Georgi/Desktop/OpenCV/Projects/snapshot_" + timestamp + ".jpg";
			imwrite(filename, faceSnap);
			break;
		}
		imshow("Frame", imeg);
		waitKey(1);
	}
	system("cls");
	finalise();
}

void book()
{
	system("cls");
	string fname, lname, id;
	int age;
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << setw(74) << "Please provide some details" << endl;
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << setw(64) << "First Name: ";
	cin >> fname;
	cout << setw(63) << "Last Name: ";
	cin >> lname;
	cout << setw(57) << "Age: ";
	cin >> age;
	cout << setw(72) << "National ID Number: ";
	cin >> id;
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << setw(69) << "Face ID Required" << endl;
	cout << setw(68) << "Loading..." << endl;
	cout << setw(83) << "---------------------------------------------" << endl;
	this_thread::sleep_for(chrono::seconds(6));
	snapshot();
}

void displayCar(char& choice, const Cars& car);
void menu(char& choice, const Cars& car);

void displayCar(char& choice, const Cars& car)
{
	cout << "\n";
	string cont;
	cout << setw(83) << "---------------------------------------------" << endl;
	cout << setw(70) << "You have selected" << endl;
	cout << setw(83) << "---------------------------------------------" << endl;
	int num = choice - '0';
	cout << setw(45) << "Model: " << car.manufacturer[num] << " " << car.model[num] << endl;
	cout << setw(44) << "Year: " << car.year[num] << "\t\tYear: " << car.color[num] << endl;
	cout << setw(44) << "Fuel: " << car.fuel[num] << "\t\tMiles: " << car.miles[num] << endl;
	cout << setw(45) << "Price: " << car.price[num] << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	photo(choice);
	system("cls");
	cout << setw(86) << "Are you sure you want to continue? (yes/no/exit): ";
	cin >> cont;
	if (cont == "yes")
	{
		book();
	}
	else if (cont == "no")
	{
		system("cls");
		menu(choice, car);
	}
	else
	{
		system("cls");
		exit(0);
	}
}

void menu(char& choice, const Cars& car)
{
	cout << "\n";
	cout << setw(90) << "---------------------------------------------" << endl;
	cout << setw(80) << "Available Cars for Rent" << endl;
	cout << setw(90) << "---------------------------------------------" << endl;
	for (int i = 0; i < max_capacity; i++)
	{
		cout << setw(57) << "*Enter " << i << ": " << car.manufacturer[i] << " " << car.model[i] << ", " << car.year[i] << endl;
	}
	cout << setw(68) << "*Enter \"e\" to exit" << endl;
	cout << "\n\n";
	cout << setw(76) << "Please enter your choice: ";
	cin >> choice;
	if (choice == 'e')
	{
		cout << setw(60) << "Loading..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		exit(0);
	}
	else
	{
		system("cls");
		displayCar(choice, car);
	}
}

void login(string password, const Cars& car)
{
	cout << "\n\n\n\n";
	cout << setw(81) << "Welcome to Georgi's Car Rental System" << endl;
	cout << setw(85) << "---------------------------------------------" << endl;
	cout << setw(77) << "Enter your password to continue: ";
	char ch;
	ch = _getch();
	while (ch != 13)
	{
		password.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	if (password == pass)
	{
		cout << "\n\n\n";
		cout << setw(87) << "Correct Password. Establishing Connection.\n" << endl;
		cout << setw(70) << "Loading..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
	else
	{
		while (password != pass)
		{
			cout << endl;
			cout << setw(85) << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << setw(75) << "You entered a wrong password! \n" << endl;
			cout << setw(62) << "Please try again: ";
			password = "";
			ch = _getch();
			while (ch != 13)
			{
				password.push_back(ch);
				cout << "*";
				ch = _getch();
			}
		}
		cout << "\n\n";
		cout << setw(87) << "Correct Password. Establishing Connection.\n" << endl;
		cout << setw(60) << "Loading..." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
	}
}

int main()
{
	Cars car;
	char choice = '1';
	string password = "";
	login(password, car);
	menu(choice, car);
	book();
	return 0;
}
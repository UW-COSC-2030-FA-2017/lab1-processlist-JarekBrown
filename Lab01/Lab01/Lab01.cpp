// Jarek Brown
// September 11 2017
// Lab 1

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	// variable declarations
	string fileName, line, first, second, secondLast, last;
	int numberCount = 0;
	ifstream file;

	//getting the file name from user
	cout << "File name: ";
	cin >> fileName;

	//opening the file using ifstream object
	file.open(fileName);

	//iterating through the file
	if (file.is_open()) //checking if the file was successfully opened
	{
		file >> line;
		while (!file.fail())
        {
			numberCount++; //using this as a counter
			cout << line << '\n'; //reading each line of file
			switch (numberCount) //switch case to get first two numbers
			{
			case 1: {first = line; } //assigning first
			case 2: {second = line; } //assigning second
			}
			file >> line;
		}
		 file.close();
		 file.open(fileName);
		for(int i = 0; i <= (numberCount-1); i++)
		{
			file >> line;
			if (i == (numberCount - 2)) {secondLast = line;}
			else if (i == (numberCount-1)) {last = line;}
		}
		file.close(); 
		cout << "Number Count: " << numberCount << endl;
		cout << "First Two Numbers: " << first << ", " << second << endl;
		cout << "Last Two Numbers: " << secondLast << ", " << last << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}
}
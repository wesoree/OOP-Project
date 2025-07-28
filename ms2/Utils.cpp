#include <string>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;
namespace seneca {
	int getInt() {
		cout << "P";
		return getInt();
	}
	//Main getInt function
	int getIntMain() {
		string temp;
		bool cantsubmit = true;
		cout << "lease enter a value: "; //Please enter a value:
		/*
		3 scenarios:
		1. empty string
		2. string can't be converted to an int (basically garbage)
		3. string can be converted to an int
		*/
		while (cantsubmit) {
			cin >> temp;
			if (isEmpty(temp)) cout << "You must enter a value: ";
			else if (!isInt(temp)) cout << "Please enter an integer: "; //checks if string can't be converted to an int
			else {
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				return stoi(temp);
			}
			cin.clear();
			while (cin.get() != '\n') // because we need this project to be portable we can't use fflush
			{
				continue;
			}
		}
	}
	int getInt(int min, int max) {
		cout << "Within the range of " << min << "and" << max << ", p";
		bool cantsubmit = true;
		while (cantsubmit) {
			int v = getIntMain();
			if (v < min || v>max) {
				cout << "Out of range: Number must be within the range of " << min << " and " << max << ".\nP";
			}
			else return v;
		}
	}
	//by KorreyD from https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
	bool isInt(string s) {
		if (!s.empty() && s[0] != '-') s = "0" + s;
		string garbage;
		stringstream ss(s);
		int x;
		ss >> x >> garbage;
		//this line above extracts the number into an int, garbage is whatever else we can't convert
		return garbage.empty();
	}
	bool isEmpty(string s) {
		if (s.empty()) return true;
		for (int i = 0; s[i]; i++) {
			if (isspace(s[i])) return true;
		}
		return false;
	}
}
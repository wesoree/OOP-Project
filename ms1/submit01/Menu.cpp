#pragma warning(disable:4996)
#include "Menu.h"
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

namespace seneca {
	MenuItem::MenuItem(const char* input, size_t indentations, size_t size, int num) {
		content = "";
		string minput = tostring(input);
		minput.erase(std::remove_if(minput.begin(), minput.end(), isexcessivewhitespace), minput.end()); 

		if (minput != "" && num <= 20 && indentations <= 4 && size <= 4) {
			content = minput;
			mindentations = indentations;
			mnum = num;
			msize = size;
		}

	}
	MenuItem::~MenuItem() {
		content = "";
	}
	ostream& MenuItem::display()const {
		if (*this) {
			if (mnum < 0) return cout;
			for (int i = 0; i < mindentations; i++) {
				for (int j = 0; j < msize; j++) {
					cout << " ";
				}
			}
			cout << mnum << "- " << content;
		}
		else {
			cout << "??????????";
		}
		return cout;
	}
	MenuItem::operator bool()const {
		return content != "";
	}
	string tostring(const char* cs) {
		if (cs == nullptr) return "";
		string s(cs);
		return s;
	}
	bool isexcessivewhitespace(char ch) { // This function is like iswhitespace(); but ignores spaces
		return ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
	}
}
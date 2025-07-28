#pragma warning(disable:4996)
#include "Menu.h"
#include <cstring>
#include <cctype> 
#include <cmath>
#include <algorithm>
#include <iostream>
#include "Utils.h"
#include <initializer_list>

//---------------------------OOP244 PROJECT CITATION---------------------------------------
/******************************************************************************************
* Name: Wesley Lo
* Number: 103835245
* Email: wlo32@myseneca.ca
* Course: OOP244
* Section: NEE
* Prof: Asam Gulaid
* Version: 2.0
* Date: 7/22/25
* Milestone: 2
* Version History:
* 7/22/25 - Final submission prep, change of code to work with hybrid c/c++
* -----------------------------------------------------------------------------------------
* I have written all the code using what the prof provided, other than removeWhitespace();
* which is sourced from dutch from https://cplusplus.com/forum/beginner/251052/
*******************************************************************************************/
//--------------------------------END OF CITATION-------------------------------------------

using namespace std;
using namespace seneca;

namespace seneca {
	Menu::Menu(const string ititle) {
		inum = 0;
		isize = 3;
		title={ ititle,inum,isize,-1 }; //requires help from prof/someone who's doing oop244
		active = { };
	}
	Menu::Menu(const char* firsttitle, string exitoption, size_t num = 0, size_t size = 3) {
		inum = num;
		isize = size;
		//title = MenuItem(firsttitle, num, size, -1);
		title = { tostring(firsttitle),num,size,-1,false };
		exitOption = { exitoption,num,size,0,false };
		prompt = { "> ",num,size,-1,true };
		active = { };
	}
	Menu& Menu::operator<<(string s) {
		if (micount == 20) return *this; //the max size for a menu is 20 items
		active.push_back(MenuItem(s, inum, isize, micount)); //instead of using a pointer array we use a vector as native c++ vectors are better than pointer array (as their dynamic memory is automatically allocated and deallocated)
		micount++;
		return *this;
	}
	size_t Menu::select() const {
		cout << title << endl;
		for (int i = 0; i < active.size(); i++) { //iterate through the active array (it's actually a vector)
			cout << active[i] << endl;
		}
		cout << exitOption << endl;
		size_t select;
		bool isinvalid = true;
		while (isinvalid) {
			cout << prompt;
			cin >> select;
			if (floor(select) == select) isinvalid = false;
		}
		return select;
	}
	size_t operator<<(std::ostream& ostr, const Menu& m) {
		if (&ostr != &cout) return 0;
		return m.select();
	}
	MenuItem::MenuItem(initializer_list<int>){}
		//docs: {indents, size of indents, index value(-1 for titles/prompts, 0 and up for everything else,)
	MenuItem::MenuItem(string input, size_t indentations, size_t size, int num) {
		content = "";
		if (input != "" && num <= 20 && indentations <= 4 && size <= 4) {
			content = removeWhitespace(input);
			indents = indentations;
			index = num;
			this->size = size;
		}
		/*cout << "indentations: " << mindentations << " indenations\nsize of indentation: "
			<< msize << " spaces\nexpected number of spaces: " << mindentations * msize + 1 << " spaces\nrow number : " << mnum << "\ncontent: [" << content << "]\nExpected output:" << endl;*/
	}
	MenuItem::~MenuItem() {
		
	}
	ostream& MenuItem::display()const {
		if (*this && index >= 0) {
			if (index < 10) cout << " ";
			for (int i = 0; i < indents; i++) {
				switch (size) {
				case 1:
					cout << ' ';
					break;
				case 2:
					cout << "  ";
					break;
				case 3:
					cout << "   ";
					break;
				case 4:
					cout << "    ";
					break;
				case 5:
					cout << "     ";
					break;
				}
			}
			cout << index << "- " << content;
		}
		else if (*this && index < 0) {
			cout << content;
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
		if (cs == NULL) return "";
		string s(cs);
		return s;
	}
	//function that removes whitespace from a cstring, but returns a string, part of the code (lines 75 to xx) is from 
	// dutch from https://cplusplus.com/forum/beginner/251052/
	string removeWhitespace(string s) {
		if (s == "") return s;
		const string WS = " \t\v\r\n\f";
		size_t start = s.find_first_not_of(WS);
		size_t end = s.find_last_not_of(WS);
		return start == end ? std::string() : s.substr(start, end - start + 1);
	}
	string removeWhitespace(const char* src) { //might not implement this because mem leaks
		char* temp = new char[256];
		char* buffer = new char[256]; //256 character buffer
		strcpy(buffer, src);
		temp = strtok(buffer, " ");
		vector<string> words;
		string finalizedstring = "";
		while (temp != NULL) {
			int h = 0;
			for (int i = 0; temp[i]; i++) {
				if (!isspace(temp[i])) {
					temp[h++] = temp[i];
				}
			}
			temp[h] = '\0';
			if (strlen(temp) != 0) {
				words.push_back(string(temp));
			}
			temp = strtok(NULL, " ");
		}
		for (int i = 0; i < words.size();i++) {
			if (i < words.size() - 1) {
				if (words[i] != "") {
					finalizedstring += words[i] + " ";
				}
			}
			else {
				if (words[i] != "") {
					finalizedstring += words[i];
				}
			}
		}
		delete[] temp;
		delete[] buffer;
		return finalizedstring;
	}
	// this function is mostly sourced by Vincenzo Pii from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	vector<string> stdstrtok(string s, const string delim) {
		vector<string> tokens;
		size_t pos = 0;
		string token;
		while ((pos = s.find(delim)) != std::string::npos) {
			token = s.substr(0, pos);
			tokens.push_back(token);
			s.erase(0, pos + delim.length());
		}
		tokens.push_back(s);

		return tokens;
	}
}
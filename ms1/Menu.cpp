#pragma warning(disable:4996)
#include "Menu.h"
#include <cstring>
#include <cctype> 
#include <algorithm>
#include <iostream>

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
* Milestone: 1
* Version History:
* 7/22/25 - Final submission prep, change of code to work with hybrid c/c++
* 7/21/25 - Added a better function by splitting up the words before removing whitespace
* 7/18/25 - Adjust output
* 7/15/25 - Preliminary submission prep
* -----------------------------------------------------------------------------------------
* I have written all the code using what the prof provided, other than removeWhitespace();
* which is sourced from dutch from https://cplusplus.com/forum/beginner/251052/
*******************************************************************************************/
//--------------------------------END OF CITATION-------------------------------------------

using namespace std;

namespace seneca {
	MenuItem::MenuItem(const char* input, size_t indentations, size_t size, int num) {
		content = "";
		string minput = tostring(input); //convert the cstring into a std::string because we can take in NULL and return an empty string
		if (minput != "" && num <= 20 && indentations <= 4 && size <= 4) {
			content = removeWhitespace(minput);
			mindentations = indentations;
			mnum = num;
			msize = size;
		}
		/*cout << "indentations: " << mindentations << " indenations\nsize of indentation: "
			<< msize << " spaces\nexpected number of spaces: " << mindentations * msize + 1 << " spaces\nrow number : " << mnum << "\ncontent: [" << content << "]\nExpected output:" << endl;*/
	}
	MenuItem::~MenuItem() {
		content = "";
	}
	ostream& MenuItem::display()const {
		if (*this && mnum >= 0) {
			if (mnum < 10) cout << " ";
			for (int i = 0; i < mindentations; i++) {
				switch (msize) {
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
			cout << mnum << "- " << content;
		}
		else if (*this && mnum < 0) {
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
		temp = strtok(buffer," ");
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
				words.push_back(tostring(temp));
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
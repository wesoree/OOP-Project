#pragma warning(disable:4996)
#include "Menu.h"
#include <cstring>
#include <cctype> //not going to use <cctype> since utils.h doesn't require me to use that warning pragma
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
* 7/22/25 - Final submission prep
* 7/21/25 - Added a better function by splitting up the words before removing whitespace
* 7/18/25 - Adjust output
* 7/15/25 - Preliminary submission prep
* -----------------------------------------------------------------------------------------
* I have written all the code using what the prof provided
* other than Line 85 to 97, which was by Arafat Hasan on Stackoverflow, sourced from:
* https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
*******************************************************************************************/
//--------------------------------END OF CITATION-------------------------------------------

using namespace std;

namespace seneca {
	MenuItem::MenuItem(const char* input, size_t indentations, size_t size, int num) {
		content = "";
		string minput = tostring(input);
		if (minput != "" && num <= 20 && indentations <= 4 && size <= 4) {
			vector<string> temp = split(minput, " "); //dissasemble the string into vector of words
			for (int i = 0; i < temp.size();i++) {
				temp[i].erase(remove_if(temp[i].begin(), temp[i].end(), isspace), temp[i].end()); //produce 
				if (i < temp.size() - 1) {
					if (temp[i] != "") {
						content += temp[i] + " ";
					}
				}
				else {
					if (temp[i] != "") {
						content += temp[i];
					}
				}
			}
			mindentations = indentations;
			mnum = num;
			msize = size;
		}

	}
	MenuItem::~MenuItem() {
		content = "";
	}
	ostream& MenuItem::display()const {
		if (*this && mnum >= 0) {
			for (int i = 0; i < mindentations; i++) {
				for (int j = 0; j < msize; j++) {
					cout << " ";
				}
			}
			cout << mnum << "- " << content;
		}
		else if (mnum < 0) {
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
	//this split function is by Arafat Hasan on stackoverflow, sourced from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	vector<string> split(string src, string delim) {
		size_t pos_start = 0, pos_end, delim_len = delim.length();
		vector<string> des;
		string token;
		while ((pos_end = src.find(delim, pos_start)) != string::npos) {
			token = src.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			des.push_back(token);
		}
		des.push_back(src.substr(pos_start));
		return des;
	}
}
#pragma once
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;
namespace seneca {
	class Menu {
		size_t micount;
		int inum;
		int isize;
		MenuItem title;
		MenuItem exitOption;
		MenuItem prompt;
		vector<MenuItem> active;
	public:
		Menu(const string ititle);
		Menu(const char* firsttitle, string exitoption, size_t num = 0, size_t size = 3);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		Menu& operator<<(string s);
		size_t select() const;
		friend MenuItem;
	};
	size_t operator<<(std::ostream& ostr, const Menu& m);
	class MenuItem {
		size_t indents;
		size_t size;
		int index;
		bool isprompt;
		string content;
		MenuItem(){}
		MenuItem(initializer_list<int>);
		MenuItem(string input, bool isPrompt = false);
		MenuItem(string input, size_t indentations, size_t size, int num); // unlike ms1 which had to take in cstrings ms2 doesn't take in cstrings, which saves a few steps
		MenuItem(const MenuItem& mi)=delete;
		MenuItem& operator=(const MenuItem& mi)=delete;
		~MenuItem();
		friend Menu;
		ostream& display() const;
		operator bool()const;
	};
	string tostring(const char* cs);
	string removeWhitespace(string s);
	string removeWhitespace(const char* src);
	vector<string> stdstrtok(string s, const string delim);
}

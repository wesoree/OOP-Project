#pragma once
#include <string>
#include <vector>

using namespace std;
namespace seneca {
	class MenuItem {
		string content;
		size_t mindentations;
		size_t msize;
		int mnum;
	public:
		MenuItem(const char* input, size_t indentations, size_t size, int num);
		MenuItem(const MenuItem& mi) = delete;
		MenuItem& operator=(const MenuItem& mi) = delete;
		~MenuItem();
		ostream& display() const;
		operator bool()const;
	};
	string tostring(const char* cs);
	string removeWhitespace(string s);
	string removeWhitespace(const char* src);
	vector<string> stdstrtok(string s, const string delim);
}
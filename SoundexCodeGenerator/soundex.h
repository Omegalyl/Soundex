#pragma once
#ifndef _Soundex_H
#define _Soundex_H
#include <string>
#include <map>
#include <vector>
using namespace std;
class Soundex {
public:
	Soundex();

	void ConvToSdx();
	void print();
private:
	std::string Sdx(std::string );
	void RemoveNonAlph(std::string&);
	std::map<char,char> table;
	void Encode(std::string &);
	void Coalesce(std::string &);
	void removeZ(std::string&);
	void Padd(std::string &);

};
#endif // !_Soundex_H
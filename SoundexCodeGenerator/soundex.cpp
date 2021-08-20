#include "soundex.h"
#include <iostream>
#include <algorithm>
#include <cstdio>


using namespace std;

Soundex::Soundex() {
	table['A'] = '0'; table['W'] = '0'; table['E'] = '0'; table['I'] = '0'; table['O'] = '0'; table['U'] = '0'; table['H'] = '0'; table['Y'] = '0';
	table['B'] = '1'; table['F'] = '1'; table['P'] = '1'; table['V'] = '1';
	table['C'] = '2'; table['G'] = '2'; table['J'] = '2'; table['K'] = '2'; table['Q'] = '2'; table['S'] = '2'; table['X'] = '2'; table['Z'] = '2'; 
	table['D'] = '3'; table['T'] = '3';
	table['L'] = '4'; 
	table['M'] = '5'; table['N'] = '5';
	table['R'] = '6';
	
}
void Soundex::print() {
}

void Soundex::RemoveNonAlph(string &s) { // Removes All Non Alphabatic chars ex (::""AABB->AABB)
	int j = 0;
	while(j<s.length()) {
		if (!isalpha(s[j])) {
			// remove the character at index j
			s = s.substr(0, j) + s.substr(j + 1);
		}
		else if(isalpha(s[j]))
		{
			j++;
		}
	}
}
void Soundex::Encode(string &s) {	// Encode The String using standard encoding method
	transform(s.begin(), s.end(), s.begin(), toupper);
	for (int i = 0;i < s.length();i++) {
		s[i] = table[s[i]];
	}
}
void Soundex::Coalesce(string &s) {	//Removes all duplicate Digits ex (6633445->6345)
	int i = 0;
	while(i<s.length()-1) {
		if (s[i] == s[i + 1]) {
			s = s.substr(0, i) + s.substr(i + 1);
		}
		else {
			i++;
		}
	}
}
void Soundex::removeZ(string& s) {	// Remove all Zeros from the string
	int i = 0;
	while (i < s.length() ) {
		if (s[i] == '0') {
			s = s.substr(0, i) + s.substr(i + 1);
		}
		else {
			i++;
		}
	}
}
void Soundex::Padd(string& s) {	// Adds Zeros or Remove chars from string to make it length of 4 
									// Removes and Adds to end of the string 
									// ex  63425 -> 6342 , 62->6200
	if (s.length() < 4) {
		while (s.length() < 4) {
			s += '0';
		}
	}
	else if (s.length() > 4) {
		while (s.length() > 4) {
			s = s.substr(0, s.length() - 1);
		}
	}
}
string Soundex::Sdx(string s) {	// <--- private helper func
	RemoveNonAlph(s);
	string a = s;
	transform(a.begin(), a.end(), a.begin(), toupper);
	Encode(s);
	Coalesce(s);
	s[0] = a[0];
	removeZ(s);
	Padd(s);
	return s;

}
void Soundex::ConvToSdx() {		// <--- public helper func 
								// only function that can be called by class object
	cout << "Enter Name:" << endl;
	string s;
	getline(cin, s);
	cout << "Soundex of Name:"<<Sdx(s) << endl;
	cout <<"enter to exit";
	getchar();
}
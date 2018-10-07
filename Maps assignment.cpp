#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <map>
#include <fstream>

using namespace std;

int main() {
	int vertices, edges;
	int x;
	map <int, int > Map;
	ifstream InFile("Input.txt");
	cin.rdbuf(InFile.rdbuf());
	cin >> vertices >> edges;
	for (int i = 0; i < edges * 2; i++) {
		cin >> x;
		Map[x]++;
	}
	InFile.close();

	ofstream OutFile;
	OutFile.open("x.txt");
	for (map< int, int >::iterator im = Map.begin(); im != Map.end(); im++)
		OutFile << im->first << "," << im->second << endl;
	OutFile.close();

	ofstream OutputFile("x.csv");
	for (map< int, int >::iterator im = Map.begin(); im != Map.end(); im++)
		OutputFile << im->first << "," << im->second << endl;
	OutFile.close();

	_getch();
	return 0;
}

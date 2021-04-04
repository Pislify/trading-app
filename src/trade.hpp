#include <raylib.h>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Trade
{
	ofstream file;
	string filename = "test.txt";
	void Init()
	{
		ofstream file;
		file.open("test.txt");
		file << "yay\n";
		file.close();
		system("cat test.txt");
	}
};

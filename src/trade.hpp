#include <raylib.h>

#include <vector>
#include <string>

#include <fstream>

using namespace std;

struct Trade
{
	ofstream file;
	string filename = "test.txt";
	void Init()
	{
		file.open(filename.data());
		file << "lol\n";
		file.close();
	}
};

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "yay\n";
    ofstream file;
    file.open("app.txt");
    file << "yay\n";
    file.close();
    system("cat app.txt");
}

#include <raylib.h>
#include <vector>
#include <string>
#include <json/json.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <time.h>
using namespace std;




void AddCoin(std::vector<int> *data)
{
    system("rm currentprice.json");
    system("wget https://api.coindesk.com/v1/bpi/currentprice.json");
    system("python3 reader.py");
    int s = 613432434234234242349;
    ifstream dataread("currentprice.json");
    int input;
    while (dataread >> input)
    {
        s = input;
        if (s == 613432434234234242349)
        {
            return;
        }
    }

    data->push_back(s);
}

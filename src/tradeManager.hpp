#include <raylib.h>
#include <vector>
#include <string>
using namespace std;


struct TradeManager
{
    vector<int> data;
    int  widthIntencity;
    int heightIntencity;

    int x_off;
    int y_off;

    int fontS = 3;

    Color colorU = GREEN;
    Color colorD = RED;
    Color colorN = BLUE;
    Color nColor= WHITE;

    void DrawGraph()
    {
       for(int i = 0 ; i < data.size()-1;i++)
       {
          Color drawColor;
          if (data[i]>data[i+1])
          {
             drawColor = colorD; //down color
          }
          if (data[i]<data[i+1])
          {
             drawColor = colorU; // up
          }
          if (data[i]==data[i+1])
          {
             drawColor = colorN; // neutral
          }
          //replace the 720's with get_windowH
          int x;
          int y;
          int x1;
          int y1;

          //DrawLine(x_off+(i*widthIntencity),720+y_off-(data[i] *heightIntencity) , (i+1)* widthIntencity,720+y_off-(data[i+1] *heightIntencity) , drawColor);
          //DrawText(s.data(),i*widthIntencity,720+y_off-(data[i]+1 *heightIntencity) ,fontS,nColor);

          x = x_off+(i*widthIntencity);
          y = 720+y_off-(data[i] *heightIntencity);
          x1 = (i+1)* widthIntencity;
          y1 = 720+y_off-(data[i+1] *heightIntencity);

          DrawLine(x,y,x1,y1,drawColor);

          string s = to_string(data[i]);
          DrawText(s.data(),x,y ,fontS,nColor);
       }
    }
};

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


struct TradeManager
{
    vector<int> data;
    int  widthIntencity = 2;
    int heightIntencity = 1;

    int x_off = 0;
    int y_off = 0;

    int fontS = 3;

    Color colorU = GREEN;
    Color colorD = RED;
    Color colorN = BLUE;
    Color nColor= WHITE;

    int up = KEY_UP;
    int down = KEY_DOWN;
    int right = KEY_RIGHT;
    int left = KEY_LEFT;
    int zoomi = KEY_W;
    int zoomu = KEY_S;
    float cam_speed = 100;
    float cam_zoom_speed = 10;
    Camera2D cam =
    {
      (Vector2){0,0},
      (Vector2){0,0},
      0,
      1
    };

    int GetCoinPrice()
    {
        system("rm currentprice.json");
        system("wget https://api.coindesk.com/v1/bpi/currentprice.json");
        system("python3 reader.py");
        int s = 69;
        ifstream dataread("currentprice.json");
        int input;
        while (dataread  >> input)
        {
            s = input;
            if (s!= 69)
            {
                return s;
            }
        }
        
        return s;
    }

    void Init()
    {
    }

    void AddCoin()
    {
        data.push_back(GetCoinPrice()/10);
    }

    void Update()
    {
        if (IsKeyDown(up))
        {
            cam.target.y -= cam_speed / GetFPS();
        }
        if (IsKeyDown(down))
        {
            cam.target.y += cam_speed / GetFPS();
        }
        if (IsKeyDown(left))
        {
            cam.target.x -= cam_speed / GetFPS();
        }
        if (IsKeyDown(right))
        {
            cam.target.x += cam_speed / GetFPS();
        }
        if (IsKeyDown(zoomi))
        {
            cam.zoom -= cam_zoom_speed / GetFPS();
            //widthIntencity -= cam_zoom_speed / GetFPS();
        }
        if (IsKeyDown(zoomu))
        {
            cam.zoom += cam_zoom_speed / GetFPS();
            //widthIntencity += cam_zoom_speed / GetFPS();
        }
        AddCoin();
        
    }

    void DrawGraph()
    {
       BeginMode2D(cam);
       int smallval;
       int bigval;
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
          int x;
          int y;
          int x1;
          int y1;

          //DrawLine(x_off+(i*widthIntencity),720+y_off-(data[i] *heightIntencity) , (i+1)* widthIntencity,720+y_off-(data[i+1] *heightIntencity) , drawColor);
          //DrawText(s.data(),i*widthIntencity,720+y_off-(data[i]+1 *heightIntencity) ,fontS,nColor);

          x = x_off + ( i * widthIntencity ) ;
          y = GetScreenHeight() + y_off - ( data[i] * heightIntencity ) ;
          x1 = x_off + (( i + 1 ) * widthIntencity);
          y1 = GetScreenHeight() + y_off - ( data[i+1] * heightIntencity ) ;

          DrawLine(x,y,x1,y1,drawColor);

          string s = to_string(data[i]);
          DrawText(s.data(),x,y ,fontS,nColor);
       }
       //for debug
       //DrawRectangle(-50,-50,100,100,RED);
       EndMode2D();
    }
};

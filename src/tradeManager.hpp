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
#include "BitcoinGetter.hpp"
using namespace std;


struct TradeManager
{
    //the integers that make the graph
    vector<int> data;
    
    //multipliers for width and height
    int  widthIntencity = 150;
    int heightIntencity = 1;

    //offsets for the graph
    int x_off = 0,y_off = 0;

    //font sise for the 
    int fontS = 1;

    //BASIC colors needs to be made into its class
    Color colorU = GREEN;
    Color colorD = RED;
    Color colorN = BLUE;
    Color nColor= WHITE;

    //BASIC key controls needs to be made into its class adds up the the offset
    int up = KEY_UP;
    int down = KEY_DOWN;
    int right = KEY_RIGHT;
    int left = KEY_LEFT;

    //BASIC key controls needs to be made into its class adds up the the mult
    int zoomi = KEY_W;
    int zoomu = KEY_S;

    //timer to plan the fetch cycle time
    int timer = 0;

    //cam speed
    float cam_speed = 2000;
    
    //used to speed up  or slow down zoom speed
    float cam_zoom_speed = 4;

    //default camera
    Camera2D cam =
    {
      (Vector2){0,0},
      (Vector2){0,0},
      0,
      1
    };


    void Init()
    {
    }

    void CamUpdate()
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
    }
    void Debug()
    {
        
    }
    void Update()
    {
        timer++;
        if(timer>=120)
        {
            DrawText("fetch" , 0,0,20 ,RED);
            thread d(AddCoin,&data);
            d.join();
            CamUpdate();
            DrawGraph();
            timer = 0;
        }
        else{
            CamUpdate();
            DrawGraph();
            Debug();
        }
                
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
          if(i == data.size()-2){
            DrawText(s.data(),x,y ,fontS * cam.zoom,nColor);
          }
       }
       //for debug
       //DrawRectangle(-50,-50,100,100,RED);
       EndMode2D();
    }
};

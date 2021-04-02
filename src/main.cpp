#include <raylib.h>
#include <vector>
#include <string>
using namespace std;


// vals : values
// space : space btw lines
// h : height line mltplier
//color U : color wh line goes up
//color d : color wh line goes down
//color n : color wh line stays
// y off : offset from up
void DrawTrail(vector<int> vals,int space,int h,Color colorU,Color colorD,Color colorN,int y_off)
{
   for(int i = 0 ; i < vals.size()-1;i++)
   {
      Color drawColor;
      if (vals[i]>vals[i+1])
      {
         drawColor = colorD; //down color
      }
      if (vals[i]<vals[i+1])
      {
         drawColor = colorU; // up
      }
      if (vals[i]==vals[i+1])
      {
         drawColor = colorN; // neutral
      }
      DrawLine(i*space,720+y_off-(vals[i] * h) , (i+1)* space,720+y_off-(vals[i+1] * h) , drawColor);
      string s = to_string(vals[i]);
      DrawText(s.data(),i*space,720+y_off-(vals[i]+1 * h) ,3,drawColor);
   }
}

int main()
{
   InitWindow(1860,1000,"pfiojasdkfj");
   SetTargetFPS(20);
   vector<int> test_data={
      12,13,16,18,11,13,14,15,14,14,17,19,10,12,11,20
   };

   int h = 1;
   int v = 1;
   while(!WindowShouldClose())
   {
      if(IsKeyDown(KEY_UP))
      {
         v++;
      }
      if(IsKeyDown(KEY_DOWN))
      {
         v--;
      }
      if(IsKeyDown(KEY_RIGHT))
      {
         h++;
      }
      if(IsKeyDown(KEY_LEFT))
      {
         h--;
      }


      BeginDrawing();
      ClearBackground(BLACK);
      DrawTrail(test_data,h,1,GREEN,RED,WHITE,v);

      EndDrawing();

   }
   CloseWindow();
}

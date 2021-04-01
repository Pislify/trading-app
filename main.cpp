#include <raylib.h>
#include <vector>
#include <string>
using namespace std;

void DrawTrail(vector<int> vals,int space,int h,Color colorU,Color colorD,Color colorN)
{
   for(int i = 0 ; i < vals.size()-1;i++)
   {
      if (vals[i]>vals[i+1])
      {
         DrawLine(i*space,720-(vals[i] * h) , (i+1)* space,720-(vals[i+1] * h) , colorD);
      }
      if (vals[i]<vals[i+1])
      {
         DrawLine(i*space,720-(vals[i] * h) , (i+1)* space,720-(vals[i+1] * h) , colorU);
      }
      if (vals[i]==vals[i+1])
      {
         DrawLine(i*space,720-(vals[i] * h) , (i+1)* space,720-(vals[i+1] * h) , colorN);
      }
      //DrawLine(i*space,720-(vals[i] * h) , (i+1)* space,720-(vals[i+1] * h) , color);
      string s = to_string(vals[i]);
      DrawText(s.data(),i*space,720-(vals[i] * h) ,3,BLUE);
   }
}

int main()
{
   InitWindow(1000,1000,"Good");
   SetTargetFPS(20);
   vector<int> test_data={
      343,
      444,
      524,
      243,
      533,
      425,
      536,
      425,
      464,
      562,
      456,
      434,
      756,
      344,
      241,
      344,
      231,
      444,
      444,
      444,
      544,
      435,
      434,
      533,
      512,
      546,
      453,
      612,
      456,
      453,
      742,
      561,
      452,
      623,
      523,
      124,
      234,
      234,
      234,
      544,
      345,
      345,
      334,
      522
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
      DrawTrail(test_data,h,v,GREEN,RED,WHITE);
      
      EndDrawing();
      
   }
   CloseWindow();
}

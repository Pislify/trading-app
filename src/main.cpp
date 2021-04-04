#include <raylib.h>
#include <vector>
#include <string>
#include <trade.hpp>
#include <tradeManager.hpp>
using namespace std;


// vals : values
// space : space btw lines
// h : height line mltplier
//color U : color wh line goes up
//color d : color wh line goes down
//color n : color wh line stays
// y off : offset from up
// void DrawTrail(vector<int> vals,int space,int h,Color colorU,Color colorD,Color colorN,int y_off)
// {
//    for(int i = 0 ; i < vals.size()-1;i++)
//    {
//       Color drawColor;
//       if (vals[i]>vals[i+1])
//       {
//          drawColor = colorD; //down color
//       }
//       if (vals[i]<vals[i+1])
//       {
//          drawColor = colorU; // up
//       }
//       if (vals[i]==vals[i+1])
//       {
//          drawColor = colorN; // neutral
//       }
//       DrawLine(i*space,720+y_off-(vals[i] * h) , (i+1)* space,720+y_off-(vals[i+1] * h) , drawColor);
//       string s = to_string(vals[i]);
//       DrawText(s.data(),i*space,720+y_off-(vals[i]+1 * h) ,3,drawColor);
//    }
// }

int main()
{
   InitWindow(1280,720,"pfiojasdkfj");
   //SetTargetFPS(200);
   vector<int> test_data =
   {79,35,24,133,112,44,94,84,74,79};

   TradeManager m;
   m.data = test_data;

   Trade d;
   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(BLACK);
      DrawFPS(0,0);
      d.Init();
      m.DrawGraph();
      m.Update();

      EndDrawing();

   }
   CloseWindow();
}

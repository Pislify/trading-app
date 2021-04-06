#include <raylib.h>
#include <vector>
#include <string>
#include <trade.hpp>
#include <tradeManager.hpp>
using namespace std;

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

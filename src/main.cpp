#include <raylib.h>
#include <vector>
#include <string>
#include <tradeManager.hpp>
using namespace std;

int main()
{
   InitWindow(1280,720,"pfiojasdkfj");
   //SetTargetFPS(200);
   vector <int> test_data = {0};
   TradeManager m;
   m.Init();
   m.data = test_data;

   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(BLACK);
      DrawFPS(0,0);
      m.DrawGraph();
      m.Update();

      EndDrawing();

   }
   CloseWindow();
}

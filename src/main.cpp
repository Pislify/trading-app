#include <raylib.h>
#include <vector>
#include <string>
#include <tradeManager.hpp>
using namespace std;

int main()
{
   InitWindow(1280,720,"pfiojasdkfj");
   SetTargetFPS(60);
   TradeManager m;
   m.Init();
   
   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground((Color){30,30,50});
      DrawFPS(0,0);
      
      m.Update();

      EndDrawing();

   }
   CloseWindow();
}

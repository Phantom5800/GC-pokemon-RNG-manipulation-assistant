#include <QApplication>

#include "GUI/MainWindow.h"

#ifdef _MSC_VER
#include <Windows.h>
#endif

int main(int argc, char** argv)
{
  #ifdef _MSC_VER
  HMODULE user32 = GetModuleHandle(TEXT("User32.dll"));
  if (user32 && GetProcAddress(user32, "SetProcessDpiAwarenessContext"))
  {
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED);
  }
  #endif
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
  return app.exec();
}

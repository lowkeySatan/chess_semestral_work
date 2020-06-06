#include "src/CApplication.h"

int main() {

    CApplication * app = new CApplication();
    app->Run();
    delete app;
    return 0;
}

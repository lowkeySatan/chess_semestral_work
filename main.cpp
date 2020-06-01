#include "src/CApplication.h"

int main() {

    CApplication * app = new CApplication();
    app->AppLoop();
    delete app;
    return 0;
}

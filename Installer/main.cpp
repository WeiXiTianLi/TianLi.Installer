#include <iostream>
#include "lib_ui/widget/rounded_rectangle.h"
#include "QApplication"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    tianli::rounded_rectangle w;
    w.show();
    return a.exec();
}
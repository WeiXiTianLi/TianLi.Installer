#pragma
#include <iostream>
#include "lib_ui/tianli_widget.h"
#include "QApplication"

int print(std::vector<std::string>& arg) {
    for (auto &i : arg) {
        std::cout << i << std::endl;
    }
    return 0;
}

int main_window(int argc, char *argv[]) {
    QApplication a(argc, argv);
    tianli::tianli_widget w;
    w.show();
    return a.exec();
}

int main_quiet_install(int argc, char *argv[]) {
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    return print(args);
}

int main_help() {
    std::vector<std::string> arg = {
            "Usage: ",
            "  -h, --help",
            "  -v, --version",
            "  -w, --window",
            "  -q, --quiet"
    };
    print(arg);
    return 1;
}

int main_version() {
    std::vector<std::string> arg = {
            "Version: 0.0.1"
    };
    print(arg);
    return 1;
}

std::map<int,std::string> error_map = {
        {0,"安装已成功"},
        {1,"用户已取消安装"},
        {2,"应用程序已存在"},
        {3,"安装已在进行"},
        {4,"磁盘空间已满"},
        {5,"需要重新启动"},
        {6,"网络故障"},
        {7,"已在安转期间拒绝包"},
};

int main(int argc, char *argv[])
{
    if (argc == 1) {
        return main_window(argc, argv);
    }
    std::string arg = argv[1];
    if (arg == "-h" || arg == "--help") {
        return main_help();
    }
    if (arg == "-v" || arg == "--version") {
        return main_version();
    }
    if (arg == "-w" || arg == "--window") {
        return main_window(argc, argv);
    }
    if (arg == "-q" || arg == "--quiet") {
        return main_quiet_install(argc, argv);
    }
    return 0;

}
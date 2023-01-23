//
// Created by YuSuiXian on 2023/1/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_rounded_rectangle.h" resolved

#include "rounded_rectangle.h"
#include "ui_rounded_rectangle.h"

namespace tianli {
    rounded_rectangle::rounded_rectangle(QWidget *parent) :
            QWidget(parent), ui(new Ui::rounded_rectangle) {
        ui->setupUi(this);
    }

    rounded_rectangle::~rounded_rectangle() {
        delete ui;
    }
} // tianli

//
// Created by YuSuiXian on 2023/1/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_rounded_rectangle.h" resolved

#include "rounded_rectangle.h"
#include "ui_rounded_rectangle.h"

#include "../common/time_line_label/time_line_label.h"

namespace tianli
{
    rounded_rectangle::rounded_rectangle(QWidget *parent) : QWidget(parent), ui(new Ui::rounded_rectangle)
    {
        ui->setupUi(this);

        time_line_label *label = new time_line_label(this);
        label->setGeometry(0, 0, 100, 100);
    }

    rounded_rectangle::~rounded_rectangle()
    {
        delete ui;
    }
} // tianli

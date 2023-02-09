//
// Created by YuSuiXian on 2023/2/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_tianli_widget.h" resolved

#include "tianli_widget.h"
#include "ui_tianli_widget.h"

#include "common/time_line_label/time_line_label.h"
#include <QDebug>

#include <QDirIterator>
#include <iostream>

namespace tianli {
    tianli_widget::tianli_widget(QWidget *parent) :
            QWidget(parent), ui(new Ui::tianli_widget) {
        ui->setupUi(this);
        //this->setWindowIcon(QIcon(":/logo/resource/icon.png"));
        QIcon icon;

         icon.addFile("qrc:///logo/resource/icon.png");

        QDirIterator it(":", QDirIterator::Subdirectories);
        while (it.hasNext()) {
            std::cout << it.next().toStdString() << std::endl;
        }
        //this->setWindowFlags(Qt::FramelessWindowHint);
        //this->setAttribute(Qt::WA_TranslucentBackground, true);

        time_line_label *label = new time_line_label(this);
        label->setGeometry(102, 51, 15, 124);
        label->setAction(true);
        label->setBegin(true);
    }

    tianli_widget::~tianli_widget() {
        delete ui;
    }
} // tianli

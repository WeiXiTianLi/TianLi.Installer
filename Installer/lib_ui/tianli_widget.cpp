//
// Created by YuSuiXian on 2023/2/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_tianli_widget.h" resolved

#include "tianli_widget.h"
#include "ui_tianli_widget.h"

#include "common/time_line_label/time_line_label.h"
#include <QMouseEvent>
#include <QFocusEvent>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

namespace tianli {
    tianli_widget::tianli_widget(QWidget *parent) :
            QWidget(parent), ui(new Ui::tianli_widget) {
        ui->setupUi(this);

        this->setWindowFlags(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground, true);


        mainShadow = new QGraphicsDropShadowEffect();
        mainShadow->setOffset(0, 0);
        mainShadow->setColor(QColor(255, 255, 255));
        mainShadow->setBlurRadius(16);
        ui->label_MainShadow->setGraphicsEffect(mainShadow);

        mainShadowAnimation = new QPropertyAnimation(mainShadow, "color");
        mainShadowAnimation->setDuration(500);
        mainShadowAnimation->setEasingCurve(QEasingCurve::OutExpo);

        mainShadow_A = new QGraphicsDropShadowEffect();
        mainShadow_A->setOffset(0, 0);
        mainShadow_A->setColor(QColor(255, 255, 255));
        mainShadow_A->setBlurRadius(16);
        ui->label_MainShadow_A->setGraphicsEffect(mainShadow_A);

        mainShadow_B = new QGraphicsDropShadowEffect();
        mainShadow_B->setOffset(0, 0);
        mainShadow_B->setColor(QColor(255, 0, 0));
        mainShadow_B->setBlurRadius(14);
        ui->label_MainShadow_B->setGraphicsEffect(mainShadow_B);

        int y = 51;

        time_line_label* timeLineLabel_1 = new time_line_label();
        timeLineLabel_1->setParent(ui->stackedWidget->widget(1));
        timeLineLabel_1->setGeometry(102, y, 15, 124);
        timeLineLabel_1->setAction(true);
        timeLineLabel_1->setBegin(true);

        time_line_label* timeLineLabel_2 = new time_line_label();
        timeLineLabel_2->setParent(ui->stackedWidget->widget(1));
        timeLineLabel_2->setGeometry(102, y + 31 *1, 15, 124);
        timeLineLabel_2->setAction(true);


        time_line_label* timeLineLabel_3 = new time_line_label();
        timeLineLabel_3->setParent(ui->stackedWidget->widget(1));
        timeLineLabel_3->setGeometry(102, y + 31 *2, 15, 124);
        timeLineLabel_3->setAction(true);
        timeLineLabel_3->setChecked(true);

        time_line_label* timeLineLabel_4 = new time_line_label();
        timeLineLabel_4->setParent(ui->stackedWidget->widget(1));
        timeLineLabel_4->setGeometry(102, y+31*3, 15, 124);
        timeLineLabel_4->setEnd(true);

        //connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget::close);
        //connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget::showMinimized);

        connect(ui->pushButton_UI_Close, &QPushButton::clicked, this, &tianli_widget::pushButton_UI_Close);
        connect(ui->pushButton_UI_Mini, &QPushButton::clicked, this, &tianli_widget::pushButton_UI_Mini);
        connect(ui->pushButton_FastInstall, &QPushButton::clicked, this, &tianli_widget::pushButton_FastInstall);
        connect(ui->pushButton_CustomizeInstall, &QPushButton::clicked, this, &tianli_widget::pushButton_CustomizeInstall);
        connect(ui->pushButton_Finishing_Cancel, &QPushButton::clicked, this, &tianli_widget::pushButton_Finishing_Cancel);
        connect(ui->pushButton_Finished_Run, &QPushButton::clicked, this, &tianli_widget::pushButton_Finished_Run);
        connect(ui->pushButton_Finished_Exit, &QPushButton::clicked, this, &tianli_widget::pushButton_Finished_Exit);

        ui->stackedWidget->setCurrentIndex(1);
    }

    tianli_widget::~tianli_widget() {
        delete ui;
    }


    void tianli_widget::mousePressEvent(QMouseEvent* event)
    {
        if (event->button() == Qt::LeftButton &&
            ui->label_MainShadow->frameRect().contains(event->globalPos() - this->frameGeometry().topLeft())) {
            m_Press = event->globalPos();
            leftBtnClk = true;
        }
        event->ignore();
    }

    void tianli_widget::mouseReleaseEvent(QMouseEvent* event)
    {
        if (event->button() == Qt::LeftButton) {
            leftBtnClk = false;
        }
        event->ignore();
    }
    void tianli_widget::mouseMoveEvent(QMouseEvent* event)
    {
        if (leftBtnClk) {
            m_Move = event->globalPos();
            this->move(this->pos() + m_Move - m_Press);
            m_Press = m_Move;
        }
        event->ignore();
    }
    bool tianli_widget::eventFilter(QObject* object, QEvent* event)
    {
        if (event->type() == QEvent::ActivationChange)
        {
            if (QApplication::activeWindow() != this)
            {
                // 焦点转移
                mainShadow_B->setEnabled(false);
            }
            else
            {
                //焦点转进
                mainShadow_B->setEnabled(true);
            }
        }
        if (event->type() == QEvent::Enter)
        {
            mainShadowAnimation->stop();
            mainShadowAnimation->setEndValue("#FF1C1C");
            mainShadowAnimation->start();
        }
        if (event->type() == QEvent::Leave)
        {
            mainShadowAnimation->stop();
            mainShadowAnimation->setEndValue("#DDDDDD");
            mainShadowAnimation->start();
        }
        return QWidget::eventFilter(object, event);
    }

    void tianli_widget::closeEvent(QCloseEvent* event)
    {
        event->accept();
    }
    void tianli_widget::pushButton_UI_Close()
    {
        ui->stackedWidget->setCurrentIndex(3);

        //ui.label_MainShadow->hide();

        ui->label_MainShadow_A->hide();
        ui->label_MainShadow_B->hide();
        ui->pushButton_UI_Close->hide();
        ui->pushButton_UI_Mini->hide();

        // 渐渐缩小
        exitAnimation = new QPropertyAnimation(ui->label_MainShadow, "geometry");
        exitAnimation->setDuration(200);
        exitAnimation->setEndValue(QRect(10+50 , 20+50, 720-100, 384-100));
        connect(exitAnimation, &QPropertyAnimation::valueChanged, [=]() {
            this->update();
        });
        connect(exitAnimation, &QPropertyAnimation::finished, [=]() {
            this->close();
        });
        exitAnimation->start();
        // 渐渐隐藏
        exitAnimation_hide = new QPropertyAnimation(ui->label_MainShadow, "windowOpacity");




        update();


        //this->close();

    }

    void tianli_widget::pushButton_UI_Mini()
    {
        this->showMinimized();
    }

    void tianli_widget::pushButton_FastInstall()
    {
        ui->stackedWidget->setCurrentIndex(1);

    }

    void tianli_widget::pushButton_CustomizeInstall()
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void tianli_widget::pushButton_Finishing_Cancel()
    {
        ui->stackedWidget->setCurrentIndex(0);
    }

    void tianli_widget::pushButton_Finished_Run()
    {
        this->close();
    }

    void tianli_widget::pushButton_Finished_Exit()
    {
        this->close();
    }
} // tianli

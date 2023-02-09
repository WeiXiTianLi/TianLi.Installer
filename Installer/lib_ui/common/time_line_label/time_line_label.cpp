//
// Created by YuSuiXian on 2023/2/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_time_line_label.h" resolved

#include "time_line_label.h"
#include "ui_time_line_label.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>

namespace tianli {
    time_line_label::time_line_label(QWidget *parent) :
            QWidget(parent), ui(new Ui::time_line_label) {
        ui->setupUi(this);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &time_line_label::timeout);
        timer->setInterval(100);

        UI_NoCheck();
    }

    time_line_label::~time_line_label() {
        delete ui;
    }

    void time_line_label::paintEvent(QPaintEvent *event)
    {
        QPainter paint(this);
        paint.setRenderHint(QPainter::HighQualityAntialiasing);

        paint.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        //paint.fillRect(this->rect(), Qt::transparent);
        paint.setCompositionMode(QPainter::CompositionMode_SourceOver);

        if (m_isAction)
        {
            paint.setPen(Qt::NoPen);//设置画笔形式
            paint.setBrush(QBrush("#fd4d4d", Qt::SolidPattern));//设置画刷形式

            if (m_isChecked)
            {
                // 激活，选中，大圆
                float x = (m_c_Width - m_c_MiniD) / 2;
                float y = 5 ;
                float w = m_c_MiniD;
                float h = m_c_MiniD;
                QRectF r(x, y, w, h);
                paint.drawEllipse(r);

                {
                    paint.setPen(QPen(QColor("#fd4d4d"), 2));
                    float x = (m_c_Width - m_c_D) / 2;
                    float y = 2;
                    float w = m_c_D;
                    float h = m_c_D;
                    float a0 = alpha;
                    float a = 90;

                    QRectF r(x, y, w, h);
                    paint.drawArc(r, a0 * 16, a * 16);
                    paint.drawArc(r, (a0+180)*16, a*16);
                }
            }
            else
            {
                // 激活，未选中，小圆
                float x = (m_c_Width - m_c_MiniD) / 2;
                float y = (m_c_Height - m_c_MiniD) / 2;
                float w = m_c_MiniD;
                float h = m_c_MiniD;
                QRectF r(x, y, w, h);
                paint.drawEllipse(r);

                paint.setPen(QPen(QColor("#fd4d4d"),1));
                if (!m_isBegin)
                {
                    float x1= m_c_Width/2;
                    float y1= 0;
                    float x2 = m_c_Width / 2;
                    float y2= static_cast<int>(y)-2-4;
                    QPointF p1(x1, y1);
                    QPointF p2(x2, y2);
                    paint.drawLine(p1,p2);
                }
                if (!m_isEnd)
                {
                    float x1 = m_c_Width / 2;
                    float y1 = y + h + 1+4;
                    float x2 = m_c_Width / 2;
                    float y2 = m_c_Height;
                    QPointF p1(x1, y1);
                    QPointF p2(x2, y2);
                    paint.drawLine(p1, p2);
                }
            }
        }
        else
        {
            // 未激活，灰色
            paint.setPen(Qt::NoPen);//设置画笔形式
            paint.setBrush(QBrush(Qt::gray, Qt::SolidPattern));//设置画刷形式
            float x = (m_c_Width  - m_c_MiniD) /2;
            float y = (m_c_Height - m_c_MiniD) / 2;
            float w = m_c_MiniD;
            float h = m_c_MiniD;
            QRectF r(x, y, w, h);
            paint.drawEllipse(r);
        }
    }

    void time_line_label::UI_NoCheck()
    {
        ui->label_Title->move(22, 7);
        ui->label_ProgressBackground->hide();
        ui->label_ProgressBar->hide();
        timer->stop();
    }

    void time_line_label::UI_Checked()
    {
        ui->label_Title->move(22, 0);
        ui->label_ProgressBackground->show();
        ui->label_ProgressBar->show();
        timer->start();
    }

    void time_line_label::setAction(bool value)
    {
        m_isAction = value;
        update();
    }

    void time_line_label::setChecked(bool value)
    {
        m_isChecked = value;
        m_isChecked ? UI_Checked(): UI_NoCheck();
        update();
    }

    void time_line_label::setBegin(bool value)
    {
        m_isBegin = value;
        update();
    }

    void time_line_label::setEnd(bool value)
    {
        m_isEnd = value;
        update();
    }

    bool time_line_label::isAction()
    {
        return m_isAction;
    }

    bool time_line_label::isChecked()
    {
        return m_isChecked;
    }
    void time_line_label::timeout()
    {
        alpha+=5;
        if (alpha > 360)alpha = 0;
        update();
    }
} // tianli

//
// Created by YuSuiXian on 2023/2/9.
//

#ifndef TIANLI_INSTALLER_TIANLI_WIDGET_H
#define TIANLI_INSTALLER_TIANLI_WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include "ui_tianli_widget.h"

namespace tianli
{
    class tianli_widget : public QWidget
    {
        Q_OBJECT

    public:
        explicit tianli_widget(QWidget *parent = nullptr);

        ~tianli_widget() override;

    private:
        QGraphicsDropShadowEffect *mainShadow_A;
        QGraphicsDropShadowEffect *mainShadow_B;
        QGraphicsDropShadowEffect *mainShadow;
        QPropertyAnimation *mainShadowAnimation;
        QPropertyAnimation *exitAnimation;
        QPropertyAnimation *exitAnimation_hide;

    private:
        QPoint m_Press;
        QPoint m_Move;
        bool leftBtnClk = false;
        void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
        void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

    private:
        bool eventFilter(QObject *object, QEvent *event) Q_DECL_OVERRIDE;
    public slots:
        void on_screen_changed(qreal dpi);
    private slots:
        void pushButton_UI_Close();
        void pushButton_UI_Mini();
        void pushButton_FastInstall();
        void pushButton_CustomizeInstall();
        void pushButton_Finishing_Cancel();
        void pushButton_Finished_Run();
        void pushButton_Finished_Exit();
    signals:
        void signal_fast_install();
        void signal_customize_install();
        void signal_finishing_cancel();
        void signal_finished_run();
        void signal_finished_exit();

    private:
        Ui::tianli_widget ui;
    };
} // tianli

#endif // TIANLI_INSTALLER_TIANLI_WIDGET_H

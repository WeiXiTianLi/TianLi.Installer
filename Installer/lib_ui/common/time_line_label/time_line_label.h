//
// Created by YuSuiXian on 2023/2/9.
//

#ifndef TIANLI_INSTALLER_TIME_LINE_LABEL_H
#define TIANLI_INSTALLER_TIME_LINE_LABEL_H

#include <QWidget>

namespace tianli {
    QT_BEGIN_NAMESPACE
    namespace Ui { class time_line_label; }
    QT_END_NAMESPACE

    class time_line_label : public QWidget {
    Q_OBJECT

    public:
        explicit time_line_label(QWidget *parent = nullptr);
        explicit time_line_label(QString step_name, QWidget *parent = nullptr);

        ~time_line_label() override;

    private:
        Ui::time_line_label *ui;


    private:
        void paintEvent(QPaintEvent* event);

    private:
        void UI_NoCheck();
        void UI_Checked();
    private:
        QTimer *timer;
    private:
        // һЩ���� ����

        // �Ƿ�ѡ��
        bool m_isChecked = false;
        // �Ƿ񼤻�
        bool m_isAction = false;
        // �Ƿ��ǵ�һ��
        bool m_isBegin = false;
        // �Ƿ������һ��
        bool m_isEnd = false;
        // �Ƕ�
        int alpha = 0;
    public:
        void setStepName(QString name);
        void setAction(bool value);
        void setChecked(bool value);
        void setBegin(bool value);
        void setEnd(bool value);
        bool isAction();
        bool isChecked();
    private slots:
        void timeout();
    signals:
        void checkChange();
    private:
        // һЩ���� ��ͼ��
        float m_c_Width = 21;
        float m_c_Height = 31;
        float m_c_MiniD = 7;
        float m_c_D = 13;
        float m_c_Magin = 5.0;
        float m_Angle = 0;

    };
} // tianli

#endif //TIANLI_INSTALLER_TIME_LINE_LABEL_H

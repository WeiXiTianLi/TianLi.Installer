//
// Created by YuSuiXian on 2023/2/9.
//

#ifndef TIANLI_INSTALLER_TIANLI_WIDGET_H
#define TIANLI_INSTALLER_TIANLI_WIDGET_H

#include <QWidget>

namespace tianli {
    QT_BEGIN_NAMESPACE
    namespace Ui { class tianli_widget; }
    QT_END_NAMESPACE

    class tianli_widget : public QWidget {
    Q_OBJECT

    public:
        explicit tianli_widget(QWidget *parent = nullptr);

        ~tianli_widget() override;

    private:
        Ui::tianli_widget *ui;
    };
} // tianli

#endif //TIANLI_INSTALLER_TIANLI_WIDGET_H

//
// Created by YuSuiXian on 2023/1/23.
//

#ifndef TIANLI_INSTALLER_ROUNDED_RECTANGLE_H
#define TIANLI_INSTALLER_ROUNDED_RECTANGLE_H

#include <QWidget>

namespace tianli {
    QT_BEGIN_NAMESPACE
    namespace Ui { class rounded_rectangle; }
    QT_END_NAMESPACE

    class rounded_rectangle : public QWidget {
        Q_OBJECT

    public:
        explicit rounded_rectangle(QWidget *parent = nullptr);

        ~rounded_rectangle() override;

    private:
        Ui::rounded_rectangle *ui;
    };
} // tianli

#endif //TIANLI_INSTALLER_ROUNDED_RECTANGLE_H

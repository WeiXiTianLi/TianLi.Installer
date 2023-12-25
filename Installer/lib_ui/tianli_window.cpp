#include "tianli_window.h"
#include "tianli_widget.h"
#include "QApplication"
#include "QObject"

namespace tianli
{
    class tianli_widget;
    namespace ui
    {
        std::shared_ptr<tianli::tianli_widget> create(int argc, char *argv[])
        {
            QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
            QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
            QApplication::setAttribute(Qt::AA_UseOpenGLES);
            static QApplication a(argc, argv);
            auto widget = std::make_shared<tianli::tianli_widget>();
            widget->show();
            return widget;
        }
        int exec(std::shared_ptr<tianli::tianli_widget> &widget)
        {
            return QApplication::exec();
        }
    } // namespace ui
} // namespace tianli

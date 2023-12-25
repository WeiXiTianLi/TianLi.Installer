#pragma once
#include <memory>

namespace tianli
{
    class tianli_widget;
    namespace ui
    {
        std::shared_ptr<tianli::tianli_widget> create(int argc, char *argv[]);
        int exec(std::shared_ptr<tianli::tianli_widget> &widget);
    } // namespace ui
} // namespace tianli

#include "Border.h"

Border::Border(Glyph* component, int borderWidth)
    : MonoGlyph(component)
    , borderWidth_(borderWidth)
{
}

void Border::Draw(Window* window)
{
    // 先委托给被装饰对象完成原始绘制，再叠加边框效果。
    MonoGlyph::Draw(window);
    DrawBorder(window);
}

void Border::DrawBorder(Window* window)
{
    (void)window;
    (void)borderWidth_;
}

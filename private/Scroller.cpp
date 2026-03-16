#include "Scroller.h"

Scroller::Scroller(Glyph* component)
    : MonoGlyph(component)
{
}

void Scroller::Draw(Window* window)
{
    // 保持对外接口不变，把额外的滚动装饰封装在内部。
    MonoGlyph::Draw(window);
    DrawScrollBar(window);
}

void Scroller::DrawScrollBar(Window* window)
{
    (void)window;
}

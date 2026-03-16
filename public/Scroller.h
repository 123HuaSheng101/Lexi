#pragma once

#include "MonoGlyph.h"

// Scroller 也是具体装饰器。
// 它扩展的是滚动相关的显示职责，而不是修改被装饰对象本身的接口。
class Scroller : public MonoGlyph
{
public:
    explicit Scroller(Glyph* component = nullptr);
    ~Scroller() override = default;

    void Draw(Window* window) override;

    void DrawScrollBar(Window* window);
};

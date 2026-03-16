#pragma once

#include "MonoGlyph.h"

// Border 是具体装饰器。
// 它在保留原始图元 Draw 行为的同时，再额外附加边框绘制逻辑。
class Border : public MonoGlyph
{
public:
    explicit Border(Glyph* component = nullptr, int borderWidth = 1);
    ~Border() override = default;

    void Draw(Window* window) override;

    // DrawBorder 表示 Border 自己新增的职责。
    void DrawBorder(Window* window);

private:
    int borderWidth_;
};

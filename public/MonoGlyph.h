#pragma once

#include "Glyph.h"

// MonoGlyph 是装饰器抽象类。
// 它只持有一个被装饰的 component，并把大部分请求透明地转发给这个 component。
class MonoGlyph : public Glyph
{
public:
    explicit MonoGlyph(Glyph* component = nullptr);
    ~MonoGlyph() override;


    void SetComponent(Glyph* component);

protected:
    Glyph* component_;
};

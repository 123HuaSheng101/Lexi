#pragma once

#include <vector>

#include "Glyph.h"

class Compositor;
//组合模式
// Composition 是可以包含多个 Glyph 子节点的复合对象，并把排版工作委托给 Compositor。
class Composition : public Glyph
{
public:
    explicit Composition(Compositor* compositor = nullptr);
    ~Composition() override = default;

    void Insert(Glyph* glyph, int index) override;
    void Remove(Glyph* glyph) override;
    Glyph* Child(int index) override;

    void SetCompositor(Compositor* compositor);
    int Count() const;

private:
    std::vector<Glyph*> children_;
    Compositor* compositor_;
};

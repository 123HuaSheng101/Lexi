#include "Glyph.h"

Glyph::Glyph()
    : parent_(nullptr)
{
}

Glyph::~Glyph() = default;

void Glyph::Draw(Window* window)
{
    (void)window;
}

void Glyph::Bounds(Rect& rect)
{
    (void)rect;
}

void Glyph::Intersects(const Point& point)
{
    (void)point;
}

void Glyph::Insert(Glyph* glyph, int index)
{
    (void)glyph;
    (void)index;
}

void Glyph::Remove(Glyph* glyph)
{
    (void)glyph;
}

Glyph* Glyph::Child(int index)
{
    (void)index;
    return nullptr;
}

Glyph* Glyph::Parent()
{
    return parent_;
}

void Glyph::SetParent(Glyph* parent)
{
    parent_ = parent;
}

void Glyph::AttachChild(Glyph* child)
{
    if (child != nullptr)
    {
        child->parent_ = this;
    }
}

void Glyph::DetachChild(Glyph* child)
{
    if (child != nullptr && child->parent_ == this)
    {
        child->parent_ = nullptr;
    }
}

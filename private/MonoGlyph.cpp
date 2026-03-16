#include "MonoGlyph.h"

MonoGlyph::MonoGlyph(Glyph* component)
    : component_(nullptr)
{
    SetComponent(component);
}

MonoGlyph::~MonoGlyph()
{
    DetachChild(component_);
}

void MonoGlyph::Draw(Window* window)
{
    if (component_ != nullptr)
    {
        component_->Draw(window);
    }
}

void MonoGlyph::Bounds(Rect& rect)
{
    if (component_ != nullptr)
    {
        component_->Bounds(rect);
    }
}

void MonoGlyph::Intersects(const Point& point)
{
    if (component_ != nullptr)
    {
        component_->Intersects(point);
    }
}

void MonoGlyph::Insert(Glyph* glyph, int index)
{
    if (component_ != nullptr)
    {
        component_->Insert(glyph, index);
    }
}

void MonoGlyph::Remove(Glyph* glyph)
{
    if (component_ != nullptr)
    {
        component_->Remove(glyph);
    }
}

Glyph* MonoGlyph::Child(int index)
{
    if (index == 0)
    {
        return component_;
    }

    return nullptr;
}

void MonoGlyph::SetComponent(Glyph* component)
{
    if (component_ == component)
    {
        return;
    }

    DetachChild(component_);
    component_ = component;
    AttachChild(component_);
}

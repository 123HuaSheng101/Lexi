#include "Composition.h"

#include <algorithm>

#include "Compositor.h"

Composition::Composition(Compositor* compositor)
    : compositor_(nullptr)
{
    SetCompositor(compositor);
}

void Composition::Insert(Glyph* glyph, int index)
{
    if (glyph == nullptr)
    {
        return;
    }

    if (index < 0)
    {
        index = 0;
    }
    else if (index > static_cast<int>(children_.size()))
    {
        index = static_cast<int>(children_.size());
    }

    children_.insert(children_.begin() + index, glyph);
    glyph->SetParent(this);

    if (compositor_ != nullptr)
    {
        compositor_->Compose();
    }
}

void Composition::Remove(Glyph* glyph)
{
    const auto it = std::find(children_.begin(), children_.end(), glyph);
    if (it == children_.end())
    {
        return;
    }

    (*it)->SetParent(nullptr);
    children_.erase(it);

    if (compositor_ != nullptr)
    {
        compositor_->Compose();
    }
}

Glyph* Composition::Child(int index)
{
    if (index < 0 || index >= static_cast<int>(children_.size()))
    {
        return nullptr;
    }

    return children_[index];
}

void Composition::SetCompositor(Compositor* compositor)
{
    compositor_ = compositor;
    if (compositor_ != nullptr)
    {
        compositor_->SetComposition(this);
    }
}

int Composition::Count() const
{
    return static_cast<int>(children_.size());
}

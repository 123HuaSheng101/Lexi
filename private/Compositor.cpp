#include "Compositor.h"

#include "Composition.h"

Compositor::Compositor()
    : composition_(nullptr)
{
}

Compositor::~Compositor() = default;

void Compositor::SetComposition(Composition* composition)
{
    composition_ = composition;
}

void ArrayCompositor::Compose()
{
    if (composition_ == nullptr)
    {
        return;
    }

    for (int index = 0; index < composition_->Count(); ++index)
    {
        (void)composition_->Child(index);
    }
}

void TexCompositor::Compose()
{
    if (composition_ == nullptr)
    {
        return;
    }

    for (int index = 0; index < composition_->Count(); ++index)
    {
        (void)composition_->Child(index);
    }
}

void SimpleCompositor::Compose()
{
    if (composition_ == nullptr)
    {
        return;
    }

    for (int index = 0; index < composition_->Count(); ++index)
    {
        (void)composition_->Child(index);
    }
}

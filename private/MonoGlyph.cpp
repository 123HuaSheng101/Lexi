#include "MonoGlyph.h"

MonoGlyph::MonoGlyph(Glyph *component):component_(component)
{
}

void MonoGlyph::Draw(Window *window)
{
    component_->Draw(window);
}

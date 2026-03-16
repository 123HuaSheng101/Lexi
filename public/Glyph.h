#pragma once

class Composition;
class Window;
class Rect;
class Point;

// Glyph 是所有图元对象的抽象基类，统一定义绘制、层级和子节点管理接口。
class Glyph
{
public:
    Glyph();
    virtual ~Glyph();

    virtual void Draw(Window* window);
    virtual void Bounds(Rect& rect);
    virtual void Intersects(const Point& point);
    virtual void Insert(Glyph* glyph, int index);
    virtual void Remove(Glyph* glyph);
    virtual Glyph* Child(int index);
    virtual Glyph* Parent();

protected:
    void SetParent(Glyph* parent);
    void AttachChild(Glyph* child);
    void DetachChild(Glyph* child);

private:
    friend class Composition;

    Glyph* parent_;
};

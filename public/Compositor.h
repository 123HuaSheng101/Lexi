#pragma once

class Composition;

// Compositor 是排版策略抽象类，负责为 Composition 组织子节点的布局。
class Compositor
{
public:
    Compositor();
    virtual ~Compositor();

    virtual void Compose() = 0;
    virtual void SetComposition(Composition* composition);

protected:
    Composition* composition_;
};

// ArrayCompositor 表示按顺序数组方式处理子节点的排版策略。
class ArrayCompositor : public Compositor
{
public:
    void Compose() override;
};

// TexCompositor 表示类似文本排版的策略，适合按行或段落组织内容。
class TexCompositor : public Compositor
{
public:
    void Compose() override;
};

// SimpleCompositor 表示最基础的排版策略，适合简单场景下快速组合子节点。
class SimpleCompositor : public Compositor
{
public:
    void Compose() override;
};

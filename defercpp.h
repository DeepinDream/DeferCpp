#pragma once

#include <functional>

class DeferCpp
{
public:
    DeferCpp(const std::function<void()> function): m_function(function){}
    ~DeferCpp(){m_function();}

private:
    std::function<void()> m_function;
};

#define DEFER_INLINE_1(x, y) x##y
#define DEFER_INLINE_2(x, y) DEFER_INLINE_1(x, y)
#define DEFER_INLINE_0(x)    DEFER_INLINE_2(x, __LINE__)
#define defer(expr)   auto DEFER_INLINE_0(_defer_) = DeferCpp([&](){expr;})

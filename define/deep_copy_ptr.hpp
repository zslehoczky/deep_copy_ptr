#pragma once

#include <memory>

namespace final
{
    template <typename T, typename D = std::default_delete<T>>
    class deep_copy_ptr : public std::unique_ptr<T, D>
    {
    public:
        explicit deep_copy_ptr(T *val = nullptr) : std::unique_ptr<T, D>{val} {}
    };
}

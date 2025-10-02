#pragma once

#include <memory>

namespace final
{
    template <typename T, typename D = std::default_delete<T>>
    class deep_copy_ptr : public std::unique_ptr<T, D>
    {
    public:
        explicit deep_copy_ptr(T *val = nullptr)
            : std::unique_ptr<T, D>{val}
        {
        }

        deep_copy_ptr(const deep_copy_ptr &other)
            : std::unique_ptr<T, D>{other.create_deep_copy_of_ptr(), other.get_deleter()}
        {
        }

        deep_copy_ptr &operator=(const deep_copy_ptr &other)
        {
            this->reset(other.create_deep_copy_of_ptr());

            return *this;
        }

        deep_copy_ptr(deep_copy_ptr &&other) = default;
        deep_copy_ptr &operator=(deep_copy_ptr &&other) = default;

    private:
        [[nodiscard]] T *create_deep_copy_of_ptr() const
        {
            if (this->operator bool())
            {
                return new T{this->operator*()};
            }

            return nullptr;
        }
    };
}

#include <deep_copy_ptr.hpp>

#include <cassert>

using namespace final;

int main()
{
    deep_copy_ptr<int> val(new int{1});
}

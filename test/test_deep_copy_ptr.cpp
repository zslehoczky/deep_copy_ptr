#include <deep_copy_ptr.hpp>

#include <cassert>

using namespace final;

int main()
{
    const deep_copy_ptr<int> val{new int{1}};

    assert(val);
    assert(*val == 1);

    deep_copy_ptr<int> val2{val};

    assert(val2);
    assert(*val2 == 1);

    assert(val.get() != val2.get());

    deep_copy_ptr<int> val3{};

    assert(!val3);

    val3 = val;

    assert(val3);
    assert(*val3 == 1);
}

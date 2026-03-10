#include <option.h>
#include <cassert>
#include <cstdlib>

using namespace Elth::functionnal;

int main() {
    Option<int> some(42);
    Option<int> none;

    assert(some);
    assert(!none);

    if (some) {
        int value = some();
        assert(value == 42);
    }

    return EXIT_SUCCESS;
}
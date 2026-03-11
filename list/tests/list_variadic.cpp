#include <list.h>
#include <cassert>

using namespace Elth::functionnal;

int main() 
{
    List<int> l0(0, 1, 2);
    assert(l0.at(0) == 0);
    assert(l0.at(1) == 1);
    assert(l0.at(2) == 2);

    return EXIT_SUCCESS;
}
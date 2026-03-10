#include <list.h>
#include <cassert>
#include <cstdlib>

using namespace Elth::functionnal;

int main() 
{
    List<int> l0;
    assert(l0.count() == 0);

    List<int> l1(0);
    assert(l1[0] == 0);
    assert(l1[0] == l1.at(0));
    assert(l1.count() == 1);

    List l2(l1);
    assert(l1[0] == l2[0]);
    assert(l1.at(0) == l2.at(0));
    assert(l1.count() == l2.count());

    return EXIT_SUCCESS;
}
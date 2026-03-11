#include <list.h>
#include <cassert>

using namespace Elth::functionnal;

int main() 
{
    List<int> l0(0);
    List<int> l1 = l0.pushFront(1);
    List<int> l2 = l1.pushFront(2);

    assert(l0.at(0) == 0);
    assert(l1.at(0) == 1); 
    assert(l1.at(1) == 0);
    assert(l2.at(0) == 2);
    assert(l2.at(1) == 1); 
    assert(l2.at(2) == 0);

    return EXIT_SUCCESS;
}
#include <list.h>
#include <cassert>
#include <cstdlib>

int main() 
{
    List<int> l0;
    assert(l0.count() == 0);

    List<int> l1(0);
    assert(*l1[0] == 0);
    assert(*l1[0] == l1.at(0));
    assert(*l1[0] == *l1);
    assert(l1.count() == 1);

    List<int> l2 = l1.pushFront(1);
    assert(*l2[0] == 1);
    assert(*l2[1] == 0);
    assert(*l2[0] == l2.at(0));
    assert(*l2[1] == l2.at(1));
    assert(l2.count() == 2);

    return EXIT_SUCCESS;
}
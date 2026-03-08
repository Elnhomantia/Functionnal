#include <list.h>
#include <cassert>
#include <cstdlib>

int main() 
{
    List<int> l0(0);
    List<int> l1= l0.pushFront(1);
    assert(&(*l1[1]) == &(*l0[0]));

    return EXIT_SUCCESS;
}
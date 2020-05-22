#include "1_lineList/cycleSingle/CycleSingleChainLine.h"
#include <iostream>

using namespace std;

int main() {
    SLinkList list = initSLinkList();
    tailInsert(list);
    printSLinkList(list);
    iteratorDeleteMin(list);
    return 0;
}
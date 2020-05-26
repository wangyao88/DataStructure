#include "1_lineList/singleChainLine.h"
#include <iostream>

using namespace std;

int main() {
    LinkList list;
    tailInsert(list);
    print(list);
    evenReverseOrder(list);
    print(list);
    return 0;
}
#include "1_lineList/singleChainLine.h"
#include <iostream>

using namespace std;

int main() {
    LinkList left;
    tailInsert(left);
    print(left);

    LinkList right;
    tailInsert(right);
    print(right);

    LNode *commonNode = findCommonNode(left, right);
    print(commonNode);
    return 0;
}
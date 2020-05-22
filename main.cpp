#include "1_lineList/cycleDouble/CycleDoubleChainLine.h"
#include <iostream>

using namespace std;

int main() {
    DLinkList symmetryLinkList = initDLinkList();
    tailInsert(symmetryLinkList, 1);
    tailInsert(symmetryLinkList, 2);
    tailInsert(symmetryLinkList, 2);
    tailInsert(symmetryLinkList, 1);
    printDLinkList(symmetryLinkList);
    bool symmetry = isSymmetry(symmetryLinkList);
    cout << (symmetry ? "对称" : "不对称") << endl;

    DLinkList notSymmetryLinkList = initDLinkList();
    tailInsert(notSymmetryLinkList, 1);
    tailInsert(notSymmetryLinkList, 2);
    tailInsert(notSymmetryLinkList, 3);
    tailInsert(notSymmetryLinkList, 1);
    printDLinkList(notSymmetryLinkList);
    symmetry = isSymmetry(notSymmetryLinkList);
    cout << (symmetry ? "对称" : "不对称") << endl;
    return 0;
}
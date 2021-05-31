#include <iostream>
#include "tree.h"
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));

    vector<double> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(rand() % 1000 / 10.0);
    }

    VTree<double> myTree(vec);
    cout << myTree.ToString() << endl;

    myTree.ToBalancedTree();
    cout << myTree.ToString() << endl;

    myTree.ToSearchTree();
    cout << myTree.ToString() << endl;

    cout << "MIN = " << myTree.Min() << endl;
}
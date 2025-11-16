#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);

    cout << "Stack setelah input:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}

void getInputStream(Stack &S) {
    char input;
    cout << "Masukkan angka (tekan Enter untuk selesai):" << endl;
    while (true) {
        input = cin.get();
        if (input == '\n') {
            break;
        }
        push(S, input - '0');
    }
}
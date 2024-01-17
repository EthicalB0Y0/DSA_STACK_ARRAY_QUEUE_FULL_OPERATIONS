#include <iostream>
#include <algorithm>
using namespace std;

class stack1 {
private:
    int num[5], top, max_size;

public:
    stack1();
    void push();
    void pop();
    int get_top();
    int display();
    void info();
    void reverse();
    void sort();
    void max_min();
};

stack1::stack1() {
    top = -1;
    max_size = 5;
}

void stack1::push() {
    int n;
    if (top < max_size - 1) {
        cout << "\tEnter how many times you want to push: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int t;
            cout << "\tEnter the value: ";
            cin >> t;
            if (top < max_size - 1) {
                top++;
                num[top] = t;
                cout << "\tValue pushed into the stack.\n";
            } else {
                cout << "\tStack is Full. Cannot push more elements.\n";
                break;
            }
        }
    } else {
        cout << "\tStack is Full. Cannot push more elements.\n";
    }
}

void stack1::pop() {
    if (top == -1) {
        cout << "\tStack is empty. Cannot pop.\n";
    } else {
        cout << "\tPopped element: " << num[top] << "\n";
        top--;
    }
}

int stack1::get_top() {
    if (top != -1) {
        return num[top];
    } else {
        return -1;
    }
}

int stack1::display() {
    if (top == -1) {
        cout << "\tStack is empty.\n";
    } else {
        cout << "\tValues in the stack:\n";
        for (int i = 0; i <= top; i++) {
            cout << "\t" << num[i] << "\n";
        }
    }
    return 0;
}

void stack1::info() {
    if (top == -1) {
        cout << "\tStack is currently empty.\n";
    } else if (top == max_size - 1) {
        cout << "\tStack is full.\n";
    } else {
        cout << "\tStack is not full.\n";
    }
}

void stack1::reverse() {
    if (top == -1) {
        cout << "\tStack is empty. Cannot reverse.\n";
    } else {
        int start = 0;
        int end = top;

        while (start < end) {
            int temp = num[start];
            num[start] = num[end];
            num[end] = temp;
            start++;
            end--;
        }

        cout << "\tStack elements after reverse:\n";
        display();
    }
}

void stack1::sort() {
    if (top == -1) {
        cout << "\tStack is empty. Cannot sort.\n";
    } else {
        std::sort(num, num + top + 1);
        cout << "\tStack sorted.\n";
    }
}

void stack1::max_min() {
    if (top == -1) {
        cout << "\tStack is empty. Cannot find max and min.\n";
    } else {
        int max = num[0];
        int min = num[0];

        for (int i = 1; i <= top; ++i) {
            if (num[i] > max) {
                max = num[i];
            }
            if (num[i] < min) {
                min = num[i];
            }
        }

        cout << "\tMax element: " << max << "\n";
        cout << "\tMin element: " << min << "\n";
    }
}

int main() {
    stack1 s1;
    stack1 s2;
    int choice;
    bool identical;

    cout << "\n\tWelcome to the Stack Program!\n";

    do {
        cout << "\n\t1. Push element into stack 1\n";
        cout << "\t2. Pop element from stack 1\n";
        cout << "\t3. Display stack 1\n";
        cout << "\t4. Check stack 1 info\n";
        cout << "\t5. Get top element of stack 1\n";
        cout << "\t6. Reverse stack 1\n";
        cout << "\t7. Sort stack 1\n";
        cout << "\t8. Max and Min of stack 1\n";
        cout << "\t9. Push element into stack 2\n"; 
        cout << "\t10. Compare stack 1 and stack 2\n";
        cout << "\t11. Exit\n";
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s1.push();
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                s1.info();
                break;
            case 5:
                cout << "\tTop element of s1: " << s1.get_top() << "\n";
                break;
            case 6:
                s1.reverse();
                break;
            case 7:
                s1.sort();
                break;
            case 8:
                s1.max_min();
                break;
            case 9:
                s2.push(); 
                break;
            case 10:
                cout << "\n\tChecking if they are identical or not\n";
                identical = true;
                for (int i = 0; i < 5; i++) {
                    if (s1.get_top() != s2.get_top()) {
                        identical = false;
                        break;
                    }
                    s1.pop();
                    s2.pop();
                }

                if (identical) {
                    cout << "\n\tStacks are identical \n";
                } else {
                    cout << "\n\tStacks are not identical \n";
                }
                break;
            case 11:
                cout << "\tExiting program.\n";
                break;
            default:
                cout << "\tInvalid choice. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

class array1 {
private:
    int arr[5];

public:
    void input();
    void dlt_insert();
    void display();
    void just_dlt();
    void reverse();
    void average();
    void sorting();
    void max_min();
};

void array1::input() {
    cout << "\n\tEnter the elements of array: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tEnter array element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void array1::dlt_insert() {
    int p, n;
    cout << "\n\tEnter the position you want to delete/insert: ";
    cin >> p;
    if (p >= 0 && p < 5) {
        cout << "\tEnter the new value: ";
        cin >> n;
        arr[p] = n;
        cout << "\n\tValue updated" << endl;
    }
    else {
        cout << "\tInvalid position" << endl;
    }
}

void array1::display() {
    cout << "\n\tArray elements are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void array1::just_dlt() {
    int p;
    cout << "\n\tEnter the position you want to remove: ";
    cin >> p;
    if (p >= 0 && p < 5) {
        for (int i = p; i < 4; i++) {
            arr[i] = arr[i + 1];
        }
        arr[4] = 0;
        cout << "\n\tElement at position " << p << " deleted" << endl;
    }
    else {
        cout << "\tInvalid choice" << endl;
    }
}

void array1::reverse() {
    int start = 0;
    int end = 4;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    cout << "\n\tArray elements after reverse:" << endl;
}

void array1::max_min() {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "\n\tMax element: " << max << endl;
    cout << "\n\tMin element: " << min << endl;
}

void array1::average() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    float average = sum / 5.0;
    cout << "\n\tAverage is: " << average << endl;
}

void array1::sorting() {
    sort(arr, arr + 5);
    cout << "\n\tArray sorted" << endl;
}

int main() {
    array1 obj;
    int choice;
    cout << "\n\tWelcome to the Array operation Program!\n";
    do {
        cout << "\n\tChoose an operation:\n";
        cout << "\t1. Input and Sort\n";
        cout << "\t2. Display\n";
        cout << "\t3. Find Max and Min\n";
        cout << "\t4. Reverse\n";
        cout << "\t5. Calculate Average\n";
        cout << "\t6. Delete/Insert\n";
        cout << "\t7. Just Delete\n";
        cout << "\t8. Exit\n";
        cout << "\tEnter your choice (1-8): ";

        cin >> choice;

        switch (choice) {
            case 1:
                obj.input();
                obj.sorting();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.max_min();
                break;
            case 4:
                obj.reverse();
                obj.display();
                break;
            case 5:
                obj.average();
                break;
            case 6:
                obj.dlt_insert();
                obj.display();
                break;
            case 7:
                obj.just_dlt();
                obj.display();
                break;
            case 8:
                cout << "\tExiting program.\n";
                break;
            default:
                cout << "\tInvalid choice. Please enter a number between 1 and 8.\n";
        }

    } while (choice != 8);

    return 0;
}


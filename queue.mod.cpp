#include <iostream>
#include <algorithm>
using namespace std;

class queue {
private:
    int rear, front;
    int Queue[50];
    int max;
    int size;

public:
    queue() {
        size = 0;
        max = 5;
        rear = front = -1;
    }
    int is_empty();
    int is_full();
    void add(int element);
    int delete_item();
    int getfront();
    void display();
    void max_min();
    void reverse();
    void sorting();
};

int queue::is_empty() {
    return front == rear;
}

int queue::is_full() {
    return rear == max - 1;
}

void queue::add(int element) {
    if (!is_full()) {
        Queue[++rear] = element;
        size++;
        cout << "\tElement " << element << " added to the queue." << endl;
    } else {
        cout << "\tQueue is full. Cannot add element." << endl;
    }
}

int queue::delete_item() {
    if (!is_empty()) {
        size--;
        return Queue[++front];
    } else {
        cout << "\tQueue is empty. Cannot delete element." << endl;
        return 0;
    }
}

int queue::getfront() {
    if (!is_empty()) {
        return Queue[front + 1];
    } else {
        cout << "\tQueue is empty." << endl;
        return 0;
    }
}

void queue::display() {
    if (is_empty()) {
        cout << "\tQueue is empty." << endl;
    } else {
        cout << "\tElements in the queue: ";
        for (int i = front + 1; i <= rear; ++i) {
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
}

void queue::max_min() {
    if (is_empty()) {
        cout << "\tQueue is empty." << endl;
    } else {
        int max = Queue[front + 1];
        int min = Queue[front + 1];

        for (int i = front + 1; i <= rear; ++i) {
            if (Queue[i] > max) {
                max = Queue[i];
            }
            if (Queue[i] < min) {
                min = Queue[i];
            }
        }

        cout << "\tMax element: " << max << endl;
        cout << "\tMin element: " << min << endl;
    }
}

void queue::reverse() {
    if (is_empty()) {
        cout << "\tQueue is empty." << endl;
    } else {
        int start = front + 1;
        int end = rear;

        while (start < end) {
            int temp = Queue[start];
            Queue[start] = Queue[end];
            Queue[end] = temp;
            start++;
            end--;
        }

        cout << "\tQueue elements after reverse: ";
        display();
    }
}

void queue::sorting() {
    if (is_empty()) {
        cout << "\tQueue is empty." << endl;
    } else {
        sort(Queue + front + 1, Queue + rear + 1);
        cout << "\tQueue sorted." << endl;
    }
}

int main() {
    queue obj;
    int choice;

    cout << "\n\tWelcome to the Queue Program!\n";

    do {
        cout << "\n\t1. Add element\n";
        cout << "\t2. Delete element\n";
        cout << "\t3. Get front element\n";
        cout << "\t4. Display elements\n";
        cout << "\t5. Max and Min\n";
        cout << "\t6. Reverse\n";
        cout << "\t7. Sort\n";
        cout << "\t8. Exit\n";
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "\tEnter element to add: ";
                cin >> element;
                obj.add(element);
                break;
            case 2:
                obj.delete_item();
                break;
            case 3:
                cout << "\tFront element: " << obj.getfront() << endl;
                break;
            case 4:
                obj.display();
                break;
            case 5:
                obj.max_min();
                break;
            case 6:
                obj.reverse();
                break;
            case 7:
                obj.sorting();
                break;
            case 8:
                cout << "\tExiting program.\n";
                break;
            default:
                cout << "\tInvalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}


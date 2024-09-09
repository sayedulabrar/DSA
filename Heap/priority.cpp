#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ar {
    int id;
    int value;
};

struct Compare {
    bool operator()(const ar& a, const ar& b) {
        return a.value > b.value; // Min heap
    }
};

priority_queue<ar, vector<ar>, Compare> pq;
int n = 0;

void print() {
    cout << endl;
    // Printing in sorted order
    while (!pq.empty()) {
        cout << pq.top().value << " ";
        pq.pop();
    }
    cout << endl << endl;
}

void insertt(int v, int cd) {
    ar x;
    x.id = cd;
    x.value = v;
    pq.push(x);
    n++;
}

int extractmin() {
    if (pq.empty())
        return 9999; // or any other appropriate value
    int x = pq.top().value;
    pq.pop();
    n--;
    return x;
}

void decreasekey(int c, int d) {
    // As priority_queue doesn't support decrease key operation directly,
    // we can simulate it by removing the element and re-inserting with updated value
    priority_queue<ar, vector<ar>, Compare> new_pq;
    while (!pq.empty()) {
        ar curr = pq.top();
        pq.pop();
        if (curr.id == c) {
            curr.value = d;
        }
        new_pq.push(curr);
    }
    pq = new_pq; // Assigning the updated priority_queue
}

void sort() {
    print(); // Print before sorting
}

int size() {
    return n;
}

int top() {
    if (pq.empty())
        return 9999; // or any other appropriate value
    return pq.top().value;
}

int main() {
    cout << "1. Insert\n2. Extract min\n3. Sort\n4. decrease Key\n5. Size\n6. Print\n7. top\n8. Exit" << endl;
    int choice;
    ar aa;
    aa.id = 0;
    aa.value = 0;
    while (1) {
        cin >> choice;
        if (choice == 1) {
            int v, d;
            cin >> v >> d;
            insertt(v, d);
            cout << "item has been inserted" << endl;
        } else if (choice == 2) {
            int v = extractmin();
            cout << v << endl;
        } else if (choice == 3) {
            sort();
        } else if (choice == 4) {
            int v1, v2;
            cin >> v1 >> v2;
            decreasekey(v1, v2);
        } else if (choice == 5) {
            int s = size();
            cout << s << endl;
        } else if (choice == 6) {
            print();
        } else if (choice == 7) {
            int zz = top();
            cout << "Top element: " << zz << endl;
        } else {
            break;
        }
    }
    return 0;
}




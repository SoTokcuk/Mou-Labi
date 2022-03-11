#include <iostream>
#include "QueueP.h"
using namespace std;

void menu() {
    cout << "1 -- copy first queue" << endl;
    cout << "2 -- copy first queue, delete first three elements, show info about first element" << endl;
    cout << "3 -- copy first queue and show size of high, medium, low and full queue" << endl;
    cout << "4 -- copy first queue and remove all the elements" << endl;
    cout << "5 -- exit" << endl;
}

int main() {
    QueueP pq;
    pq.push(2, "medium");
    pq.push(3, "medium");
    pq.push(4, "medium");
    pq.push(8, "low");
    pq.push(1, "high");
    pq.push(5, "medium");
    pq.push(6, "medium");
    pq.push(7, "medium");
    cout << "first ";
    pq.Print();
    cout << endl;
    QueueP pq2(pq);
    menu();
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("CLS");
        cout << "second ";
        pq2.Print();
        cout << endl;
        system("PAUSE");
        break;
    case 2:
        system("CLS");
        pq2.pop();
        pq2.pop();
        pq2.pop();
        pq2.InfoFirst();
        cout << endl;
        cout << "second ";
        pq2.Print();
        cout << endl;
        system("PAUSE");
        break;
    case 3:
        system("CLS");
        cout << "second ";
        pq2.Print();
        cout << endl;
        cout << "size of high: " << pq.GetSizeHigh() << endl;
        cout << "size of medium: " << pq.GetSizeMedium() << endl;
        cout << "size of low: " << pq.GetSizeLow() << endl;
        cout << "size of all queue: " << pq.GetSize() << endl;
        system("PAUSE");
        break;
    case 4:
        system("CLS");
        pq2.Print();
        cout << endl;
        while (pq2.GetSize() > 0) {
            pq2.pop();
        }
        cout << endl;
        cout << "after removing ";
        pq2.Print();
        cout << endl;
        system("PAUSE");
        break;
    case 5:
        return 0;
    }
     

    return 0;
}
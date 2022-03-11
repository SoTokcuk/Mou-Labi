#include "QueueP.h"
#include <exception>
#include <iostream>

using namespace std;

QueueP::QueueP() {}

bool QueueP::is_empty() {
    if (FirstItem == nullptr) {
        return true;
    }
    return false;
}

int QueueP::GetSizeLow() const {
    return SizeLow;
}

int QueueP::GetSizeMedium() const {
    return SizeMedium;
}

int QueueP::GetSizeHigh() const {
    return SizeHigh;
}

int QueueP::GetSize() const {
    return SizeLow + SizeMedium + SizeHigh;
}

void QueueP::push(int num, string priority) {
    if (priority == "high") {
        Queue_item* element = new Queue_item(num, priority);
        SizeHigh++;
        if (is_empty()) {
            FirstItem = element;
            LastItemHigh = element;
            return;
        }
        if (LastItemHigh == nullptr) {
            element->next = FirstItem;
            FirstItem = element;
            LastItemHigh = element;
            return;
        }
        element->next = LastItemHigh->next;
        LastItemHigh->next = element;
        LastItemHigh = element;
    }
    else if (priority == "medium") {
        Queue_item* element = new Queue_item(num, priority);
        SizeMedium++;
        if (is_empty()) {
            FirstItem = element;
            LastItemMedium = element;
            return;
        }
        if (LastItemHigh == nullptr && LastItemMedium == nullptr) {
            element->next = FirstItem;
            FirstItem = element;
            LastItemMedium = element;
            return;
        }
        if (LastItemMedium == nullptr) {
            element->next = LastItemHigh->next;
            LastItemHigh->next = element;
            LastItemMedium = element;
            return;
        }
        element->next = LastItemMedium->next;
        LastItemMedium->next = element;
        LastItemMedium = element;
    }
    else if (priority == "low") {
        Queue_item* element = new Queue_item(num, priority);
        SizeLow++;
        if (is_empty()) {
            FirstItem = element;
            LastItemLow = element;
            return;
        }
        if (LastItemMedium == nullptr && LastItemLow == nullptr) {
            LastItemHigh->next = element;
            LastItemLow = element;
            return;
        }
        if (LastItemLow == nullptr && LastItemHigh == nullptr) {
            LastItemMedium->next = element;
            LastItemLow = element;
            return;
        }
        if (LastItemLow == nullptr) {
            LastItemMedium->next = element;
            LastItemLow = element;
            return;
        }
        LastItemLow->next = element;
        LastItemLow = element;
    }
    else
        throw exception("incoreect priority");
}

void QueueP::Print() {
    Queue_item* el = FirstItem;
    cout << "queue:";
    while (el != nullptr) {
        cout << ' ' << el->value;
        el = el->next;
    }
}

void QueueP::pop() {
    if (FirstItem == nullptr) {
        return;
    }
    Queue_item* el = FirstItem->next;
    if (FirstItem->priority == "high")
        SizeHigh--;
    if (FirstItem->priority == "medium")
        SizeMedium--;
    if (FirstItem->priority == "low")
        SizeLow--;
    if (SizeHigh == 0)
        LastItemHigh = nullptr;
    if (SizeMedium == 0)
        LastItemMedium = nullptr;
    if (SizeLow == 0)
        LastItemLow = nullptr;
    delete FirstItem;
    FirstItem = el;
}

void QueueP::operator=(QueueP& pq) {
    Queue_item* el = pq.FirstItem;
    QueueP out;
    if (this == &pq) {
        return;
    }

    while (FirstItem != nullptr) {
        pop();
    }
    while (el != nullptr) {
        push(el->value, el->priority);
        el = el->next;
    }
}

void QueueP::InfoFirst() {
    if (FirstItem == nullptr) {
        std::cout << "queue is empty";
        return;
    }
    std::cout << "first element: " << FirstItem->value << " priority: " << FirstItem->priority << endl;
}

QueueP::QueueP(QueueP& pq) {
    if (this == &pq) {
        return;
    }

    while (FirstItem != nullptr) {
        pop();
    }

    Queue_item* el = pq.FirstItem;

    while (el != nullptr) {
        push(el->value, el->priority);
        el = el->next;
    }
}
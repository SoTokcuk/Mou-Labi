#pragma once

#include <string>

using namespace std;

class QueueP {
public:
    QueueP();
    QueueP(QueueP& pq);
    QueueP(QueueP&& pq) noexcept:
        FirstItem(move(pq.FirstItem)), LastItemHigh(move(pq.LastItemHigh)),
        LastItemMedium(move(pq.LastItemMedium)), LastItemLow(move(pq.LastItemLow)),
        SizeHigh(move(pq.SizeHigh)), SizeMedium(move(pq.SizeMedium)),
        SizeLow(move(pq.SizeLow)) {
        pq.FirstItem = nullptr;
        pq.LastItemHigh = nullptr;
        pq.LastItemMedium = nullptr;
        pq.LastItemLow = nullptr;
        pq.SizeHigh = 0;
        pq.SizeMedium = 0;
        pq.SizeLow = 0;
    };
    void operator=(QueueP&);
    bool is_empty();
    void push(int, string);
    void pop();
    void InfoFirst();
    int GetSizeLow() const;
    int GetSizeMedium() const;
    int GetSizeHigh() const;
    int GetSize() const;
    void Print();
private:
    struct Queue_item {
        int value;
        string priority;
        Queue_item* next;

        Queue_item(int number, string prior)
            : value(number), priority(prior), next(nullptr) {};
    };
    Queue_item* FirstItem = nullptr;
    Queue_item* LastItemHigh = nullptr;
    Queue_item* LastItemMedium = nullptr;
    Queue_item* LastItemLow = nullptr;
    int SizeHigh = 0;
    int SizeMedium = 0;
    int SizeLow = 0;
};

#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = 0;
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (info[mid] == someItem) {
            return true;
        } else if (info[mid] < someItem) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

template<class T>
void SortedList<T>::AddItem(T item) {

    if (IsFull()) {
        return;
    }

    for (int i = 0; i < length; i++) {
        if (info[i] > item) {
            // Slide
            for (int j = length - 1; j >= i; j--) {
                info[j + 1] = info[j];
            }
            info[i] = item;
            length++;
            return;
        }
    }

    info[length] = item;
    length++;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {

    for (int i = 0; i < length; i++) {
        // found item
        if (info[i] == item) {
            // Slide
            for (int j = i + 1; j < length; j++) {
                info[j - 1] = info[j];
            }
            --length;
            return;
        }
    }

}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
T SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

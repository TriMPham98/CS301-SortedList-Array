
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
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

    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    if (IsFull()) {
        return;
    }

    for (int i = 0; i < length; i++) {
        if (item < info[i]) {
            for (int j = length - 1;
                 j >= i; j--) { // Shift over one for every element in the array to make space to put item
                info[j + 1] = info[j];
            }
            info[i] = item;
            length++;
            return;
        }
    }
    info[length] = item; // Add to end if item is larger than all values in array
}

template<class T>
void SortedList<T>::DeleteItem(T item) {

}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}


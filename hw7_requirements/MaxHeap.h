/*
 * File   : MaxHeap.h
 * Author : giebasjo (Jordan Giebas)
 * Class  : fdsa
 * Proj   : Hw7
 * Created on November 2, 2016, 5:03 PM
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct UnderFlow : public exception {

    string static e() throw() {

        string output = "Heap UnderFlow";
        return output;

    }

};


struct OverFlow : public exception {

    string static e() throw() {

        string output = "Heap OverFlow";
        return output;

    }

};

template<typename T>
class myMaxHeap {

    private:

        //vars
        unsigned long currentsize_;
        vector<T> heap_;

        //methods
        void percolateDown(int hole);
        void percolateUp(int hole);
        void buildHeap();

        //extra methods
        int parent(int i) { return (i - 1) / 2; }
        int left(int i) { return (2 * i + 1); }
        int right(int i) { return (2 * i + 2); }

    public:

        //Exceptions HeapOverflow and HeapUnderflow go here...
        void HeapOverFlow() {

            cout << "Heap full" << endl;

        }

        void HeapUnderFlow() {

            cout << "Heap empty" << endl;

        }

        //constructor
        myMaxHeap(vector<T> &input);

        //additional methods from Requirements
        bool isEmpty() { return currentsize_ == 0; }
        bool isFull() { return currentsize_ == heap_.size(); }
        const T getItem(int index) { return heap_[index]; }
        void display();
        int getHeight() { return (log2(currentsize_ + 1)); }
        int getNumberOfNodes() { return currentsize_; }

        //void clear();
        T peekTop() { return heap_.at(0); }

        void add(const T &newData);

        void remove();
        void clear();
        void increaseKey(int p, T positiveValue);
        void decreaseKey(int p, T positiveValue);

};

/*
 * pre    : none
 * param  : vector<T>
 * post   : turn vector into heap
 * return : max_heap
 */
template<typename T>
myMaxHeap<T>::myMaxHeap( vector<T> &input ) {

    vector<T> temp(input.size() + 1);
    heap_ = temp;

    for (auto i = 0; i < input.size(); i++) {

        heap_.at(i) = input.at(i);

    }

    currentsize_ = input.size();

    buildHeap();

}

/*
 * pre    : need heap
 * param  : none
 * post   : display heap
 * return : void
 */
template<typename T>
void myMaxHeap<T>::display() {

    if (!isEmpty()) {

        size_t size = heap_.size();
        int i;

        if (size != 0) {

            cout << "<";

            if (size > 0) {

                for (i = 0; i < size - 1; ++i) {

                    std::cout << heap_.at(i) << ", ";

                }

                std::cout << heap_.at(i);

            }

            cout << ">";

        }

        else {

            cout << "Heap is empty" << endl;

        }

    }

    else {

        throw UnderFlow::e();

    }

}

/*
 * pre    : none
 * param  : none
 * post   : buildheap (driver function)
 * return : void
 */
template<typename T>
void myMaxHeap<T>::buildHeap() {

    size_t size = heap_.size();

    for (int i = size / 2 - 1; i >= 0; --i) {

        percolateUp(i);

    }


}

/*
 * pre    : heap
 * param  : index (int hole)
 * post   : aintains max-heap property when adding elm
 * return : void
 */
template<typename T>
void myMaxHeap<T>::percolateUp(int hole) {

    int left = myMaxHeap<T>::left(hole);
    int right = myMaxHeap<T>::right(hole);
    int max;

    if (left < currentsize_ && heap_.at(left) > heap_.at(hole)) {

        max = left;

    }

    else {

        max = hole;

    }

    if (right < currentsize_ && heap_.at(right) > heap_.at(max)) {

        max = right;

    }

    if (max != hole) {

        std::swap(heap_.at(hole), heap_.at(max));
        percolateUp(max);

    }
}

/*
 * pre    : none
 * param  : index (int i), value (T Key)
 * post   : The value A[i] is now (A[i] + Key), heap structure preserved
 * return : void
 */
template<typename T>
void myMaxHeap<T>::increaseKey(int i, T key) {

    if (key < heap_.at(i)) {

        throw std::invalid_argument("New Key is smaller than current key!");

    }

    key = heap_.at(i);

    while (i > 0 && heap_.at(parent(i)) < heap_.at(i)) {

        std::swap(heap_.at(i), heap_.at(parent(i)));
        i = parent(i);

    }

}


/*
 * pre    : heap not full
 * param  : node
 * post   : added node to heap, preserve heap structure
 * return : void
 */
template<typename T>
void myMaxHeap<T>::add(const T &node) {

    if (!isFull()) {

        heap_.push_back(node);
        myMaxHeap<T>::increaseKey(heap_.size() - 1, node);
        currentsize_++;

    }

    else {

        throw OverFlow::e();

    }

}

/*
 * pre    : non-empty heap
 * param  : none
 * post   : removed min elm, preserve heap structure
 * return : void
 */
template<typename T>
void myMaxHeap<T>::remove() {

    if (!myMaxHeap<T>::isEmpty()) {

        heap_.at(1) = heap_.at(currentsize_--);
        percolateDown(1);

    }

    else {

        throw UnderFlow::e();

    }

}

/*
 * pre    : none
 * param  : index (int i), value (T Key)
 * post   : The value A[i] is now (A[i] - Key), heap structure preserved
 * return : void
 */
template<typename T>
void myMaxHeap<T>::decreaseKey(int p, T positiveValue) {

    heap_.at(p) -= positiveValue;
    myMaxHeap::percolateUp(p);

}

/*
 * pre    : non empty tree
 * param  : index (int hole)
 * post   : maintains max-heap property when removing elm
 * return : void
 */
template<typename T>
void myMaxHeap<T>::percolateDown(int hole) {

    unsigned long child;
    T temp = heap_.at(hole);

    for ( ; hole * 2 <= currentsize_; hole = child) {

        child = hole * 2;

        if (child != currentsize_ && heap_.at(child + 1) < heap_.at(child)) {

            child++;

        }


        if (heap_.at(child) < temp) {

            heap_.at(hole) = heap_.at(child);

        }

        else {

            break;

        }

    }

    heap_.at(hole) = temp;

}

template<typename T>
void myMaxHeap<T>::clear() {

    for ( auto i = 0; i < currentsize_; i++ ) {

        this->remove();

    }

}
#endif /* MAXHEAP_H */


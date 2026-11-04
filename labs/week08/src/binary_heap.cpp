#include "binary_heap.hpp"

#include <stdexcept>
#include <utility>
#include <algorithm>

BinaryHeap::BinaryHeap(std::vector<int> values)
    : data_(std::move(values)) {
    heapify();
}

const int& BinaryHeap::top() const {
    if (data_.empty()) {
        throw std::out_of_range("BinaryHeap is empty");
    }
    return data_.front();
}

void BinaryHeap::push(int value) {
    data_.push_back(value);
    sift_up(data_.size() - 1);
}

void BinaryHeap::pop() {
    if (data_.empty()) {
        throw std::out_of_range("BinaryHeap is empty");
    }
    data_.front() = data_.back();
    data_.pop_back();
    if (!data_.empty()) {
        sift_down(0);
    }
}

bool BinaryHeap::check_invariant() const {
    for (std::size_t i = 0; i < data_.size(); ++i) {
        std::size_t l = left(i);
        std::size_t r = right(i);
        if (l < data_.size() && data_[l] > data_[i]) {
            return false;
        }
        if (r < data_.size() && data_[r] > data_[i]) {
            return false;
        }
    }
    return true;
}

std::size_t BinaryHeap::parent(std::size_t i) {
    return (i - 1) / 2;
}

std::size_t BinaryHeap::left(std::size_t i) {
    return 2 * i + 1;
}

std::size_t BinaryHeap::right(std::size_t i) {
    return 2 * i + 2;
}

void BinaryHeap::sift_up(std::size_t i) {
    while (i > 0) {
        std::size_t p = parent(i);
        if (data_[i] > data_[p]) {
            std::swap(data_[i], data_[p]);
            i = p;
        } else {
            break;
        }
    }
}

void BinaryHeap::sift_down(std::size_t i) {
    std::size_t size = data_.size();
    while (true) {
        std::size_t largest = i;
        std::size_t l = left(i);
        std::size_t r = right(i);

        if (l < size && data_[l] > data_[largest]) {
            largest = l;
        }
        if (r < size && data_[r] > data_[largest]) {
            largest = r;
        }

        if (largest != i) {
            std::swap(data_[i], data_[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void BinaryHeap::heapify() {
    if (data_.empty()) {
        return;
    }
    for (long long i = static_cast<long long>(data_.size() - 1) / 2; i >= 0; --i) {
        sift_down(static_cast<std::size_t>(i));
    }
}
#include "arrayd.hpp"
#include <iostream>
class arrayd {
    public:
        arrayd::arrayd() = default;
        arrayd::arrayd(const ptrdiff_t size) :
        capacity_(size),
        size_(size) {
        if (size < 0) {
            throw;
        }
        data_ = new float[capacity_];
        for (int i = 0; i < capacity_; i++) {
             data_[i] = NULL;
            }
        }

        float& arrayd::operator[](const ptrdiff_t i) {
        if (i < 0 || size_ < i) {
            throw;
        }
        return data_[i];
        }

        arrayd::~arrayd() {
            delete[] data_;
        }

        arrayd arrayd::operator=(const arrayd rhs) {
            if (this != &rhs) {
                delete[] data_;
                capacity_ = rhs.capacity_;
                size_ = rhs.size_;
                data_ = new float[capacity_];

                for (size_t i = 0; i < int(capacity_); i++) {
                    data_[i] = rhs.data_[i];
                }
                    }
                    return *this;
                }

        void arrayd::resize(const ptrdiff_t size) {
            float* data = new float[size];

                    for (size_t i = 0; i < int(capacity_); i++)
                    {
                        data[i] = data_[i];
                    }

                    delete[] data_;
                    data_ = data; 
                }

                ptrdiff_t arrayd::size()const {
                    return size_;
                }
    };

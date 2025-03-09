#include "IntegerArray.h"
#include <exception>
#include <algorithm>
#include <iostream>

struct BadRange : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Bad Range Arguments!";
    }
};

struct BadLength : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Bad Length Arguments!";
    }
};

IntegerArray::IntegerArray(int length) throw() : iLength(length) {
	if (length <= 0) {
        throw BadLength();
    }
    aData = new int[length];
}

IntegerArray::IntegerArray(const IntegerArray& a) : IntegerArray(a.GetLength())
{
    std::copy_n(a.aData, iLength, aData);
}

IntegerArray::~IntegerArray() {
    aData = nullptr;
    delete[] aData;
}

void IntegerArray::Erase()
{
    aData = nullptr;
    delete[] aData;
    iLength = 0;
}

int& IntegerArray::operator[](int index) throw()
{
    if (index < 0 || iLength <= index) {
        throw BadRange();
    }
    return aData[index];
}

int IntegerArray::GetLength() const {
    return iLength;
}

void IntegerArray::Resize(int newLength) throw()
{
    if (newLength == iLength) {
        return;
    }
    if (newLength <= 0) {
        throw BadLength();
    }

    int* data = new int[newLength];

    if (iLength > 0) {
        int copyLength = ((newLength > iLength) ? iLength : newLength);
        std::copy_n(aData, copyLength, data);
    }

    aData = nullptr;
    delete[] aData;

    aData = data;
    iLength = newLength;
}

void IntegerArray::Insert(int value, int index) throw()
{
    if (index < 0 || iLength <= index) {
        throw BadRange();
    }

    int* data = new int[iLength + 1];
    std::copy_n(aData, index, data);
    data[index] = value;
    std::copy_n(aData + index, iLength - index, data + index + 1);

    aData = nullptr;
    delete[] aData;

    aData = data;
    ++iLength;
}


void IntegerArray::InsertFirst(int value)
{
    Insert(value, 0);
}

void IntegerArray::InsertLast(int value)
{
    int* data = new int[iLength + 1];
    std::copy_n(aData, iLength, data);
    data[iLength] = value;

    aData = nullptr;
    delete[] aData;

    aData = data;
    ++iLength;
}

void IntegerArray::Remove(int index) throw()
{
    if (index < 0 || iLength <= index) {
        throw BadRange();
    }

    if (iLength == 1) {
        Erase();
        return;
    }

    int* data{ new int[iLength - 1] };

    std::copy_n(aData, index, data);
    std::copy_n(aData + index + 1, iLength - index - 1, data + index);

    aData = nullptr;
    delete[] aData;

    aData = data;
    --iLength;
}

int* IntegerArray::Find(int value) {
    for (int i = 0; i < iLength; i++) {
        if (aData[i] == value) {
            return &aData[i];
        }
    }
    return nullptr;
}

void IntegerArray::Print() const {
    std::cout << "(" << iLength << "): ";
    for (int i = 0; i < iLength; i++) {
        std::cout << aData[i] << " ";
    }
    std::cout << std::endl;
}

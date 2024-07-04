#pragma once

class IntegerArray {
private:
	int iLength;
	int* aData;
public:
	IntegerArray() = default;
	IntegerArray(int length) throw();
	IntegerArray(const IntegerArray&);
	~IntegerArray();
	void Erase();
	int& operator[](int) throw();
	int GetLength() const;
	void Resize(int newLength) throw();
	void Insert(int value, int index) throw();
	void InsertFirst(int value);
	void InsertLast(int value);
	void Remove(int index) throw();
	int* Find(int value);
	void Print() const;
};

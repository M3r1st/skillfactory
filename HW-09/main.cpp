#include "IntegerArray.h"
#include <iostream>

int main() {
    for (int TEST = 0; TEST <= 10; TEST++) {
        try {
            IntegerArray a;
            switch (TEST) {
            case 0:
                a = IntegerArray(2);
                a.Print();
                a[0] = 3;
                a[1] = 5;
                a.Print();
                a.Resize(4);
                a[2] = -2;
                a.Print();
                a.Resize(1);
                a.Print();
                a.InsertFirst(6);
                a.InsertLast(-9);
                a.Insert(45, 1);
                a.Print();
                if (a.Find(3))
                    *a.Find(3) = 0;
                a.Print();
                break;
            case 1:
                a = IntegerArray(-1);
                break;
            case 2:
                a = IntegerArray();
                a.Resize(-2);
                break;
            case 3:
                a = IntegerArray(3);
                a[-1] = 2;
                break;
            case 4:
                a = IntegerArray(3);
                a[3] = 2;
                break;
            case 5:
                a = IntegerArray(3);
                a.Remove(-1);
                break;
            case 6:
                a = IntegerArray(3);
                a.Remove(3);
                break;
            }
        }
        catch (std::exception& e) {
            std::cout << TEST << ": " << e.what() << std::endl;
        }
    }
}

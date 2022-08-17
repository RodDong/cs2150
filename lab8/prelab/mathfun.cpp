#include <iostream>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main()
{
    int a, b;
    cout << "Enter integer 1:" << endl;
    cin >> a;
    cout << "Enter integer 2:" << endl;
    cin >> b;
    int prod = product(a, b);
    int pow = power(a, b);
    cout << "Product: " << prod << endl;
    cout << "Power: " << pow << endl;
}
#include <iostream>
#include "Date.h"
#include "Triad.h"

using std::cout;

int main()
{
    Date d1(2022, 12, 4), d2(2022, 12, 8);
    cout << d1 << d2;
    cout << "t1 > t2: " << (d1 > d2) << " t1 < t2: " << (d1 < d2) << " t1 == t2: " << (d1 == d2) << '\n';
    cout << "Difference: " << d1.calculateDifference(d2);
}

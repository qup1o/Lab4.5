#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

int main()
{
    double x, y, R;

    cout << "R = "; cin >> R;

    if (R <= 0)
    {
        cout << "R must be positive" << endl;
        return 1;
    }

    srand((unsigned)time(NULL));

    // 1 спосіб: координати з клавіатури
    for (int i = 0; i < 10; i++)
    {
        cout << " x = "; cin >> x;
        cout << " y = "; cin >> y;

        if ((x >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && fabs(y) >= -x && fabs(y) <= R))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // 2 спосіб: випадкові координати з інтервалу [-R; R]
    for (int i = 0; i < 10; i++)
    {
        x = 2. * R * rand() / RAND_MAX - R;
        y = 2. * R * rand() / RAND_MAX - R;

        if ((x >= 0 && x * x + y * y <= R * R) ||
            (x <= 0 && fabs(y) >= -x && fabs(y) <= R))
            cout << setw(8) << setprecision(4) << x << "  "
            << setw(8) << setprecision(4) << y << "  " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << "  "
            << setw(8) << setprecision(4) << y << "  " << "no" << endl;
    }

    return 0;
}
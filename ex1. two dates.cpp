using namespace std;
#include <iostream>
void correctdate(int& d, int& m, int y) {                     //func for verifing dates
    do {
        if (m < 1 || m>12) {
            cout << "Not correct number of month\n";
            cout << "Input month\n";
            cin >> m;
        }
    } while (m < 1 || m>12);

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) {
            start:
            cout << "You inputted wrong number of day\nFix it\n";
            cout << m << " month has 31 days\n";
            cin >> d;
            if (d > 31 || d < 1) {
                goto start;
            }
        }
    }

    if (m == 4 || m == 6 || m == 9 || m == 11 ) {
        if (d > 30) {
        start1:
            cout << "You inputted wrong number of day\nFix it\n";
            cout << m << " month has  30 days\n";
            cin >> d;
            if (d > 30 || d < 1) {
                goto start1;
            }
        }
    }
    if (y % 4 == 0 && m == 2) {
        if (d > 29) {
        start2:
            cout << "You inputted wrong number of day\nFix it\n";
            cin >> d;
            if (d > 29 || d < 1) {
                goto start2;
            }
        }
    }
    else if (y % 4 != 0 && m == 2) {
        if (d > 28) {
        start3:
            cout << "You inputted wrong number of day\nFix it\n";
            cin >> d;
            if (d > 28 || d < 1) {
                goto start3;
            }
        }
    }
} 
void firstdate(int& d, int& m, int& y) {       //inputting first date
    cout << "Input the first date \n";
    cout << "Input day "; cin >> d;
    cout << "Input month "; cin >> m;
    cout << "Input year  "; cin >> y;
    correctdate(d, m, y);
}
void seconddate(int& d1, int& m1, int& y1, int d, int m, int y) {       //inputting second date
    start:
    cout << "Input the second date \n";
    cout << "Input day "; cin >> d1;
    cout << "Input month "; cin >> m1;
    cout << "Input year  ";
    cin >> y1;
    correctdate(d1, m1, y1);
    if (y1 < y) {
         cout << "Second year must be at least equal to the first \n";
         cout << "Input again\n";
         goto start;
    }

    if (y1 == y) {
        if (m1 < m) {
            cout << "You must input bigger month\n";
            goto start;
        }
        if (m1 == m) {
            if (d1 < d) {
                cout << "You must input bigger day\n";
                goto start;
            }
        }
    }
}
int leapyear(int d, int m, int y, int d1, int m1, int y1) {
    int leap = 0;
    int year = y;
    while (year <= y1) {
        if (year % 4 == 0) {
            leap++;
        }
        year++;
    }
    if (y == y1 && y % 4 == 0) {
        leap++;
    }
    if ((y % 4 == 0) && (m >= 3 || m == 2 && d == 29)) {
        leap = leap - 1; 
    }
    if ((y1 % 4 == 0 && m1 == 2 && d1 < 29) || (y1 % 4 == 0 && m1 < 2)) {
        leap = leap - 1; 
    }
    return leap;
}
int counting(int d1, int m1, int y1, int d, int m, int y) {
    int days = 0;
    int days1 = 0;
    int leap = leapyear(d, m, y, d1, m1, y1);
    for (int i = m; i >= 1; i--) {
        if (i == m) {
            days = d;
            continue;
           
        }
        else {
            if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                days = days + 31;
            }
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                days = days + 30;
            }
            if (i == 2) {
                days = days + 28;
            }
        }
    }
    for (int i = m1; i >=1; i--) {
        cout << i << " ";
        if (i == m1) {
            days1 = d1;
            continue;
        }
        else {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                days1 = days1 + 31;
            }
            if (i == 4 || i == 6 || i == 9 || i == 11) {
                days1 = days1 + 30;
            }
            if (i == 2) {
                days1 = days1 + 28;
            }
        }
    }
    if (y == y1) {
        days = days1 - days + leap;
    }
    else {
        days = 365 * (y1 - y) + (days1 - days) + leap;
    }
    return days;
}
int main()
{
    int q = 0;
    do {
        int d = 0, d1 = 0;
        int m = 0, m1 = 0;
        int y = 0, y1 = 0;
        firstdate(d, m, y);
        seconddate(d1, m1, y1, d, m, y);
        cout << "------------------------------------------------\n";
        cout << "You inputted " << d << "." << m << "." << y << " and " << d1 << "." << m1 << "." << y1 << endl;
        cout << "------------------------------------------------\n";
        int days = counting(d1, m1, y1, d, m, y);
        cout << "Amount days between two dates is " << days << " days\n";
        cout << "------------------------------------------------\n";
        start:
        cout << "Try again? (1 - yes; 0 -exit) \n";
        cin >> q;
        if (q != 0 && q != 1) {
            cout << "Wrong inputting\n";
            goto start;
        }
    } while (q != 0);
}


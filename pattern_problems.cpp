#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void print5(int n)
{
    int t;
    t = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            cout << "*";
        }
        cout << endl;
        t--;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < (n * 2) - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < (n * 2) - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n)
{
    for (int i = 1; i <= (2 * n) - 1; i++)
    {
        int stars = i;
        if (stars > n)
        {
            stars = (2 * n) - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    int digit = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            digit = 1;
        else
            digit = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << digit;
            digit = 1 - digit;
        }
        cout << endl;
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // numbers
        int num = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << num;
            num++;
        }

        // space
        int ini = (n * 2) - (2 * i);
        for (int j = 0; j < ini; j++)
        {
            cout << " ";
        }

        // numbers
        for (int j = 1; j <= i; j++)
        {
            num--;
            cout << num;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            ++num;
        }
        cout << endl;
    }
}
void print14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void print15(int n)
{
    int num = n;
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j < 'A' + num; j++)
        {
            cout << j;
        }
        num--;
        cout << endl;
    }
}
void print16(int n)
{
    char a = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a;
        }
        a++;
        cout << endl;
    }
}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        // character
        char a = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= (2 * i) + 1; j++)
        {
            cout << a;
            if (j <= breakpoint)
                a++;
            else
                a--;
        }

        // space
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char a = 'E' - i; a <= 'E'; a++)
        {
            cout << a;
        }
        cout << endl;
    }
}
void print19(int n)
{
    int iniS = 0;
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 0; j < (n - i); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        iniS = iniS + 2;

        // star
        for (int j = 0; j < (n - i); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // space
        int iniS = (2 * n - 2 * i);
        for (int j = 1; j <= iniS; j++)
        {
            cout << " ";
        }
        iniS = iniS - 2;

        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print20(int n)
{
    int iniS = (2 * n) - 2;
    for (int i = 1; i <= (2 * n) - 1; i++)
    {
        int star = i;
        if (i >= n)
            star = (2 * n) - i;
        // star
        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 1; j <= iniS; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }

        if (i < n)
            iniS -= 2;
        else
            iniS += 2;
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    print21(n);

    return 0;
}
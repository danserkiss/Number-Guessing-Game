#include <iostream>
#include<istream>
#include<string>
#include <cstdlib>
#include <random>
#include <vector>
using namespace std;
vector<int> foo() {
    random_device rd;
    uniform_int_distribution<int> other(0, 9);
    vector<int> a;
    int k = 1;
    while (k) {
        a.clear(); 
        int n = 0;
        for (int i = 0; i < 4; i++) { 
            a.push_back(other(rd));
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < i; j++) { 
                if (a[i] == a[j]) {
                    n++;
                    break; 
                }
            }
        }
        if (n == 0)
            k = 0;
    }
    return a;
}

void check(const vector<int>& a, const int k[4]) {
    int onrightplaces = 0;
    int all = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] == k[i])
            onrightplaces++;
        for (int j = 0; j < 4; j++) {
            if (a[i] == k[j])
                all++;
        }
    }
    cout << all << " all right" << endl;
    cout << onrightplaces << " on right places" << endl;
    if(all==4 && onrightplaces==4)
    {
        cout << "You win!!!\n";
            system("pause");
            exit(1);
    }
}

void enternum(int* a) 
{
    string num;
    int f;
    cout << "Enter your number: ";
    cin >> num;
    if(num.length()==4)
    {
        f = stoi(num);
        *a = f;
    }
    else
    {
        cout << "Number must consist of 4 digits!\n\n";
        enternum(a);
    }

}

int main() {
    vector<int> a = foo();
    string f;

    int n;
    int *number=&n;
    int k[4];


    while (1) {
        enternum(number);
        for (int i = 0;i <4;i++) {
            k[i] = (n / pow(10, 3 - i));
            k[i] = k[i]%10;
        }
        check(a, k);
        cout << endl;
    }

    return 0;
}

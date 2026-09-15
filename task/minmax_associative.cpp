#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    set<int> numbers;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.insert(x);
    }

    cout << "Минимум: " << *numbers.begin() << endl;
    cout << "Максимум: " << *numbers.rbegin() << endl;

    return 0;
}

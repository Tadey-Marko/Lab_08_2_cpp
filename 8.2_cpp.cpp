// ЛР 8.2, варіант 3.
// Умова: вилучити всі групи символів у круглих дужках
// разом із самими дужками. Якщо є вкладені дужки,
// вивести повідомлення про помилку.
#include <iostream>
#include <string>
using namespace std;

// Повертає false при вкладених чи неправильних дужках.
// Якщо дужки правильні, записує очищений рядок у result.
bool removeGroups(const string& s, string& result) {
    result.clear();
    bool inside = false;
    for (char c : s) {
        if (c == '(') {
            if (inside) return false;
            inside = true;
        }
        else if (c == ')') {
            if (!inside) return false;
            inside = false;
        }
        else if (!inside) result += c;
    }
    return !inside;
}

#ifndef UNIT_TEST
int main() {
    string s, result;
    cout << "Enter text: ";
    getline(cin, s);
    if (!removeGroups(s, result))
        cout << "Error: nested or unmatched parentheses.\n";
    else
        cout << "New text: " << result << '\n';
}
#endif

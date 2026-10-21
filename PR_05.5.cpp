#include <iostream>
#include <cmath>
using namespace std;

// Функція, корінь якої шукаємо: f(x) = sin(x) - cos(x)
double f(double x) {
    return sin(x) - cos(x);
}

// Рекурсивний метод дихотомії.
// a, b  - межі відрізка, eps - точність,
// level - поточний рівень рекурсії (параметр-значення, на кожному виклику +1),
// depth - глибина рекурсії (параметр-посилання, максимальний досягнутий рівень).
double bisect(double a, double b, double eps, int level, int& depth) {
    if (level > depth)               // оновлюємо глибину, якщо рівень більший
        depth = level;

    cout << " level = " << level << endl;

    double m = (a + b) / 2;          // середина відрізка

    // Умова завершення: відрізок менший за eps або точний корінь знайдено
    if (b - a < eps || f(m) == 0)
        return m;

    // Рекурсивний крок
    if (f(a) * f(m) < 0)             // корінь у лівій половині [a, m]
        return bisect(a, m, eps, level + 1, depth);
    else                             // інакше корінь у правій половині [m, b]
        return bisect(m, b, eps, level + 1, depth);
}

int main() {
    double a, b, eps;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "eps = ";
    cin >> eps;

    if (eps <= 0 || a >= b || f(a) * f(b) >= 0) {
        cout << "Invalid input: eps > 0, a < b and f(a)*f(b) < 0 are required\n";
        return 1;
    }

    int depth = 0;                               // початкове значення глибини
    double root = bisect(a, b, eps, 1, depth);   // 1 - початкове значення level

    cout << "Root x = " << root << endl;
    cout << "depth = " << depth << endl;

    return 0;
}
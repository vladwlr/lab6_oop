#include "fuzzynumber.h"
#include <iostream>
#include <sstream>

// Конструктори
FuzzyNumber::FuzzyNumber() : left(0), mid(0), right(0) {}
FuzzyNumber::FuzzyNumber(double left, double mid, double right) : left(left), mid(mid), right(right) {}

// Ініціалізація
void FuzzyNumber::Init(double left, double mid, double right) {
    this->left = left;
    this->mid = mid;
    this->right = right;
}

// Введення з клавіатури
void FuzzyNumber::Read() {
    std::cout << "Enter left, mid, and right values: ";
    std::cin >> left >> mid >> right;
}

// Виведення на екран
void FuzzyNumber::Display() const {
    std::cout << "Fuzzy number: (" << left << ", " << mid << ", " << right << ")" << std::endl;
}

// Перетворення в рядок
std::string FuzzyNumber::toString() const {
    std::stringstream ss;
    ss << "(" << left << ", " << mid << ", " << right << ")";
    return ss.str();
}

// Операція додавання
FuzzyNumber FuzzyNumber::add(const FuzzyNumber& other) const {
    return FuzzyNumber(left + other.left, mid + other.mid, right + other.right);
}

// Операція віднімання
FuzzyNumber FuzzyNumber::sub(const FuzzyNumber& other) const {
    return FuzzyNumber(left - other.left, mid - other.mid, right - other.right);
}

// Операція множення
FuzzyNumber FuzzyNumber::mul(const FuzzyNumber& other) const {
    double newLeft = mid * other.mid - other.mid * left - mid * other.left + left * other.left;
    double newMid = mid * other.mid;
    double newRight = mid * other.mid + other.mid * left + mid * other.left + left * other.left;
    return FuzzyNumber(newLeft, newMid, newRight);
}

// Операція ділення
FuzzyNumber FuzzyNumber::div(const FuzzyNumber& other) const {
    if (other.mid == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return *this;
    }
    double newLeft = (mid - left) / (other.mid + other.right);
    double newMid = mid / other.mid;
    double newRight = (mid + right) / (other.mid - other.left);
    return FuzzyNumber(newLeft, newMid, newRight);
}

// Обернене число
FuzzyNumber FuzzyNumber::inverse() const {
    if (mid == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return *this;
    }
    return FuzzyNumber(1 / (mid + right), 1 / mid, 1 / (mid - left));
}

// Операція порівняння
bool FuzzyNumber::equal(const FuzzyNumber& other) const {
    return (left == other.left && mid == other.mid && right == other.right);
}

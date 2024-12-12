#pragma once
#ifndef FUZZYNUMBER_H
#define FUZZYNUMBER_H

#include <string>

class FuzzyNumber {
private:
    double left;  // A - al
    double mid;   // A
    double right; // A + ar

public:
    // Методи ініціалізації
    FuzzyNumber();
    FuzzyNumber(double left, double mid, double right);

    // Методи введення/виведення
    void Init(double left, double mid, double right);
    void Read();
    void Display() const;
    std::string toString() const;

    // Операції
    FuzzyNumber add(const FuzzyNumber& other) const;
    FuzzyNumber sub(const FuzzyNumber& other) const;
    FuzzyNumber mul(const FuzzyNumber& other) const;
    FuzzyNumber div(const FuzzyNumber& other) const;
    FuzzyNumber inverse() const; // Обернене число

    // Операції порівняння
    bool equal(const FuzzyNumber& other) const;
};

#endif // FUZZYNUMBER_H

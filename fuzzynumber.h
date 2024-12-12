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
    // ������ �����������
    FuzzyNumber();
    FuzzyNumber(double left, double mid, double right);

    // ������ ��������/���������
    void Init(double left, double mid, double right);
    void Read();
    void Display() const;
    std::string toString() const;

    // ��������
    FuzzyNumber add(const FuzzyNumber& other) const;
    FuzzyNumber sub(const FuzzyNumber& other) const;
    FuzzyNumber mul(const FuzzyNumber& other) const;
    FuzzyNumber div(const FuzzyNumber& other) const;
    FuzzyNumber inverse() const; // �������� �����

    // �������� ���������
    bool equal(const FuzzyNumber& other) const;
};

#endif // FUZZYNUMBER_H

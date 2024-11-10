#pragma once
template <typename T1, typename T2, typename T3, typename T4, typename T5>
class CustomClass {
private:
    T1 data1;
    T2 data2;
    T3 data3;
    T4 data4;
    T5 data5;

public:
    CustomClass(T1 d1, T2 d2, T3 d3, T4 d4, T5 d5)
        : data1(d1), data2(d2), data3(d3), data4(d4), data5(d5) {}

    void showInfo() const {
        std::cout << "Data: " << data1 << ", " << data2 << ", " << data3 << ", " << data4 << ", " << data5 << std::endl;
    }
};


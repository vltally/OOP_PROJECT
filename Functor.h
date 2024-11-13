class Functor {
public:
    // Арифметичні операції
    int plus(int a, int b) const { return a + b; }
    int minus(int a, int b) const { return a - b; }
    int multiply(int a, int b) const { return a * b; }
    int divide(int a, int b) const { return b != 0 ? a / b : 0; }
    int modulus(int a, int b) const { return b != 0 ? a % b : 0; }
    int negate(int a) const { return -a; }

    // Порівняльні операції
    bool equal_to(int a, int b) const { return a == b; }
    bool not_equal_to(int a, int b) const { return a != b; }
    bool greater(int a, int b) const { return a > b; }
    bool less(int a, int b) const { return a < b; }
    bool greater_equal(int a, int b) const { return a >= b; }
    bool less_equal(int a, int b) const { return a <= b; }

    // Логічні операції
    bool logical_and(bool a, bool b) const { return a && b; }
    bool logical_or(bool a, bool b) const { return a || b; }
    bool logical_not(bool a) const { return !a; }
};

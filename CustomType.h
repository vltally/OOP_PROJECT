class CustomType {
public:
    int value;
    std::string value1;
    CustomType(int v, std::string v1) : value(v), value1(v1) {}
};

template <typename T>
class Wrapper {
private:
    T data;

public:
    Wrapper(T d) : data(d) {}

    void showInfo() const {
        std::cout << "Data value: " << data.value << " data1 value: " << data.value1 << std::endl;
    }
};

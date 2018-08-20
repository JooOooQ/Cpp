#include <iostream>
#include <memory>

class Base
{
public:
    Base(int var1, int var2)
    {
        init(var1, var2);
    }
    virtual ~Base() {}

    void init(int var1, int var2) {
        countResult(var1, var2);
    }

    int result() { return result_; }

protected:
    virtual void countResult(int var1, int var2) = 0;

    int result_;
};

class DerivedAdd : public Base
{
public:
    DerivedAdd(int var1, int var2) : Base(var1, var2) {}
protected:
    void countResult(int var1, int var2) override
    {
        result_ = var1 + var2;
    }
};

class DerivedMult : public Base
{
public:
    DerivedMult(int var1, int var2) : Base(var1, var2) {}
protected:
    void countResult(int var1, int var2) override
    {
        result_ = var1 * var2;
    }
};

int main()
{
    constexpr int var1 {2};
    constexpr int var2 {3};

    std::unique_ptr<Base> addition = std::make_unique<DerivedAdd>(var1, var2);
    std::unique_ptr<Base> multiplication = std::make_unique<DerivedMult>(var1, var2);
    std::cout << var1 << " + " << var2 << " = " << addition->result() << std::endl
              << var1 << " * " << var2 << " = " << multiplication->result() << std::endl;

    return 0;
}

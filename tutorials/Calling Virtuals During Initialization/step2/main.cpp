#include <iostream>
#include <memory>

class Base
{
public:
    Base(int result) : result_(result) {}
    virtual ~Base() {}

    int result() { return result_; }

protected:
    int result_;
};

class DerivedAdd : public Base
{
public:
    DerivedAdd(int var1, int var2) :
        Base(countResult(var1, var2))
    {
    }

protected:
    static int countResult(int var1, int var2)
    {
        return var1 + var2;
    }
};

class DerivedMult : public Base
{
public:
    DerivedMult(int var1, int var2) :
        Base(countResult(var1, var2))
    {
    }

protected:
    static int countResult(int var1, int var2)
    {
        return var1 * var2;
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

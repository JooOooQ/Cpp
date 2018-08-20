#include <iostream>
#include <memory>

class Base
{
public:
    virtual ~Base() {}

    template <class D, typename... Args>
    static std::unique_ptr<Base> create(Args&&... args)
    {
        std::unique_ptr<Base> ptr = std::make_unique<D>();
        ptr->init(std::forward<Args>(args)...);
        return ptr;
    }

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
protected:
    void countResult(int var1, int var2) override
    {
        result_ = var1 + var2;
    }
};

class DerivedMult : public Base
{
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

    std::unique_ptr<Base> addition = Base::create<DerivedAdd>(var1, var2);
    std::unique_ptr<Base> multiplication = Base::create<DerivedMult>(var1, var2);
    std::cout << var1 << " + " << var2 << " = " << addition->result() << std::endl
              << var1 << " * " << var2 << " = " << multiplication->result() << std::endl;

    return 0;
}

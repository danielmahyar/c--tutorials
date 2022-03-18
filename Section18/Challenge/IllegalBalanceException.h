#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : std::exception
{
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept{
        return "Balance can't be negative";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__

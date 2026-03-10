#ifndef OPTION_H
#define OPTION_H

namespace Elth::functionnal {

template <typename T>
class Option
{
public:

    Option() : hasValue(false), storage() {}
    Option(const T& v) : hasValue(true), storage(v) {}
    ~Option() { if (hasValue) storage.some.~T(); }

    const T & operator()() const { return storage.some; };

    explicit operator bool() const { return hasValue; }

protected:
    const  bool hasValue;

    union Storage {
        T some;
        void* none;
        Storage() : none(nullptr) {}
        Storage(const T& s) : some(s) {}
    } const storage;
};

}

#endif
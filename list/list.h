#ifndef LIST_H
#define LIST_H

#include <memory>

template<typename T>
class List
{
public:
    List() : _count(0), _head(nullptr) {}
    List(const T& value) : _count(1), _head(std::make_shared<Node>(value, nullptr)) {}
    List(const List<T>& list) : _count(list._count), _head(list._head) {}

    const List<T> pushFront(const T& value) const { return List(value, *this); }
    const List<T> pushBack(const T& value) const
    {
        if (!_head)
            return List(value);

        if (!_head->next)
            return List(_head->value, List(value));

        List<T> tail(_head->next, _count - 1);
        return List(_head->value, tail.pushBack(value));
    }
    const T& at(const unsigned int index) const { return *(this[index]); }

    inline const unsigned int count() const { return _count; }

    const List<T> operator[](const unsigned int index) const { return (index == 0) ? *this : List(_head->next, _count - 1)[index-1]; }
    const T& operator*() const { return _head->value; }

protected:
    struct Node
    {
        const T value;
        const std::shared_ptr<Node> next;
    };

    List(const T& value, List tail) : _count(tail._count +1), _head(std::make_shared<Node>(value, tail._head)) {}
    List(const std::shared_ptr<Node> head, const unsigned int count) : _head(head), _count(count) {}

    const unsigned int _count;
    const std::shared_ptr<Node> _head;
};

#endif LIST_H
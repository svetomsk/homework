#include <iostream>
#include <functional>

struct A {
    int data;
};

int main() {
    std::function<void(A a)> a = [](A a){std::cout << "Hello " << a.data;};
    A p;
    a(p);
    return 0;
}
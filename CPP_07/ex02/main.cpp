#include "Array.hpp"

int main(void) {
    std::cout << "=============== INT ARRAY ===============" << std::endl;

    std::cout << "Empty constructor: \n" << std::endl;

    Array<int> a;

    std::cout << a << std::endl;
    std::cout << "size : " << a.size() << std::endl;

    std::cout << "\nConstructor with parameters: \n" << std::endl;

    Array<int> b(10);

    std::cout << "At initialization:" << std::endl;


    std::cout << b << std::endl;
    std::cout << "size : " << b.size() << std::endl;

    for (int i=0; i<10; i++)
        b[i] = 67;

    std::cout << b << std::endl;

    std::cout << "Access element:" << std::endl;
    std::cout << b[2] << std::endl;
    b[2] = 5;
    std::cout << "After edit:" << std::endl;
    std::cout << b[2] << std::endl;

    std::cout << "\nCopy Constructor: \n" << std::endl;

    Array<int> c(b);

    std::cout << c << std::endl;
    std::cout << "size : " << c.size() << std::endl;
    std::cout << "Access element:" << std::endl;
    std::cout << c[2] << std::endl;
    c[2] = 7;
    std::cout << "After edit:" << std::endl;
    std::cout << c[2] << std::endl;
    std::cout << "Original is:" << std::endl;
    std::cout << b[2] << std::endl;


    std::cout << "\nCopy assignment operator: \n" << std::endl;


    Array<int> d;
    d = c;

    std::cout << d << std::endl;
    std::cout << "size : " << d.size() << std::endl;

    for (int i=0; i<10; i++)
        c[i] += 2;

    std::cout << "After editing original:" << std::endl;


    std::cout << d << std::endl;
    std::cout << "size : " << d.size() << std::endl;

    

    std::cout << "=============== STD::STRING ARRAY ===============" << std::endl;
    
    std::cout << "Empty constructor: \n" << std::endl;

    Array<std::string> e;

    std::cout << e << std::endl;
    std::cout << "size : " << e.size() << std::endl;

    std::cout << "\nConstructor with parameters: \n" << std::endl;

    Array<std::string> f(10);

    std::cout << "At initialization:" << std::endl;


    std::cout << f << std::endl;
    std::cout << "size : " << f.size() << std::endl;

    for (int i=0; i<10; i++)
        f[i] = "tasty crousty";

    std::cout << f << std::endl;

    std::cout << "\nCopy Constructor: \n" << std::endl;

    Array<std::string> g(f);

    std::cout << g << std::endl;
    std::cout << "size : " << g.size() << std::endl;

    std::cout << "\nCopy assignment operator: \n" << std::endl;


    Array<std::string> h;
    h = g;

    std::cout << h << std::endl;
    std::cout << "size : " << h.size() << std::endl;

    for (int i=0; i<10; i++)
        g[i] += 2;

    std::cout << "After editing original:" << std::endl;


    std::cout << h << std::endl;
    std::cout << "size : " << h.size() << std::endl;

    std::cout << h[9] << std::endl;
    std::cout << h[10] << std::endl;
}
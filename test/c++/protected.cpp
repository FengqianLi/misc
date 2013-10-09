#include <iostream>

//using namespace std;

class base 
{
protected:
    static const int num = 10;
};

class derived : public base
{
public:
    void print() {
        std::cout << get_num() << std::endl;
    }


protected:
    int get_num() {
        return num;
    }
};

    int
main( int argc, char **argv )
{
    derived inst; 
    inst.print();
    return 0;
}

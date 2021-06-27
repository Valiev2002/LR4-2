#include <iostream>
#include<vector>
#include<stdexcept>
#include <algorithm>
#include<exception>
#include <string>
class my_ex: public std::exception{
public:
    my_ex(char *message,int data):std::exception(){
        this->data=data;//присваиваем входящий параметр конструктора нашему полю
    }
    int get_data(){//возвращает нашу дату
        return data;
    }
     virtual const char* what() { return std::exception::what();};
private:
    int data;
};
void foo(int age){
    if(age==19){
        throw ("This is my age");
    }
    if(age<0)
    {
        throw my_ex("What?",age);
    }
}
class King { virtual ~King();};
class Prince { virtual ~Prince(); };
void foo1(int a){
    std::cout<<"Enter a>0"<<std::endl;
    std::cin>>a;
    if(a<0){
        throw std::invalid_argument("///");
    }
    else{std::cout<<"a = "<<a<<std::endl;}
}
class A {
private:
    int *ptr;
public:
    A() {
         ptr = new int[10];
    }
    ~A() {
        delete [] ptr;
    }
};
int main() {
   /*std::cout<<"First exception"<<std::endl;
    std::vector<int> vec(5);
    std::cout << "Vector size = " << vec.size() << '\n';
    try {
        if(vec.size()>5) {
            throw std::exception();
        }
            vec.at(6) = 2002;//СЕТИМ 6 ЭЛЕМЕНТ,КОТОРОГО НЕТ
    }
    catch (std::out_of_range &e) {
        std::cout << "Error: there are 5 elements in vector "<<std::endl<<e.what() <<'\n';
    }
    //-----------------------------------------------------------------------------------
    */std::cout<<"Second exception"<<std::endl;
    try {
        std::vector<int> myvector(30);
        int new_size=0;
        std::cout<<"Vector size is "<<myvector.size()<<std::endl;
        std::cin>>new_size;
        myvector.reserve(-1);
            if (new_size > myvector.max_size()) {
                throw std::length_error("---");
            }
        }

    catch(std::length_error&le){std::cout<< "Argument error: " << le.what() << '\n';}
  /*std::cout<<"Third exception"<<std::endl;
    try{
        std::string str1 = "Valiev Vali Samedovich";
        std::string str2 = "Student of BMSTU";
        int my_int1 = std::stoi(str1);
        int my_int2 = std::stoi(str2);
        std::cout << "std::stoi(\"" << str1 << "\") is " << my_int1 << '\n';
        std::cout << "std::stoi(\"" << str2 << "\") is " << my_int2 << '\n';
        }
    catch(std::invalid_argument&inv){std::cout<< "Argument error: " << inv.what() << '\n';}
    std::cout<<"Fourth exception"<<std::endl;
    Prince p;
    try {
        King& k = dynamic_cast<King&>(p);
    } catch(const std::bad_cast& e)
    {
        std::cout << e.what() << '\n';
    }
        std::cout<<"Fifth exception"<<std::endl;
    long double *ptr ;

    try {
        for (int i = 0; i < 200000; i++){
            ptr = new long double[50000000];
                std::cout << "New memmory for ptr[" << i << "]\n";
        }
    }
    catch(std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
    }*/
    std::cout<<"Task 2"<<std::endl;
    try{
        foo(-1);
    }
    catch(my_ex&ex){
        std::cout<<"Error cathed: "<<ex.what()<<std::endl;
        std::cout<<"Data status: "<<ex.get_data()<<std::endl<<"This is where something went wrong,"
                                                              "because age can't be with the minus"<<std::endl;
    }
  std::cout<<"Task 3"<<std::endl;
    try
    {
        int *a=new int [10];
        foo1(-1);
        delete[] a;
    }
    catch(...)
    {
        std::cout<< "Error";
    }
    std::cout<<"UTECHKA"<<std::endl;
    std::cout<<"Now let's see correct code"<<std::endl;
    try
    {
        A b;
        int *a = new int[10];
        foo1(-1);
        delete[] a;
    }
    catch(...)
    {
        std::cout << "Error\n";
    }
    return 0;
}



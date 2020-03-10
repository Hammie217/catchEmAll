#include <array>
#include <iostream>

#define ARRAYSIZE 10

void printArray1(const std::array<int, ARRAYSIZE> arr){ //ensure no modification given array defined as const
    std::cout << "Array of length " << arr.size() <<": " << "<";
    for(auto i=arr.begin();i<arr.end();i++){
        std::cout << ' ' << *i ;
    }
    std::cout  << " >" << std::endl;
}

void printArray2(std::array<int, ARRAYSIZE> arr){
    std::cout << "Array of length " << arr.size() <<": " << "<";
    for(auto i=arr.cbegin();i<arr.cend();i++){//ensure not modification given array pointers are const
        std::cout << ' ' << *i ;
    }
    std::cout  << " >" << std::endl;
}

void printArrayReverse1(const std::array<int, ARRAYSIZE> arr){ //ensure no modification given array defined as const
    std::cout << "Array of length " << arr.size() <<": " << "<";
    for(auto i=arr.rbegin();i<arr.rend();i++){
        std::cout << ' ' << *i;
    }
    std::cout  << " >" << std::endl;
}

void printArrayReverse2(std::array<int, ARRAYSIZE> arr){
    std::cout << "Array of length " << arr.size() <<": " << "<";
    for(auto i=arr.crbegin();i<arr.crend();i++){//ensure not modification given array pointers are const
        std::cout << ' ' << *i ;
    }
    std::cout  << " >" << std::endl;
}

void editDataFromPointer(int* arrayPointer, int size){
    for(int i=0;i<size;i++){
        *(arrayPointer+i)=i;
    }
}

int main(){
    std::array<int, ARRAYSIZE> a ={0};
    std::array<int, ARRAYSIZE> b ;
    std::cout << "a " << (a.empty() ? "is empty" : "is not empty") << std::endl;
    std::cout << "b " << (b.empty() ? "is empty" : "is not empty") << std::endl;
    std::cout << "a can hold " << a.max_size() << " Ints" << std::endl;
    std::cout << "b can hold " << b.max_size() << " Ints" << std::endl ;
    printArray1(a);
    a.fill(255);
    printArray1(a);
    //cumulate a into b
    for(auto i=0;i<a.size();i++){
        try{
            b.at(i)=b.at(i-1)+a.at(i);
        }
        catch (const std::out_of_range& e){
            b.at(i)=a.at(i);
        }
    }
    printArray2(b);
    a.swap(b);
    printArray2(b);
    printArrayReverse1(a);
    std::cout << "a starting with: " << a.front() << std::endl;
    std::cout << "a ending with: " << a.back() << std::endl;
    editDataFromPointer(b.data(),b.size());
    printArrayReverse2(b);
    return 0;
}
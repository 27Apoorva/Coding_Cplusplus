// Assignment 15.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;
class Person
{
    private:
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }

        void Display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void Shout()
        {
            cout<<"Ooooooooooooooooo"<<endl;
        }
};
class ReferenceCount
{
    private:
    int count;
    public:
    void AddRef()
    {
        count++;
    }
    int Release()
    {
        return count--;
    }
};

template <class T>
class smart_pointer
{
    private:
    T *sPtr;
    ReferenceCount *reference;
    public:
    smart_pointer():sPtr(0),reference(0)
    {
        reference = new ReferenceCount();
        reference->AddRef();
    }
    smart_pointer(T *cl):sPtr(cl),reference(0)
    {
        reference = new ReferenceCount();
        reference->AddRef();
        cout<<"constructor called"<<endl;
    }

    smart_pointer(const smart_pointer<T>& sp) : sPtr(sp.sPtr), reference(sp.reference)
    {
        reference->AddRef();
    }
    ~smart_pointer()
    {
        if(reference->Release() == 0)
        {
            delete sPtr;
            delete reference;
        }
    }
    T & operator *()
    {
        return *sPtr;
    }
    T *operator ->()
    {
      return sPtr;
    }

    smart_pointer<T>& operator = (const smart_pointer<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            if(reference->Release() == 0)
            {
                delete sPtr;
                delete reference;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            sPtr = sp.sPtr;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};

int main()
{
    int *iPtr = new int(9);
    smart_pointer<int> sp(iPtr);
    cout << *sp <<endl;
    smart_pointer<Person> sp1(new Person("appu",10));
    sp1->Display();
    sp1->Shout();
}


#include <iostream>

using namespace std;
template <class T>
class miniVec
{
    private:
    int vCapacity;
    int vSize;
    T *vArr;
    public:
    typedef T* iterator;
    miniVec()
    {
        vCapacity = 0;
        vSize = 0;
    }
    T & operator [ ] (unsigned int i);
    void push_back(const T &item);
    void resize(int n, bool bollean);
    iterator begin()
    {
      return vArr;
    }

    iterator end()
    {
      return vArr + vSize;
    }
};
template <typename T>
T &miniVec<T>::operator [ ] (unsigned int i)
{
    return vArr[i];
}
template <typename T>
void miniVec<T>::push_back(const T &item)
{
    if(vSize == vCapacity)
    {
        if(vCapacity == 0)
        {
            resize(1,false);
        }
        else
        {
            resize(2*vCapacity,true);
        }
    }
    vArr[vSize] = item;
    vSize++;
}
template <typename T>
void miniVec<T>::resize(int n, bool boolean)
{
    T *newArr;
    newArr = new T[n];
    if(boolean)
    {
        for(int i = 0;i<vSize;i++)
        {
            newArr[i] = vArr[i];
        }
    }
    if(vArr != NULL)
    {
        delete [] vArr;
    }
    vArr = newArr;
    vCapacity = n;

}


int main()
{
    miniVec<int> my_first_vector;
    my_first_vector.push_back(10);
    my_first_vector.push_back(20);
    my_first_vector.push_back(30);
    my_first_vector.push_back(40);
    cout << my_first_vector[3] <<endl;
    for(auto it = my_first_vector.begin();it!=my_first_vector.end();it++)
    {
      cout << *it<<endl;
    }

}

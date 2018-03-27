#include<iostream>

template<typename T>
class item
{
  private:
    T data;
  public:
    item():data(T())
    {

    }
    void setData(T value)
    {
      data = value;
    }
    T getData() const
    {
      return data;
    }
    void printData()
    {
      std::cout << "data: "<< data << '\n';
    }
};
template<class t1,class t2>
class pair
{
  t1 first;
  t2 second;
  public:
    pair():first(t1()),second(t2())
    {
      std::cout << "my_pair: "<< first <<' '<< second << '\n';
    }
};
template<int ARRAY_SIZE>
class IntArray
{
  public:
    int TheArray[ARRAY_SIZE];

    template<typename T>
    void Copy(T target_array[ARRAY_SIZE])
    {
       for(int nIndex = 0; nIndex<ARRAY_SIZE; ++nIndex)
       {
            target_array[nIndex] = static_cast<T>(TheArray[nIndex]);
       }

    }
};
template<class T>
class Convert
{
   T data;
public:
   Convert(const T& tData = T()) : data(tData)
   { }

   template<class C>
   bool IsEqualTo( const C& other ) const
   {
       return data == other;
   }
};
int main()
{
  item<int> first_item; //Unlike function template instantiation, where arguments of function itself helps the compiler to deduce template type arguments, with class templates you must explicitly pass template type (in angle brackets).
  first_item.setData(90);
  first_item.printData();
  pair<int,double> my_pair;
  IntArray<5> my_arr;
  float float_arr[5] = {1,2,3,4,5};
  my_arr.Copy(float_arr);

  Convert<int> Data;
  float Data2 = 0.6 ;
  bool b = Data.IsEqualTo(Data2);
  std::cout << "b: "<<b << '\n';
}

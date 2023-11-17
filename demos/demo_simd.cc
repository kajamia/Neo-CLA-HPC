#include <iostream>
#include <sstream>


#include <simd.h>

using namespace ASC_HPC;
using std::cout, std::endl;

auto Func1 (SIMD<double> a, SIMD<double> b)
{
  return a+b;
}

auto Func2 (SIMD<double,4> a, SIMD<double,4> b)
{
  return a+3*b;
}

auto Func3 (SIMD<double,4> a, SIMD<double,4> b, SIMD<double,4> c)
{
  return FMA(a,b,c);
}


auto Load (double * p)
{
  return SIMD<double,2>(p);
}

auto LoadMask (double * p, SIMD<mask64,2> m)
{
  return SIMD<double,2>(p, m);
}

auto TestSelect (SIMD<mask64,2> m, SIMD<double,2> a, SIMD<double,2> b)
{
  return Select (m, a, b);
}

SIMD<double,2> TestHSum (SIMD<double,4> a, SIMD<double,4> b)
{
  return HSum(a,b);
}



int main()
{
  SIMD<double,4> double_test(1.,2.,3.,4.);
  SIMD<double,4> b(1.0);
  SIMD<int64_t,4> int_test(1,2,3,4);
  
  /*cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a+b = " << a+b << endl;

  cout << "HSum(a) = " << HSum(a) << endl;
  cout << "HSum(a,b) = " << HSum(a,b) << endl;*/

 
 //TESTING COMPARISONS
 //===================
  /*
  auto mask1 = (2 >= double_test);
  auto mask2 = (2 >= int_test);
  auto mask3 = (2 > double_test);
  auto mask4 = (2 > int_test);
  auto mask5 = (2 <= double_test);
  auto mask6 = (2 <= int_test);
  auto mask7 = (2 < double_test);
  auto mask8 = (2 < int_test);
  cout << "2 >= " << double_test << " = " << mask1 << endl;
  cout << "2 >= " << int_test << " = " << mask2 << endl;
  cout << "2 > " << double_test << " = " << mask3 << endl;
  cout << "2 > " << int_test << " = " << mask4 << endl;
  cout << "2 <= " << double_test << " = " << mask5 << endl;
  cout << "2 <= " << int_test << " = " << mask6 << endl;
  cout << "2 < " << double_test << " = " << mask7 << endl;
  cout << "2 < " << int_test << " = " << mask8 << endl;
  */

  {
    //SIMD<double,4> sa(&a[0], mask);
    //cout << "sa = " << sa << endl;
  }

  //cout << "Select(mask1, a, b) = " << Select(mask1, a,b) << endl;

  //auto d = a*b-c;
  //cout << d << endl;
}

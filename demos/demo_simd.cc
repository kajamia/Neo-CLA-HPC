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
  // the scalar value 2 is type-cast to the appropriate SIMD type
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

 // TESTING DIVISION AND SQRT
 //==========================
  /* SIMD<double, 4> a(1, 3, 3.14, 42);
  SIMD<double, 4> e(2, 2, 0.5, 0.33);

  cout << a/e << endl;
  cout << 3/e << endl;
  cout << sqrt(e) << endl;

  SIMD<double, 4> c = 3 * a;
  SIMD<double, 4> d = a/e; */

 // SIMD<double, 2>
 //================
  /* SIMD<double, 2> f(2, 3);
  SIMD<double, 2> i(2, 2);
  cout << f << endl;
  cout << f.Lo() << endl;

  SIMD<mask64, 2> mask9(_mm_cmp_pd(f.Val(),i.Val(), _CMP_GT_OQ));
  cout << mask9 << endl;
  double* g = new double[2];
  g[0] = 100;
  g[1] = 200;
  SIMD<double, 2> h(g, mask9);
  cout << h << endl;

  auto mask10 = (2 > int_test);
  cout << mask10.Lo() << endl; */

  {
    //SIMD<double,4> sa(&a[0], mask);
    //cout << "sa = " << sa << endl;
  }

  //cout << "Select(mask1, a, b) = " << Select(mask1, a,b) << endl;

  //auto d = a*b-c;
  //cout << d << endl;
}

#include <iostream>
#include <sstream>


#include <taskmanager.h>
#include <timer.h>

using namespace Neo_HPC;
using std::cout, std::endl;


int main()
{
  timeline = std::make_unique<TimeLine>("demo.trace");

  StartWorkers(3);
  
  std::mutex mut;
  RunParallel(10, [&mut] (int i, int size) {
  std::lock_guard<std::mutex> lock(mut);    
  cout << "I am task " << i << " out of " << size << endl;
  });

  /*
  RunParallel(10, [] (int i, int size)
  {
    static Timer t("timer one");
    RegionTimer reg(t);
    cout << "I am task " << i << " out of " << size << endl;
  });
  */
  
  RunParallel(6, [] (int i, int s)
  {
    RunParallel(6, [i] (int j, int s2)
    {
      static Timer t("timer nested", {1,0,0});
      RegionTimer reg(t);
      
      std::stringstream str;
      str << "nested, i,j = " << i << "," << j << "\n";
      cout << str.str();
    });
  });



  
  RunParallel(100,  [] (int i, int size)
  {
    static Timer t("one of 100", { 0, 0, 1});
    RegionTimer reg(t);
  });

  {
    static Timer t("100x10 parallel runs", { 0, 0, 1});
    RegionTimer reg(t);

    for (int k = 0; k < 100; k++)
      RunParallel(10,  [] (int i, int size)
      {
        ;
      });
  }

  
  {
    static Timer t("10x10x10 parallel runs", { 0, 0, 1});
    RegionTimer reg(t);

    for (int k = 0; k < 10; k++)
      RunParallel(10, [] (int i, int size)
      {
        RunParallel (10, [] (int j, int size)
        {
        });
      });
  }

  
  RunParallel(1000,  [] (int i, int size)
  {
    static Timer t("timer 1000 tasks", { 1, 0, 0});
    RegionTimer reg(t);
  });

  RunParallel(100, [] (int i, int s)
  {
    static Timer t("timer 4", { 1, 1, 0});
    RegionTimer reg(t);    
    RunParallel(100, [i](size_t j, size_t s2)
    {
      ;
    });
  });

  int cnt = 0;
  RunParallel(1000, [&cnt] (int i, int size) { cnt++; });
  cout << "cnt = " << cnt << endl;


  
  StopWorkers();
}


/**
 * @file main.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 10:02:45 2010 last updated
 * @date Sun Sep 19 15:48:55 2010 created
 */

#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "simhash.hpp"

using namespace std;
using namespace colfil;

int main()
{
  SimHash<8, map<long, long> > simHash;
  map<long, long> test;
  srand(time(NULL));

  for (int i = 0; i < 10; ++i) {
    test[rand()] = rand();
  }

  cout << simHash(test) << endl;

  return 0;
}

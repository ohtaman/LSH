/**
 * @file main.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 17:10:54 2010 last updated
 * @date Wed Aug 18 00:39:57 2010 created
 */

#include <map>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


#include "minhash.hpp"

using namespace colfil;
using namespace std;

int main(int argc, char **argv)
{
  cout << "MinHash Demo" << endl;

  typedef MinHash<list<unsigned int> > MinHashType;
  MinHashType minHash;
  list<unsigned int> user;

  for (int i = 0; i < 100; ++i) {
    user.push_back(i);
  }

  cout << minHash(user) << endl;

  return 0;
}

/**
 * @file main.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Dec 31 01:15:04 2012 last updated
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

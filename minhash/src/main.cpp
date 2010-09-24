/**
 * @file main.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Tue Sep 21 16:25:10 2010 last updated
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

  MinHash<> minHash;

  list<list<unsigned int> > users;
  list<unsigned int> items;

  srand(time(NULL));

  cout << "Generating demo data ... ";
  cout.flush();
  for (int i = 0; i < 10000; ++i) {
    items.clear();
    for (int j = 0; j < 100; ++j) {
      items.push_front(rand()%100);
    }
    users.push_front(items);
  }
  cout << "O.K." << endl;

  map<unsigned int, unsigned int> hashes;
  cout << "Calculating minHash values ... ";
  cout.flush();
  for (list<list<unsigned int> >::const_iterator ite = users.begin(); ite != users.end(); ++ite) {
    hashes[minHash(*ite)]++;
  }
  cout << "O.K." << endl;

  for (map<unsigned int, unsigned int>::const_iterator ite = hashes.begin(); ite != hashes.end(); ++ite) {
    cout << (*ite).first << " : " << (*ite).second << endl;
  }

  return 0;
}

/**
 * @file multi_minhash.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 16:09:13 2010 last updated
 * @date Mon Sep 20 15:49:26 2010 created
 */

#include <iostream>
#include "multi_minhash.hpp"

using namespace std;
using namespace colfil;

int main(int argc, char **argv)
{
  cout << "MultiMinHash demo" << endl;


  typedef MultiMinHash<3, list<unsigned int> > MultiMinHashType;
  MultiMinHashType multiMinHash;
  multiMinHash.setSeed(10);

  list<unsigned int> user;
  for (unsigned int i = 0; i < 100; ++i) {
    user.push_back(i);
  }

  MultiMinHashType::ValueType hashValue = multiMinHash(user);
  for (int i = 0; i < hashValue.size(); ++i) {
    cout << hashValue[i] << " ";
  }
  cout << endl;

  return 0;
}

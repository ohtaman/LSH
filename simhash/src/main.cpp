/**
 * @file main.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Fri Sep 24 18:02:12 2010 last updated
 * @date Sun Sep 19 15:48:55 2010 created
 */

#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "simhash.hpp"
#include "hash_multi_classifier.hpp"

using namespace std;
using namespace colfil;

int main()
{
  SimHash<8, map<long, long> > simHash;
  map<long, long> test;
  srand(time(NULL));
  simHash.setSeed(rand());

  for (int i = 0; i < 10; ++i) {
    test[rand()] = rand();
  }

  cout << simHash(test) << endl;


  SimHash<8, long*> simHash2;
  simHash2.setInputDataSize(10);
  long test2[10];
  for (int i = 0; i < 100; ++i) {
    rand();
  }
  simHash2.setSeed(rand());

  for (int i = 0; i < 10; ++i) {
    test2[i] = rand();
  }

  cout << simHash2(test2) << endl;

  typedef HashMultiClassifier<10, SimHash<8, map<long, long> > > ClassifierType;
  ClassifierType simClassifier(rand());
  ClassifierType::ValueType cluster;

  simClassifier.classify(test, &cluster);

  cout << endl;
  for (int i = 0; i < cluster.size(); ++i) {
    cout << cluster[i] << endl;
  }

  return 0;
}

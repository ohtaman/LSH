/**
 * @file minhash_multi_classfier.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 18:07:14 2010 last updated
 * @date Mon Sep 20 17:44:32 2010 created
 */

#include <iostream>
#include "minhash_multi_classifier.hpp"

using namespace std;
using namespace colfil;

int main(int argc, char **argv)
{
  cout << "MinHashMultiClassifier Demo" << endl;

  typedef MinHashMultiClassifier<20, 3, list<unsigned int> > MinHashMultiClassifierType;
  MinHashMultiClassifierType classifier;
  list<unsigned int> user;
  MinHashMultiClassifierType::ValueType value;

  for (int i = 0; i < 100; ++i) {
    user.push_back(i);
  }

  classifier.setSeed(10);
  classifier.classify(user, &value);

  for (int i = 0; i < value.size(); ++i) {
    for (int j = 0; j < value[i].size(); ++j) {
      cout << value[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

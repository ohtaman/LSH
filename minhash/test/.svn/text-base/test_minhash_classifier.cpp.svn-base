/**
 * @file test_minhash_classifier.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Aug 21 22:00:14 2010 last updated
 * @date Sat Aug 21 09:33:06 2010 created
 */

#include <iostream>
#include <list>
#include <map>
#include <cstdlib>

#include "minhash_classifier.hpp"

using namespace colfil;
using namespace std;

int main()
{
  cout << "Testing MinHashClassifier Class" << endl;

  cout << "Iniializing Classifiers ...";

  typedef MinHashClassifier<3> ClassifierType;
  ClassifierType classifier;

  for (unsigned int i = 0; i < classifier.size(); ++i) {
    classifier.getHash(i).setSeed(rand());
  }
  cout << "O.K." << endl;


  list<list<unsigned int> > users;
  list<unsigned int> items;

  srand(time(NULL));

  cout << "Generating demo data ... ";
  cout.flush();
  for (int i = 0; i < 100000; ++i) {
    items.clear();
    for (int j = 0; j < 100; ++j) {
      items.push_front(rand()%1000);
    }
    users.push_front(items);
  }
  cout << "O.K." << endl;

  cout << "Classifying users ... " << endl;
  cout.flush();

  map<ClassifierType::ValueType, unsigned int> hashes;
  for (list<list<unsigned int> >::const_iterator ite = users.begin(); ite != users.end(); ++ite) {
    hashes[classifier.classify(*ite)]++;
  }
  cout << "O.K." << endl;

  for (map<ClassifierType::ValueType, unsigned int>::const_iterator ite = hashes.begin(); ite != hashes.end(); ++ite) {
    for (int i = 0; i < 3; ++i) {
      cout << (*ite).first[i] << " ";
    }
    cout << ": " << (*ite).second << endl;
  }

  cout << "size of the map : " << hashes.size() << endl;

  return 0;
}

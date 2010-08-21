/**
 * @file test_minhash_multi_classifier.cpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Aug 21 23:41:51 2010 last updated
 * @date Sat Aug 21 11:04:21 2010 created
 */

#include <iostream>
#include <map>
#include <ctime>
#include <sstream>
#include <log4cxx/logger.h>


#include "minhash_multi_classifier.hpp"

using namespace colfil;
using namespace std;
using namespace log4cxx;

LoggerPtr logger = Logger::getLogger("TestMinHashMultiClassifier");

template<typename T>
void generateUserData(int numOfUser, int numOfItem, int numOfBuying, list<T> *users)
{
  T items;
  for (int i = 0; i < numOfUser; ++i) {
    items.clear();
    for (int j = 0; j < numOfBuying; ++j) {
      items.push_front(rand()%numOfItem);
    }
    users->push_front(items);
  }
}

int main()
{
  logger->info("start main function in test_minhash_multi_classifier.cpp");
  cout << "Testing MinHashMultiClassifier Class ..." << endl;

  const int N = 20;
  const int Q = 2;
  const int numOfUsers = 100000;
  const int numOfItems = 1000;
  const int numOfBuying = 100;

  typedef MinHashMultiClassifier<N, Q> Classifier;
  Classifier classifier;
  ostringstream os;
  os << "using params N = " << N << ", Q = " << Q << ", #users = " << numOfUsers << ", #items = " << numOfItems << ", #buying = " << numOfBuying;
  logger->info(os.str());

  logger->info("starting shuffling ...");
  classifier.shuffle(time(NULL));
  logger->info("done");

  list<Classifier::ContainerType> users;
  logger->info("generating random users data");
  cout << "Generating User Data ..." << flush;
  generateUserData(numOfUsers, numOfItems, numOfBuying, &users);
  cout << "O.K." << endl;
  logger->info("done");


  map<Classifier::ClusterType, unsigned int> clusters;
  Classifier::ValueType tmpClusters;
  logger->info("clustering users");
  cout << "Clustering users ... " << flush;
  for (list<Classifier::ContainerType>::const_iterator ite = users.begin(); ite != users.end(); ++ite) {
    classifier.classify(*ite, &tmpClusters);
    for (Classifier::ValueType::const_iterator ite2 = tmpClusters.begin(); ite2 != tmpClusters.end(); ++ite2) {
      clusters[ite2->first] += ite2->second;
    }
  }
  cout << "O.K." << endl;
  logger->info("done");

  for (map<Classifier::ClusterType, unsigned int>::const_iterator ite = clusters.begin(); ite != clusters.end(); ++ite) {
    cout << ite->second << endl;
  }
  cout <<  "#clusters = " << clusters.size() << endl;

  return 0;
}

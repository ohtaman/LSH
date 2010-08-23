/**
 * @file minhash_multi_classifier.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Aug 23 23:15:23 2010 last updated
 * @date Sat Aug 21 10:51:10 2010 created
 */

#ifndef COLFIL_MINHASH_MULTI_CLASSIFIER__
#define COLFIL_MINHASH_MULTI_CLASSIFIER__

#include <cstdlib>
#include <list>
#include <map>
#include "minhash_classifier.hpp"

namespace colfil {
  template<unsigned int Q, unsigned int N, typename MIN_HASH = MinHash<> >
  class MinHashMultiClassifier{
  public:

    typedef MinHashClassifier<N, MIN_HASH> ClassifierType;
    typedef typename ClassifierType::ValueType ClusterType;
    typedef typename ClassifierType::ContainerType ContainerType;
    typedef std::map<unsigned int, typename ClassifierType::ValueType> ValueType;
    typedef MinHashMultiClassifier<Q, N, ClassifierType> SelfType;

  private:

    ClassifierType classifier[Q];

  public:

    void shuffle(int seed = 0)
    {
      if (seed) {
        srand(seed);
      }
      for (unsigned int i = 0; i < Q; ++i) {
        for (unsigned int j = 0; j < classifier[i].size(); ++j) {
          classifier[i].getHash(j).setSeed(rand());
        }
      }
    }

    unsigned int size() const
    {
      return Q;
    }

    void classify(const ContainerType &input, ValueType *dest) const
    {
      for (unsigned int i = 0; i < Q; ++i) {
        (*dest)[i] = classifier[i].classify(input);
      }
    }
  };
}

#endif /* COLFIL_MINHASH_MULTI_CLASSIFIER__ */

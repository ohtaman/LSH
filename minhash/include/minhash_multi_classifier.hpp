/**
 * @file minhash_multi_classifier.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Sep 11 18:15:49 2010 last updated
 * @date Sat Aug 21 10:51:10 2010 created
 */

#ifndef COLFIL_MINHASH_MULTI_CLASSIFIER__
#define COLFIL_MINHASH_MULTI_CLASSIFIER__

#include <cstdlib>
#include "minhash_classifier.hpp"

namespace colfil {
  template<unsigned int Q,
           unsigned int N,
           typename CONTAINER_T,
           typename CLASSIFIER_T = MinHashClassifier<N, CONTAINER_T>,
           typename VALUE_T = Array<typename MinHashClassifier<N, CONTAINER_T>::ValueType, Q> >
  class MinHashMultiClassifier{
  public:

    typedef CLASSIFIER_T ClassifierType;
    typedef typename ClassifierType::ValueType ClusterType;
    typedef CONTAINER_T ContainerType;
    typedef VALUE_T ValueType;
    typedef MinHashMultiClassifier<Q, N, ContainerType, ClassifierType> SelfType;

  private:

    ClassifierType classifier_[Q];

  public:

    void shuffle(int seed = 0)
    {
      if (seed) {
        srand(seed);
      }
      for (unsigned int i = 0; i < Q; ++i) {
        for (unsigned int j = 0; j < classifier_[i].size(); ++j) {
          classifier_[i].getHash(j).setSeed(rand());
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
        (*dest)[i] = classifier_[i].classify(input);
      }
    }
  };
}

#endif /* COLFIL_MINHASH_MULTI_CLASSIFIER__ */

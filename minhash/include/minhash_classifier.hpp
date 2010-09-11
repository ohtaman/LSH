/**
 * @file minhash_classifier.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Sep 11 18:14:34 2010 last updated
 * @date Fri Aug 20 23:47:30 2010 created
 */

#ifndef COLFIL_MINHASH_CLASSIFIER__
#define COLFIL_MINHASH_CLASSIFIER__

#include "minhash.hpp"
#include "array.hpp"

namespace colfil {

  template<unsigned int N,
           typename CONTAINER_T,
           typename MIN_HASH = MinHash<CONTAINER_T>,
           typename VALUE_T = Array<typename MIN_HASH::ValueType, N> >
  class MinHashClassifier{
  public:

    typedef CONTAINER_T ContainerType;
    typedef MIN_HASH MinHashType;
    typedef MinHashClassifier<N, CONTAINER_T> SelfType;
    typedef VALUE_T ValueType;

  private:

    MinHashType minHashes_[N];

  public:

    MinHashClassifier()
    {
    }

    MinHashClassifier(const typename MinHashType::ValueType *seed)
    {
      for (unsigned int i = 0; i < N; ++i) {
        minHashes_[i].setSeed(seed);
      }
    }

    virtual ~MinHashClassifier()
    {
    }

    MinHashType &getHash(unsigned int i)
    {
      return minHashes_[i];
    }

    const MinHashType &getHash(unsigned int i) const
    {
      return minHashes_[i];
    }

    unsigned int size() const
    {
      return N;
    }

    ValueType classify(const ContainerType &input) const
    {
      ValueType output;

      for (unsigned int i = 0; i < N; ++i) {
        output[i] = minHashes_[i](input);
      }

      return output;
    }
  };
}

#endif /* COLFIL_MINHASH_CLASSIFIER__ */

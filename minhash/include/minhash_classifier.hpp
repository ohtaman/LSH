/**
 * @file minhash_classifier.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Aug 21 12:28:21 2010 last updated
 * @date Fri Aug 20 23:47:30 2010 created
 */

#ifndef COLFIL_MINHASH_CLASSIFIER__
#define COLFIL_MINHASH_CLASSIFIER__

#include "minhash.hpp"
#include "array.hpp"

namespace colfil {

  template<unsigned int N, typename MIN_HASH = MinHash<> >
  class MinHashClassifier{
  public:

    typedef typename MIN_HASH::ContainerType ContainerType;
    typedef MIN_HASH MinHashType;
    typedef MinHashClassifier<N, MIN_HASH> SelfType;
    typedef Array<typename MIN_HASH::ValueType, N> ValueType;

  private:

    MIN_HASH minHashes_[N];

  public:

    MinHashClassifier()
    {
    }

    MinHashClassifier(const typename MIN_HASH::ValueType *seed)
    {
      for (unsigned int i = 0; i < N; ++i) {
        minHashes_[i].setSeed(seed);
      }
    }

    virtual ~MinHashClassifier()
    {
    }

    MIN_HASH &getHash(unsigned int i)
    {
      return minHashes_[i];
    }

    const MIN_HASH &getHash(unsigned int i) const
    {
      return minHashes_[i];
    }

    unsigned int size() const
    {
      return N;
    }

    Array<typename MIN_HASH::ValueType, N> classify(const ContainerType &input) const
    {
      Array<typename MIN_HASH::ValueType, N> output;

      for (unsigned int i = 0; i < N; ++i) {
        output[i] = minHashes_[i](input);
      }

      return output;
    }
  };
}

#endif /* COLFIL_MINHASH_CLASSIFIER__ */

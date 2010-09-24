/**
 * @file minhash_multi_classifier.hpp
 * @author Ohtaman
 * @brief
 *
<<<<<<< HEAD
 * @date Fri Aug 27 16:09:39 2010 last updated
=======
 * @date Mon Sep 20 17:45:33 2010 last updated
>>>>>>> 2d3597aeb51436a5c3d1d9eafedcb16211dcf241
 * @date Sat Aug 21 10:51:10 2010 created
 */

#ifndef COLFIL_MINHASH_MULTI_CLASSIFIER__
#define COLFIL_MINHASH_MULTI_CLASSIFIER__

#include <cstdlib>
#include "multi_minhash.hpp"
#include "random.hpp"

namespace colfil {
  template<unsigned int Q,
           unsigned int N,
           typename CONTAINER_T,
           typename HASH_T = MultiMinHash<N, CONTAINER_T>,
           typename VALUE_T = Array<typename HASH_T::ValueType, Q>,
           typename RANDOM_T = NLRandom>
  class MinHashMultiClassifier{
  public:

    typedef HASH_T HashType;
    typedef typename HashType::ValueType HashValueType;
    typedef CONTAINER_T ContainerType;
    typedef VALUE_T ValueType;
    typedef MinHashMultiClassifier<Q, N, ContainerType, HashType, ValueType> SelfType;
    typedef RANDOM_T RandomType;

  private:

    RandomType random_;
    HashType hash_[Q];

  public:

    void setSeed(int seed)
    {
      random_.setSeed(seed);
      for (unsigned int i = 0; i < Q; ++i) {
        hash_[i].setSeed(random());
      }
    }

    int getSeed()
    {
      return random_.getSeed();
    }

    unsigned int size() const
    {
      return Q;
    }

    void classify(const ContainerType &input, ValueType *output) const
    {
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (unsigned int i = 0; i < Q; ++i) {
        (*output)[i] = hash_[i](input);
      }
    }
  };
}

#endif /* COLFIL_MINHASH_MULTI_CLASSIFIER__ */

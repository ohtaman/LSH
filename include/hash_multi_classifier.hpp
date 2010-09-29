/**
 * @file hash_multi_classifier.hpp
 * @author Mitsuhisa Ohta
 * @brief
 *
 * @date Fri Sep 24 18:09:10 2010 last updated
 * @date Fri Sep 24 15:35:20 2010 created
 */

#ifndef COLFIL_HASH_MULTI_CLASSIFIER__
#define COLFIL_HASH_MULTI_CLASSIFIER__

#include "array.hpp"
#include "container_traits.hpp"
#include "random.hpp"

namespace colfil {

  template<unsigned int N,
           typename HASH_T,
           typename INPUT_T = typename HASH_T::InputType,
           typename VALUE_T = Array<typename HASH_T::ValueType, N>,
           typename RANDOM_T = NLRandom>
  class HashMultiClassifier{
  public:

    typedef HASH_T HashType;
    typedef INPUT_T InputType;
    typedef VALUE_T ValueType;
    typedef RANDOM_T RandomType;

  private:

    RandomType random_;
    HashType hashes_[N];

  public:

    HashMultiClassifier()
    {
    }

    HashMultiClassifier(int seed)
    {
      setSeed(seed);
    }

    void setSeed(int seed)
    {
      random_.setSeed(seed);
      for (int i = 0; i < 314; ++i) {
        random_();
      }

      for (unsigned int i = 0; i < N; ++i) {
        hashes_[i].setSeed(random_());
      }
    }

    int getSeed() const
    {
      return random_.getSeed();
    }

    unsigned int size() const
    {
      return N;
    }

    virtual void classify(InputType input, ValueType *output) const
    {
      for (unsigned int i = 0; i < N; ++i) {
        MapTraits<VALUE_T>::set(output, i, hashes_[i](input));
      }
    }
  };


  template<unsigned int N, typename HASH_T, typename INPUT_T, typename RANDOM_T>
  class HashMultiClassifier<N,
                            HASH_T,
                            INPUT_T,
                            typename HASH_T::ValueType*,
                            RANDOM_T>{
  public:

    typedef HASH_T HashType;
    typedef INPUT_T InputType;
    typedef typename HashType::ValueType *ValueType;
    typedef RANDOM_T RandomType;

  private:

    RandomType random_;
    HashType hashes_[N];

  public:

    HashMultiClassifier()
    {
    }

    HashMultiClassifier(int seed)
    {
      setSeed(seed);
    }

    void setSeed(int seed)
    {
      random_.setSeed(seed);
      for (unsigned int i = 0; i < N; ++i) {
        hashes_[i].setSeed(random_());
      }
    }

    int getSeed() const
    {
      return random_.getSeed();
    }

    unsigned int size() const
    {
      return N;
    }

    virtual void classify(InputType input, ValueType output) const
    {
      for (unsigned int i = 0; i < N; ++i) {
        output[i] = hashes_[i](input);
      }
    }
  };
}

#endif /* COLFIL_HASH_MULTI_CLASSIFIER__ */

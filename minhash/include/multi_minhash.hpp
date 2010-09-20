/**
 * @file multi_minhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 23:38:26 2010 last updated
 * @date Mon Sep 20 10:35:43 2010 created
 */

#ifndef COLFIL_MULTI_MINHASH__
#define COLFIL_MULTI_MINHASH__

#include <cstdlib>
#include <ctime>

#include "minhash.hpp"
#include "array.hpp"
#include "random.hpp"

namespace colfil {
  template<unsigned int N,
           typename CONTAINER_T,
           typename MIN_HASH = MinHash<CONTAINER_T>,
           typename VALUE_T = Array<typename MIN_HASH::ValueType, N>,
           typename RANDOM_T = NLRandom>
  class MultiMinHash : public Hash<typename MIN_HASH::InputType, VALUE_T>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef MIN_HASH MinHashType;
    typedef typename MinHashType::ValueType MinHashValueType;
    typedef MultiMinHash<N, CONTAINER_T, MIN_HASH, VALUE_T, RANDOM_T> SelfType;
    typedef VALUE_T ValueType;
    typedef RANDOM_T RandomType;
    typedef typename RandomType::SeedType SeedType;

  private:

    RandomType random_;
    MinHashType minHashes_[N];

    void setSeeds()
    {
      for (unsigned int i = 0; i < N; ++i) {
        minHashes_[i].setSeed(random_());
      }
    }

  public:

    MultiMinHash()
    {
      setSeeds();
    }

    MultiMinHash(int seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    virtual ~MultiMinHash()
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

    void setSeed(int seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    int getSeed() const
    {
      return random_.getSeed();
    }

    ValueType operator()(const ContainerType &input) const
    {
      ValueType output;

      for (unsigned int i = 0; i < N; ++i) {
        output[i] = minHashes_[i](input);
      }

      return output;
    }

    void operator()(const ContainerType &input, ValueType *output)
    {
      for (unsigned int i = 0; i < N; ++i) {
        (*output)[i] = minHashes_[i](input);
      }
    }
  };


  template<unsigned int N,
           typename INPUT_VALUE_T,
           typename MIN_HASH = MinHash<const INPUT_VALUE_T*>,
           typename VALUE_T = Array<typename MIN_HASH::ValueType, N>,
           typename RANDOM_T = NLRandom>
  class MultiMinHash : public Hash<typename MIN_HASH::InputType, VALUE_T>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef MIN_HASH MinHashType;
    typedef typename MinHashType::ValueType MinHashValueType;
    typedef MultiMinHash<N, CONTAINER_T, MIN_HASH, VALUE_T, RANDOM_T> SelfType;
    typedef VALUE_T ValueType;
    typedef RANDOM_T RandomType;
    typedef typename RandomType::SeedType SeedType;

  private:

    RandomType random_;
    MinHashType minHashes_[N];

    void setSeeds()
    {
      for (unsigned int i = 0; i < N; ++i) {
        minHashes_[i].setSeed(random_());
      }
    }

  public:

    MultiMinHash()
    {
      setSeeds();
    }

    MultiMinHash(int seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    virtual ~MultiMinHash()
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

    void setSeed(int seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    int getSeed() const
    {
      return random_.getSeed();
    }

    ValueType operator()(const ContainerType &input) const
    {
      ValueType output;

      for (unsigned int i = 0; i < N; ++i) {
        output[i] = minHashes_[i](input);
      }

      return output;
    }

    void operator()(const ContainerType &input, ValueType *output)
    {
      for (unsigned int i = 0; i < N; ++i) {
        (*output)[i] = minHashes_[i](input);
      }
    }
  };
}

#endif /* COLFIL_MULTI_MINHASH__ */

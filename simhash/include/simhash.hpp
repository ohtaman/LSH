/**
 * @file simhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 20:46:08 2010 last updated
 * @date Sat Sep 11 15:39:48 2010 created
 */

#ifndef COLFIL_SIMHASH__
#define COLFIL_SIMHASH__

#include "hash.hpp"
#include "container_traits.hpp"
#include "random.hpp"

namespace colfil {

  /* need to be N <= sizeof(VALUE_T)*8 */
  template<unsigned int N,
           typename CONTAINER_T,
           typename VALUE_T = unsigned long int,
           typename HASH_T = HashAdaptor<Shift32ConstHash,
                                       typename Shift32ConstHash::InputType,
                                         signed char>,
           typename RANDOM_T = NLRandom>
  class SimHash : public Hash<const CONTAINER_T&, VALUE_T>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef VALUE_T ValueType;
    typedef typename HASH_T::ValueType HashValueType;
    typedef HASH_T HashType;
    typedef SimHash<N, CONTAINER_T, VALUE_T, HASH_T> SelfType;
    typedef ContainerTraits<CONTAINER_T> ContainerTraitsType;
    typedef typename ContainerTraitsType::ConstIterator ContainerConstIterator;
    typedef RANDOM_T RandomType;
    typedef typename RandomType::SeedType SeedType;

  private:

    HashType hash_;
    RandomType random_;
    SeedType seeds_[N];

    void setSeeds()
    {
      for (int i = 0; i < N; ++i) {
        seeds_[i] = random_();
      }
    }

  public:

    SimHash()
    {
      setSeeds();
    }

    SimHash(SeedType seed)
    {
      setSeed(seed);
    }

    virtual ~SimHash()
    {
    }

    void setSeed(SeedType seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    SeedType getSeed() const
    {
      return random_.getSeed();
    }

    virtual ValueType operator()(const ContainerType &input) const
    {
      ValueType result = 0;

      for (unsigned int i = 0; i < N; ++i) {
        typename ContainerTraitsType::ValueType tmp = 0;

        for (ContainerConstIterator ite = input.begin(); ite != input.end(); ++ite) {
          tmp += ContainerTraitsType::getValue(ite)*hash_(ContainerTraitsType::getKey(ite) + seeds_[i]);
        }

        result <<= 1;
        if (tmp > 0) {
          result |= 0x1;
        }
      }

      return result;
    }
  };


  /* need to be N <= sizeof(VALUE_T)*8 */
  template<unsigned int N,
           typename INPUT_VALUE_T,
           typename VALUE_T,
           typename HASH_T,
           typename RANDOM_T>
  class SimHash<N, INPUT_VALUE_T*, VALUE_T, HASH_T, RANDOM_T> : public Hash<const INPUT_VALUE_T*, VALUE_T>{
  public:

    typedef INPUT_VALUE_T InputValueType;
    typedef InputValueType* InputType;
    typedef VALUE_T ValueType;
    typedef typename HASH_T::ValueType HashValueType;
    typedef HASH_T HashType;
    typedef SimHash<N, INPUT_VALUE_T, VALUE_T, HASH_T> SelfType;
    typedef RANDOM_T RandomType;
    typedef typename RandomType::SeedType SeedType;

  private:

    HashType hash_;
    RandomType random_;
    SeedType seeds_[N];
    int inputDataSize_;

    void setSeeds()
    {
      for (int i = 0; i < N; ++i) {
        seeds_[i] = random_();
      }
    }

  public:

    SimHash()
      :inputDataSize_(0)
    {
      setSeeds();
    }

    SimHash(SeedType seed, int inputDataSize = 0)
      :inputDataSize_(inputDataSize)
    {
      setSeed(seed);
    }

    virtual ~SimHash()
    {
    }

    void setSeed(SeedType seed)
    {
      random_.setSeed(seed);
      setSeeds();
    }

    SeedType getSeed() const
    {
      return random_.getSeed();
    }

    void setInputDataSize(int inputDataSize)
    {
      inputDataSize_ = inputDataSize;
    }

    int getInputDataSize()
    {
      return inputDataSize_;
    }

    virtual ValueType operator()(const InputValueType *input) const
    {
      ValueType result = 0;

      for (unsigned int i = 0; i < N; ++i) {
        InputValueType tmp = 0;

        for (int j = 0; j < inputDataSize_; ++j) {
          tmp += input[j]*hash_(j + seeds_[i]);
        }

        result <<= 1;
        if (tmp > 0) {
          result |= 0x1;
        }
      }

      return result;
    }
  };

}

#endif /* COLFIL_SIMHASH__ */

/**
 * @file simhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 09:59:05 2010 last updated
 * @date Sat Sep 11 15:39:48 2010 created
 */

#ifndef COLFIL_SIMHASH__
#define COLFIL_SIMHASH__

#include <cstdlib>
#include <ctime>

#include "hash.hpp"
#include "container_traits.hpp"

namespace colfil {

  /* need to be N <= sizeof(VALUE_T)*8 */
  template<unsigned int N,
           typename CONTAINER_T,
           typename VALUE_T = unsigned long int,
           typename HASH = HashAdaptor<Shift32ConstHash,
                                       typename Shift32ConstHash::InputType,
                                       signed char> >
  class SimHash : public Hash<const CONTAINER_T&, VALUE_T>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef VALUE_T ValueType;
    typedef typename HASH::ValueType HashValueType;
    typedef HASH HashType;
    typedef SimHash<N, VALUE_T, CONTAINER_T, HASH> SelfType;
    typedef ContainerTraits<CONTAINER_T> ContainerTraitsType;
    typedef typename ContainerTraitsType::ConstIterator ContainerConstIterator;

  private:

    HASH hash_;
    unsigned int seed_;
    int seeds_[N];

  public:

    SimHash()
    {
      seed_ = (unsigned int)time(NULL);
      std::srand(seed_);
      for (int i = 0; i < N; ++i) {
        seeds_[i] = std::rand();
      }
    }

    SimHash(unsigned int seed)
    {
      seed_ = seed;
      std::srand(seed);
      for (int i = 0; i < N; ++i) {
        seeds_[i] = std::rand();
      }
    }

    virtual ~SimHash()
    {
    }

    virtual ValueType operator()(const ContainerType &input) const
    {
      ValueType result = 0;

      for (unsigned int i = 0; i < N; ++i) {
        typename ContainerTraitsType::ValueType tmp = 0;
        typename ContainerTraitsType::ValueType hash = 0;

        for (ContainerConstIterator ite = input.begin(); ite != input.end(); ++ite) {
          hash = hash_(ContainerTraitsType::getKey(ite) + seeds_[i]);
          tmp += ContainerTraitsType::getValue(ite)*hash;
        }

        result <<= 1;
        if (tmp > 0) {
          result |= 0x1;
        }
      }

      return result;
    }

    unsigned int getSeed() const
    {
      return seed_;
    }

    void setSeed(unsigned int seed)
    {
      seed_ = seed;
      std::srand(seed);
      for (int i = 0; i < N; ++i) {
        seeds_[i] = std::rand();
      }
    }
  };

}

#endif /* COLFIL_SIMHASH__ */

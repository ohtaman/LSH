/**
 * @file minhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Dec 31 01:15:41 2012 last updated
 * @date Tue Aug 17 23:02:07 2010 created
 */

#ifndef COLFIL_MINHASH__
#define COLFIL_MINHASH__


#include "hash.hpp"
#include "container_traits.hpp"

namespace colfil {

  template<typename CONTAINER_T, typename HASH_T = Shift32ConstHash>
  class MinHash : public Hash<const CONTAINER_T&,
                              typename ContainerTraits<CONTAINER_T>::ValueType>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef typename ContainerTraits<ContainerType>::ConstIterator ContainerConstIterator;
    typedef typename ContainerTraits<ContainerType>::ValueType ValueType;
    typedef HASH_T HashType;
    typedef typename HashType::ValueType HashValueType;
    typedef MinHash<CONTAINER_T, HashType> SelfType;

  private:


    HashType hash_;
    ValueType seed_;

  public:

    MinHash()
    {
    }

    MinHash(ValueType seed)
      : seed_(seed)
    {
    }

    MinHash(const HashType &hash)
      : hash_(hash)
    {
    }

    MinHash(const HashType &hash, ValueType seed)
      : hash_(hash), seed_(seed)
    {
    }

    MinHash(const SelfType &rhs)
      : hash_(rhs.hash_), seed_(rhs.seed_)
    {
    }

    virtual ~MinHash(){}

    void setSeed(ValueType seed)
    {
      seed_ = seed;
    }

    ValueType getSeed() const
    {
      return seed_;
    }

    virtual ValueType operator()(const ContainerType &input) const
    {
      HashValueType min = hash_(*(input.begin())^seed_);
      ValueType minItem = *(input.begin());
      ValueType tmp;

      for (ContainerConstIterator ite = ContainerTraits<ContainerType>::getBegin(input);
           ite != ContainerTraits<ContainerType>::getEnd(input);
           ++ite) {
        tmp = hash_(*ite^seed_);
        if (tmp < min) {
          min = tmp;
          minItem = *ite;
        }

      }

      return minItem;
    }

    virtual SelfType &operator=(const SelfType &rhs)
    {
      seed_ = rhs.seed_;

      return *this;
    }
  };
}

#endif /* COLFIL_MINHASH__ */

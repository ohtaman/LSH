/**
 * @file minhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Aug 23 23:14:05 2010 last updated
 * @date Tue Aug 17 23:02:07 2010 created
 */

#ifndef COLFIL_MINHASH__
#define COLFIL_MINHASH__

#include <list>

namespace colfil {
  template<typename INPUT_T, typename T>
  class Hash{
  public:

    typedef INPUT_T InputType;
    typedef T ValueType;

  public:
    virtual ~Hash(){}
    virtual T operator()(INPUT_T input) const = 0;
  };

  class Shift32Hash : public Hash<int, int>{
  public:
    int operator()(int input) const
    {
      input = ~input + (input << 15);
      input ^= (input >> 12);
      input += (input << 2);
      input ^= (input >> 4);
      input *= 2057;
      input ^= (input >> 16);

      return input;
    }
  };

  class Shift32ConstHash : public Hash<unsigned int, unsigned int>{
  public:
    unsigned int operator()(unsigned int input) const
    {
      input = (input + 0x7ed55d16) + (input<<12);
      input = (input^0xc761c23c)^(input>>19);
      input += 0x165667b1 + (input<<5);
      input = (input + 0xd3a2646c)^(input<<9);
      input += 0xfd7046c5 + (input<<3);
      input = (input^0xb55a4f09)^(input>>16);

      return input;
    }
  };

  class NL32LCGHash : public Hash<unsigned int, unsigned int>{
  public:
    unsigned int operator()(unsigned int input) const
    {
      return input*1664525 + 1013904223;
    }
  };

  class Schrage32LCGHash : public Hash<unsigned int, unsigned int>{
  public:
    unsigned int operator()(unsigned int input) const
    {
      volatile unsigned int tmp1 = input/127773;
      unsigned int tmp2 = 16807*(input%127773);
      unsigned int tmp3 = tmp1*2836;
      return (tmp2 > tmp3)? tmp2 - tmp3 : (tmp2 + (2<<30) -1) - tmp3;
    }
  };

  class Shift64Hash : Hash<unsigned long, unsigned long>{
  public:
    unsigned long operator()(unsigned long input) const
    {
      input = ~input + (input << 21);
      input ^= (input>>24);
      input += (input<<3) + (input<<8);
      input ^= (input>>14);
      input += (input<<2) + (input<<4);
      input ^= (input>>28);
      input += (input<<31);
      return input;
    }
  };

  template<typename T = unsigned int, typename CONTAINER_T = std::list<T>, typename HASH = Shift32ConstHash>
  class MinHash : public Hash<const CONTAINER_T&, T>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef T ValueType;
    typedef typename HASH::ValueType HashValueType;
    typedef HASH HashType;
    typedef MinHash<T, CONTAINER_T, HASH> SelfType;

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

    void setSeed(T seed)
    {
      seed_ = seed;
    }

    T getSeed() const
    {
      return seed_;
    }

    virtual ValueType operator()(const ContainerType &input) const
    {
      HashValueType min = hash_(*(input.begin())^seed_);
      ValueType minItem = *(input.begin());
      ValueType tmp;

      for (typename ContainerType::const_iterator ite = input.begin(); ite != input.end(); ++ite) {
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

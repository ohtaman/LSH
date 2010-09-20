/**
 * @file hash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 09:11:41 2010 last updated
 * @date Sat Sep 11 13:03:16 2010 created
 */

#ifndef COLFIL_HASH__
#define COLFIL_HASH__

namespace colfil {

  template<typename INPUT_T, typename VALUE_T>
  class Hash{
  public:

    typedef INPUT_T InputType;
    typedef VALUE_T ValueType;

  public:
    virtual ~Hash(){}
    virtual VALUE_T operator()(INPUT_T input) const = 0;
  };


  template<typename HASH,
           typename INPUT_T = typename HASH::InputType,
           typename VALUE_T = typename HASH::ValueType>
  class HashAdaptor : public Hash<INPUT_T, VALUE_T>{

    HASH hash_;

  public:

    VALUE_T operator()(INPUT_T input) const
    {
      return (VALUE_T) hash_((typename HASH::InputType)input);
    }
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
}

#endif /* COLFIL_HASH__ */

/**
 * @file random.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Mon Sep 20 16:01:13 2010 last updated
 * @date Mon Sep 20 15:07:10 2010 created
 */

#ifndef COLFIL_RANDOM__
#define COLFIL_RANDOM__

namespace colfil {
  template<typename VALUE_T, typename SEED_T = VALUE_T>
  class Random{
  public:

    typedef VALUE_T ValueType;
    typedef SEED_T SeedType;

  public:

    virtual ~Random()
    {
    }

    virtual ValueType operator()() = 0;
    virtual void setSeed(SeedType seed) = 0;
    virtual SeedType getSeed() const = 0;
  };

  class NLRandom : public Random<unsigned int, unsigned int>{

    unsigned int seed_;
    unsigned int value_;

  public:

    NLRandom()
    {
    }

    NLRandom(unsigned int seed)
    {
      setSeed(seed);
    }

    unsigned int operator()()
    {
      value_ = value_*1664525 + 1013904223;
      return value_;
    }

    void setSeed(unsigned int seed)
    {
      seed_ = seed;
      value_ = seed_;
      for (int i = 0; i < 100; ++i) {
        this->operator()();
      }
    }

    SeedType getSeed() const
    {
      return seed_;
    }
  };
}

#endif /* COLFIL_RANDOM__ */

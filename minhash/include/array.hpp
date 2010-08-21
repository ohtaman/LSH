/**
 * @file array.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Aug 21 10:49:33 2010 last updated
 * @date Sat Aug 21 09:25:48 2010 created
 */

#ifndef COLFIL_ARRAY__
#define COLFIL_ARRAY__

#include <vector>

namespace colfil {
  template<typename T, unsigned int N>
  class Array : public std::vector<T>{
  public:
    Array() : std::vector<T>(N)
    {
    }
  };

  /*
  template<typename T, unsigned int N>
  class Array{
  public:

    typedef Array<T, N> SelfType;

  private:

    T array_[N];

  public:

    Array()
    {
    }

    Array(const T *rhs)
    {
      for (unsigned int i = 0; i < N; ++i) {
        (*this)[i] = rhs[i];
      }
    }


    T &operator[](unsigned int i)
    {
      return array_[i];
    }

    const T &operator[](unsigned int i) const
    {
      return array_[i];
    }

    SelfType operator=(const SelfType &rhs)
    {
      for (int i = 0; i < N; ++i) {
        (*this)[i] = rhs[i];
      }

      return *this;
    }

    bool operator==(const SelfType &other) const
    {
      for (int i = 0; i < N; ++i) {
        if ((*this)[i] != other[i]) {
          return false;
        }
      }

      return true;
    }

    bool operator<(const SelfType &other) const
    {
      for (int i = 0; i < N; ++i) {
        if ((*this)[i] < other[i]) {
          return true;
        } else if ((*this)[i] > other[i]) {
          return false;
        }
      }

      return false;
    }

    bool operator>(const SelfType &other) const
    {
      return other < *this;
    }
  };
  */
}

#endif /* COLFIL_ARRAY__ */

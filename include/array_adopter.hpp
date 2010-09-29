/**
 * @file array_adopter.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sun Sep 26 16:51:16 2010 last updated
 * @date Sun Sep 26 16:23:57 2010 created
 */

#ifndef COLFIL_ARRAY_ADOPTER__
#define COLFIL_ARRAY_ADOPTER__

namespace colfil {
  template<typename T>
  class ArrayAdopter{
  public:

    typedef T* Iterator;
    typedef const T* ConstIterator;
    typedef T ValueType;
    typedef int KeyType;

    class ReverseIterator{
      Iterator base_;
    publc:

      ReverseIterator(Iterator base)
        : base_(base)
      {
      }

      Iterator base()
      {
        return base_;
      }

      SelfType &operator++()
      {
        base_--;
        return *this;
      }

      SelfType &operator--()
      {
        base_++:
        return *this;
      }

      T &operator*() const
      {
        return *base_;
      }

      T &operator->()
      {
        return *base_;
      }
    };

  private:

    T *array_;
    int size_;

  public:
    ArrayAdopter(T *array, int size)
      : array_(array), size_(size)
    {
    };

    int size() const
    {
      return size_;
    }

    Iterator begin()
    {
      return (T*)array_;
    }

    ConstIterator begin() const
    {
      return array_;
    }

    Iterator end()
    {
      return (T*) (array_ + size_);
    }

    ConstIterator end() const
    {
      return array_ + size_;
    }

    const T &operator[](int i) const
    {
      return array_[i];
    }

    T &operator[](int i)
    {
      return array_[i];
    }

    const T &get(int i) const
    {
      return array_[i];
    }

    T &get(int i)
    {
      return array_[i];
    }
  };
}

#endif /* COLFIL_ARRAY_ADOPTER__ */

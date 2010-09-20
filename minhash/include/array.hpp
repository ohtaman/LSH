/**
 * @file array.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sun Sep 12 12:28:46 2010 last updated
 * @date Sat Aug 21 09:25:48 2010 created
 */

#ifndef COLFIL_ARRAY__
#define COLFIL_ARRAY__

#include <vector>

namespace colfil {
  template<typename T, unsigned int N>
  class Array : public std::vector<T>{
  public:

    typedef typename std::vector<T>::iterator Iterator;
    typedef typename std::vector<T>::const_iterator ConstIterator;
    typedef typename std::vector<T>::reverse_iterator ReverseIterator;
    typedef typename std::vector<T>::const_reverse_iterator ConstReverseIterator;
    typedef typename std::vector<T>::value_type ValueType;

  public:

    Array() : std::vector<T>(N)
    {
    }
  };

}

#endif /* COLFIL_ARRAY__ */

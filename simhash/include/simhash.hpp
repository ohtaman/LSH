/**
 * @file simhash.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Sep 11 18:31:19 2010 last updated
 * @date Sat Sep 11 15:39:48 2010 created
 */

#ifndef COLFIL_SIMHASH__
#define COLFIL_SIMHASH__


#include "hash.hpp"
#include "container_traits.hpp"

namespace colfil {

  /* need to be N <= sizeof(VALUE_T)*8 */
  template<unsigned int N, typename VALUE_T = unsigned int, typename CONTAINER_T, typename HASH = Shift32ConstHash>
  class SimHash : public Hash<const CONTAINER_T&, unsigned int>{
  public:

    typedef CONTAINER_T ContainerType;
    typedef VALUE_T ValueType;
    typedef typename HASH::ValueType HashValueType;
    typedef HASH HashType;
    typedef SimHash<N, VALUE_T, T, CONTAINER_T, HASH> SelfType;
    typedef ContainerTraits<CONTAINER_T>::ConstIterator ContainerConstIterator;

  private:

    HASH hash_;

  public:

    ValueType operator()(const ContainerType &input) const
    {
      ValueType result = 0;

      for (unsigned int i = 0; i < N; ++i) {
        T tmp = 0;
        for (ContainerConstIterator ite = input.begin(); ite != input.end(); ++ite) {
          tmp += ite->second * (hash_(ite->first)>>1) * (-1);
        }

        result << 1;
        if (tmp > 0) {
          result &= 1;
        }
      }

      return result;
    }
  };

}

#endif /* COLFIL_SIMHASH__ */

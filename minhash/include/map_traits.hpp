/**
 * @file map_traits.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sun Sep 12 00:48:29 2010 last updated
 * @date Sun Sep 12 00:32:11 2010 created
 */

#ifndef COLFIL_MAP_TRAITS__
#define COLFIL_MAP_TRAITS__

#include "container_traits.hpp"

namespace colfil {
  template<typename T>
  class MapTraits : public ContainerTraits<T>{
  public:

    typedef typename T::KeyType KeyType;

    template<typename ITERATOR_T>
    KeyType getKey(const ITERATOR_T &ite)
    {
      return ite.key();
    }

  };

  template<>
  template<typename T, typename A>
  class MapTraits<std::vector<T, A> > : public ContainerTraits<std::vector<T, A> >{
  public:

    typedef int KeyType;

    template<typename ITERATOR_T>
    KeyType getKey(const ITERATOR_T &ite)
    {
      return *ite;
    }
  };

  template<>
  template<typename K, typename T, typename C, typename A>
  class MapTraits<std::map<K, T, C, A> > : public ContainerTraits<std::map<K, T, C, A> >{
  public:

    typedef K KeyType;
    KeyType getKey(const ConstIterator &ite)
    {
      return ite.first;
    }
  };
}

#endif /* COLFIL_MAP_TRAITS__ */

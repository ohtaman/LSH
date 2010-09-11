/**
 * @file container_traits.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Sat Sep 11 16:09:00 2010 last updated
 * @date Sat Sep 11 15:05:23 2010 created
 */

#ifndef COLFIL_CONTAINER_TRAITS__
#define COLFIL_CONTAINER_TRAITS__

#include <vector>
#include <list>
#include <set>
#include <map>


namespace colfil {

  template<typename T>
  class ContainerTraits {
  public:
    typedef typename T::Iterator Iterator;
    typedef typename T::ConstIterator ConstIterator;
    typedef typename T::ReverseIterator ReverseIterator;
    typedef typename T::ConstReverseIterator ConstReverseIterator;

    typedef typename T::ValueType ValueType;
  };

  template<>
  template<typename T, typename A>
  class ContainerTraits<std::vector<T, A> > {
  public:
    typedef typename std::vector<T, A>::iterator Iterator;
    typedef typename std::vector<T, A>::const_iterator ConstIterator;
    typedef typename std::vector<T, A>::reverse_iterator ReverseIterator;
    typedef typename std::vector<T, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::vector<T, A>::value_type ValueType;
  };

  template<>
  template<typename T, typename A>
  class ContainerTraits<std::list<T, A> > {
  public:
    typedef typename std::list<T, A>::iterator Iterator;
    typedef typename std::list<T, A>::const_iterator ConstIterator;
    typedef typename std::list<T, A>::reverse_iterator ReverseIterator;
    typedef typename std::list<T, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::list<T, A>::value_type ValueType;
  };

  template<>
  template<typename K, typename C, typename A>
  class ContainerTraits<std::set<K, C, A> > {
  public:
    typedef typename std::set<K, C, A>::iterator Iterator;
    typedef typename std::set<K, C, A>::const_iterator ConstIterator;
    typedef typename std::set<K, C, A>::reverse_iterator ReverseIterator;
    typedef typename std::set<K, C, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::set<K, C, A>::value_type ValueType;
  };

  template<>
  template<typename K, typename C, typename A>
  class ContainerTraits<std::multiset<K, C, A> > {
  public:
    typedef typename std::multiset<K, C, A>::iterator Iterator;
    typedef typename std::multiset<K, C, A>::const_iterator ConstIterator;
    typedef typename std::multiset<K, C, A>::reverse_iterator ReverseIterator;
    typedef typename std::multiset<K, C, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::multiset<K, C, A>::value_type ValueType;
  };

  template<>
  template<typename K, typename T, typename C, typename A>
  class ContainerTraits<std::map<K, T, C, A> > {
  public:
    typedef typename std::map<K, T, C, A>::iterator Iterator;
    typedef typename std::map<K, T, C, A>::const_iterator ConstIterator;
    typedef typename std::map<K, T, C, A>::reverse_iterator ReverseIterator;
    typedef typename std::map<K, T, C, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::map<K, T, C, A>::value_type ValueType;
  };

  template<>
  template<typename K, typename T, typename C, typename A>
  class ContainerTraits<std::multimap<K, T, C, A> > {
  public:
    typedef typename std::multimap<K, T, C, A>::iterator Iterator;
    typedef typename std::multimap<K, T, C, A>::const_iterator ConstIterator;
    typedef typename std::multimap<K, T, C, A>::reverse_iterator ReverseIterator;
    typedef typename std::multimap<K, T, C, A>::const_reverse_iterator ConstReverseIterator;

    typedef typename std::multimap<K, T, C, A>::value_type ValueType;
  };

}

#endif /* COLFIL_CONTAINER_TRAITS__ */

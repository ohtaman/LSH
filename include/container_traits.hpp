/**
 * @file container_traits.hpp
 * @author Ohtaman
 * @brief
 *
 * @date Fri Sep 24 17:45:59 2010 last updated
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

    typedef T ContainerType;
    typedef typename T::Iterator Iterator;
    typedef typename T::ConstIterator ConstIterator;
    typedef typename T::ReverseIterator ReverseIterator;
    typedef typename T::ConstReverseIterator ConstReverseIterator;

    typedef typename T::ValueType ValueType;

    static Iterator getBegin(T &container)
    {
      return container.begin();
    }

    static ConstIterator getBegin(const T &container)
    {
      return container.begin();
    }

    static Iterator getEnd(T &container)
    {
      return container.end();
    }

    static ConstIterator getEnd(const T &container)
    {
      return container.end();
    }
  };

  template<typename T>
  class MapTraits : public ContainerTraits<T> {
  public:


    typedef typename T::KeyType KeyType;
    typedef typename T::ValueType ValueType;
    typedef MapTraits<T> SelfType;

    static KeyType getKey(const typename SelfType::ConstIterator &ite)
    {
      return ite->first;
    }

    static ValueType getValue(const typename SelfType::ConstIterator &ite)
    {
      return ite->second;
    }

    static T &set(T *container,
                  const typename SelfType::KeyType &key,
                  const typename SelfType::ValueType &value)
    {
      (*container)[key] = value;
      return *container;
    }
  };


  template<typename T>
  class STLContainerTraits {
  public:

    typedef T ContainerType;
    typedef typename T::iterator Iterator;
    typedef typename T::const_iterator ConstIterator;
    typedef typename T::reverse_iterator ReverseIterator;
    typedef typename T::const_reverse_iterator ConstReverseIterator;

    typedef typename T::value_type ValueType;

    static Iterator getBegin(T &container) {
      return container.begin();
    }

    static ConstIterator getBegin(const T &container) {
      return container.begin();
    }

    static Iterator getEnd(T &container) {
      return container.end();
    }

    static ConstIterator getEnd(const T &container) {
      return container.end();
    }
  };


  template<>
  template<typename T, typename A>
  class ContainerTraits<std::vector<T, A> >
    : public STLContainerTraits<std::vector<T, A> >{
  public:

    typedef int KeyType;
    typedef ContainerTraits<std::vector<T, A> > SelfType;

    static std::vector<T, A> &set(std::vector<T, A> *container,
                                  int key,
                                  const typename SelfType::ValueType &value)
    {
      (*container)[key] = value;
      return *container;
    }
  };

  template<>
  template<typename T, typename A>
  class ContainerTraits<std::list<T, A> >
    : public STLContainerTraits<std::list<T, A> > {
  public:
  };

  template<>
  template<typename K, typename C, typename A>
  class ContainerTraits<std::set<K, C, A> >
    : public STLContainerTraits<std::set<K, C, A> > {
  public:
  };

  template<>
  template<typename K, typename C, typename A>
  class ContainerTraits<std::multiset<K, C, A> >
    : public STLContainerTraits<std::multiset<K, C, A> > {
  public:
  };


  template<>
  template<typename K, typename T, typename C, typename A>
  class ContainerTraits<std::map<K, T, C, A> >
    : public STLContainerTraits<std::map<K, T, C, A> > {
  public:

    typedef typename std::map<K, T, C, A>::key_type KeyType;
    typedef typename std::map<K, T, C, A>::mapped_type ValueType;

    typedef ContainerTraits<std::map<K, T, C, A> > SelfType;

    static KeyType getKey(const typename SelfType::ConstIterator &ite)
    {
      return ite->first;
    }

    static ValueType getValue(const typename SelfType::ConstIterator &ite)
    {
      return ite->second;
    }

    static std::map<K, T, C, A> &set(std::map<K, T, C, A> *container,
                                     const typename SelfType::KeyType &key,
                                     const typename SelfType::ValueType &value)
    {
      (*container)[key] = value;
      return *container;
    }
  };

  template<>
  template<typename K, typename T, typename C, typename A>
  class ContainerTraits<std::multimap<K, T, C, A> >
    : public STLContainerTraits<std::multimap<K, T, C, A> > {
  public:

    typedef typename std::multimap<K, T, C, A>::key_type KeyType;
    typedef typename std::multimap<K, T, C, A>::mapped_type ValueType;

    typedef ContainerTraits<std::multimap<K, T, C, A> > SelfType;

    static KeyType getKey(const typename SelfType::ConstIterator &ite)
    {
      return ite->first;
    }

    static ValueType getValue(const typename SelfType::ConstIterator &ite)
    {
      return ite->second;
    }
  };

}

#endif /* COLFIL_CONTAINER_TRAITS__ */

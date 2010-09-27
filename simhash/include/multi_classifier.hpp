/**
 * @file multi_classifier.hpp
 * @author Mitsuhisa Ohta
 * @brief
 *
 * @date Fri Sep 24 15:38:11 2010 last updated
 * @date Fri Sep 24 15:37:58 2010 created
 */

#ifndef COLFIL_MULTI_CLASSIFIER__
#define COLFIL_MULTI_CLASSIFIER__

namespace colfil {
  template<typename INPUT_T, typename VALUE_T>
  class MultiClassifier{
  public:
    virtual void classify(const INPUT_T &input, VALUE_T *output) const = 0;
  };
}

#endif /* COLFIL_MULTI_CLASSIFIER__ */

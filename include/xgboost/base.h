/*!
 * Copyright (c) 2015 by Contributors
 * \file base.h
 * \brief defines configuration macros of xgboost.
 */
#ifndef XGBOOST_BASE_H_
#define XGBOOST_BASE_H_

#include <dmlc/base.h>
#include <dmlc/omp.h>

namespace xgboost {
/*!
 * \brief unsigned interger type used in boost,
 *  used for feature index and row index.
 */
typedef uint32_t bst_uint;
/*! \brief float type, used for storing statistics */
typedef float bst_float;

/*! \brief gradient statistics pair usually needed in gradient boosting */
struct bst_gpair {
  /*! \brief gradient statistics */
  bst_float grad;
  /*! \brief second order gradient statistics */
  bst_float hess;
  bst_gpair() {}
  bst_gpair(bst_float grad, bst_float hess) : grad(grad), hess(hess) {}
};

const float rt_eps = 1e-5f;
// min gap between feature values to allow a split happen
const float rt_2eps = rt_eps * 2.0f;

typedef dmlc::omp_ulong omp_ulong;
typedef dmlc::omp_uint bst_omp_uint;

/*!
 * \brief define compatible keywords in g++
 *  Used to support g++-4.6 and g++4.7
 */
#if DMLC_USE_CXX11 && defined(__GNUC__) && !defined(__clang_version__)
#if __GNUC__ == 4 && __GNUC_MINOR__ < 8
#define override
#define final
#endif
#endif
}  // namespace xgboost
#endif  // XGBOOST_BASE_H_

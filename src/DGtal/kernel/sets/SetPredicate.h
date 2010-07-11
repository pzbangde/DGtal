#pragma once

/**
 * @file SetPredicate.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/10
 *
 * Header file for module SetPredicate.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(SetPredicate_RECURSES)
#error Recursive header files inclusion detected in SetPredicate.h
#else // defined(SetPredicate_RECURSES)
/** Prevents recursive inclusion of headers. */
#define SetPredicate_RECURSES

#if !defined SetPredicate_h
/** Prevents repeated inclusion of headers. */
#define SetPredicate_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/BasicPointPredicates.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class SetPredicate
  /**
   * Description of template class 'SetPredicate' <p> \brief Aim:
   * The predicate returning true iff the point is in the domain given
   * at construction.
   *
   * Model of CPointPredicate
   */
  template <typename TDigitalSet>
  struct SetPredicate
  {
    // ----------------------- Standard services ------------------------------
  public:
    typedef TDigitalSet DigitalSet;
    typedef typename DigitalSet::DomainType Domain;
    typedef typename Domain::Point Point;

    /**
     * Constructor.
     * @param aSet any set.
     */
    SetPredicate ( const DigitalSet & aSet );

    /**
     * Copy constructor.
     * @param other the object to clone.
     */
    SetPredicate ( const SetPredicate & other );

   /**
     * @param p any point.
     * @return true iff p is in the domain.
     */
    bool operator()( const Point & p ) const;

    // ------------------------- Hidden services ------------------------------
  protected:

    /**
     * Constructor.
     * Forbidden by default (protected to avoid g++ warnings).
     */
    SetPredicate();

  private:
    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    SetPredicate & operator= ( const SetPredicate & other );

    // ------------------------- Internals ------------------------------------
  private:
    const DigitalSet* const mySet;

  }; // end of struct SetPredicate


} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/kernel/sets/SetPredicate.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined SetPredicate_h

#undef SetPredicate_RECURSES
#endif // else defined(SetPredicate_RECURSES)
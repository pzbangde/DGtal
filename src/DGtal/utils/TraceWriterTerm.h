/** 
 * @file TraceWriterTerm.h
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2010/02/17
 * 
 * Header file for module TraceWriterTerm.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(TraceWriterTerm_RECURSES)
#error Recursive header files inclusion detected in TraceWriterTerm.h
#else // defined(TraceWriterTerm_RECURSES)
/** Prevents recursive inclusion of headers. */
#define TraceWriterTerm_RECURSES

#if !defined TraceWriterTerm_h
/** Prevents repeated inclusion of headers. */
#define TraceWriterTerm_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <string>
#include "DGtal/utils/TraceWriter.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal 
{
  
  /////////////////////////////////////////////////////////////////////////////
  // class TraceWriterTerm
  /** 
   * Description of class 'TraceWriterTerm' <p>
   * Aim: Implements trace prefix for color terminals
   *
   * \todo Detect if the terminal has color capabilities
   */
  class TraceWriterTerm: public TraceWriter
  {
    // ----------------------- Standard services ------------------------------
  public:
    
    /**
     * Constructor.
     * @param outputStream the current output Stream 
     *
     */
    TraceWriterTerm(std::ostream &outputStream=std::cerr) : TraceWriter(outputStream) {};
    

    /**
     * Destructor. 
     */
    ~TraceWriterTerm() {};

    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    
    /**
     * Create a Wrarning Prefix
     *
     * @return the prefix
     */
    std::string  prefixWarning() 
      {
#if ( (defined(UNIX)||defined(unix)||defined(linux)) )
	return "\033[0m\033[35m";
#else
	return "";
#endif
      }
    
    /**
     * Create an Info Prefix
     * @return the prefix
     */
    std::string  prefixInfo()  
      {
#if ( (defined(UNIX)||defined(unix)||defined(linux)) )
	return "\033[0m";
#else
	return "";
#endif
    }

    /**
     * Create an Error Prefix
     * @return the prefix
     */
    std::string  prefixError() 
      {
#if ( (defined(UNIX)||defined(unix)||defined(linux)) )
	return "\033[0m\033[31m[ERR]";
#else
	return "";
#endif
      }
    
    /**
     * Create an Emphase Prefix
     * @return the prefix
     */
    std::string  prefixEmphase() 
      {
#if ( (defined(UNIX)||defined(unix)||defined(linux)) )
	return "\033[0m\033[1m";
#else
	return "";
#endif
      }

    /**
     * Create a Reset postfix
     * @return the postfix
     */
    std::string  postfixReset() 
      {
#if ( (defined(UNIX)||defined(unix)||defined(linux)) )
	return "\033[0m";
#else
	return "";
#endif
      }
   
  private:

    /**
     * Copy constructor.
     * @param other the object to clone.
     * Forbidden by default.
     */
    TraceWriterTerm( const TraceWriterTerm & other );

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     * Forbidden by default.
     */
    TraceWriterTerm & operator=( const TraceWriterTerm & other );
 
  }; // end of class TraceWriterTerm


  /**
   * Overloads 'operator<<' for displaying objects of class 'TraceWriterTerm'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'TraceWriterTerm' to write.
   * @return the output stream after the writing.
   */
  std::ostream&
  operator<<( std::ostream & out, const TraceWriterTerm & object );

  
} // namespace DGtal


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined TraceWriterTerm_h

#undef TraceWriterTerm_RECURSES
#endif // else defined(TraceWriterTerm_RECURSES)

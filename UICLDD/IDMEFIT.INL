#ifndef _IDMEFIT_INL_
  #define _IDMEFIT_INL_ 0
/*******************************************************************************
* FILE NAME: idmefit.inl                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmefit.hpp.                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmefit.inv  $                         *
//
//   Rev 1.0   10 Aug 1993 15:21:00   banzai
//Make drag item provider into template
//
*******************************************************************************/
#ifndef _IDMEFIT_
  #undef  _IDMEFIT_INL_
  #define _IDMEFIT_INL_ 1
  #include <idmefit.hpp>
#endif


#if _IDMEFIT_INL_
  #define inline
#endif


/*=========================================================================
  Inlines for IDMEFItem                                         MAB 07/22 |
=========================================================================*/
inline IString IDMEFItem :: text() const
{
  return(contents());
}

inline unsigned IDMEFItem :: size() const
{
  return(contentsSize());
}

/*=========================================================================
| Inlines for IDMEFItemHandle                                   MAB 06/14 |
=========================================================================*/

#endif // _IDMEFIT_INL_

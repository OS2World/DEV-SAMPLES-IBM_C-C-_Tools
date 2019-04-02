#ifndef _IDMMLEIT_INL_
  #define _IDMMLEIT_INL_ 0
/*******************************************************************************
* FILE NAME: idmmleit.inl                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmmleit.hpp.                                        *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmmleit.inv  $                         *
//
//   Rev 1.0   10 Aug 1993 15:21:30   banzai
//Make drag item provider into template
//
*******************************************************************************/
#ifndef _IDMMLEIT_
  #undef  _IDMMLEIT_INL_
  #define _IDMMLEIT_INL_ 1
  #include <idmmleit.hpp>
#endif


#if _IDMMLEIT_INL_
  #define inline
#endif


/*=========================================================================
  Inlines for IDMMLEItem                                        MAB 07/22 |
=========================================================================*/
inline IString IDMMLEItem :: text() const
{
  return(contents());
}

inline unsigned IDMMLEItem :: size() const
{
  return(contentsSize());
}

/*=========================================================================
| Inlines for IDMMLEItemHandle                                  MAB 06/14 |
=========================================================================*/

#endif // _IDMMLEIT_INL_

#ifndef _IDMRENDR_INL_
  #define _IDMRENDR_INL_ 0
/*******************************************************************************
* FILE NAME: idmrendr.inl                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmrendr.hpp.                                        *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmrendr.inv  $                         *
//
//   Rev 1.9   12 Aug 1993 13:53:16   banzai
//Merge source and target item into one
//
//   Rev 1.8   17 Jul 1993 14:04:48   banzai
//Fix trap on exit
//
//   Rev 1.7   13 Jul 1993 15:57:44   banzai
//Add assignment operator for handles
//
//   Rev 1.6   09 Jun 1993 16:10:00   banzai
//More changes
//
//   Rev 1.5   07 Jun 1993 16:29:22   unknown
//Same oh sam oh
//
//   Rev 1.4   04 Jun 1993 16:50:04   unknown
//Control Enablement
//
//   Rev 1.3   05 May 1993 16:36:04   unknown
//Source Render Prepare changes
//
//   Rev 1.2   30 Apr 1993 11:46:14   HAGGAR
//
//   Rev 1.1   22 Apr 1993 15:05:38   HAGGAR
//preprocessor problem
//
//   Rev 1.0   22 Apr 1993 10:42:02   HAGGAR
//Initial revision.
//
*******************************************************************************/
#ifndef _IDMRENDR_
  #undef  _IDMRENDR_INL_
  #define _IDMRENDR_INL_ 1
  #include <idmrendr.hpp>
#endif


#if _IDMRENDR_INL_
  #define inline
#endif

/*=========================================================================
| Inlines for IDMRenderer                                       MAB 04/14 |
=========================================================================*/
inline IString IDMRenderer :: supportedTypes() const
{
  return(strTypes);
}

inline IString IDMRenderer :: supportedRMFs() const
{
  return(strRMFs);
}


/*=========================================================================
| Inlines for IDMSourceRenderer                                 MAB 04/07 |
=========================================================================*/


/*=========================================================================
| Inlines for IDMTargetRenderer                                 MAB 04/08 |
=========================================================================*/

#endif //_IDMRENDR_INL_

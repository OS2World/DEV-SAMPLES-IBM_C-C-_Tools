#ifndef _IDMOPER_INL_
  #define _IDMOPER_INL_ 0
/*******************************************************************************
* FILE NAME: idmoper.inl                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmoper.hpp.                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmoper.inv  $                                 *
//
//   Rev 1.9   17 Aug 1993 15:25:08   banzai
//Move ISet stuff to .CPP
//
//   Rev 1.8   13 Aug 1993 14:16:04   banzai
//Move setOperation to public & move PM specific stuff to private
//
//   Rev 1.7   12 Aug 1993 13:53:06   banzai
//Merge source and target item into one
//
//   Rev 1.6   01 Jul 1993 12:22:38   HAGGAR
//rendering changes
//
//   Rev 1.5   28 Jun 1993 11:47:28   banzai
//Fix traps in handle logic
//
//   Rev 1.4   18 Jun 1993 14:14:44   banzai
//Fix handle bugs
//
//   Rev 1.3   04 Jun 1993 16:35:14   HAGGAR
//No change.
//
//   Rev 1.2   03 May 1993 16:05:58   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:46:12   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:42:02   HAGGAR
//Initial revision.
//
*******************************************************************************/
#ifndef _IDMOPER_
  #undef  _IDMOPER_INL_
  #define _IDMOPER_INL_ 1
  #include <idmoper.hpp>
#endif

#ifndef _IDMSRCOP_
  #include <idmsrcop.hpp>
#endif

#ifndef _IDMTGTOP_
  #include <idmtgtop.hpp>
#endif

#ifndef _IDMITEM_
//  #include <idmitem.hpp>
#endif

#if _IDMOPER_INL_
  #define inline
#endif

/*=========================================================================
| Inlines for IDMOperation                                                |
|                                                                         |
| History:                                                                |
| 03/23/93  Peter Haggar  Created it.                                     |
=========================================================================*/
inline IPoint IDMOperation :: position () const
{
  return (pos);
}

/**************************************************************************/
/* IDMOperation :: numberOfImages                                         */
/*   Returns the number of drag images.                                   */
/**************************************************************************/
//pfh inline unsigned IDMOperation :: numberOfImages ( )
//pfh{
//pfh  return (imageSetCl()->numberOfElements());
//pfh}

/**************************************************************************/
/* IDMOperation :: image                                                  */
/*   Returns the drag image with the given index.                         */
/**************************************************************************/
//pfh inline IDMDragImageHandle IDMOperation :: image (unsigned index)
//pfh {
//pfh   return (imageSetCl()->elementAtPosition(index));
//pfh }

inline IWindowHandle IDMOperation :: sourceWindow () const
{
  return (srcWindow);
}

inline IDMTgtOperationHandle IDMTargetOperation :: targetOperation ( )
{
  return (pDMTgtOpHandle);
}

//pfh inline IDMSrcItemHandle IDMSourceOperation :: item (unsigned index)
//pfh {
//pfh   return (itemCollection()->elementAtPosition(index));
//pfh }

//pfh inline IDMTgtItemHandle IDMTargetOperation :: item (unsigned index)
//pfh {
//pfh   return (itemCollection()->elementAtPosition(index));
//pfh }

#endif //_IDMOPER_INL_

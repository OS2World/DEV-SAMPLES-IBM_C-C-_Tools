#ifndef _IDMSRCH_INL_
  #define _IDMSRCH_INL_ 0
/*******************************************************************************
* FILE NAME: idmsrch.inl                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmsrch.hpp.                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   I:/ibmclass/idrag/vcs/idmsrch.inv  $                                 *
//
//   Rev 1.9   17 Aug 1993 12:46:54   law
//Removed templates from i/f.
//
//   Rev 1.8   12 Aug 1993 13:53:22   banzai
//Merge source and target item into one
//
//   Rev 1.7   05 Aug 1993 18:50:38   banzai
//Clean up headers and function names
//
//   Rev 1.6   29 Jul 1993 19:28:06   banzai
//Move reuseable code to handlers per controls
//
//   Rev 1.5   14 Jun 1993 17:00:08   banzai
//Publicize renderer support
//
//   Rev 1.4   11 Jun 1993 15:55:30   banzai
//Move Drag Item Provider back to IWindow
//
//   Rev 1.3   10 Jun 1993 16:52:26   banzai
//Put drag item provider in src handler
//
//   Rev 1.2   18 May 1993 13:43:26   unknown
//No change
//
//   Rev 1.1   30 Apr 1993 11:46:18   HAGGAR
//No change.
//
//   Rev 1.0   22 Apr 1993 10:42:04   HAGGAR
//Initial revision.
//
*******************************************************************************/
#ifndef _IDMSRCH_
  #undef  _IDMSRCH_INL_
  #define _IDMSRCH_INL_ 1
  #include <idmsrch.hpp>
#endif

#if _IDMSRCH_INL_
  #define inline
#endif

/*=========================================================================
| Inlines for IDMSRCH                                                     |
|                                                                         |
| History:                                                                |
| 03/23/93  Peter Haggar  Created it.                                     |
=========================================================================*/
/**************************************************************************/
/* IDMSourceHandler :: targetEnterNotify                                  */
/*   Called when a target window processes a target enter event.          */
/**************************************************************************/
inline Boolean IDMSourceHandler ::
               targetEnterNotify (IDMSourceNotifyEvent &event)
{
  return (false);
}

/**************************************************************************/
/* IDMSourceHandler :: numberOfRenderers                                  */
/*   Handles the ending of a conversation of a partiular drag item.       */
/**************************************************************************/
#if 0
inline unsigned IDMSourceHandler :: numberOfRenderers ()
{
  return (rendererSeqCl()->numberOfElements());
}
#endif

/**************************************************************************/
/* IDMSourceHandler :: renderer                                           */
/*   Returns the renderer with the given index.                           */
/**************************************************************************/
#if 0
inline IDMSourceRenderer* IDMSourceHandler :: renderer (unsigned index)
{
  return (rendererSeqCl()->elementAtPosition(index));
}
#endif

#endif //_IDMSRCH_INL_

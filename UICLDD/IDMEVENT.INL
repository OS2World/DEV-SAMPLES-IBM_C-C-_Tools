#ifndef _IDMEVENT_INL_
  #define _IDMEVENT_INL_ 0
/*******************************************************************************
* FILE NAME: idmevent.inl                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmevent.hpp.                                        *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmevent.inv  $                         *
//
//   Rev 1.12   12 Aug 1993 13:52:38   banzai
//Merge source and target item into one
//
//   Rev 1.11   06 Aug 1993 16:40:14   banzai
//Remove pos stuff from constructor per breaking derivedclasses
//
//   Rev 1.10   03 Aug 1993 20:17:24   banzai
//Add support for dropPosition()
//
//   Rev 1.9   02 Aug 1993 15:26:38   HAGGAR
//rendering changes
//
//   Rev 1.8   01 Jul 1993 12:22:28   HAGGAR
//rendering changes
//
//   Rev 1.7   28 Jun 1993 11:46:50   banzai
//Fix traps in handle logic
//
//   Rev 1.6   10 Jun 1993 09:25:08   banzai
//Here's the Beef
//
//   Rev 1.5   09 Jun 1993 16:09:50   banzai
//More changes
//
//   Rev 1.4   09 Jun 1993 09:44:38   banzai
//Enable additional events
//
//   Rev 1.3   04 Jun 1993 16:39:40   unknown
//Control Enablement
//
//   Rev 1.2   03 May 1993 16:05:48   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:46:02   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:58   HAGGAR
//Initial revision.
//
*******************************************************************************/
#ifndef _IDMEVENT_
  #undef  _IDMEVENT_INL_
  #define _IDMEVENT_INL_ 1
  #include <idmevent.hpp>
#endif

#if _IDMEVENT_INL_
  #define inline
#endif


/*=========================================================================
| Inlines for IDMSourceBeginEvent                               PFH 04/23 |
=========================================================================*/

/*=========================================================================
| Inlines for IDMSourceRenderEvent                              PFH 06/16 |
=========================================================================*/
inline IWindowHandle IDMSourceRenderEvent::targetWindow()
{
  return (tgtWindow);
}

/*=========================================================================
| Inlines for IDMSourcePrepareEvent                             MAB 06/09 |
=========================================================================*/


/*=========================================================================
| Inlines for IDMSourceEndEvent                                 PFH 04/23 |
=========================================================================*/


/*=========================================================================
| Inlines for IDMTargetEnterEvent                               MAB 04/30 |
=========================================================================*/

/*=========================================================================
| Inlines for IDMUMTgtEnterEvent                                MAB 04/30 |
=========================================================================*/

/*=========================================================================
| Inlines for IDMTargetDropEvent                                MAB 04/02 |
=========================================================================*/

#endif // _IDMEVENT_INL_

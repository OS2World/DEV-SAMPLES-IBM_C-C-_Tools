#ifndef _IDMTGTH_INL_
  #define _IDMTGTH_INL_ 0
/*******************************************************************************
* FILE NAME: idmtgth.inl                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmtgth.hpp.                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmtgth.inv  $                         *
//
//   Rev 1.10   19 Aug 1993 11:05:36   banzai
//No change.
//
//   Rev 1.9   17 Aug 1993 12:45:54   law
//Removed templates from i/f.
//
//   Rev 1.8   12 Aug 1993 13:53:32   banzai
//Merge source and target item into one
//
//   Rev 1.7   29 Jul 1993 19:28:18   banzai
//Move reuseable code to handlers per controls
//
//   Rev 1.6   17 Jul 1993 14:04:40   banzai
//Fix trap on exit
//
//   Rev 1.5   14 Jun 1993 17:00:18   banzai
//Publicize renderer support
//
//   Rev 1.4   19 May 1993 09:30:12   HAGGAR
//
//   Rev 1.3   05 May 1993 16:37:48   unknown
//DM_DROP changes
//
//   Rev 1.2   03 May 1993 16:06:08   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:46:18   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:42:06   HAGGAR
//Initial revision.
//
//   Rev 1.2   18 Feb 1993 09:46:00   BANZAI
//Move functions that return void* to private
//
//   Rev 1.1   11 Feb 1993 15:54:06   BANZAI
//Std const and enum names
//
//   Rev 1.0   21 Jan 1993 16:54:32   BANZAI
//Split inlines from header
//
*                                                                              *
*******************************************************************************/
#ifndef _IDMTGTH_
  #undef  _IDMTGTH_INL_
  #define _IDMTGTH_INL_ 1
  #include <idmtgth.hpp>
#endif

#if _IDMTGTH_INL_
  #define inline
#endif

/*=========================================================================
| Inlines for IDMTargetHandler                                            |
=========================================================================*/
#if 0
inline IDMTargetHandler::IDMTgtRendererSeq& IDMTargetHandler ::
                                            rendererCollection()
{
  return (tgtRenderersSeqCl);
}

inline unsigned IDMTargetHandler :: numberOfRenderers()
{
  return (rendererCollection().numberOfElements());
}

inline IDMTargetRenderer* IDMTargetHandler :: renderer(unsigned index)
{
  return (rendererCollection().elementAtPosition(index));
}
#endif

#endif // _IDMTGTH_INL_

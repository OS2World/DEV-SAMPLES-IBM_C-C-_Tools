#ifndef _IDMITEM_INL_
  #define _IDMITEM_INL_ 0
/*******************************************************************************
* FILE NAME: idmitem.inl                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the definition of the inline functions for the          *
*   class(es) declared in idmitem.hpp.                                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmitem.inv  $                         *
//
//   Rev 1.16   18 Aug 1993 15:42:22   banzai
//Remove render associations
//
//   Rev 1.15   17 Aug 1993 09:29:14   law
//Removed template from public i/f.
//
//   Rev 1.14   16 Aug 1993 15:29:42   banzai
//Update PM dragitem iff source update
//
//   Rev 1.13   12 Aug 1993 22:08:20   banzai
//Track src and tgt op handles separately
//
//   Rev 1.12   12 Aug 1993 14:41:14   banzai
//Fix link bug
//
//   Rev 1.11   12 Aug 1993 13:52:50   banzai
//Merge source and target item into one
//
//   Rev 1.10   10 Aug 1993 15:20:20   banzai
//Make drag item provider into template
//
//   Rev 1.9   07 Aug 1993 13:34:10   banzai
//Prose cleanup
//
//   Rev 1.8   26 Jul 1993 19:25:40   banzai
//Design changes per prv/item/rndr
//
//   Rev 1.7   17 Jul 1993 14:04:26   banzai
//Fix trap on exit
//
//   Rev 1.6   15 Jul 1993 13:38:58   banzai
//No change
//
//   Rev 1.5   13 Jul 1993 15:57:32   banzai
//Add assignment operator for handles
//
//   Rev 1.4   12 Jul 1993 11:33:20   banzai
//Rendering changes
//
//   Rev 1.3   01 Jul 1993 12:22:40   HAGGAR
//No change.
//
//   Rev 1.2   04 Jun 1993 15:55:54   unknown
//Changes per control enablement
//
//   Rev 1.1   30 Apr 1993 11:46:08   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:42:00   HAGGAR
//Initial revision.
//
*******************************************************************************/
#ifndef _IDMITEM_
  #undef  _IDMITEM_INL_
  #define _IDMITEM_INL_ 1
  #include <idmitem.hpp>
#endif


#if _IDMITEM_INL_
  #define inline
#endif


/*=========================================================================
| Inlines for IDMItem                                           MAB 08/11 |
=========================================================================*/
inline IWindowHandle IDMItem :: sourceWindow() const
{
  return(this->sourceWndh);
}

inline IString IDMItem :: containerName() const
{
  return(this->strContainerName);
}

inline IString IDMItem :: sourceName() const
{
  return(this->strSourceName);
}

inline IString IDMItem :: targetName() const
{
  return(this->strTargetName);
}

inline unsigned short IDMItem :: attributes() const
{
  return(this->dragAttrs);
}

inline unsigned short IDMItem :: supportedOperations() const
{
  return(this->dragSupOps);
}

inline ISize IDMItem :: origin() const
{
  return(this->sizeOrigin);
}

//pfh inline IDMImageHandle IDMItem :: dragImage() const
//pfh {
//pfh   return(pDragImage);
//pfh }

inline IString IDMItem :: types() const
{
  return(this->strTypes);

}

inline Boolean IDMItem :: hasType(const IString& aType) const
{
  //Scan stored types for argument
  if (this->strTypes.indexOf(aType))
    return(true);
  else
    return(false);
}

inline IString IDMItem :: sourceRMFs() const
{
  return(this->strRMFs);
}

inline Boolean IDMItem :: hasRMF(const IString& aRMF)
{
  //Scan stored RMFs for argument
  if (this->strRMFs.indexOf(aRMF))
    return(true);
  else
    return(false);
}

#if 0
inline IDMRendererAssocSeq& IDMItem :: rendererAssociations()
{
  return(this->rendererAssocSeqCl);
}
#endif

inline IString IDMItem :: contents() const
{
  return(this->strContents);
}

inline unsigned IDMItem :: contentsSize() const
{
  return(this->contents().size());
}

#if 0
/*=========================================================================
| Inlines for IDMRendererAssociate                              MAB 08/11 |
=========================================================================*/
inline IString IDMRendererAssociate :: type() const
{
  return(this->strAType);
}

inline IDMRenderer* IDMRendererAssociate :: renderer() const
{
  return(this->pRenderer);
}
#endif

#endif // _IDMITEM_INL_

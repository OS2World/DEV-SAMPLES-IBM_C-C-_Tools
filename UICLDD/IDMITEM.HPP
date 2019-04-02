#ifndef _IDMITEM_
#define _IDMITEM_
/*******************************************************************************
  FILE NAME: idmitem.hpp

  DESCRIPTION:
    This file contains the declaration(s) of the class(es):
      IDMItem                   - Base direct manipulation "item" class.
      IDMItemHandle             - Handle to manage references to IDMItem
                                  objects.
      IDMRendererAssociate      - Base direct manipulation renderer association
                                  class.

  COPYRIGHT:
    Licensed Materials - Property of IBM
    (C) Copyright IBM Corporation 1992, 1993
    All Rights Reserved
    US Government Users Restricted Rights - Use, duplication, or
    disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.

* $Log:   M:/ibmclass/idrag/vcs/idmitem.hpv  $
//
//   Rev 1.25   18 Aug 1993 15:42:18   banzai
//Remove render associations
//
//   Rev 1.24   17 Aug 1993 15:38:46   HAGGAR
//changes due to new design
//
//   Rev 1.23   17 Aug 1993 12:43:48   law
//Removed templates from i/f.
//
//   Rev 1.22   17 Aug 1993 09:29:10   law
//Removed template from public i/f.
//
//   Rev 1.21   16 Aug 1993 15:29:40   banzai
//Update PM dragitem iff source update
//
//   Rev 1.20   16 Aug 1993 09:20:38   banzai
//Cleanup for reference
//
//   Rev 1.19   14 Aug 1993 17:58:48   banzai
//Make setNativeRMF public
//
//   Rev 1.18   12 Aug 1993 22:08:16   banzai
//Track src and tgt op handles separately
//
//   Rev 1.17   12 Aug 1993 15:36:42   banzai
//Cleanup compiler warnings
//
//   Rev 1.16   12 Aug 1993 14:41:12   banzai
//Fix link bug
//
//   Rev 1.15   12 Aug 1993 13:52:48   banzai
//Merge source and target item into one
//
//   Rev 1.14   10 Aug 1993 15:20:16   banzai
//Make drag item provider into template
//
//   Rev 1.13   09 Aug 1993 12:43:00   banzai
//Rename sourceRenderer & targetRenderer to renderer
//
//   Rev 1.12   07 Aug 1993 13:34:12   banzai
//Prose cleanup
//
//   Rev 1.11   02 Aug 1993 15:27:54   HAGGAR
//more rendering changes
//
//   Rev 1.10   26 Jul 1993 19:25:42   banzai
//Design changes per prv/item/rndr
//
//   Rev 1.9   17 Jul 1993 14:04:24   banzai
//Fix trap on exit
//
//   Rev 1.8   15 Jul 1993 13:38:54   banzai
//No change
//
//   Rev 1.7   13 Jul 1993 15:57:30   banzai
//Add assignment operator for handles
//
//   Rev 1.6   12 Jul 1993 18:57:00   banzai
//Drag provider changes
//
//   Rev 1.5   12 Jul 1993 11:31:28   banzai
//Rendering changes
//
//   Rev 1.4   01 Jul 1993 12:23:20   HAGGAR
//rendering changes
//
//   Rev 1.3   18 Jun 1993 14:14:52   banzai
//Fix handle bugs
//
//   Rev 1.2   04 Jun 1993 15:55:46   unknown
//Changes per control enablement
//
//   Rev 1.1   30 Apr 1993 11:45:28   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:06   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IREFCNT_
  #include <irefcnt.hpp>
#endif

#if 0
#ifndef _ISEQ_H
  #include <iseq.h>
#endif
#endif

#ifndef _IDMSRCOP_
  #include <idmsrcop.hpp>
#endif

#ifndef _IDMTGTOP_
  #include <idmtgtop.hpp>
#endif

#ifndef _IDMRENDR_
  #include <idmrendr.hpp>
#endif

#ifndef _ISTRING_
  #include <istring.hpp>
#endif

/* Forward Declarations */
struct _DRAGITEM;
class IDMItemHandle;
class IDMRendererAssociate;

#if 0
class IDMRendererAssocSeq : public ISequence< IDMRendererAssociate* > {
/*******************************************************************************
  This class is just a wrapper for a sequence of IDMRendererAssociate's.  It
  is used to add a level of indirection in the IDMItem interface.
*******************************************************************************/
}; // class IDMRendererAssocSeq
#else
//class IDMRendererAssocSeq;
#endif

class IDMItem : public IRefCounted {
typedef IRefCounted
  Inherited;
/*******************************************************************************
* This is the common base class for the direct manipulation drag item classes. *
* This base class provides the common support required to represent objects    *
* that are dragged/dropped during a direct manipulation operation.             *
*                                                                              *
* Objects of this class are created by windows when a direct manipulation      *
* operation commences in a source window and during a direct manipulation      *
* operation when the objects are dragged over a target window.                 *
*                                                                              *
* Objects of this class possess the following attributes (in addition to       *
* those inherited from its base class):                                        *
*   o source window handle                                                     *
*   o types ("true" and additional) of the dragged object                      *
*   o container name (at the source)                                           *
*   o source name                                                              *
*   o suggested target name                                                    *
*   o relative position of the corresponding object image in the drag pointer  *
*   o source flags providing instructions as to how the object is to be        *
*     rendered, etc.                                                           *
*   o Generic IString buffer (contents) to hold a various assortment of "bytes"*
*   o association with a source drag operation object (see                     *
*     IDMSourceOperation)                                                      *
*   o association(s) with source drag renderer object(s) (see                  *
*     IDMSourceRenderer) which are created by the source handler (see          *
*     IDMSourceHandler)                                                        *
*   o association with a target drag operation object (see                     *
*     IDMTargetOperation)                                                      *
*   o association(s) with target drag renderer object(s) (see                  *
*     IDMTargetRenderer) which are created by the target handler (see          *
*     IDMTargetHandler)                                                        *
*                                                                              *
* This class provides virtual functions that implements the base ICLUI support *
* for direct manipulation (i.e. drag drop) drag item objects.  Derived classes *
* are created to support specific drag item objects such as text item and      *
* container item objects.                                                      *
*******************************************************************************/
public:
friend class IDMSourceOperation;
friend class IDMTargetOperation;

/*----------------------  Supported Operations Flags  --------------------------
  The following static members define a drag object's supported
  operations flags:

  The valid supported operations are:
    unknown   - No supported drag operations are available.
    copyable  - The source object that is being dragged can be copied to
                the specified drop location.
    moveable  - The source object that is being dragged can be moved to
                the specified drop location.
    linkable  - The source object that is being dragged can be linked to
                the specified object.

  Note:  These static members represent bit masks.  User defined values
         must be greater than linkable.
------------------------------------------------------------------------------*/
static const unsigned short
  unknown,
  copyable,
  moveable,
  linkable;

/*----------------------------  Attributes Flags  ------------------------------
  The following static members define the drag object's attribute flags:

  The valid attributes of dragged objects are:
    none             - No attributes are defined.
    open             - Source object is open
    reference        - Source object is a reference to another object
    group            - Source object is a group of objects
    container        - Source object is a container of other objects
    prepare          - Source object requires preparation before it
                         establishes a data transfer conversation
    removableMedia   - Source object is on removable media, or source object
                         cannot be recovered after a move operation

  Note:  These static members represent bit masks.  User defined values
         must be greater than removableMedia.
----------------------------------------------------------------------------*/
static const unsigned short
  none,
  open,
  reference,
  group,
  container,
  prepare,
  removableMedia;

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to attributes of instances of this class:     |
|   sourceWindow         - Returns handle of the source window for this item.  |
|   containerName        - Returns the source container name.                  |
|   sourceName           - Returns the source object "name."                   |
|   targetName           - Returns the suggested target object "name."         |
|   attributes           - Returns the control attributes for this item.       |
|   supportedOperations  - Returns the operations supported by this item       |
|   origin               - Returns the item's origin offset from pointer       |
|                           hotspot.                                           |
|   dragImage            - Returns the drag image for this item, or 0 if none. |
------------------------------------------------------------------------------*/
IWindowHandle
  sourceWindow           ( ) const;

IString
  containerName          ( ) const,
  sourceName             ( ) const,
  targetName             ( ) const;

unsigned short
  attributes             ( ) const;

unsigned short
  supportedOperations    ( ) const;

ISize
  origin                 ( ) const;

//pfh virtual IDMImageHandle
//pfh   dragImage              ( ) const;

/*-------------------------------- Attributes ----------------------------------
| These functions permit the testing of a variety of drag item "attribute"     |
| flags:                                                                       |
|   isOpen                 - Indicates whether the dragged object is "open".   |
|   isReference            - Indicates whether the dragged object is a         |
|                            "reference" to another object.                    |
|   isGroup                - Indicates whether the item is a group of objects. |
|   isContainer            - Indicates whether the item is a container of other|
|                            objects.                                          |
|   isOnRemovableMedia     - Indicates whether the item is on removable media  |
|                            or cannot be recovered after a move operation.    |
|   requiresPreparation    - Indicates whether the source requires preparation |
|                            prior to rendering.                               |
------------------------------------------------------------------------------*/
virtual Boolean
  isOpen                    ( ) const,
  isReference               ( ) const,
  isGroup                   ( ) const,
  isContainer               ( ) const,
  isOnRemovableMedia        ( ) const,
  requiresPreparation       ( ) const;

/*-------------------------------- Operations ----------------------------------
| These functions permit the querying of the supported direct manipulation     |
| operations for this class:                                                   |
|   canBeCopied  - Indicates whether a copy operation is supported.            |
|   canBeLinked  - Indicates whether a link operation is supported.            |
|   canBeMoved   - Indicates whether a move operation is supported.            |
------------------------------------------------------------------------------*/
virtual Boolean
  canBeCopied    ( ) const,
  canBeLinked    ( ) const,
  canBeMoved     ( ) const;

/*------------------------------- Object Type ----------------------------------
| These functions provide means for querying the "type" of the item:           |
|   trueType  - Returns the "true type" of the item.                           |
|   types     - Returns all types for the item.                                |
|   hasType   - Indicates whether the item supports an argument type.          |
------------------------------------------------------------------------------*/
virtual IString
  trueType          ( ) const,
  types             ( ) const;

virtual Boolean
  hasType           ( const IString &aType ) const;

/*-----------------------  Rendering Mechanisms/Formats  -----------------------
| These functions provide means for querying the rendering mechanism and/or    |
| format of the item:                                                          |
|   nativeSourceRMF - Returns the "native" rendering mechanism and format of   |
|                     the item.                                                |
|   nativeSourceRM  - Returns the "native" rendering mechanism of the item.    |
|   nativeSourceRF  - Returns the "native" rendering format of the item.       |
|   sourceRMFs      - Returns all rendering mechanisms and formats of the item.|
|   hasRMF          - Indicates whether the item supports a specific rendering |
|                     mechanism and format.                                    |
|   setNativeRMF    - Sets the "native" RMF to the argument type.              |
------------------------------------------------------------------------------*/
virtual IString
  nativeSourceRMF    ( ) const,
  nativeSourceRM     ( ) const,
  nativeSourceRF     ( ) const,
  sourceRMFs         ( ) const;

virtual Boolean
  hasRMF             ( const IString &aType );

virtual IDMItem
 &setNativeRMF       ( const IString &aRMF );

#if 0
/*----------------------------- Renderering Support ----------------------------
| This function provides renderering support:                                  |
|   rendererAssociations - Used to access the rendering mechanism and format,  |
|                          and type associations for this item.                |
|   addAssoc             - Adds a new association to the collection.           |
|   assocEntries         - Returns number of entries in the collection.        |
|   assocRenderer        - Returns renderer associate at index.                |
|   firstAssoc           - Tactical implementation for idmtgth.                |
------------------------------------------------------------------------------*/
IDMRendererAssocSeq
 &rendererAssociations    ( );

IDMItem
 &addAssoc                ( IDMRendererAssociate *pAssoc );

unsigned
  assocEntries            ( );

IDMRendererAssociate
 *assocRenderer           ( unsigned index );
 *firstAssoc              ( );
#endif

/*----------------------------- Renderering Support ----------------------------
| These functions are temporary pending redesign of the renderer selection     |
| logic:                                                                       |
|   srcRenderer    - Returns source renderer for this drag drop operation.     |
|   tgtRenderer    - Returns target renderer for this drag drop operation.     |
|   setSrcRenderer - Sets source renderer for this drag drop operation.        |
|   setTgtRenderer - Sets target renderer for this drag drop operation.        |
------------------------------------------------------------------------------*/
IDMSourceRenderer
 *srcRenderer       ( );

IDMTargetRenderer
 *tgtRenderer       ( );

IDMItem
 &setSrcRenderer    ( IDMSourceRenderer *pRenderer ),
 &setTgtRenderer    ( IDMTargetRenderer *pRenderer );

/*------------------------------ Drag Contents ---------------------------------
| These functions provide read/write access to the actual data associated      |
| with the direct manipulation operation:                                      |
|   contents           - Returns the contents of the drag item.                |
|   contentsSize       - Returns the size of the contents of the drag item.    |
|   setSourceContents  - Sets contents of the drag item from the source window.|
|                        Derived class should override to provide specific     |
|                        implementation based upon characteristics of the      |
|                        source window.                                        |
|   setTargetContents  - Sets contents of the drag item into the target window.|
|                        Derived class should override to provide specific     |
|                        implementation based upon characteristics of the      |
|                        target window.                                        |
------------------------------------------------------------------------------*/
virtual IString
  contents             ( ) const;

virtual unsigned
  contentsSize         ( ) const;

virtual Boolean
  setSourceContents    ( const IString &data ),
  setTargetContents    ( const IString &data, IWindow *target );


protected:
/*----------------------------- Constructor ------------------------------------
| Generic objects of this class are constructed in the following manner:       |
|   o By providing the drag source operation handle, types, supported          |
|     operations and attributes.                                               |
|   o By providing the drag target operation handle and generic drag item      |
|     handle.                                                                  |
------------------------------------------------------------------------------*/
  IDMItem     ( const IDMSrcOperationHandle sourceOperation,
                const IString &types,
                const unsigned short supportedOperations = unknown,
                const unsigned short attributes = none);

  IDMItem     ( const IDMTgtOperationHandle targetOperation,
                _DRAGITEM                   *dragItem );

virtual
  ~IDMItem    ( );


/*--------------------------- Source Accessors ---------------------------------
| These functions allow the setting of attributes for instances of this class: |
|   setSourceWindow      - Sets the source window for this item.               |
|   setContainerName     - Sets the source container name.                     |
|   setTargetName        - Sets the suggested target object "name".            |
|   setSourceName        - Sets the source object "name".                      |
|   setOrigin            - Sets this item's origin offset from the pointer     |
|                          hotspot.                                            |
|   setDragImage         - Sets or removes this item's drag image              |
------------------------------------------------------------------------------*/
IDMItem
 &setSourceWindow        ( IWindowHandle window ),
 &setContainerName       ( const char* containerName ),
 &setTargetName          ( const char* targetName ),
 &setSourceName          ( const char* sourceName ),
 &setOrigin              ( const ISize& origin );
//pfh &setDragImage           ( IDMImageHandle image,
//pfh                           Boolean        autoDelete = true);

/*--------------------------- Source Attributes --------------------------------
| These functions permit the setting of a variety of drag item                 |
| "attribute" flags:                                                           |
|   setRequiresPreparation - Set/reset the "requiresPreparation" flag.         |
|   setOpen                - Set/reset the "isOpen" flag.                      |
|   setReference           - Set/reset the "isReference" flag.                 |
|   setGroup               - Set/reset the "isGroup" flag.                     |
|   setContainer           - Set/reset the "isContainer" flag.                 |
|   setOnRemovableMedia    - Set/reset the "isOnRemovableMedia" flag.          |
------------------------------------------------------------------------------*/
virtual IDMItem
 &setRequiresPreparation    ( Boolean requiresPrep     = true ),
 &setOpen                   ( Boolean open             = true ),
 &setReference              ( Boolean reference        = true ),
 &setGroup                  ( Boolean group            = true ),
 &setContainer              ( Boolean container        = true ),
 &setOnRemovableMedia       ( Boolean onRemovableMedia = true );

/*--------------------------- Source Operations --------------------------------
| These functions permit the setting of the supported direct manipulation      |
| operations for this class:                                                   |
|   enableCopy    - Enables or disables copy operation for the item.           |
|   enableLink    - Enables or disables link operation for the item.           |
|   enableMove    - Enables or disables move operation for the item.           |
------------------------------------------------------------------------------*/
virtual IDMItem
 &enableCopy       ( Boolean copyable = true ),
 &enableLink       ( Boolean linkable = true ),
 &enableMove       ( Boolean moveable = true );

/*-------------------------- Source Object Type --------------------------------
| These functions provide means for setting the "type" of the drag item:       |
|   setTrueType     - Sets the "true type" to the argument type.               |
|   addType         - Adds an additional type (or types).                      |
|   removeType      - Removes a type from this item.                           |
|   replaceType     - Replaces a type for this item.                           |
------------------------------------------------------------------------------*/
virtual IDMItem
 &setTrueType       ( const IString &aType ),
 &addType           ( const IString &aType ),
 &removeType        ( const IString &aType ),
 &replaceType       ( const IString &oldType, const IString &newType );

/*-----------------------  Rendering Mechanisms/Formats  -----------------------
| These functions provide means for setting the "RMF" of the drag item:        |
|   addRMF          - Adds an additional RMF (or RMFs).                        |
|   removeRMF       - Removes a RMF from this item.                            |
|   replaceRMF      - Replaces a RMF for this item.                            |
|   buildRMF        - builds a rendering mechanism and format (RMF)            |
|                     string.  This function is provided as base function      |
|                     and is intended to be overloaded by subclasses           |
|                     who need to add additional information to the RMF        |
|                     string.  For example, text items may want to add         |
|                     their process identifiers.                               |
------------------------------------------------------------------------------*/
virtual IDMItem
 &addRMF            ( const IString &aRMF ),
 &removeRMF         ( const IString &aRMF ),
 &replaceRMF        ( const IString &oldRMF, const IString &newRMF );

virtual IString
  buildRMF (const IString &RendMech, const IString &Format);
private: /*------------------------ PRIVATE ----------------------------------*/
friend class IDMSourceRenderEvent;
friend class IDMTargetRenderer;
friend class IDMTargetEndEvent;

unsigned short
  dragSupOps,
  dragAttrs;

IWindowHandle
  sourceWndh;

//pfhIDMImageHandle
//pfh  pDragImage;

Boolean
  bAutoDelImage;

ISize
  sizeOrigin;

IString
  strContainerName,
  strSourceName,
  strTargetName,
  strTypes,
  strRMFs,
  strContents;

IDMSrcOperationHandle
  pDMSrcOperationH;

IDMTgtOperationHandle
  pDMTgtOperationH;

#if 0
IDMRendererAssocSeq
  rendererAssocSeqCl;
#else
// *rendererAssocSeqCl;
#endif

IDMSourceRenderer
 *pSrcRenderer;

IDMTargetRenderer
 *pTgtRenderer;

_DRAGITEM
 *PMDragItem    ( );

void
 setPMDragItem  ( _DRAGITEM *pDragItem );

void
  asPMDragItem  ( _DRAGITEM *pDragItem );

_DRAGITEM
 *pPMDragItem;

static IString
  stringFromHandle (const IStringHandle& hstr);

IStringHandle
  handleFromString (IString inputStr);

}; // IDMItem


class IDMItemHandle : public IReference< IDMItem > {
/*******************************************************************************
* Objects of this class provide access to IDMItem objects associated with      *
* a direct manipulation event.  This "handle" class manages references to      *
* the IDMItem object to ensure that it is not deleted until the drag           *
* operation is completed.                                                      *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMItem object.                                    *
*                                                                              *
* Example:                                                                     *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMItem >.                                                       *
*******************************************************************************/
public:
  IDMItemHandle  ( IDMItem *item );
  ~IDMItemHandle ( );

/*--------------------------------- Operators ---------------------------------+
| Operators defined for IDMSrcItemHandle:                                      |
|   =  - Overload definition to handle assignments of source drag item         |
|        pointers to source drag item handles.                                 |
+-----------------------------------------------------------------------------*/
IDMItemHandle
 &operator = ( IDMItem *item );

}; // IDMItemHandle


#if 0
class IDMRendererAssociate : public IRefCounted {
typedef IBase
  Inherited;
/*******************************************************************************
* Objects of this class are created by windows when a direct manipulation      *
* operation commences on the source side and during a direct manipulation      *
* operation when the objects are dragged over or dropped on a target window.   *
*                                                                              *
* This class provides the support required to link source and target           *
* renderers with drag items based upon the drag item type(s).                  *
*******************************************************************************/
public:

/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o By providing a type and identifying the renderer.                        |
------------------------------------------------------------------------------*/
  IDMRendererAssociate     ( const IString &aType,
                             IDMRenderer   *itemRenderer );

virtual
  ~IDMRendererAssociate    ( );

/*-------------------------------- Accessors -----------------------------------
| This function provides access to attributes of instances of this class:      |
|   type      - Returns the type                                               |
|   renderer  - Returns a pointer to the renderer.                             |
------------------------------------------------------------------------------*/
virtual IString
  type        ( ) const;

virtual IDMRenderer
 *renderer    ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

IString
  strAType;

IDMRenderer
 *pRenderer;

}; // class IDMRendererAssociate
#endif

#ifndef I_NO_INLINES
  #include <idmitem.inl>
#endif

#endif // _IDMITEM_

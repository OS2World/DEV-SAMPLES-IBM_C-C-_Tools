#ifndef _IDMOPER_
#define _IDMOPER_
/*******************************************************************************
* FILE NAME: idmoper.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMOperation          - General purpose "direct manipulation operation"  *
*                             class.                                           *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmoper.hpv  $
//
//   Rev 1.12   17 Aug 1993 15:25:06   banzai
//Move ISet stuff to .CPP
//
//   Rev 1.11   16 Aug 1993 20:20:34   banzai
//Make IDMCOMM stuff into IDM struct
//
//   Rev 1.10   14 Aug 1993 08:47:30   banzai
//Hide PM Drag info stuff & make setOperation public
//
//   Rev 1.9   13 Aug 1993 14:16:02   banzai
//Move setOperation to public & move PM specific stuff to private
//
//   Rev 1.8   12 Aug 1993 22:09:28   banzai
//Remove IDMOperationHandle class
//
//   Rev 1.7   12 Aug 1993 13:53:02   banzai
//Merge source and target item into one
//
//   Rev 1.6   09 Aug 1993 12:45:04   HAGGAR
//rendering
//
//   Rev 1.5   06 Aug 1993 16:41:46   banzai
//No changes
//
//   Rev 1.4   02 Aug 1993 15:27:56   HAGGAR
//No change.
//
//   Rev 1.3   12 Jul 1993 15:57:10   banzai
//No change.
//
//   Rev 1.2   28 Jun 1993 11:47:24   banzai
//Fix traps in handle logic
//
//   Rev 1.1   30 Apr 1993 11:45:36   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:10   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IREFCNT_
  #include <irefcnt.hpp>
#endif

#ifndef _IPOINT_
  #include <ipoint.hpp>
#endif

#ifndef _IHANDLE_
  #include <ihandle.hpp>
#endif

#if 0
#ifndef _ISET_H
  #include <iset.h>
#endif
#endif

#ifndef _IDMCOMM_
  #include <idmcomm.hpp>
#endif

typedef IDM::Source Source;

/* Forward Declarations */
struct _DRAGINFO;


class IDMOperation : public IRefCounted {
typedef IRefCounted
  Inherited;
/*******************************************************************************
* This is the common base class for the direct manipulation source and target  *
* drag operation classes.  Objects of this class provide general-purpose       *
* information about direct manipulation operations.                            *
*                                                                              *
* Access to this information is gained via its derived classes.                *
*                                                                              *
* Objects of this class possess the following attributes:                      *
*   o Information about the direct manipulation operation as a whole:          *
*       - operation "type" (i.e., copy, move, or link),                        *
*       - position (i.e., of the pointing device) within the source or         *
*         target window,                                                       *
*       - source of the operation (pointing device versus keyboard),           *
*       - generic drag item handle.                                            *
*                                                                              *
* Instances of this class are not intended to be created by application        *
* programmers.  Generally, they are created only by their subclasses           *
* requiring this information.                                                  *
*******************************************************************************/
public:
//pfh typedef ISet<IDMDragImageHandle> IDMDragImageSet;

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to attributes of instances of this class:     |
|   position     - Returns the drag or drop position within the source/target  |
|                  window.                                                     |
|   source       - Returns the source of the direct manipulation operation     |
|                  (always "unknown" on the target side).                      |
|   sourceWindow - Returns the handle of the source window for the direct      |
|                  manipulation operation.                                     |
------------------------------------------------------------------------------*/
IPoint
  position        ( ) const;

Source
  source          ( ) const;

IWindowHandle
  sourceWindow    ( ) const;

/*-------------------------------- Operations ----------------------------------
| These functions deal with the "default operation" attribute of instances     |
| of this class:                                                               |
|   operation     - Returns the default direct manipulation operation.         |
|   setOperation  - Set the default direct manipulation operation.             |
|                                                                              |
| These static members provide the set of pre-defined operation codes:         |
|   drag    - Default drag (no augmentation keys are pressed).                 |
|   copy    - Copy (the copy augmentation key is pressed).                     |
|   link    - Link (the link augmentation key(s) is(are) pressed).             |
|   move    - Move (the move augmentation key is pressed).                     |
|   unknown - Unknown (application-defined operation codes should              |
|             be assigned values greater than this).                           |
------------------------------------------------------------------------------*/
virtual unsigned short
  operation        ( ) const;

virtual IDMOperation
  &setOperation    ( unsigned short Operation );

static const unsigned short
  drag,
  copy,
  link,
  move,
  unknown;

/*------------------------------ Implementation --------------------------------
| These functions provide various utility services used to implement this      |
| class:                                                                       |
|   cleanup - Releases resources at the conclusion of a direct manipulation    |
|             operation.                                                       |
------------------------------------------------------------------------------*/
IDMOperation
 &cleanup    ( );

protected:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o by providing the source of the direct manipulation operation, the        |
|     position of the pointing device, and the default operation.              |
------------------------------------------------------------------------------*/
  IDMOperation     ( Source               source,
                     const IPoint         &position,
                     const unsigned short defaultOperation = drag );

virtual
  ~IDMOperation    ( );

/*-------------------------------- Drag Items ----------------------------------
| The following functions provide means of accessing the IDMDragImage objects  |
| involved in the direct manipulation operation.                               |
|   numberOfImages - Returns the number of drag images.                        |
|   image          - Returns the drag image with given index.                  |
|   replaceImage   - Replaces a given drag image with another.                 |
|   addImage       - Associates another drag image with this operation.        |
|   removeImage    - Removes a drag image from the operation.                  |
------------------------------------------------------------------------------*/
unsigned
  numberOfImages    ( );

//pfh IDMDragImageHandle
//pfh   image ( unsigned index );

  IDMOperation
//pfh  &replaceImage ( unsigned        index,
//pfh                  IDMDragImageHandle replacement ),

//pfh  &addImage    ( IDMDragImageHandle newImage ),

 &removeImage       ( unsigned index );

/*------------------------------ Implementation --------------------------------
| These functions provide various utility services used to implement this      |
| class:                                                                       |
|   setSrcWindow  - Set the source window of the direct manipulation operation.|
|   setSrc        - Set the source of the direct manipulation operation.       |
|   setPosition   - Set the pointing device position for the direct            |
|                   manipulation operation.                                    |
|   imageSetCl    - Returns a pointer to the collection of IDMDragImages.      |
|   setImages     - Sets the pointer to the collection of IDMDragImages.       |
|   setDragInfo   - Sets the handle to our drag information.                   |
------------------------------------------------------------------------------*/
IDMOperation
 &setSrcWindow    ( IWindowHandle sourceWindow ),
 &setSrc          ( Source        source ),
 &setPosition     ( IPoint        position ),
 &setDragInfo     ( _DRAGINFO     *pDragInfo );

//pfh IDMDragImageSet
//pfh  *imageSetCl ( ) const;

//pfh IDMOperation
//pfh   &setImages ( IDMDragImageSet *pIDMDragImageSet );

private: /*------------------------ PRIVATE ----------------------------------*/

unsigned short
  op;

IWindowHandle
  srcWindow;

Source
  src;

IPoint
  pos;

_DRAGINFO
 *pPMDragInfo;

_DRAGINFO
 *PMDragInfo ();

//pfh IDMDragImageSet
//pfh   *pDMDragImageSetCl;

}; // class IDMOperation

#ifndef I_NO_INLINES
  #include <idmoper.inl>
#endif

#endif //_IDMOPER_

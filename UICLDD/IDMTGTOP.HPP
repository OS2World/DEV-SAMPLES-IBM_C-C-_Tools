#ifndef _IDMTGTOP_
#define _IDMTGTOP_
/*******************************************************************************
* FILE NAME: idmtgtop.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMTargetOperation    - Direct manipulation "Target" operation class.    *
*     IDMTgtOperationHandle - "Handle" for IDMTgtOperation object to maintain  *
*                             references to it.                                *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmtgtop.hpv  $
//
//   Rev 1.21   17 Aug 1993 15:25:12   banzai
//Move ISet stuff to .CPP
//
//   Rev 1.20   14 Aug 1993 08:50:38   banzai
//Prose cleanup
//
//   Rev 1.19   12 Aug 1993 22:11:04   banzai
//Can't remember - its late
//
//   Rev 1.18   12 Aug 1993 15:36:58   banzai
//Cleanup compiler warnings
//
//   Rev 1.17   12 Aug 1993 13:53:34   banzai
//Merge source and target item into one
//
//   Rev 1.16   02 Aug 1993 15:28:04   HAGGAR
//more rendering changes
//
//   Rev 1.15   15 Jul 1993 14:02:46   HAGGAR
//rendering changes
//
//   Rev 1.14   13 Jul 1993 15:57:50   banzai
//Add assignment operator for handles
//
//   Rev 1.13   12 Jul 1993 18:57:14   banzai
//Drag provider changes
//
//   Rev 1.12   12 Jul 1993 15:57:18   banzai
//No change.
//
//   Rev 1.11   12 Jul 1993 11:31:50   banzai
//Rendering changes
//
//   Rev 1.10   01 Jul 1993 12:23:18   HAGGAR
//rendering changes
//
//   Rev 1.9   28 Jun 1993 11:47:50   banzai
//Fix traps in handle logic
//
//   Rev 1.8   21 Jun 1993 10:57:14   banzai
//Enable setItemsRC
//
//   Rev 1.7   18 Jun 1993 14:15:06   banzai
//Fix handle bugs
//
//   Rev 1.6   04 Jun 1993 16:35:16   HAGGAR
//drag changes
//
//   Rev 1.5   13 May 1993 13:57:50   HAGGAR
//No change.
//
//   Rev 1.4   13 May 1993 08:19:20   HAGGAR
//
//   Rev 1.3   03 May 1993 16:14:02   unknown
//Remove dead function
//
//   Rev 1.2   03 May 1993 16:06:08   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:45:48   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:18   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IHANDLE_
  #include <ihandle.hpp>
#endif

#ifndef _IREFCNT_
  #include <irefcnt.hpp>
#endif

/* Forward Declarations */
struct _DRAGINFO;
class IEvent;
class IDMItem;
class IDMItemHandle;
class IDMTgtOperationHandle;
class IDMEvent;
class IDMTargetItemSet;


class IDMTargetOperation : public IDMOperation {
typedef IDMOperation
  Inherited;
/*******************************************************************************
* This is the direct manipulation target drag operation class.  Objects of     *
* this class provide information about target direct manipulation operations.  *
*                                                                              *
* Access to this information is usually gained in one of the following ways:   *
*   o Via an associated IDMItem object's dragOperation() function.       *
*   o Via an associated direct manipulation event's dragOperation() function.  *
*                                                                              *
* Objects of this class possess the following attributes:                      *
*   o Information about the target direct manipulation operation as a whole:   *
*       - number of associated drag items (ie. IDMItems).                *
*       - pointer to the collection of IDMItems.                         *
*   o A collection of IDMItem objects, one for each item being "dragged" *
*     on this operation.                                                       *
*                                                                              *
* Instances of this class are not intended to be created by application        *
* programmers.  Generally, they are created only by the direct manipulation    *
* event classes requiring this information.  Typically, access is via an       *
* IDMTgtOperationHandle object (see below).                                    *
*******************************************************************************/
public:
#if 0
typedef ISet<IDMItemHandle> IDMTargetItemSet;
#endif

/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o by providing a reference to a generic IEvent.                            |
------------------------------------------------------------------------------*/
  IDMTargetOperation     ( IEvent &event );

  ~IDMTargetOperation    ( );

/*-------------------------------- Drag Items ----------------------------------
| The following functions provide means of accessing the IDMTargetItem objects |
| involved in the direct manipulation operation described by instances of      |
| this class:                                                                  |
|   numberOfItems - Returns the number of target drag items.                   |
|   item          - Returns the drag item with given index.                    |
|   addItem       - Associates another drag item with this operation.          |
------------------------------------------------------------------------------*/
unsigned
  numberOfItems    ( );

IDMItemHandle
  item             ( unsigned index );

IDMTargetOperation
  &addItem         ( const IDMItemHandle &newItem );

/*------------------------------ Implementation --------------------------------
| These functions provide various utility services used to implement this      |
| class:                                                                       |
|   instanceFor         - Returns IDMTargetOperation object                    |
|   targetOperation     - Returns IDMTargetOperation object handle that was    |
|                         created during the target enter event.               |
|   setTargetOperation  - Set IDMTargetOperation object handle during the      |
|                         target enter event.                                  |
------------------------------------------------------------------------------*/
static IDMTgtOperationHandle
  instanceFor           ( IEvent &event );

static IDMTgtOperationHandle
  targetOperation       ( );

static void
  setTargetOperation    ( IDMTgtOperationHandle tgtOperation );

/*------------------------------ Implementation --------------------------------
| The following utility functions are used to implement the behavior of        |
| this class:                                                                  |
|   itemCollection - Returns a pointer to the target collection of             |
|                    IDMItemHandles.                                           |
|   itemsRC        - Returns a pointer to the items return code (RC) array.    |
|   setItemsRC     - Sets the pointer to the items return code (RC) array.     |
------------------------------------------------------------------------------*/
IDMTargetItemSet
 *itemCollection    ( );

unsigned int
 *itemsRC           ( ) const;

IDMTargetOperation
 &setItemsRC        ( unsigned int *returnCodes );


virtual void
  addRef    ( ),
  removeRef ( );


protected:

/*------------------------------ Implementation --------------------------------
| The following utility function is used to implement the behavior of          |
| this class:                                                                  |
|   allocIDMTgtOper     - Creates an instance of the IDMTargetOperation class  |
|                         and returns a handle to it.                          |
------------------------------------------------------------------------------*/
static IDMTgtOperationHandle
  allocIDMTgtOper    ( IEvent &event );

private: /*------------------------ PRIVATE ----------------------------------*/

IDMTargetItemSet
 *pDMTgtItemSetCl;

static IDMTgtOperationHandle
  pDMTgtOpHandle;

unsigned int
 *pItemsRC;
}; //class IDMTargetOperation

class IDMTgtOperationHandle : public IReference< IDMTargetOperation > {
/*******************************************************************************
* Objects of this class provide access to IDMTargetOperation objects           *
* associated with a direct manipulation event.  This "handle" class manages    *
* references to the IDMTargetOperation object to ensure that it is not deleted *
* until the drag operation is completed.                                       *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMTargetOperation object.                         *
*                                                                              *
* Example:                                                                     *
*   // Event providing access to the drag information...                       *
*   IBeginDragEvent                                                            *
*    &event;                                                                   *
*                                                                              *
*   // Get drag information handle from event...                               *
*   IDMTgtOperationHandle                                                      *
*     tgtinfo = event.dragOperation();                                         *
*                                                                              *
*   // Process items (using info as a "pointer to IDMTargetOperation")...      *
*   for( int i = 0; i < tgtinfo->numberOfItems(); i++ )                        *
*     {                                                                        *
*     // Process drag items.                                                   *
*     }                                                                        *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMTargetOperation >.                                            *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o by providing a pointer to this handle class.                             |
------------------------------------------------------------------------------*/
  IDMTgtOperationHandle  ( IDMTargetOperation *tgtOperation );
  ~IDMTgtOperationHandle ( );

/*--------------------------------- Operators ---------------------------------+
| Operators defined for IDMTgtItemHandle:                                      |
|   =  - Overload definition to handle assignments of target drag operation    |
|        pointers to target drag operation handles.                            |
+-----------------------------------------------------------------------------*/
IDMTgtOperationHandle
 &operator = (IDMTargetOperation *tgtOperation);

}; //IDMTgtOperationHandle

#endif //_IDMTGTOP_

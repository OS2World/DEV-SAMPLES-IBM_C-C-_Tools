#ifndef _IDMSRCOP_
#define _IDMSRCOP_
/*******************************************************************************
* FILE NAME: idmsrcop.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMSourceOperation    - Direct manipulation "Source" operation class.    *
*     IDMSrcOperationHandle - "Handle" for the IDMSrcOperation object to       *
*                             maintain references to it.                       *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmsrcop.hpv  $
//
//   Rev 1.12   17 Aug 1993 15:25:08   banzai
//Move ISet stuff to .CPP
//
//   Rev 1.11   16 Aug 1993 13:00:38   banzai
//Forward declare IDMSrcOperationHandle
//
//   Rev 1.10   14 Aug 1993 08:50:44   banzai
//Prose cleanup
//
//   Rev 1.9   12 Aug 1993 13:53:24   banzai
//Merge source and target item into one
//
//   Rev 1.8   03 Aug 1993 20:10:38   banzai
//Remove addRef()
//
//   Rev 1.7   02 Aug 1993 15:28:02   HAGGAR
//more rendering changes
//
//   Rev 1.6   15 Jul 1993 14:02:42   HAGGAR
//rendering changes
//
//   Rev 1.5   13 Jul 1993 15:57:48   banzai
//Add assignment operator for handles
//
//   Rev 1.4   12 Jul 1993 11:31:48   banzai
//Rendering changes
//
//   Rev 1.3   01 Jul 1993 12:23:16   HAGGAR
//rendering changes
//
//   Rev 1.2   12 May 1993 17:28:40   HAGGAR
//various changes
//
//   Rev 1.1   30 Apr 1993 11:45:44   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:14   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IHANDLE_
  #include <ihandle.hpp>
#endif

#ifndef _IREFCNT_
  #include <irefcnt.hpp>
#endif

#ifndef _IWINDOW_
  #include <iwindow.hpp>
#endif

#ifndef _IDMOPER_
  #include <idmoper.hpp>
#endif

#ifndef _ISTRING_
  #include <istring.hpp>
#endif

/* Forward Declarations */
struct _DRAGINFO;
class IDMItem;
class IDMItemHandle;
class IDMSourceBeginEvent;
class IDMSrcOperationHandle;
class IDMSourceItemSet;


class IDMSourceOperation : public IDMOperation {
typedef IDMOperation
  Inherited;
/*******************************************************************************
* This is the direct manipulation source drag operation class.  Objects of     *
* this class provide information about source direct manipulation operations.  *
*                                                                              *
* Access to this information is usually gained in one of the following ways:   *
*   o Via an associated IDMItem object's dragOperation() function.             *
*   o Via an associated direct manipulation event's dragOperation() function.  *
*                                                                              *
* Objects of this class possess the following attributes:                      *
*   o Information about the source direct manipulation operation as a whole:   *
*       - number of associated drag items (ie. IDMItems).                      *
*       - pointer to the collection of IDMItems.                               *
*   o A collection of IDMItem objects, one for each item being "dragged"       *
*     on this operation.                                                       *
*                                                                              *
* Instances of this class are not intended to be created by application        *
* programmers.  Generally, they are created only by the direct manipulation    *
* event classes requiring this information.  Typically, access is via an       *
* IDMSrcOperationHandle object (see below).                                    *
*******************************************************************************/
public:
#if 0
typedef ISet<IDMItemHandle> IDMSourceItemSet;
#endif

/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed one of two ways:                       |
|   o by providing the source of the direct manipulation operation and a       |
|     source begin event.                                                      |
|   o by providing a generic drag item handle.                                 |
------------------------------------------------------------------------------*/
  IDMSourceOperation     ( Source                    source,
                           const IDMSourceBeginEvent &event );

  IDMSourceOperation     ( _DRAGINFO                 *pDragInfo );

  ~IDMSourceOperation    ( );

/*-------------------------------- Drag Items ----------------------------------
| The following functions provide means of accessing the IDMItem objects       |
| involved in the direct manipulation operation described by instances of      |
| this class:                                                                  |
|   numberOfItems  - Returns the number of drag items.                         |
|   item           - Returns the drag item with given index.                   |
|   replaceItem    - Replaces a given drag item with another.                  |
|   addItem        - Associates another drag item with this operation.         |
|   removeItem     - Removes a drag item from the operation.                   |
|   itemCollection - Returns a pointer to the source collection of             |
|                    IDMItemHandles.                                           |
|   begin          - Initiates the dragging of the object(s).                  |
------------------------------------------------------------------------------*/
unsigned
  numberOfItems     ( );

IDMItemHandle
  item              ( unsigned            index );

IDMSourceOperation
 &replaceItem       ( unsigned            index,
                      IDMItemHandle       replacement ),
 &addItem           ( const IDMItemHandle &newItem ),
 &removeItem        ( unsigned            index );

IDMSourceItemSet
 *itemCollection    ( );

IDMSourceOperation
 &begin             ( );

/*------------------------------ Implementation --------------------------------
| These functions provide various utility services used to implement this      |
| class:                                                                       |
|   setSourceOperation - Sets the IDMSourceOperation object that is created    |
|                        when a drag operation begins.                         |
|   sourceOperation    - Returns the IDMSrcOperationHandle that was created    |
|                        when the drag was initiated.                          |
------------------------------------------------------------------------------*/
static void
  setSourceOperation    ( IDMSrcOperationHandle sourceOp );

static IDMSrcOperationHandle
  sourceOperation ();

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

IDMSourceItemSet
 *pDMSrcItemSetCl;

static IDMSrcOperationHandle
  pDMSrcOpHandle;
}; //class IDMSourceOperation

class IDMSrcOperationHandle : public IReference< IDMSourceOperation > {
/*******************************************************************************
* Objects of this class provide access to IDMSourceOperation objects           *
* associated with a direct manipulation event.  This "handle" class manages    *
* references to the IDMSourceOperation object to ensure that it is not deleted *
* until the direct manipulation operation is completed.                        *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMSourceOperation object.                         *
*                                                                              *
* Example:                                                                     *
*   // Event providing access to the drag information...                       *
*   IBeginDragEvent                                                            *
*    &event;                                                                   *
*                                                                              *
*   // Get drag information handle from event...                               *
*   IDMSrcOperationHandle                                                      *
*     srcinfo = event.dragOperation();                                         *
*                                                                              *
*   // Process items (using info as a "pointer to IDMSoruceOperation")...      *
*   for( int i = 0; i < srcinfo->numberOfItems(); i++ )                        *
*     {                                                                        *
*     // Process drag items.                                                   *
*     }                                                                        *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMSourceOperation >.                                            *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o by providing a pointer to this handle class.                             |
------------------------------------------------------------------------------*/
  IDMSrcOperationHandle  ( IDMSourceOperation *srcOperation );
  ~IDMSrcOperationHandle ( );

/*--------------------------------- Operators ---------------------------------+
| Operators defined for IDMSrcOperationHandle:                                 |
|   =  - Overload definition to handle assignments of source drag operation    |
|        pointers to source drag operation handles.                            |
+-----------------------------------------------------------------------------*/
IDMSrcOperationHandle
 &operator = (IDMSourceOperation *srcOperation);

}; //IDMSrcOperationHandle

#endif //_IDMSRCOP_

#ifndef _IDMEVENT_
#define _IDMEVENT_
/*******************************************************************************
* FILE NAME: idmevent.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMEvent                                                                 *
*                                                                              *
*     IDMSourceBeginEvent                                                      *
*     IDMSourceRenderEvent                                                     *
*     IDMSourcePrepareEvent                                                    *
*     IDMSourceEndEvent                                                        *
*     IDMSourceNotifyEvent                                                     *
*                                                                              *
*     IDMTargetEnterEvent                                                      *
*     IDMTargetDropEvent                                                       *
*     IDMTargetEndEvent                                                        *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmevent.hpv  $
//
//   Rev 1.21   19 Aug 1993 16:26:26   banzai
//Tune DRAGINFO access
//
//   Rev 1.20   16 Aug 1993 20:20:22   banzai
//Make IDMCOMM stuff into IDM struct
//
//   Rev 1.19   12 Aug 1993 13:52:36   banzai
//Merge source and target item into one
//
//   Rev 1.18   06 Aug 1993 16:40:18   banzai
//Remove pos stuff from constructor per breaking derivedclasses
//
//   Rev 1.17   03 Aug 1993 20:17:30   banzai
//Add support for dropPosition()
//
//   Rev 1.16   03 Aug 1993 20:02:42   banzai
//No change.
//
//   Rev 1.15   02 Aug 1993 15:27:46   HAGGAR
//more rendering changes
//
//   Rev 1.14   26 Jul 1993 19:25:50   banzai
//Design changes per prv/item/rndr
//
//   Rev 1.13   12 Jul 1993 11:31:24   banzai
//Rendering changes
//
//   Rev 1.12   01 Jul 1993 12:23:04   HAGGAR
//rendering changes
//
//   Rev 1.11   30 Jun 1993 10:03:14   banzai
//Fix drag leave breakage
//
//   Rev 1.10   28 Jun 1993 11:46:48   banzai
//Fix traps in handle logic
//
//   Rev 1.9   15 Jun 1993 18:12:54   banzai
//Fix bug in IC_UM_BEGINDRAG
//
//   Rev 1.8   10 Jun 1993 09:25:06   banzai
//Here's the Beef
//
//   Rev 1.7   09 Jun 1993 16:09:00   banzai
//More changes
//
//   Rev 1.6   09 Jun 1993 09:44:36   banzai
//Enable additional events
//
//   Rev 1.5   07 Jun 1993 16:29:04   unknown
//Same oh sam oh
//
//   Rev 1.4   04 Jun 1993 16:39:34   unknown
//Control Enablement
//
//   Rev 1.3   10 May 1993 15:39:36   HAGGAR
//initial bugs
//
//   Rev 1.2   03 May 1993 16:05:46   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:45:18   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:02   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IEVENT_
  #include <ievent.hpp>
#endif

#ifndef _IDMITEM_
  #include <idmitem.hpp>
#endif

#ifndef _IDMSRCOP_
  #include <idmsrcop.hpp>
#endif

#ifndef _IDMTGTOP_
  #include <idmtgtop.hpp>
#endif

#ifndef _IDMCOMM_
  #include <idmcomm.hpp>
#endif

typedef IDM::DropIndicator DropIndicator;
typedef IDM::Source Source;

/* Forward Declarations */
struct _DRAGTRANSFER;
struct _DRAGINFO;
struct _DRAGITEM;
class IPoint;
class IWindowHandle;
class IString;

class IDMEvent : public IEvent {
/*******************************************************************************
* This is the common base class for all direct manipulation event classes.     *
*******************************************************************************/
public:

/*----------------------- Constructor/Destructor ------------------------------|
| Instances of this class are constructed from a generic IEvent and an         |
| IDragInformation handle.                                                     |
|                                                                              |
| The constructor is protected so that this class is effectively an abstract   |
| base class.                                                                  |
------------------------------------------------------------------------------*/
  IDMEvent ( IEvent &event );
virtual
  ~IDMEvent ( );

protected:
private: /*------------------------ PRIVATE ----------------------------------*/
};


class IDMSourceBeginEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* Objects of this class represent the event that occurs upon initiation        *
* of a direct manipulation event at the source window.  Instances are          *
* passed as argument to the IDMSourceHandler functions setup() and             *
* begin() functions.                                                           *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMSourceBeginEvent ( IEvent &event );
  ~IDMSourceBeginEvent ( );

/*--------------------------------- Accessors ----------------------------------
| These functions provide means of getting and setting the accessible          |
| attributes of instances of this class:                                       |
|   source        - Returns the source of the drag operation.                  |
|   position      - Returns the pointing device position (only if source is    |
|                   pointingDevice).                                           |
------------------------------------------------------------------------------*/

Source
  source ( ) const;

virtual IPoint
  position ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/
Source
  src;

//IPoint
//  pos;

}; // IDMSourceBeginEvent


class IDMUMSrcBeginEvent : public IDMSourceBeginEvent {
typedef IDMSourceBeginEvent
  Inherited;
/*******************************************************************************
* Instances of this class encapsulate direct manipulation events that          *
* occur at the source handler when a drag operation commences.                 *
* Source handlers access information about the dragged                         *
* items from the associated IDMSourceOperation object                          *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent object.            |
------------------------------------------------------------------------------*/
  IDMUMSrcBeginEvent     ( IEvent &event );

  ~IDMUMSrcBeginEvent    ( );

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

}; // IDMUMSrcBeginEvent


class IDMSourceRenderEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* Objects of this class represent direct manipulation "rendering" events.      *
* Such events are created and dispatched to source handlers when a direct      *
* manipulation target handler requests source rendering.                       *
*                                                                              *
* In addition to the standard IEvent attributes (event and window              *
* identifiers), such objects also possess:                                     *
*   o an associated IDragItem                                                  *
*   o a target window handle                                                   *
*   o a rendering mechanism/format selected by the target                      *
*   o a target name                                                            *
*   o an arbitrary target "information" (an unsigned long)                     *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMSourceRenderEvent  ( IEvent &event );

  ~IDMSourceRenderEvent ( );


/*-------------------------------- Accessors -----------------------------------
| The following functions provide read/write access to the accessible          |
| attributes of instances of this class:                                       |
|   dragItem          - Returns handle to the IDMItem corresponding to         |
|                       the item being rendered.                               |
|   alternateWindow   - Returns the handle of the alternate source window.     |
|   selectedMechanism - Returns the selected rendering mechanism.              |
|   selectedFormat    - Returns the selected rendering format.                 |
|   targetName        - Returns the target "render to" name.                   |
|   targetInfo        - Returns the target-defined "information."              |
|   setTargetInfo     - Can be used to pass information to the target          |
|   targetWindow      - returns the target window.                             |
------------------------------------------------------------------------------*/
IDMItemHandle
  dragItem          ( ) const;

IWindowHandle
  alternateWindow   ( ) const;

IString
  selectedMechanism ( ) const,
  selectedFormat    ( ) const,
  targetName        ( ) const;

unsigned long
  targetInfo        ( ) const;

IDMSourceRenderEvent
 &setTargetInfo     ( unsigned long info );

IWindowHandle
  targetWindow();
protected:
private: /*------------------------ PRIVATE ----------------------------------*/

_DRAGTRANSFER
 *pmDragTransfer ();

IDMItemHandle
  pDMSrcItemHandle;

IWindowHandle
  hwndAltWindow;

IString
  strSelMechanism,
  strSelFormat,
  strTgtName;

unsigned long
  ulTgtInfo;

_DRAGTRANSFER
 *pPMDragTransfer;

IWindowHandle
  tgtWindow;
}; // IDMSourceRenderEvent

class IDMSourcePrepareEvent : public IDMSourceRenderEvent {
typedef IDMSourceRenderEvent
  Inherited;
/*******************************************************************************
* These events are sent to the source window when the source renderer for a    *
* given object has indicated such notification is necessary prior to starting  *
* the source rendering of a drag item.                                         *
*                                                                              *
* Objects of this class provide all the "query" functions inherited from       *
* IDMSourceRenderEvent.  In addition, functions are provided to provide        *
* return information to the target:                                            *
*   o an alternate source window that the target should communicate with       *
*     during rendering                                                         *
*   o two result flags indicating whether rendering should be done by the      *
*     target and/or whether the target should retry with a different           *
*     rendering mechanism and format.                                          *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMSourcePrepareEvent ( IEvent &event );
  ~IDMSourcePrepareEvent ( );


/*---------------------------------- Result ------------------------------------
| These functions provide means of specifying render preparation results to    |
| be passed back to the target:                                                |
|   setAlternateWindow   - Sets alternate source window handle.                |
|   targetCanRetry       - Returns current setting of the "retry" flag.        |
|   setTargetCanRetry    - Sets "retry" flag.                                  |
|   noSourceRendering    - Returns current "no source rendering" flag.         |
|   setNoSourceRendering - Sets "no source rendering" flag.                    |
------------------------------------------------------------------------------*/
virtual Boolean
  targetCanRetry       ( ) const,
  noSourceRendering    ( ) const;

virtual IDMSourcePrepareEvent
 &setAlternateWindow   ( const IWindowHandle &window ),
 &setTargetCanRetry    ( Boolean             flag ),
 &setNoSourceRendering ( Boolean             flag );

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

IWindowHandle
  hwndAltWindow;

Boolean
  bTgtCanRetry,
  bNoSrcRendering;

_DRAGTRANSFER
 *pPMDragTransfer;

}; // IDMSourcePrepareEvent

class IDMSourceEndEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* These events are sent to the direct manipulation source window when a        *
* target renderer has completed the rendering of a drag item.  One such        *
* event is expected for each of the drag items involved in the direct          *
* manipulation operation.                                                      *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMSourceEndEvent ( IEvent &event );
  ~IDMSourceEndEvent ( );

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to attributes of instances of this class:     |
|   dragItem            - Returns handle of drag item the target has           |
|                         completed rendering of.                              |
|   wasTargetSuccessful - Returns whether target successfully completed its    |
|                         rendering.                                           |
------------------------------------------------------------------------------*/
IDMItemHandle
  dragItem ( ) const;

virtual Boolean
  wasTargetSuccessful ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/
Boolean
  bWasTgtSuccessful;

IDMItemHandle
  pDMSrcItemHandle;

}; // IDMSourceEndEvent


class IDMSourceNotifyEvent : public IDMEvent {
/*******************************************************************************
* Events of this class are sent to the source window when the dragged objects  *
* pass over a new potential target window.  The event essentially passes to    *
* the source the result information returned by IDMTargetHandler::enter().     *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMSourceNotifyEvent ( IEvent &event );
  ~IDMSourceNotifyEvent ( );

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to attributes of instances of this class:     |
|   dropIndicator    - Returns target indicator of whether drop is permitted.  |
|   defaultOperation - Returns default operation to be used by target.         |
------------------------------------------------------------------------------*/
virtual DropIndicator
  dropIndicator ( ) const;

virtual unsigned short
  defaultOperation ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/
DropIndicator
  dropInd;

unsigned short
  op;

}; // IDMSourceNotifyEvent


class IDMTargetEnterEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* Instances of this class encapsulate direct manipulation events that          *
* occur at the target handler when a drag operation enters a potential         *
* target window.  Target handlers access information about the dragged         *
* items from the associated IDMTargetOperation object                          *
*                                                                              *
* The event result field is of particular importance for these event objects.  *
* The result will indicate whether the dragged object(s) can be dropped on     *
* this target, and if so, what the default operation would be.  This class     *
* provides specialized functions to set the components of the event result.    *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMTargetEnterEvent     ( IEvent &event );

  ~IDMTargetEnterEvent    ( );

/*--------------------------------- Accessors ----------------------------------
| These functions provide means of getting and setting the accessible          |
| attributes of instances of this class:                                       |
|   position      - Returns the pointing device position.                      |
------------------------------------------------------------------------------*/
virtual IPoint
  position         ( ) const;

/*---------------------------------- Result ------------------------------------
| These functions provide means of querying and setting the components of      |
| the event result:                                                            |
|   dropIndicator       - Returns indicator of whether drop is allowed.        |
|   setDropIndicator    - Sets indicator of whether drop is allowed.           |
|   defaultOperation    - Returns the default operation for this target.       |
|   setDefaultOperation - Sets the default operation for this target.          |
------------------------------------------------------------------------------*/
virtual DropIndicator
  dropIndicator ( ) const;

virtual unsigned short
  defaultOperation ( ) const;

IDMTargetEnterEvent
 &setDropIndicator    ( DropIndicator  indicator ),
 &setDefaultOperation ( unsigned short operation );


protected:
private: /*------------------------ PRIVATE ----------------------------------*/
//IPoint
//  pos;

DropIndicator
  dropInd;

unsigned short
  op;

}; // IDMTargetEnterEvent


class IDMUMTgtEnterEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* Instances of this class encapsulate direct manipulation events that          *
* occur at the target handler when a drag operation enters a potential         *
* target window.  Target handlers access information about the dragged         *
* items from the associated IDMTargetOperation object                          *
*                                                                              *
* The event result field is of particular importance for these event objects.  *
* The result will indicate whether the dragged object(s) can be dropped on     *
* this target, and if so, what the default operation would be.  This class     *
* provides specialized functions to set the components of the event result.    *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMUMTgtEnterEvent     ( IEvent &event );

  ~IDMUMTgtEnterEvent    ( );

/*--------------------------------- Accessors ----------------------------------
| These functions provide means of getting and setting the accessible          |
| attributes of instances of this class:                                       |
|   position      - Returns the pointing device position.                      |
------------------------------------------------------------------------------*/
virtual IPoint
  position         ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/
//IPoint
//  pos;

}; // IDMUMTgtEnterEvent


class IDMTargetDropEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
* Instances of this class encapsulate direct manipulation events that          *
* occur at the target handler when a drop occurs on a target window.           *
* Target handlers access information about the dragged items from the          *
* stored IDMTargetOperation object that was created as part of the             *
* IDMTargetEnterEvent processing.                                              *
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMTargetDropEvent     ( IEvent &event );

  ~IDMTargetDropEvent    ( );

/*--------------------------------- Accessors ----------------------------------
| This function provides means of getting and setting the accessible           |
| attributes of instances of this class:                                       |
|   dragItem      - Returns handle of a drag item that was dropped on the      |
|                   target.                                                    |
|   setDragItem   - Sets handle of a drag item that was dropped on the target. |
|   dropPosition  - Returns the position, expressed in desktop coordinates,    |
|                   where the drop occurred.                                   |
------------------------------------------------------------------------------*/
IDMItemHandle
  dragItem        ( ) const;

IDMTargetDropEvent
 &setDragItem     ( const IDMItemHandle &targetItem );

virtual IPoint
  dropPosition    ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

//IPoint
//  pos;

IDMItemHandle
  pDMTgtItemHandle;

}; // IDMTargetDropEvent


class IDMTargetEndEvent : public IDMEvent {
typedef IDMEvent
  Inherited;
/*******************************************************************************
  These events occur when the source window has completed rendering of a
  given drag item, and has indicated so to the target.  The event provides
  source window information about the item rendering results.
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed from generic IEvent objects.           |
------------------------------------------------------------------------------*/
  IDMTargetEndEvent     ( IEvent &event );
  ~IDMTargetEndEvent    ( );


/*--------------------------------- Accessors ----------------------------------
| This function provides means of getting and setting the accessible           |
| attributes of instances of this class:                                       |
|   dragItem        - Returns handle of the drag item that source has          |
|                     completed renderering.                                   |
|   alternateWindow - Returns the handle of the alternate source window.       |
------------------------------------------------------------------------------*/
IDMItemHandle
  dragItem          ( ) const;

IWindowHandle
  alternateWindow   ( ) const;

/*---------------------------------- Result ------------------------------------
  These functions provide access to rendering result information returned
  by the source window:
    renderingFailed - Source is unable to perform the rendering operation.
                      The target may be allowed to retry, but if it
                      chooses not to, it must call informSourceOfCompletion()
                      to end the operation.
    targetCanRetry  - Source has completed the rendering operation and will
                      allow the target to retry its part of the operation
                      if it fails.
------------------------------------------------------------------------------*/
virtual Boolean
  renderingFailed    ( ) const,
  targetCanRetry     ( ) const;

protected:
private: /*------------------------ PRIVATE ----------------------------------*/

IDMItemHandle
  targetItemFromPM (_DRAGITEM *pDragItem);

IDMItemHandle
  pDMTgtItemHandle;

unsigned short
  usCompletion;

IWindowHandle
  hwndAltWindow;

_DRAGTRANSFER
 *pPMDragTransfer;

}; // IDMTargetEndEvent

#ifndef I_NO_INLINES
  #include <idmevent.inl>
#endif

#endif //_IDMEVENT_

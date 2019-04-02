#ifndef _IDMTGTH_
#define _IDMTGTH_
/*******************************************************************************
* FILE NAME: idmtgth.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*     IDMTargetHandler - Drag/Drop target window handler.                      *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmtgth.hpv  $
//
//   Rev 1.21   22 Aug 1993 12:49:04   banzai
//Remove Cnr headers
//
//   Rev 1.20   19 Aug 1993 15:11:16   banzai
//Trace stuff & remove provider/setProvider
//
//   Rev 1.19   17 Aug 1993 12:45:50   law
//Removed templates from i/f.
//
//   Rev 1.18   12 Aug 1993 13:53:28   banzai
//Merge source and target item into one
//
//   Rev 1.17   10 Aug 1993 15:20:36   banzai
//Make drag item provider into template
//
//   Rev 1.16   09 Aug 1993 14:35:46   MERLYN
//No change.
//
//   Rev 1.15   09 Aug 1993 12:45:20   HAGGAR
//rendering
//
//   Rev 1.14   05 Aug 1993 19:04:34   banzai
//Clean up headers and function names
//
//   Rev 1.13   02 Aug 1993 13:38:56   banzai
//Remove container constructor
//
//   Rev 1.12   29 Jul 1993 19:28:16   banzai
//Move reuseable code to handlers per controls
//
//   Rev 1.11   17 Jul 1993 14:04:38   banzai
//Fix trap on exit
//
//   Rev 1.10   15 Jul 1993 13:39:52   banzai
//Limit creation of renderer associations on drag over
//
//   Rev 1.9   13 Jul 1993 18:01:00   banzai
//It works
//
//   Rev 1.8   14 Jun 1993 17:00:16   banzai
//Publicize renderer support
//
//   Rev 1.7   09 Jun 1993 16:09:44   banzai
//More changes
//
//   Rev 1.6   19 May 1993 14:32:10   HAGGAR
//
//   Rev 1.5   19 May 1993 09:30:24   HAGGAR
//
//   Rev 1.4   18 May 1993 13:44:54   unknown
//Enable drag item provider
//
//   Rev 1.3   05 May 1993 16:37:44   unknown
//DM_DROP changes
//
//   Rev 1.2   03 May 1993 16:06:06   unknown
//Latest changes per IC_UM_DRAGOVER
//
//   Rev 1.1   30 Apr 1993 11:45:46   HAGGAR
//
//   Rev 1.0   22 Apr 1993 10:41:16   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IDMHNDLR_
  #include <idmhndlr.hpp>
#endif

#ifndef _IDMEVENT_
  #include <idmevent.hpp>
#endif

#ifndef _IDMRENDR_
  #include <idmrendr.hpp>
#endif

#ifndef _IENTRYFD_
  #include <ientryfd.hpp>
#endif

#ifndef _IMLE_
  #include <imle.hpp>
#endif

#if 0
#ifndef _ISEQ_H
  #include <iseq.h>
#endif
#endif

/* Forward Declarations */
class IEvent;
class IDMTargetEnterEvent;
class IDMSourceNotifyEvent;
class IDMTargetDropEvent;
class IDMTargetEndEvent;
class IDMTargetRenderer;

class IDMTgtRendererSeq;

class IDMTargetHandler : public IDMHandler {
typedef IDMHandler
  Inherited;
/*******************************************************************************
* Objects of this class handle events occuring at target windows in direct     *
* manipulation operations.  An instance of this class (or a derived class)     *
* must be added to any window that will support direct manipulation from       *
* that window.                                                                 *
*                                                                              *
* Example:                                                                     *
* // Create frame window object ...                                            *
* IFrameWindow                                                                 *
*   frame( "ICLUI Direct Manipulation Sample" );                               *
*                                                                              *
* // Create client entry field and entry field extension objects ...           *
* IEntryField                                                                  *
*   client( 0, &frame, &frame ),                                               *
*   ext   ( 0, &frame, &frame );                                               *
*                                                                              *
* // Define target handler for the entry field ...                             *
* IDMTargetHandler                                                             *
*   target( &client );                                                         *
*                                                                              *
* // Reuse target item provider in the extension that was instantiated         *
* // for the client and configure the extension as a target handler            *
* ext.setTargetItemProvider(client.itemProvider());                            *
* target.handleEventsFor( &ext );                                              *
*                                                                              *
* Note:  Direct Manipulation support for the entry field is built into the     *
*        class library.                                                        *
*******************************************************************************/
public:
#if 0
typedef ISequence<IDMTargetRenderer *> IDMTgtRendererSeq;
#endif

/*------------------------ Constructor/Destructor ------------------------------
| Objects of this class are constructed as follows:                            |
|                                                                              |
| Note:  Constructors are provided that will construct target handlers         |
|        designed specifically for the entry field and multi line edit         |
|        controls.                                                             |
------------------------------------------------------------------------------*/
  IDMTargetHandler     ( IEntryField *entryField );

  IDMTargetHandler     ( IMultiLineEdit *multiLineEdit );

  IDMTargetHandler     ( );

  ~IDMTargetHandler    ( );

/*------------------------------ Rendering -------------------------------------
| These functions permit specificiation of derived IDMSourceRenderer objects   |
| that will be used to handle rendering of dropped objects of compatible       |
| types:                                                                       |
|   numberOfRenderers - Returns the number of renderers.                       |
|   renderer          - Returns the renderer with given index.                 |
|   replaceRenderer   - Replaces a given renderer with another.                |
|   addRenderer       - Associates another renderer with this operation.       |
|   removeRenderer    - Removes a renderer from the operation.                 |
------------------------------------------------------------------------------*/
unsigned
  numberOfRenderers  ( );

IDMTargetRenderer
 *renderer           ( unsigned           index );

IDMTargetHandler
 &replaceRenderer    ( unsigned           index,
                       IDMTargetRenderer  *replacement ),
 &addRenderer        ( IDMTargetRenderer  *newItem ),
 &removeRenderer     ( unsigned           index );


protected:

/*------------------------------ Event Handling --------------------------------
| These functions are dispatched in response to specific direct manipulation   |
| target events:                                                               |
|   targetEnter    - Called when dragged objects enter into/over the target    |
|                    window.                                                   |
|   targetLeave    - Called when the dragged objects are moved off the target  |
|                    window.                                                   |
|   targetDrop     - Called when the dragged objects are dropped on the        |
|                    target window.                                            |
|   sourceComplete - Called when the source has completed rendering of a       |
|                    particular dragged object.                                |
|   targetHelp     - Called when the user has requested help while dragging    |
|                    over the target window.                                   |
------------------------------------------------------------------------------*/
virtual Boolean
  targetEnter       ( IDMTargetEnterEvent  &event ),

  targetLeave       ( IDMSourceNotifyEvent &event ),
  targetDrop        ( IDMTargetDropEvent   &event ),
  targetHelp        ( IDMSourceNotifyEvent &event ),

  sourceComplete    ( IDMTargetEndEvent    &event );

/*------------------------------ Implementation --------------------------------
| The following utility functions are used to implement the behavior of        |
| this class:                                                                  |
|   setRenderers        - Sets the pointer to the collection of                |
|                         IDMTargetRenderers.                                  |
|   rendererCollection  - Returns a reference to the collection of             |
|                         IDMTargetRenderers.                                  |
------------------------------------------------------------------------------*/
//virtual IDMTargetHandler
//  &setRenderers      ( IDMTgtRendererSeq *renderers );

IDMTgtRendererSeq
  &rendererCollection  ( );

/*-------------------------------- Overrides -----------------------------------
| This class overrides the following inherited functions:                      |
|   dispatchHandlerEvent - Dispatching function; handles drag target events.   |
------------------------------------------------------------------------------*/
virtual Boolean
  dispatchHandlerEvent ( IEvent &event );


private: /*------------------------ PRIVATE ----------------------------------*/

Boolean
  assocItmsToRndrs(IDMUMTgtEnterEvent &tgtEnterEvt);

IDMTargetRenderer
 *rendererInUse();

void
  setRendererInUse(IDMTargetRenderer *pTgtRndr);

IDMTgtRendererSeq
 *tgtRenderersSeqCl;

IDMTargetRenderer
  *pTgtRenderer;

}; // IDMTargetHandler

#ifndef I_NO_INLINES
  #include <idmtgth.inl>
#endif

#endif // _IDMTGTH_

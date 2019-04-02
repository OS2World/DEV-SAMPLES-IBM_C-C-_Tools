#ifndef _IDMSRCH_
#define _IDMSRCH_
/*******************************************************************************
* FILE NAME: idmsrch.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*     IDMSourceHandler - Direct manipulation source window handler.            *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmsrch.hpv  $
//
//   Rev 1.18   22 Aug 1993 12:49:06   banzai
//Remove Cnr headers
//
//   Rev 1.17   19 Aug 1993 15:11:10   banzai
//Trace stuff & remove provider/setProvider
//
//   Rev 1.16   17 Aug 1993 12:46:46   law
//Removed templates from i/f.
//
//   Rev 1.15   12 Aug 1993 13:53:20   banzai
//Merge source and target item into one
//
//   Rev 1.14   10 Aug 1993 15:20:30   banzai
//Make drag item provider into template
//
//   Rev 1.13   09 Aug 1993 12:45:16   HAGGAR
//rendering
//
//   Rev 1.12   05 Aug 1993 19:04:58   banzai
//Add to constructor prose
//
//   Rev 1.11   05 Aug 1993 18:50:38   banzai
//Clean up headers and function names
//
//   Rev 1.10   02 Aug 1993 13:38:44   banzai
//Remove container constructor
//
//   Rev 1.9   29 Jul 1993 19:28:02   banzai
//Move reuseable code to handlers per controls
//
//   Rev 1.8   15 Jul 1993 14:02:28   HAGGAR
//rendering changes
//
//   Rev 1.7   14 Jul 1993 17:30:00   banzai
//Include ISEQ instead of ISET
//
//   Rev 1.6   15 Jun 1993 18:13:04   banzai
//Fix bug in IC_UM_BEGINDRAG
//
//   Rev 1.5   14 Jun 1993 17:00:06   banzai
//Publicize renderer support
//
//   Rev 1.4   11 Jun 1993 15:55:28   banzai
//Move Drag Item Provider back to IWindow
//
//   Rev 1.3   10 Jun 1993 16:52:24   banzai
//Put drag item provider in src handler
//
//   Rev 1.2   18 May 1993 13:43:20   unknown
//No change
//
//   Rev 1.1   30 Apr 1993 11:45:42   HAGGAR
//No change.
//
//   Rev 1.0   22 Apr 1993 10:41:12   HAGGAR
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

class IDMSrcRendererSeq;

class IDMSourceHandler : public IDMHandler {
typedef IDMHandler
  Inherited;
/*******************************************************************************
* Objects of this class handle events occuring at source windows in direct     *
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
* // Define source handler for the entry field ...                             *
* IDMSourceHandler                                                             *
*   source( &client );                                                         *
*                                                                              *
* // Reuse source item provider in the extension that was instantiated         *
* // for the client and configure the extension as a source handler            *
* ext.setSourceItemProvider(client.itemProvider());                            *
* source.handleEventsFor( &ext );                                              *
*                                                                              *
* Note:  Direct Manipulation support for the entry field is built into the     *
*        class library.                                                        *
*******************************************************************************/
public:
#if 0
typedef ISequence<IDMSourceRenderer *> IDMSrcRendererSeq;
#else
#endif

/*----------------------- Constructor/Destructor -------------------------------
| Objects of this class are constructed as follows:                            |
|                                                                              |
| Note:  Constructors are provided that will construct source handlers         |
|        designed specifically for the entry field and multi line edit         |
|        controls.                                                             |
------------------------------------------------------------------------------*/
  IDMSourceHandler  ( IEntryField *entryField );

  IDMSourceHandler  ( IMultiLineEdit *multiLineEdit );

  IDMSourceHandler  ( );

  ~IDMSourceHandler ( );

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

IDMSourceRenderer
 *renderer           ( unsigned index );

IDMSourceHandler
 &replaceRenderer    ( unsigned           index,
                       IDMSourceRenderer  *replacement ),
 &addRenderer        ( IDMSourceRenderer  *newItem ),
 &removeRenderer     ( unsigned           index );

protected:
/*------------------------------ Event Handling --------------------------------
| These functions are dispatched in response to specific direct manipulation   |
| source events:                                                               |
|   setup             - Called to process the initiation of a drag operation   |
|                       and subsequently commence a drag operation.  This is   |
|                       called in response to a system begin drag event.  The  |
|                       initial processing of this function is to invoke the   |
|                       allocIDMSrcOper() function.  Then the                  |
|                       provideSourceItems() function of the IDMItemProvider   |
|                       class is envoked to retrieve the items that are to be  |
|                       dragged.  Then the user begin drag event is sent to    |
|                       all source handlers.  If there are items to be dragged,|
|                       the function begin() is called to commence the drag    |
|                       operation.                                             |
|   assocItmsToRndrs  - Called to associate each IDMItem object with an        |
|                       IDMSourceRenderer object that supports the specified   |
|                       Type and renderering mechanism and format (RMF).  This |
|                       is called in response to the user begin drag event.    |
|   prepareToRender   - Called to indicate to the source that rendering is     |
|                       about to commence.  Requests for rendering preparation |
|                       are made within source item providers following        |
|                       instantiation of an IDMItem object.  The               |
|                       default implementation in this class dispatches        |
|                       the prepareToRender() function on the corresponding    |
|                       IDMItem object.                                        |
|   render            - Called to indicate to the source handler to render     |
|                       a given drag item.  The default implementation in      |
|                       this class is to dispatch the render() function on     |
|                       the IDMItem object.                                    |
|   endConversation   - Called to indicate that a given item has been processed|
|                       by the target.  The default implementation in this     |
|                       class dispatches the endConversation() function on the |
|                       corresponding IDMItem object.  When all of the         |
|                       end conversation events have been received, then the   |
|                       IDMSourceOperation object will be deleted.             |
|   targetEnterNotify - Called to indicate that a target window has processed  |
|                       a "target enter" event.  The default implementation in |
|                       this class takes no action.  Derived classes can use   |
|                       the information received from the target to draw       |
|                       different source emphasis, etc.                        |
------------------------------------------------------------------------------*/
virtual Boolean
  setup             ( IDMSourceBeginEvent   &event ),
  assocItmsToRndrs  ( IDMUMSrcBeginEvent    &event ),
  prepareToRender   ( IDMSourcePrepareEvent &event ),
  render            ( IDMSourceRenderEvent  &event ),
  endConversation   ( IDMSourceEndEvent     &event ),
  targetEnterNotify ( IDMSourceNotifyEvent  &event ),
  begin             ( IDMSourceBeginEvent   &event );

/*------------------------------ Implementation --------------------------------
| The following utility functions are used to implement the behavior of        |
| this class:                                                                  |
|   allocIDMSrcOper     - Creates an instance of the IDMSourceOperation class  |
|                         and returns a pointer to it.                         |
|   sendBeginEvent      - Sends user begin drag event to the associated window.|
|   setRenderers        - Sets the pointer to the collection of                |
|                         IDMSourceRenderers.                                  |
|   rendererSeqCl       - Returns a pointer to the collection of               |
|                         IDMSourceRenderers.                                  |
------------------------------------------------------------------------------*/
virtual IDMSrcOperationHandle
  allocIDMSrcOper ( IDMSourceBeginEvent& event ) const;

virtual IDMSourceHandler
 &sendBeginEvent ( IDMSourceBeginEvent &beginEvent );

IDMSourceHandler
 &setRenderers ( IDMSrcRendererSeq *renderers );

IDMSrcRendererSeq
 *rendererSeqCl ( );

/*-------------------------------- Overrides -----------------------------------
| This class overrides the following inherited functions:                      |
|   dispatchHandlerEvent - Dispatching function; handles source drag events.   |
------------------------------------------------------------------------------*/
virtual Boolean
  dispatchHandlerEvent ( IEvent &event );


private: /*------------------------ PRIVATE ----------------------------------*/

unsigned long
  SrcEndConversationCount;

IDMSrcRendererSeq
  *pIRendererSeqCl;

}; //IDMSourceHandler

#ifndef I_NO_INLINES
  #include <idmsrch.inl>
#endif

#endif //_IDMSRCH_

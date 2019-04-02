#ifndef _IDMRENDR_
#define _IDMRENDR_
/*******************************************************************************
* FILE NAME: idmrendr.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMRenderer          - Direct manipulation renderer common base class.   *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmrendr.hpv  $
//
//   Rev 1.18   16 Aug 1993 20:20:44   banzai
//Make IDMCOMM stuff into IDM struct
//
//   Rev 1.17   16 Aug 1993 13:59:18   banzai
//Move setSupportedXxx to public
//
//   Rev 1.16   16 Aug 1993 09:21:28   banzai
//Make subclass of IVBase
//
//   Rev 1.15   14 Aug 1993 08:48:06   banzai
//Rename checkOperation to selectOperation
//
//   Rev 1.14   12 Aug 1993 13:53:14   banzai
//Merge source and target item into one
//
//   Rev 1.13   09 Aug 1993 12:45:12   HAGGAR
//rendering
//
//   Rev 1.12   02 Aug 1993 15:27:58   HAGGAR
//more rendering changes
//
//   Rev 1.11   17 Jul 1993 14:04:50   banzai
//Fix trap on exit
//
//   Rev 1.10   14 Jul 1993 17:29:32   banzai
//Testing changes
//
//   Rev 1.9   13 Jul 1993 18:01:04   banzai
//It works
//
//   Rev 1.8   13 Jul 1993 15:57:42   banzai
//Add assignment operator for handles
//
//   Rev 1.7   12 Jul 1993 11:31:40   banzai
//Rendering changes
//
//   Rev 1.6   01 Jul 1993 12:23:12   HAGGAR
//rendering changes
//
//   Rev 1.5   09 Jun 1993 16:09:08   banzai
//More changes
//
//   Rev 1.4   07 Jun 1993 16:29:18   unknown
//Same oh sam oh
//
//   Rev 1.3   04 Jun 1993 16:39:46   unknown
//Control Enablement
//
//   Rev 1.2   05 May 1993 16:36:00   unknown
//Source Render Prepare changes
//
//   Rev 1.1   30 Apr 1993 11:45:40   HAGGAR
//No change.
//
//   Rev 1.0   22 Apr 1993 10:44:08   HAGGAR
//Initial revision.
*******************************************************************************/
#ifndef _IVBASE_
  #include <ivbase.hpp>
#endif


#ifndef _ISTRING_
  #include <istring.hpp>
#endif

#ifndef _IDMCOMM_
  #include <idmcomm.hpp>
#endif

typedef IDM::DropIndicator DropIndicator;

/* Forward Declarations */
struct _DRAGTRANSFER;
class IDMSourceRenderEvent;
class IDMSourcePrepareEvent;
class IDMSourceNotifyEvent;
class IDMSourceEndEvent;
class IDMTargetDropEvent;
class IDMTargetEndEvent;
class IDMItemHandle;
class IDMTgtOperationHandle;


class IDMRenderer : public IVBase {
typedef IVBase
  Inherited;
/*******************************************************************************
* This is the common base class for the source and target direct               *
* manipulation renderer classes.                                               *
*                                                                              *
* Objects of this class perform the "rendering" of items during direct         *
* manipulation.  Such "rendering" is essentially the transfer of the dragged   *
* object from the source to the target window.                                 *
*                                                                              *
* This class is an abstract base class that defines the common protocol of     *
* source and target renderers.  The derived classes IDMSourceRenderer and      *
* IDMTargetRenderer, declared below, define the specific protocol for source   *
* and target renderers.                                                        *
*                                                                              *
* A generic renderer possesses the following attributes:                       *
*   o A set of supported types.  These are the types of dragged items that     *
*     this renderer can work with.                                             *
*   o A set of supported rendering mechanisms and rendering formats (RMFs).    *
*     These describe the various means by which this renderer can transfer     *
*     the dragged object.                                                      *
*                                                                              *
* The operations that can be performed on objects of this class fall into      *
* two basic categories:                                                        *
*   o Queries as to whether the renderer can render a given item.              *
*   o Requests to perform one of the basic rendering processes.                *
*******************************************************************************/
public:

/*------------------------ Constructor/Destructor ------------------------------
| Generic objects of this class are constructed without formal parameters.     |
------------------------------------------------------------------------------*/
  IDMRenderer     ( );

virtual
  ~IDMRenderer    ( );

/*------------------------- Supported Types and RMFs ---------------------------
  These functions return the types and renderering mechanisms/formats
  supported by an IDMRenderer object:
    supportedTypes    - Returns the types of items supported by the renderer.
    supportedRMFs     - Returns the rendering mechanisms and formsts supported
                        by this renderer.
    setSupportedTypes - Sets the types of items supported by the renderer.
    setSupportedRMFs  - Sets the rendering mechanisms and formsts supported
                        by this renderer.
------------------------------------------------------------------------------*/
virtual IString
  supportedTypes       ( ) const,
  supportedRMFs        ( ) const;

virtual IDMRenderer
 &setSupportedTypes    ( const IString &aType ),
 &setSupportedRMFs     ( const IString &aRMF );

protected:
/*------------------------------ Implementation --------------------------------
| These functions provide utilities used to implement this class:              |
|   setProcessInfo - sets the process information.                             |
|   sourcePID      - returns the PID for the source window.                    |
|   targetPID      - returns the PID for the target window.                    |
------------------------------------------------------------------------------*/
void
  setProcessInfo (IDMItemHandle dragItem),
  setProcessInfo (IDMSourceRenderEvent event);

unsigned long
  sourcePID () const,
  targetPID () const;
private: /*------------------------ PRIVATE ----------------------------------*/

IString
  strTypes,
  strRMFs;

unsigned long
  srcPID,
  tgtPID;
}; // class IDMRenderer


class IDMSourceRenderer : public IDMRenderer {
/*******************************************************************************
* Objects of this class provide source rendering when a direct manipulation    *
* operation is performed.  Instances of this class are "registered" with the   *
* source handler.  The handler selects a renderer for a given drag item and    *
* invokes rendering functions of the renderer when source rendering events     *
* occur.                                                                       *
*******************************************************************************/
public:
/*--------------------------------- Testing ------------------------------------
| These functions are used to test whether a given item can be rendered:       |
|   canRender - Returns true if the renderer can render items with the         |
|               argument attribute(s).                                         |
------------------------------------------------------------------------------*/
virtual Boolean
  canRender    ( const IString  &types ),
  canRender    ( const IString  &selectedType,
                 const IString  &selectedRMF,
                 unsigned short selectedOp );

/*-------------------------------- Rendering -----------------------------------
| These functions are called to perform rendering operations:                  |
|   sourceRender         - Called when the target renderer requests that a     |
|                          source renderer render an item.                     |
|   sourceRenderPrepare  - Called when the target renderer requests source     |
|                          preparation on an item.                             |
|   sourceRenderComplete - Called when the source renderer indicates that      |
|                          it has completed a sourceRender.                    |
|   sourceRenderEnd      - Called when the target renderer indicates that      |
|                          it has finished transferring an item.               |
------------------------------------------------------------------------------*/
virtual IDMSourceRenderer
 &sourceRender            ( IDMSourceRenderEvent  &event ),
 &sourceRenderPrepare     ( IDMSourcePrepareEvent &event ),
 &sourceRenderComplete    ( IDMSourceRenderEvent  &event ),
 &sourceRenderEnd         ( IDMSourceEndEvent     &event );

protected:
/*------------------------------ Implementation --------------------------------
| These functions provide utilities used to implement this class:              |
|   renderPrepare  - Called when a "render prepare" event occurs for a drag    |
|                    item to be rendered by this renderer.                     |
|   render         - Called when a "render" event occurs for a drag item to    |
|                    be rendered by this renderer.                             |
|   renderEnd      - Called when an "end" event occurs on a drag item being    |
|                    rendered by this renderer.                                |
------------------------------------------------------------------------------*/
virtual Boolean
  renderPrepare     ( IDMSourcePrepareEvent &event ),
  render            ( IDMSourceRenderEvent  &event ),
  renderEnd         ( IDMSourceEndEvent     &event );

private: /*------------------------ PRIVATE ----------------------------------*/

_DRAGTRANSFER
 *pPMDragTransfer;

}; // class IDMSourceRenderer


class IDMTargetRenderer : public IDMRenderer {
/*******************************************************************************
  Objects of this class provide target rendering when a direct manipulation
  operation is performed.  Instances of this class are "registered" with the
  target handler.  The handler selects a renderer for a given drag item and
  invokes rendering functions of the renderer when target rendering events
  occur.
*******************************************************************************/
public:

/*------------------------ Constructor/Destructor ------------------------------
| Generic objects of this class are constructed without formal parameters.     |
------------------------------------------------------------------------------*/
  IDMTargetRenderer     ( );

virtual
  ~IDMTargetRenderer    ( );


/*-------------------------------- Accessors -----------------------------------
| The following function provides access to the accessible attributes of       |
| instances of this class:                                                     |
|   targetInfo        - Returns the target-defined information.                |
|   refreshTargetInfo - Refreshes and returns the target-defined information   |
|                       with source preparation modifications (if any).        |
------------------------------------------------------------------------------*/
unsigned long
  targetInfo           ( ) const,
  refreshTargetInfo    ( );

/*--------------------------------- Testing ------------------------------------
| These functions are used to test whether a given item can be rendered:       |
|   canRender       - Returns drop indicator per the renderers ability to      |
|                     render the item with the argument attributes.            |
|   selectOperation - Returns true if the default operation (i.e. move, copy   |
|                     or link) is supported by the item.  If the operation set |
|                     by the source is IDMOperation::drag, we will need        |
|                     to indicate which operation we support (i.e. copy,       |
|                     move, or link) here in the target.  If the operation     |
|                     value defined by the source is > IDMOperation::unknown,  |
|                     it will be up to the application to define the           |
|                     operation it supports.  Otherwise, we'll use the         |
|                     operation the source indicated if the item supports it.  |
------------------------------------------------------------------------------*/
virtual DropIndicator
  canRender         ( const IString               &types ),
  canRender         ( const IDMTgtOperationHandle targetOperation,
                      const IString               &aType,
                      const IString               &sourceRMFs,
                      unsigned short              supportedOps );

virtual Boolean
  selectOperation    ( const IDMTgtOperationHandle targetOperation,
                       unsigned short              supportedOps );

/*-------------------------------- Rendering -----------------------------------
| These functions are called to perform rendering operations:                  |
|   targetRender             - Called when a "drop" event occurs for a drag    |
|                              item to be rendered by this renderer.           |
|   targetRenderPrepare      - Called when the source requests the target to   |
|                              generate a "preparation" event.                 |
|   targetRenderComplete     - Called when a "completion" event occurs for a   |
|                              drag item to be rendered by this renderer.      |
|   informSourceOfCompletion - Send "end" event to source to inform it that    |
|                              rendering is completed for the argument item.   |
------------------------------------------------------------------------------*/
virtual IDMTargetRenderer
 &targetRender                ( IDMTargetDropEvent &event ),
 &targetRenderPrepare         ( IDMTargetDropEvent &event ),
 &targetRenderComplete        ( IDMTargetEndEvent  &event ),
 &informSourceOfCompletion    ( IDMTargetEndEvent  &event );

protected:
/*------------------------------ Implementation --------------------------------
| These functions provide utilities used to implement this class:              |
|   sourceRender        - Send "render" event to source window to request      |
|                         source rendering for the argument item.              |
|   sourceRenderPrepare - Send "prepare" event to source window to request     |
|                         source preparation for the argument item.            |
|   renderComplete      - Called to process a "completion" event for a drag    |
|                         item.                                                |
|   renderToName        - Called to provide the name to render the data        |
|                         to.  This could be a filename, shared memory         |
|                         name, etc.                                           |
------------------------------------------------------------------------------*/
virtual Boolean
  sourceRender                ( IDMTargetDropEvent &event ),
  sourceRenderPrepare         ( IDMTargetDropEvent &event ),
  renderComplete              ( IDMTargetEndEvent  &event );

virtual IString
  renderToName                ( IDMItemHandle dragItem );

/*-------------------------------- Accessors -----------------------------------
| The following function provides writeable access to the accessible           |
| attributes of instances of this class:                                       |
|   setTargetInfo - Can be used to pass information to the target              |
------------------------------------------------------------------------------*/
virtual IDMTargetRenderer
 &setTargetInfo     ( unsigned long info );

private: /*------------------------ PRIVATE ----------------------------------*/

unsigned long
  ulTgtInfo;

_DRAGTRANSFER
 *dragTransfer (IDMTargetDropEvent &dropEvent);

_DRAGTRANSFER
 *pPMDragTransfer;

unsigned long
  TgtEndConversationCount;
}; // class IDMTargetRenderer


#ifndef I_NO_INLINES
  #include <idmrendr.inl>
#endif

#endif // _IDMRENDR_

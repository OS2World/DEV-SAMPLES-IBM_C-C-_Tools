#ifndef _IDMISRND_
  #define _IDMISRND_
/*******************************************************************************
* FILE NAME: idmisrnd.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*                  window.                                                     *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmisrnd.hpv  $
//
//   Rev 1.5   14 Aug 1993 08:48:26   banzai
//Override selectOperation
//
//   Rev 1.4   12 Aug 1993 13:52:42   banzai
//Merge source and target item into one
//
//   Rev 1.3   10 Aug 1993 15:20:04   banzai
//Make drag item provider into template
//
//   Rev 1.2   02 Aug 1993 15:27:50   HAGGAR
//more rendering changes
//
//   Rev 1.1   26 Jul 1993 19:25:56   banzai
//Design changes per prv/item/rndr
//
//   Rev 1.0   23 Jul 1993 09:28:18   banzai
//Initial version
//
*******************************************************************************/
#ifndef _IDMRNDR_
  #include <idmrendr.hpp>
#endif

/* Shared buffer name */
#define IISBuffer "\\SHAREMEM\\IISBuffer.mem"

// Forward declarations for other classes:
class IString;


class IDMISSrcRenderer : public IDMSourceRenderer {
typedef IDMSourceRenderer
  Inherited;
/*******************************************************************************
* The IDMISSrcRenderer class handles source direct manipulation rendering for  *
* objects capable of being represented by IString.                             *
*                                                                              *
* EXAMPLE:                                                                     *
*   IDMISSrcRenderer srcRenderer;                                              *
*                                                                              *
*******************************************************************************/

public:

/*------------------------ Constructors ----------------------------------------
| Objects of this class are constructed in the following manner:               |
|   o By providing a type which indicates which drag item can be rendered      |
|     by this renderer.                                                        |
------------------------------------------------------------------------------*/
  IDMISSrcRenderer     ( const IString &type );

virtual
  ~IDMISSrcRenderer    ( );


/*--------------------------------- Testing ------------------------------------
| This function is used to test whether a given item can be rendered:          |
|   canRender - Returns true if this renderer can render items with the        |
|               argument attribute(s).                                         |
------------------------------------------------------------------------------*/
Boolean
  canRender    ( const IString &types );

/*-------------------------------- Overrides -----------------------------------
| This class overrides the following inherited functions:                      |
|   renderPrepare - Called to indicate that the IString object requires source |
|                   preparation prior to rendering.                            |
|   render        - Called to indicate that the IString source renderer is to  |
|                   render an item.                                            |
|   renderEnd     - Called to indicate that the target has finished processing |
|                   an IString object                                          |
------------------------------------------------------------------------------*/
Boolean
  renderPrepare    ( IDMSourcePrepareEvent &event ),
  render           ( IDMSourceRenderEvent  &event ),
  renderEnd        ( IDMSourceEndEvent     &event );

protected:

private:
/*--------------------------------- PRIVATE ----------------------------------*/

};  // class IDMISSrcRenderer


class IDMISTgtRenderer : public IDMTargetRenderer {
typedef IDMTargetRenderer
  Inherited;
/*******************************************************************************
* The IDMISTgtRenderer class handles target direct manipulation rendering for  *
* objects capable of being represented by IString.                             *
*                                                                              *
* EXAMPLE:                                                                     *
*   IDMISTgtRenderer tgtRenderer;                                              *
*                                                                              *
*******************************************************************************/

public:

/*------------------------ Constructors ----------------------------------------
| Objects of this class are constructed in the following manner:               |
|   o By providing a type which indicates which drag item can be rendered      |
|     by this renderer.                                                        |
------------------------------------------------------------------------------*/
  IDMISTgtRenderer     ( const IString &type );

virtual
  ~IDMISTgtRenderer    ( );


/*--------------------------------- Testing ------------------------------------
| This function is used to test whether a given item can be rendered:          |
|   canRender       - Returns drop indicator per the renderers ability to      |
|                     render the item with the argument attributes.            |
|   selectOperation - Returns true if the default operation (i.e. move, copy   |
|                     or link) is supported by the item.  If the operation set |
|                     by the source is IDMOperation::drag, the default         |
|                     operation we support will be copy.  If the operation     |
|                     value defined by the source is > IDMOperation::unknown,  |
|                     we will ignore and return false.  Otherwise, we'll use   |   |
|                     the operation the source indicated if the item supports  |
|                     it.                                                      |
------------------------------------------------------------------------------*/
DropIndicator
  canRender          ( const IDMTgtOperationHandle targetOperation,
                       const IString               &aType,
                       const IString               &sourceRMFs,
                       unsigned short              supportedOps );

virtual Boolean
  selectOperation    ( const IDMTgtOperationHandle targetOperation,
                       unsigned short              supportedOps );

/*-------------------------------- Accessors -----------------------------------
| This function provides access to attributes of instances of this class:      |
|   dataBuffer - returns the data buffer used to transfer the data.            |
------------------------------------------------------------------------------*/
static void
 *dataBuffer    ( );

/*-------------------------------- Overrides -----------------------------------
| This class overrides the following inherited functions:                      |
|   sourceRender             - Called to indicate that a target window         |
|                              has been dropped on and source rendering        |
|                              is requested                                    |
|   sourceRenderPrepare      - Called to indicate that a target window         |
|                              has been dropped on and source rendering        |
|                              preparation is requested                        |
|   renderComplete           - Called to indicate that the source has          |
|                              completed its render operation.                 |
|   renderToName             - Called so the target can provide the source     |
|                              with the "render-to" name.                      |
------------------------------------------------------------------------------*/
Boolean
  sourceRender                ( IDMTargetDropEvent &event ),
  sourceRenderPrepare         ( IDMTargetDropEvent &event ),
  renderComplete              ( IDMTargetEndEvent  &event );

IString
  renderToName                ( IDMItemHandle dragItem );

protected:

/*-------------------------------- Accessors -----------------------------------
| This function provides access to attributes of instances of this class:      |
|   setDataBuffer - sets the data buffer used to transfer the data.                 |
------------------------------------------------------------------------------*/
IDMISTgtRenderer
 &setDataBuffer    ( void *data );

private:
/*--------------------------------- PRIVATE ----------------------------------*/

static void
 *pBuf;

};  // class IDMISTgtRenderer

extern IString buildRMF ();
#endif  /* _IDMISRND_ */

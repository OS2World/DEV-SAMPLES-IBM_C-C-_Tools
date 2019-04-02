#ifndef _IDMMLEIT_
#define _IDMMLEIT_
/*******************************************************************************
  FILE NAME: idmmleit.hpp

  DESCRIPTION:
    This file contains the declaration(s) of the class(es):
      IDMMLEItem       - Direct manipulation entry field item class.
      IDMMLEItemHandle - Handle to manage references to IDMMLEItem objects.

  COPYRIGHT:
    Licensed Materials - Property of IBM
    (C) Copyright IBM Corporation 1992, 1993
    All Rights Reserved
    US Government Users Restricted Rights - Use, duplication, or
    disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.

* $Log:   S:/ibmclass/idrag/vcs/idmmleit.hpv  $
//
//   Rev 1.2   19 Aug 1993 17:17:56   HAGGAR
//IMultiLineEdit support
//
//   Rev 1.1   12 Aug 1993 13:52:54   banzai
//Merge source and target item into one
//
//   Rev 1.0   10 Aug 1993 15:21:28   banzai
//Make drag item provider into template
//
*******************************************************************************/
#ifndef _IDMITEM_
  #include <idmitem.hpp>
#endif

/* Forward Declarations */


class IDMMLEItem : public IDMItem {
typedef IDMItem
  Inherited;
/*******************************************************************************
* Objects of this class are created by windows when a direct manipulation      *
* text operation commences on the source side.                                 *
*                                                                              *
* Objects of this class possess the following attributes (in addition to       *
* those inherited from its base class):                                        *
*   o association with a source drag operation object (see                     *
*     IDMSourceOperation)                                                      *
*   o association(s) with derived source renderer object(s) capable of         *
*     renderering text (see IDMISSrcRenderer) which are created by the         *
*     source handler (see IDMSourceHandler)                                    *
*                                                                              *
* This class provides virtual functions that implement the source rendering    *
* of the dragged/dropped objects.  Derived classes are created to support      *
* additional rendering mechanisms and/or formats.  The IDMMLEItem              *
* class supports, in conjunction with the standard library IWindow subclasses, *
* rendering with all the standard system rendering mechanisms whenever such    *
* rendering makes sense.                                                       *
*******************************************************************************/

public:

/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o By providing the drag source operation handle, types, supported          |
|     operations and attributes.                                               |
|   o By providing a pointer to a target drag item.                            |
------------------------------------------------------------------------------*/
  IDMMLEItem     ( const IDMSrcOperationHandle &sourceOperation,
                    const IString &types,
                    const unsigned short supportedOperations = unknown );

  IDMMLEItem     ( IDMItem &dragItem );

virtual
  ~IDMMLEItem    ( );


/*------------------------------ Source Items ----------------------------------
| This function generates source items:                                        |
|   generateSourceItems - Generates text items based upon data in the          |
|                         source text control window.                          |
------------------------------------------------------------------------------*/
static Boolean
  generateSourceItems    ( const IDMSrcOperationHandle &sourceOperation );

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to generic text per a text oriented direct    |
| manipulation operation:                                                      |
|   text           - Returns the drag item text.                               |
|   size           - Returns the size of the drag item text.                   |
------------------------------------------------------------------------------*/
virtual IString
  text             ( ) const;

virtual unsigned
  size             ( ) const;

/*------------------------------- Target Data ----------------------------------
| This function writes the data to the window:                                 |
|   setTargetContents  - Writes text into the target MLE.                      |
------------------------------------------------------------------------------*/
virtual Boolean
  setTargetContents    ( const IString &data, IWindow *mle );

protected:
/*-----------------------  Rendering Mechanisms/Formats  -----------------------
| These functions provide means for setting the "RMF" of the drag item:        |
|   buildRMF  - builds a rendering mechanism and format (RMF) string.  This    |
|               function is an overloaded version of the one provided as part  |
|               of the IDMItem class.                                          |
------------------------------------------------------------------------------*/
IString
  buildRMF (const IString &RendMech, const IString &Format);
private: /*------------------------ PRIVATE ----------------------------------*/

}; // IDMMLEItem


class IDMMLEItemHandle : public IReference< IDMMLEItem > {
/*******************************************************************************
* Objects of this class provide access to IDMMLEItem objects                   *
* associated with a direct manipulation event.  This "handle" class manages    *
* references to the IDMMLEItem object to ensure that it is not                 *
* deleted until the drag operation is completed.                               *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMMLEItem object.                                 *
*                                                                              *
* Example:                                                                     *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMMLEItem >.                                                    *
*******************************************************************************/
public:
  IDMMLEItemHandle  ( IDMMLEItem *mleItem );
  ~IDMMLEItemHandle ( );

/*--------------------------------- Operators ---------------------------------+
| Operators defined for IDMMLEItemHandle:                                      |
|   =  - Overload definition to handle assignments of MLE item pointers to     |
|        MLE item handles.                                                     |
+-----------------------------------------------------------------------------*/
IDMMLEItemHandle
 &operator = ( IDMMLEItem *mleItem );

}; // IDMMLEItemHandle


/*******************************************************************************
* Objects of this class are created by windows when a direct manipulation      *
* text operation enters a potential target.                                    *
*                                                                              *
* Objects of this class possess the following attributes (in addition to       *
* those inherited from its base class):                                        *
*   o association with a target drag operation object (see                     *
*     IDMTargetOperation)                                                      *
*   o association(s) with derived target renderer object(s) capable of         *
*     renderering text (see IDMISTgtRenderer) which are created by the         *
*     target handler (see IDMTargetHandler)                                    *
*                                                                              *
* This class provides virtual functions that implement the source rendering    *
* of the dragged/dropped objects.  Derived classes are created to support      *
* additional rendering mechanisms and/or formats.  The IDMTextTgtItem          *
* class supports, in conjunction with the standard library IWindow subclasses, *
* rendering with all the standard system rendering mechanisms whenever such    *
* rendering makes sense.                                                       *
*******************************************************************************/

/*******************************************************************************
* Objects of this class provide access to IDMTextTgtItem objects               *
* associated with a direct manipulation event.  This "handle" class manages    *
* references to the IDMTextTgtItem object to ensure that it is not             *
* deleted until the drag operation is completed.                               *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMTextTgtItem object.                             *
*                                                                              *
* Example:                                                                     *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMTextTgtItem >.                                                *
*******************************************************************************/

#ifndef I_NO_INLINES
  #include <idmmleit.inl>
#endif

#endif // _IDMMLEIT_

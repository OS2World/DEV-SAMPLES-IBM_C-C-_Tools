#ifndef _IDMEFIT_
#define _IDMEFIT_
/*******************************************************************************
  FILE NAME: idmefit.hpp

  DESCRIPTION:
    This file contains the declaration(s) of the class(es):
      IDMEFItem       - Direct manipulation entry field item class.
      IDMEFItemHandle - Handle to manage references to IDMEFItem objects.

  COPYRIGHT:
    Licensed Materials - Property of IBM
    (C) Copyright IBM Corporation 1992, 1993
    All Rights Reserved
    US Government Users Restricted Rights - Use, duplication, or
    disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.

* $Log:   M:/ibmclass/idrag/vcs/idmefit.hpv  $
//
//   Rev 1.3   19 Aug 1993 10:35:02   banzai
//Prose changes
//
//   Rev 1.2   17 Aug 1993 15:38:04   HAGGAR
//changes due to new design
//
//   Rev 1.1   12 Aug 1993 13:52:24   banzai
//Merge source and target item into one
//
//   Rev 1.0   10 Aug 1993 15:20:56   banzai
//Make drag item provider into template
//
*******************************************************************************/
#ifndef _IDMITEM_
  #include <idmitem.hpp>
#endif

/* Forward Declarations */


class IDMEFItem : public IDMItem {
typedef IDMItem
  Inherited;
/*******************************************************************************
* Objects of this class are created by entry fields when a direct manipulation *
* operation commences in an source entry field and during a direct             *
* manipulation operation when a text object is dragged over a potential        *
* entry field.                                                                 *
*                                                                              *
* Objects of this class possess the following attributes (in addition to       *
* those inherited from its base class):                                        *
*   o association with a source or target drag operation object (see           *
*     IDMSourceOperation or IDMTargetOperation)                                *
*   o association(s) with derived source or target renderer object(s) capable  *
*     of renderering text (see IDMISSrcRenderer or IDMISTgtRenderer) which are *
*     created by the source or handler (see IDMSourceHandler or                *
*     IDMTargetHandler)                                                        *
*                                                                              *
* This class provides virtual functions that implement support for direct      *
* manipulation (i.e. drag drop) entry field text items.                        *
*******************************************************************************/
public:

/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
|   o By providing the drag source operation handle, types, supported          |
|     operations and attributes.                                               |
|   o By providing a pointer to a target drag item.                            |
------------------------------------------------------------------------------*/
  IDMEFItem     ( const IDMSrcOperationHandle &sourceOperation,
                  const IString &types,
                  const unsigned short supportedOperations = unknown );

  IDMEFItem     ( IDMItem &dragItem );

virtual
  ~IDMEFItem    ( );


/*------------------------------ Source Items ----------------------------------
| This function generates source items:                                        |
|   generateSourceItems - Generates entry field text items based upon data in  |
|                         the source entry field window.                       |
------------------------------------------------------------------------------*/
static Boolean
  generateSourceItems    ( const IDMSrcOperationHandle &sourceOperation );

/*-------------------------------- Accessors -----------------------------------
| These functions provide access to text per an entry field direct             |
| manipulation operation:                                                      |
|   text           - Returns the drag item text.                               |
|   size           - Returns the size of the drag item text.                   |
------------------------------------------------------------------------------*/
virtual IString
  text             ( ) const;

virtual unsigned
  size             ( ) const;

/*------------------------------- Target Data ----------------------------------
| This function writes the data to the target window:                          |
|   setTargetContents  - Writes text into the target entry field.              |
------------------------------------------------------------------------------*/
virtual Boolean
  setTargetContents    ( const IString &data, IWindow *entryField );

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

}; // IDMEFItem


class IDMEFItemHandle : public IReference< IDMEFItem > {
/*******************************************************************************
* Objects of this class provide access to IDMEFItem objects                    *
* associated with a direct manipulation event.  This "handle" class manages    *
* references to the IDMEFItem object to ensure that it is not                  *
* deleted until the drag operation is completed.                               *
*                                                                              *
* This class provides a "->" operator that enables instances to be treated     *
* just like a pointer to an IDMEFItem object.                                  *
*                                                                              *
* Example:                                                                     *
*                                                                              *
* This class has no members.  It is essentially a synonym for the type         *
* IReference< IDMEFItem >.                                                     *
*******************************************************************************/
public:
  IDMEFItemHandle  ( IDMEFItem *entryFieldItem );
  ~IDMEFItemHandle ( );

/*--------------------------------- Operators ---------------------------------+
| Operators defined for IDMEFItemHandle:                                       |
|   =  - Overload definition to handle assignments of entry field item         |
|        pointers to entry field item handles.                                 |
+-----------------------------------------------------------------------------*/
IDMEFItemHandle
 &operator = ( IDMEFItem *entryFieldItem );

}; // IDMEFItemHandle


#ifndef I_NO_INLINES
  #include <idmefit.inl>
#endif

#endif // _IDMEFIT_

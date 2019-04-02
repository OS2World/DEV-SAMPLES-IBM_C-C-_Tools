#ifndef _IDMPROV_
#define _IDMPROV_
/*******************************************************************************
* FILE NAME: idmprov.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   This file contains the declaration(s) of the class(es):                    *
*     IDMItemProvider    - Base class used to provide drag items.              *
*     IDMSrcItemProvider - Template class used to provide drag items to a      *
*                          source handler at commencement of a direct          *
*                          manipulation operation.                             *
*     IDMTgtItemProvider - Template class used to provide drag items to a      *
*                          target handler at commencement of a direct          *
*                          manipulation operation.                             *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or               *
*   disclosure                                                                 *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmprov.hpv  $
//
//   Rev 1.10   19 Aug 1993 10:57:10   banzai
//Prose changes
//
//   Rev 1.9   18 Aug 1993 15:45:48   banzai
//Make provideSourceItems virtual
//
//   Rev 1.8   12 Aug 1993 22:08:58   banzai
//Use handles instead of refs for accurate count
//
//   Rev 1.7   12 Aug 1993 15:36:50   banzai
//Cleanup compiler warnings
//
//   Rev 1.6   12 Aug 1993 13:53:10   banzai
//Merge source and target item into one
//
//   Rev 1.5   10 Aug 1993 15:20:22   banzai
//Make drag item provider into template
//
//   Rev 1.4   09 Aug 1993 14:59:36   banzai
//Use template for target drag provider
//
//   Rev 1.3   26 Jul 1993 19:26:04   banzai
//Design changes per prv/item/rndr
//
//   Rev 1.2   20 Jul 1993 10:47:02   banzai
//Data acquisition design changes
//
//   Rev 1.1   12 Jul 1993 18:57:06   banzai
//Drag provider changes
//
//   Rev 1.0   12 Jul 1993 12:14:30   banzai
//New Tgt/Src drag item providers
//
*******************************************************************************/
#ifndef _IVBASE_
  #include <ivbase.hpp>
#endif

/* Forward declarations */
struct _DRAGITEM;
class IDMSrcOperationHandle;
class IDMItemHandle;


class IDMItemProvider : public IVBase {
typedef IVBase
  Inherited;
/*******************************************************************************
  BUGBUG - rewrite the commentary per latest round of changes

  Objects of this class have one purpose: they provide an IDMSourceOperation
  object with the items to be dragged when a direct manipulation operation
  begins.  A pointer to an object derived from this class must be provided
  when an IDMSourceHandler is constructed.

  When the source handler detects that a direct manipulation operation is
  being initiated from one of its windows, it will call the provideSourceItems
  function of the derived class, passing the IDMSourceOperation object (via a
  handle to it).  The class derived from IDMSourceProvider simply creates
  IDMItem derived objects to represent the items to be dragged from the
  source window and adds these to the IDMSourceOperation object.

  This class is an abstract base class.  Derived classes must implement the
  provideSourceItems function in an application (or control) specific manner.
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
------------------------------------------------------------------------------*/
  IDMItemProvider ( );

virtual
  ~IDMItemProvider ( );

/*--------------------------- Drag Item Provision ------------------------------
  provideSourceItems   - Called to give provider opportunity to attach derived
                         IDMItems to the argument IDMSourceOperation
                         object.  This function is called when a drag operation
                         commences over a control object.  Returns true if
                         items were provided, false otherwise.
  provideTargetItemFor - Called to give provider opportunity to replace generic
                         IDMItems with a derived class.  This function
                         is called when a drop occurs on a target window.
------------------------------------------------------------------------------*/
virtual Boolean
  provideSourceItems   ( const IDMSrcOperationHandle sourceOperation );

virtual IDMItemHandle
  provideTargetItemFor ( const IDMItemHandle dragItem );

protected:

private: /*------------------------ PRIVATE ----------------------------------*/
}; // class IDMItemProvider


template < class T >
class IDMItemProviderFor : public IDMItemProvider {
typedef IDMItemProvider
  Inherited;
/*******************************************************************************
  BUGBUG - rewrite the commentary per latest round of changes

  Objects of this class have one purpose: they provide an IDMSourceOperation
  object with the items to be dragged when a direct manipulation operation
  begins.  A pointer to an object derived from this class must be provided
  when an IDMSourceHandler is constructed.

  When the source handler detects that a direct manipulation operation is
  being initiated from one of its windows, it will call the provideSourceItems
  function of the derived class, passing the IDMSourceOperation object (via a
  handle to it).  The class derived from IDMSourceProvider simply creates
  IDMItem derived objects to represent the items to be dragged from the
  source window and adds these to the IDMSourceOperation object.

  This class is an abstract base class.  Derived classes must implement the
  provideSourceItems function in an application (or control) specific manner.
*******************************************************************************/
public:
/*------------------------- Constructors/Destructor ----------------------------
| Objects of this class are constructed in the following manner:               |
------------------------------------------------------------------------------*/
  IDMItemProviderFor ( ) {}

virtual
  ~IDMItemProviderFor ( ) {}


/*--------------------------- Drag Item Provision ------------------------------
  provideSourceItems   - Defines template that provider uses to attach derived
                         IDMItems to the argument IDMSourceOperation
                         object.  This function is called when a drag operation
                         commences over a control object.  Returns true if
                         items were provided, false otherwise.
  provideTargetItemFor - Defines template that provider uses to replace generic
                         IDMItems with a derived class.  This function
                         is called when a drop occurs on a target window.
------------------------------------------------------------------------------*/
virtual Boolean
  provideSourceItems   ( const IDMSrcOperationHandle sourceOperation )
{

  return( T::generateSourceItems( sourceOperation ) );
}

virtual IDMItemHandle
  provideTargetItemFor ( const IDMItemHandle dragItem )
{

  return( (IDMItemHandle)new T( *dragItem ) );
}


protected:

private: /*------------------------ PRIVATE ----------------------------------*/
}; // class IDMItemProviderFor

#endif //_IDMPROV_

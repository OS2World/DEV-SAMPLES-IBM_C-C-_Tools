#ifndef _IDMEFPV_
  #define _IDMEFPV_
/*******************************************************************************
* FILE NAME: idmefpv.hpp                                                       *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*    IDMEFItemProvider - This class creates and manages entry field drag       *
*                        item providers.                                       *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmefpv.hpv  $
//
//   Rev 1.3   19 Aug 1993 10:56:52   banzai
//No changes
//
//   Rev 1.2   12 Aug 1993 13:52:30   banzai
//Merge source and target item into one
//
//   Rev 1.1   10 Aug 1993 15:19:58   banzai
//Make drag item provider into template
//
//   Rev 1.0   09 Aug 1993 16:34:20   banzai
//Back to entry field
//
*******************************************************************************/
#ifndef _IDMPROV_
  #include <idmprov.hpp>
#endif

#ifndef _IDMEFIT_
  #include <idmefit.hpp>
#endif

// Forward declarations for other classes:


class IDMEFItemProvider : public IDMItemProviderFor < IDMEFItem >
{
/*******************************************************************************
* The IDMEFItemProvider class provides support for creating entry field        *
* source and target drag items.                                                *
*                                                                              *
* EXAMPLE:                                                                     *
*   IDMEFItemProvider dragEFItem();                                            *
*                                                                              *
*******************************************************************************/

public:

/*------------------------ Constructors ----------------------------------------
| Objects of this class are constructed in the following manner:               |
------------------------------------------------------------------------------*/
  IDMEFItemProvider     ( );

virtual
  ~IDMEFItemProvider    ( );

protected:

private:
/*--------------------------------- PRIVATE ----------------------------------*/

};  // class IDMEFItemProvider

#endif  /* _IDMEFPV_ */

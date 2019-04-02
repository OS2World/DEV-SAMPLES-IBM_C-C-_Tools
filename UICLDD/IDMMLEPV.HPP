#ifndef _IDMMLEPV_
  #define _IDMMLEPV_
/*******************************************************************************
* FILE NAME: idmmlepv.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*    IDMMLEItemProvider - This class creates and manages entry field drag      *
*                         item providers.                                      *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
* $Log:   M:/ibmclass/idrag/vcs/idmmlepv.hpv  $
//
//   Rev 1.1   12 Aug 1993 13:52:58   banzai
//Merge source and target item into one
//
//   Rev 1.0   10 Aug 1993 15:21:16   banzai
//Make drag item provider into template
//
*******************************************************************************/
#ifndef _IDMPROV_
  #include <idmprov.hpp>
#endif

#ifndef _IDMMLEIT_
  #include <idmmleit.hpp>
#endif

// Forward declarations for other classes:


class IDMMLEItemProvider : public IDMItemProviderFor < IDMMLEItem >
{
/*******************************************************************************
* The IDMMLEItemProvider class provides support for creating entry field       *
* source and target drag items.                                                *
*                                                                              *
* EXAMPLE:                                                                     *
*   IDMMLEItemProvider dragMLEItem();                                          *
*                                                                              *
*******************************************************************************/

public:

/*------------------------ Constructors ----------------------------------------
| Objects of this class are constructed in the following manner:               |
------------------------------------------------------------------------------*/
  IDMMLEItemProvider     ( );

virtual
  ~IDMMLEItemProvider    ( );

protected:

private:
/*--------------------------------- PRIVATE ----------------------------------*/

};  // class IDMMLEItemProvider

#endif  /* _IDMMLEPV_ */

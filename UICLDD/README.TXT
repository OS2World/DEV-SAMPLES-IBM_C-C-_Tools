------------------------------------------------------------------------
|						       August 22, 1993                               |
| BETA1 for C Set++ Class Library direct manipulation (drag/drop)      |
 -----------------------------------------------------------------------

  ***IMPORTANT NOTE***

   You cannot distribute or sell any programs which use this beta code!
for more information, read UICLDD.LIC.

PREREQ's
--------
1) You MUST read the file UICLDD.LIC included in this ZIP file.
2) You MUST install CSD 1 for C-Set++ prior to using this beta.


HEADER REPLACEMENT:
-------------------
1) You MUST install IWINDOW.HPP in a subdirectory that is listed in the
   INCLUDE path before \IBMCPP\IBMCLASS.


CONTROLS SUPPORTED
------------------
1) We have included built-in support for the Entry Field and MLE.  Please
   see the DMSAMP1 sample for additional information.  You can substitute
   IMultiLineEdit for IEntryField in the sample to demonstrate.  We plan
   to include support for the Container in our next drop.


RENDERING MECHANISMS AND FORMATS (RMFs)
---------------------------------------
1) IDMISRND.HPP contains a generic IString renderer that implements an RMF
   that supports source rendering of item(s).  It contains support for both
   inter and intra process source renderering of item(s).  We use it to
   support renderering of text items in our MLE and Entry Field support,
   but it can also be used for renderering such things as icon and bitmap
   images, with no modifications.


ISSUES
------
1) IDMTargetRenderer::canRender always returns IDM::ok as the default
   case, when you use the default target renderer, which is implemented
   in such a manner to allow for target rendering.  Therefore, you must
   verify the type and RMF of item(s) in your code.  Please see the
   DMSAMP2 sample for additional information.


SAMPLES
-------
1) The DMSAMP2 sample contains what we feel is some "flakiness" in the
   bitmap settings logic (i.e. dropping a bitmap several times before
   it shows up in the window).


HEADERS AND INLINES
-------------------
idmcomm.hpp
idmefit.hpp
idmefpv.hpp
idmevent.hpp
idmhndlr.hpp
idmisrnd.hpp
idmitem.hpp
idmmleit.hpp
idmmlepv.hpp
idmoper.hpp
idmprov.hpp
idmrendr.hpp
idmsrch.hpp
idmsrcop.hpp
idmtgth.hpp
idmtgtop.hpp
idmefit.inl
idmevent.inl
idmitem.inl
idmmleit.inl
idmoper.inl
idmrendr.inl
idmsrch.inl
idmtgth.inl


DLL
---
idrag.dll


IMPORT LIB
----------
idragi.lib


STATIC LIB
----------
idrag.lib


PUBS
----
dragdrop.lst    list3820
dragdrop.doc    ascii
dragdrop.ps     postscript
dragdrop.boo    BookManager/Read

1) These are  preliminary versions of the users guide.


SAMPLES
-------
DMSAMP1.CPP
DMSAMP1.EXE
DMSAMP2.CPP
DMSAMP2.EXE
DMSAMP2.HPP

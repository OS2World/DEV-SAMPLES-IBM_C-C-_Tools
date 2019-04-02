#include <idmprov.hpp>

#include <idmitem.hpp>

class ABitmapItem : public IDMItem {
/*******************************************************************************
  Objects of this class provide "bitmap control" drop behavior when a
  source bitmap file is dropped on a bitmap control properly configured
  with a target handler and a ABitmapProvider.
*******************************************************************************/
public:
/*------------------------------- Constructor ----------------------------------
  Objects of this class are constructed from a generic item handle.
------------------------------------------------------------------------------*/
  ABitmapItem ( const IDMItemHandle &item );

/*------------------------------ Drop Behavior ---------------------------------
  setTargetContents - Take the dropped file, create a PM bitmap object, 
                      and set it into the target window.
------------------------------------------------------------------------------*/
virtual Boolean
  setTargetContents ( const IString &, IWindow* target );
};

class ABitmapProvider : public IDMItemProvider {
/*******************************************************************************
  Objects of this class are attached to bitmap controls in order to have
  ABitmapItem objects created when a bitmap file is dropped on such a
  control.
*******************************************************************************/
public:
/*------------------------------- Target Items ---------------------------------
  provideSourceItems   - Implemented to satisfy compiler (shouldn't have to!).
  provideTargetItemFor - Returns an ABitmapItem to replace the argument item.
------------------------------------------------------------------------------*/
virtual Boolean
  provideSourceItems ( const IDMSrcOperationHandle ) { return false; }
virtual IDMItemHandle
  provideTargetItemFor ( const IDMItemHandle item );
};

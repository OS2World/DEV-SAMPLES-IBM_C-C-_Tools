extern "C"
  {
  #include <stdio.h>
  #include <sys\stat.h>
  #define INCL_GPIBITMAPS
  #include <os2.h>
  }

#include <iostream.h>
#include <fstream.h>

#include <iframe.hpp>
#include <ibmpctl.hpp>
#include <istring.hpp>

#include <idmtgth.hpp>

#include "dmsamp2.hpp"

void main()
  {
  // Use a generic frame window...
  IFrameWindow
    frame ( "C Set ++ Direct Manipulation - Sample 2" );

  // Create an empty bitmap control...
  IBitmapControl
    bmpControl ( 0, &frame, &frame );

  // Create target handler for the bitmap control...
  IDMTargetHandler
    handler;

  // Instruct handler to handle dropping on bitmap control...
  handler.handleEventsFor( &bmpControl );

  // Create bitmap drag item provider...
  ABitmapProvider
    itemProvider;

  // Attach provider to the bitmap control...
  bmpControl.setItemProvider( &itemProvider );

  // Create renderer to render items when dropped on bitmap control...
  IDMTargetRenderer
    renderer;

  // Set up renderer to accept .bmp files...
  renderer.setSupportedRMFs( "<DRM_OS2FILE,DRF_TEXT>" )
	  .setSupportedTypes( "Bitmap" );

  handler.addRenderer( &renderer );

  // Set the bitmap control as the frame's client and
  // display the frame...
  bmpControl.setText( "Drop .bmp files here." );
  frame.setClient( &bmpControl )
       .showModally();
  }

ABitmapItem :: ABitmapItem ( const IDMItemHandle &item )
  : IDMItem( *item )
  {
  }

Boolean ABitmapItem :: setTargetContents ( const IString &, IWindow *target )
  {
  // Get pointer to target bitmap control...
  IBitmapControl
   *bmpControl = (IBitmapControl*)target;

  // Construct dropped .bmp file name from this item...
  IString
    fname = this->containerName() + "\\" + this->sourceName();

  // Get file size...
  struct stat
    buf;
  stat( fname, &buf);

  // Open and read the file...
  FILE
   *fileptr = fopen( fname, "rb" );
  char
   *buffer = new char[ buf.st_size ];
  fread( buffer, sizeof(char), buf.st_size, fileptr );

  // Construct the bitmap from the file...
  BITMAPARRAYFILEHEADER2
   *array = ( BITMAPARRAYFILEHEADER2 * )buffer;
  BITMAPFILEHEADER2
   *header;

  // First, see if file holds array of bitmaps...
  if ( array->usType == BFT_BITMAPARRAY ) {
    // It is, point to first file header in array...
    header = &array->bfh2;
  } else {
    // It isn't, point to file header at start of file...
    header = ( BITMAPFILEHEADER2 * )buffer;
  }

  // Now check to see if this is a bitmap...
  if ( header->usType == BFT_BMAP) {

    // We can proceed, first get a presentation space...
    IPresSpaceHandle
      hps = bmpControl -> presSpace();

    if ( hps ) {
      // Now create the bitmap from the file contents...
      IBitmapHandle
	hbm = GpiCreateBitmap( hps,
			       &header->bmp2,
			       CBM_INIT,
			       buffer + header->offBits,
			       (BITMAPINFO2*)&header->bmp2 );
      if ( hbm ) {
	// Get previously dropped bitmap...
	IBitmapHandle
	  old = bmpControl -> bitmap();

	// Set new one...
	bmpControl -> setBitmap( hbm );

	// Destroy old since we no longer need it...
	GpiDeleteBitmap( old );

	// Indicate name of dropped file...
	bmpControl -> setText( fname );
      } else {
	bmpControl -> setText( "Couldn't create bitmap!" );
      }
      // Release the presentation space...
      bmpControl -> releasePresSpace(hps);
    } else {
      bmpControl -> setText ( "Couldn't get PS!" );
    }
  } else {
    bmpControl -> setText( fname + " isn't a bitmap!" );
  }

  // Free buffer.
  delete [] buffer;

  return true;
  }

IDMItemHandle ABitmapProvider :: provideTargetItemFor ( const IDMItemHandle item )
  {
  return new ABitmapItem ( item );
  }

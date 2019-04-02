#include <iframe.hpp>
#include <ientryfd.hpp>
#include <idmefit.hpp>
#include <idmefpv.hpp>
#include <idmsrch.hpp>
#include <idmtgth.hpp>
#include <idmisrnd.hpp>

void main()
{

  /*-------------------------------------------------------------------
     Standard frame with client area divided between client
     entry field and an entry field extension...
   -------------------------------------------------------------------*/
  IFrameWindow
    frame( "ICLUI Direct Manipulation Sample 1" );

  IEntryField
    client( 0, &frame, &frame ),
    ext   ( 0, &frame, &frame );

  /*-------------------------------------------------------------------
     Instantiate source and target Direct Manipulation handlers
     and configure client as both a source and target handler
   -------------------------------------------------------------------*/
  IDMSourceHandler
    srcHandler( &client );
  IDMTargetHandler
    tgtHandler( &client );

  /*-------------------------------------------------------------------
     Reuse the drag item provider in the extension that was
     instantiated for the client.
   -------------------------------------------------------------------*/
  ext.setItemProvider(client.itemProvider());

  /*-------------------------------------------------------------------
     Configure the extension as both a source and target handler
   -------------------------------------------------------------------*/
  srcHandler.handleEventsFor(&ext);
  tgtHandler.handleEventsFor(&ext);

  /*-------------------------------------------------------------------
     Frame setup
   -------------------------------------------------------------------*/
  frame
    .setClient( &client )
    .addExtension( &ext, IFrameWindow::belowClient, 0.5 )
    .setFocus()
    .show();

  /*-------------------------------------------------------------------
     Invoke ICLUI Direct Manipulation Sample 1
   -------------------------------------------------------------------*/
  IApplication::current().run();

}

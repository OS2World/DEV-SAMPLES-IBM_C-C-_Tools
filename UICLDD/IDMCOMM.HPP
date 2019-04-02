#ifndef _IDMCOMM_
#define _IDMCOMM_


#ifndef _ISTRING_
  #include <istring.hpp>
#endif

struct IDM {
/*-------------------------------- Enumerations --------------------------------
| These enumerations define various direct manipulation values:                |
|   Source         - Enumeration of the possible drag start sources:           |
|                        pointingDevice - Drag initiated via mouse.            |
|                        keyboard       - Drag initiated via keyboard.         |
|   DropIndicator  - Enumeration of possible drop indicator values:            |
|                        ok             - Drop permitted.                      |
|                        notOk          - Not permitted at this location.      |
|                        operationNotOk - Operation(s) not permitted.          |
|                        neverOk        - Not permitted on this window.        |
------------------------------------------------------------------------------*/
enum Source
{
  pointingDevice,
  keyboard
};

enum DropIndicator
{
  notOk          = 0x0000,
  ok             = 0x0001,
  operationNotOk = 0x0002,
  neverOk        = 0x0003
};

/*------------------------------- Type Constants ------------------------------+
| These static constants define various direct manipulation drag item types:   |
|   TEXT            - Generic text drag item type                              |
|   BITMAP          - Bitmap drag item type                                    |
|   ICON            - Icon drag item type                                      |
|   FILE            - FILE drag item type                                      |
|   CONTAINER       - Container drag item type                                 |
|   CONTAINEROBJECT - Container object drag item type                          |
|   UNKNOWN         - Unknown drag item type                                   |
------------------------------------------------------------------------------*/
static const IString
  TEXT,
  BITMAP,
  ICON,
  FILE,
  CONTAINER,
  CONTAINEROBJECT,
  UNKNOWN;
};

#endif

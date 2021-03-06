/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - Département ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail         : mailto:alliance-users@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU General Public |
| License as  published by the Free Software Foundation;      |
| either version 2 of the License, or (at your option) any    |
| later version.                                              |
|                                                             |
| Alliance VLSI  CAD System  is distributed  in the hope that |
| it  will be useful, but WITHOUT  ANY WARRANTY;              |
| without even the  implied warranty of MERCHANTABILITY or    |
| FITNESS FOR A PARTICULAR PURPOSE. See the GNU General       |
| Public License for more details.                            |
|                                                             |
| You should have received a copy  of the GNU General Public  |
| License along with the GNU C Library; see the file COPYING. |
| If not, write to the Free Software Foundation, Inc.,        |
| 675 Mass Ave, Cambridge, MA 02139, USA.                     |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
| Tool    :                    XPAT                           |
|                                                             |
| File    :                  Message.c                        |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                   04.12.96                        |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <Xm/Xm.h>
# include <Xm/PushBG.h>
# include <Xm/CascadeBG.h>
 
# include "mut.h"
# include "aut.h"
# include "pat.h"
# include "XSB.h"
# include "XPT.h"
# include "XMX.h"
# include "XTB.h"
# include "XME.h"
# include "XME_edit.h"
# include "XME_message.h"

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                    XpatPromptEditIdentify                   |
|                                                             |
\------------------------------------------------------------*/

void XpatPromptEditIdentify()

{
  autbegin();

  XpatDisplayMessage( XPAT_MESSAGE_MODE  , "Identify" );
  XpatDisplayMessage( XPAT_MESSAGE_INFO  , "Select object" );
  XpatDisplayMessage( XPAT_MESSAGE_PROMPT, "Enter select point" );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    XpatPromptEditConnected                  |
|                                                             |
\------------------------------------------------------------*/

void XpatPromptEditConnected()

{
  autbegin();

  XpatDisplayMessage( XPAT_MESSAGE_MODE  , "Connected" );
  XpatDisplayMessage( XPAT_MESSAGE_INFO  , "Select object" );
  XpatDisplayMessage( XPAT_MESSAGE_PROMPT, "Enter select point" );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    XpatPromptEditAddCursor                  |
|                                                             |
\------------------------------------------------------------*/

void XpatPromptEditAddCursor()

{
  autbegin();

  XpatDisplayMessage( XPAT_MESSAGE_MODE  , "Add cursor" );
  XpatDisplayMessage( XPAT_MESSAGE_INFO  , "Select time" );
  XpatDisplayMessage( XPAT_MESSAGE_PROMPT, "Enter select point" );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    XpatPromptEditDelCursor                  |
|                                                             |
\------------------------------------------------------------*/

void XpatPromptEditDelCursor()

{
  autbegin();

  XpatDisplayMessage( XPAT_MESSAGE_MODE  , "Delete cursor" );
  XpatDisplayMessage( XPAT_MESSAGE_INFO  , "Select cursor" );
  XpatDisplayMessage( XPAT_MESSAGE_PROMPT, "Enter select point" );

  autend();
}

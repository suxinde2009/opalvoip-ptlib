/*
 * pwlib.h
 *
 * Umbrella include file for all GUI classes.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-1998 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Portions are Copyright (C) 1993 Free Software Foundation, Inc.
 * All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: pwlib.h,v $
 * Revision 1.46  1999/08/17 03:46:40  robertj
 * Fixed usage of inlines in optimised version.
 *
 * Revision 1.45  1998/11/30 02:50:44  robertj
 * New directory structure
 *
 * Revision 1.44  1998/09/23 06:19:54  robertj
 * Added open source copyright license.
 *
 * Revision 1.43  1998/09/21 13:30:41  robertj
 * Changes to support new PListView class. Different call back method.
 *
 * Revision 1.42  1996/10/14 03:06:55  robertj
 * Fixed name conflict with colordlg.h
 *
 * Revision 1.41  1996/08/08 10:08:49  robertj
 * Directory structure changes for common files.
 *
 * Revision 1.40  1995/11/09 12:18:53  robertj
 * Added static (filled) rectange control.
 *
 * Revision 1.39  1995/10/14 15:03:12  robertj
 * Added floating dialogs.
 *
 * Revision 1.38  1995/07/31 12:06:04  robertj
 * Split off pop up window from balloon.
 *
 * Revision 1.37  1995/04/02 09:27:25  robertj
 * Added "balloon" help.
 *
 * Revision 1.36  1995/02/19  04:19:15  robertj
 * Added dynamically linked command processing.
 *
 * Revision 1.35  1995/01/22  07:29:39  robertj
 * Added font & colour standard dialogs.
 *
 * Revision 1.34  1995/01/07  04:39:38  robertj
 * Redesigned font enumeration code and changed font styles.
 *
 * Revision 1.33  1994/10/23  04:53:25  robertj
 * Added PPixel subclasses
 *
 * Revision 1.32  1994/08/23  11:32:52  robertj
 * Oops
 *
 * Revision 1.31  1994/08/22  00:46:48  robertj
 * Added pragma fro GNU C++ compiler.
 *
 * Revision 1.30  1994/07/25  03:31:41  robertj
 * Renamed common pwlib to pwmisc to avoid name conflict.
 *
 * Revision 1.29  1994/07/17  10:46:06  robertj
 * Reordered classes to fix class references.
 *
 * Revision 1.28  1994/06/25  11:55:15  robertj
 * Unix version synchronisation.
 *
 * Revision 1.27  1994/04/20  12:17:44  robertj
 * Made pwlib.h common
 *
 */

#ifndef _PWLIB_H
#define _PWLIB_H

#ifdef __GNUC__
#pragma interface
#endif


#define P_GUI


///////////////////////////////////////////////////////////////////////////////
// Basic text mode library

#include <ptlib.h>


///////////////////////////////////////////////////////////////////////////////
// PResourceData

#include <pwlib/resdata.h>


///////////////////////////////////////////////////////////////////////////////
// PResourceString

#include <pwlib/rstring.h>


///////////////////////////////////////////////////////////////////////////////
// PDim

#include <pwlib/dim.h>


///////////////////////////////////////////////////////////////////////////////
// PPoint

#include <pwlib/point.h>


///////////////////////////////////////////////////////////////////////////////
// PRect

#include <pwlib/rect.h>


///////////////////////////////////////////////////////////////////////////////
// PRegion

#include <pwlib/region.h>


///////////////////////////////////////////////////////////////////////////////
// PKeyCode

#include <pwlib/keycode.h>


//////////////////////////////////////////////////////////////////////////////
// PColour

#include <pwlib/colour.h>


//////////////////////////////////////////////////////////////////////////////
// PRealColour

#include <pwlib/rcolour.h>


///////////////////////////////////////////////////////////////////////////////
// PFont

#include <pwlib/font.h>


///////////////////////////////////////////////////////////////////////////////
// PRealFont

#include <pwlib/rfont.h>


///////////////////////////////////////////////////////////////////////////////
// PFontFamily

#include <pwlib/fontfam.h>


///////////////////////////////////////////////////////////////////////////////
// PPalette

#include <pwlib/palette.h>


///////////////////////////////////////////////////////////////////////////////
// PPattern

#include <pwlib/pattern.h>


///////////////////////////////////////////////////////////////////////////////
// PImage

#include <pwlib/image.h>


///////////////////////////////////////////////////////////////////////////////
// PPixels

#include <pwlib/pixels.h>
#include <pwlib/pixels1.h>
#include <pwlib/pixels2.h>
#include <pwlib/pixels4.h>
#include <pwlib/pixels8.h>
#include <pwlib/pixels24.h>
#include <pwlib/pixels32.h>


///////////////////////////////////////////////////////////////////////////////
// PPict

#include <pwlib/pict.h>


///////////////////////////////////////////////////////////////////////////////
// PCursor

#include <pwlib/cursor.h>


///////////////////////////////////////////////////////////////////////////////
// PCaret

#include <pwlib/caret.h>


///////////////////////////////////////////////////////////////////////////////
// PImgIcon

#include <pwlib/imgicon.h>


///////////////////////////////////////////////////////////////////////////////
// PIcon

#include <pwlib/icon.h>


///////////////////////////////////////////////////////////////////////////////
// PCanvasState

#include <pwlib/canstate.h>


///////////////////////////////////////////////////////////////////////////////
// PCanvas

#include <pwlib/canvas.h>


///////////////////////////////////////////////////////////////////////////////
// PInteractorCanvas

#include <pwlib/icanvas.h>


///////////////////////////////////////////////////////////////////////////////
// PDrawCanvas

#include <pwlib/dcanvas.h>


///////////////////////////////////////////////////////////////////////////////
// PRedrawCanvas

#include <pwlib/rcanvas.h>


///////////////////////////////////////////////////////////////////////////////
// PMemoryCanvas

#include <pwlib/mcanvas.h>


///////////////////////////////////////////////////////////////////////////////
// PPrintInfo

#include <pwlib/prinfo.h>


///////////////////////////////////////////////////////////////////////////////
// PPrintCanvas

#include <pwlib/pcanvas.h>


///////////////////////////////////////////////////////////////////////////////
// PMenuEntry

#include <pwlib/menuent.h>


///////////////////////////////////////////////////////////////////////////////
// PMenuItem

#include <pwlib/menuitem.h>


///////////////////////////////////////////////////////////////////////////////
// PMenuSeparator

#include <pwlib/menusep.h>


///////////////////////////////////////////////////////////////////////////////
// PSubMenu

#include <pwlib/submenu.h>


///////////////////////////////////////////////////////////////////////////////
// PRootMenu

#include <pwlib/rootmenu.h>


///////////////////////////////////////////////////////////////////////////////
// PInteractor

#include <pwlib/interact.h>


///////////////////////////////////////////////////////////////////////////////
// PControl

#include <pwlib/control.h>


///////////////////////////////////////////////////////////////////////////////
// PNamedControl

#include <pwlib/ncontrol.h>


///////////////////////////////////////////////////////////////////////////////
// PStaticText

#include <pwlib/stattext.h>


///////////////////////////////////////////////////////////////////////////////
// PStaticIcon

#include <pwlib/staticon.h>


///////////////////////////////////////////////////////////////////////////////
// PStaticBox

#include <pwlib/statbox.h>


///////////////////////////////////////////////////////////////////////////////
// PStaticRect

#include <pwlib/statrect.h>


///////////////////////////////////////////////////////////////////////////////
// PPushButton

#include <pwlib/pbutton.h>


///////////////////////////////////////////////////////////////////////////////
// PTextButton

#include <pwlib/tbutton.h>


///////////////////////////////////////////////////////////////////////////////
// PImageButton

#include <pwlib/ibutton.h>


///////////////////////////////////////////////////////////////////////////////
// PCheck3WayBox

#include <pwlib/check3.h>


///////////////////////////////////////////////////////////////////////////////
// PCheckBox

#include <pwlib/checkbox.h>


///////////////////////////////////////////////////////////////////////////////
// PRadioButton

#include <pwlib/rbutton.h>


///////////////////////////////////////////////////////////////////////////////
// PChoiceBox

#include <pwlib/choicbox.h>


///////////////////////////////////////////////////////////////////////////////
// PListBox

#include <pwlib/listbox.h>


///////////////////////////////////////////////////////////////////////////////
// PListViewControl

#include <pwlib/listview.h>


///////////////////////////////////////////////////////////////////////////////
// PStringListBox

#include <pwlib/slistbox.h>


///////////////////////////////////////////////////////////////////////////////
// PComboBox

#include <pwlib/combobox.h>


///////////////////////////////////////////////////////////////////////////////
// PScrollBar

#include <pwlib/scrollb.h>


///////////////////////////////////////////////////////////////////////////////
// PVerticalScrollBar

#include <pwlib/vscrollb.h>


///////////////////////////////////////////////////////////////////////////////
// PHorizontalScrollBar

#include <pwlib/hscrollb.h>


///////////////////////////////////////////////////////////////////////////////
// PEditBox

#include <pwlib/editbox.h>


///////////////////////////////////////////////////////////////////////////////
// PPasswordEditBox

#include <pwlib/pwedbox.h>


///////////////////////////////////////////////////////////////////////////////
// PMultiLineEditBox

#include <pwlib/meditbox.h>


///////////////////////////////////////////////////////////////////////////////
// PNumberEditBox

#include <pwlib/numedbox.h>


///////////////////////////////////////////////////////////////////////////////
// PIntegerEditBox

#include <pwlib/intedit.h>


///////////////////////////////////////////////////////////////////////////////
// PFloatEditBox

#include <pwlib/realedit.h>


///////////////////////////////////////////////////////////////////////////////
// PInteractorLayout

#include <pwlib/ilayout.h>


///////////////////////////////////////////////////////////////////////////////
// PDialog

#include <pwlib/dialog.h>


///////////////////////////////////////////////////////////////////////////////
// PFloatingDialog

#include <pwlib/floatdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PModalDialog

#include <pwlib/modaldlg.h>


///////////////////////////////////////////////////////////////////////////////
// PSimpleDialog

#include <pwlib/simpdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PFileDialog

#include <pwlib/filedlg.h>


///////////////////////////////////////////////////////////////////////////////
// POpenFileDialog

#include <pwlib/opendlg.h>


///////////////////////////////////////////////////////////////////////////////
// PSaveFileDialog

#include <pwlib/savedlg.h>


///////////////////////////////////////////////////////////////////////////////
// POpenDirDialog

#include <pwlib/dirdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PPrintDialog

#include <pwlib/printdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PPrinterSetupDialog

#include <pwlib/prsetdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PPrintJobDialog

#include <pwlib/prjobdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PFontDialog

#include <pwlib/fontdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PColourDialog

#include <pwlib/pclrdlg.h>


///////////////////////////////////////////////////////////////////////////////
// PScrollable

#include <pwlib/scrollab.h>


///////////////////////////////////////////////////////////////////////////////
// PPopUp

#include <pwlib/popup.h>


///////////////////////////////////////////////////////////////////////////////
// PBalloon

#include <pwlib/balloon.h>


///////////////////////////////////////////////////////////////////////////////
// PTitledWindow

#include <pwlib/titlewnd.h>


///////////////////////////////////////////////////////////////////////////////
// PTopLevelWindow

#include <pwlib/toplwnd.h>


///////////////////////////////////////////////////////////////////////////////
// PMDIFrameWindow

#include <pwlib/mdiframe.h>


///////////////////////////////////////////////////////////////////////////////
// PMDIDocWindow

#include <pwlib/mdidoc.h>


///////////////////////////////////////////////////////////////////////////////
// PCommandSink, PCommandSource

#include <pwlib/commands.h>


///////////////////////////////////////////////////////////////////////////////
// PClipboard

#include <pwlib/clipbrd.h>


///////////////////////////////////////////////////////////////////////////////
// PApplication

#include <pwlib/applicat.h>


///////////////////////////////////////////////////////////////////////////////

#if P_USE_INLINES
#include <pwlib/pwlib.inl>
#include <pwlib/pwmisc.inl>
#include <pwlib/graphics.inl>
#include <pwlib/interact.inl>
#endif

#endif // _PWLIB_H

// PWLIB.H

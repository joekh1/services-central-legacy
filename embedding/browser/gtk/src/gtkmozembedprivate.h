/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Christopher Blizzard.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Christopher Blizzard <blizzard@mozilla.org>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef gtkmozembedprivate_h
#define gtkmozembedprivate_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "gtkmozembed.h"

/* signals */

enum {
  LINK_MESSAGE,
  JS_STATUS,
  LOCATION,
  TITLE,
  PROGRESS,
  PROGRESS_ALL,
  NET_STATE,
  NET_STATE_ALL,
  NET_START,
  NET_STOP,
  NEW_WINDOW,
  VISIBILITY,
  DESTROY_BROWSER,
  OPEN_URI,
  SIZE_TO,
  DOM_KEY_DOWN,
  DOM_KEY_PRESS,
  DOM_KEY_UP,
  DOM_MOUSE_DOWN,
  DOM_MOUSE_UP,
  DOM_MOUSE_CLICK,
  DOM_MOUSE_DBL_CLICK,
  DOM_MOUSE_OVER,
  DOM_MOUSE_OUT,
  SECURITY_CHANGE,
  STATUS_CHANGE,
  DOM_ACTIVATE,
  DOM_FOCUS_IN,
  DOM_FOCUS_OUT,
  EMBED_LAST_SIGNAL
};

extern guint moz_embed_signals[EMBED_LAST_SIGNAL];

extern void gtk_moz_embed_single_create_window(GtkMozEmbed **aNewEmbed,
					       guint aChromeFlags);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* gtkmozembedprivate_h */

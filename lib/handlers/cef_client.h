// Copyright (c) 2014 The cefcapi authors. All rights reserved.
// License: BSD 3-clause.
// Website: https://github.com/CzarekTomczak/cefcapi

#include "handlers/cef_base.h"
#include "include/capi/cef_client_capi.h"
#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_life_span_handler_capi.h"
#include "include/capi/cef_render_handler_capi.h"

// ----------------------------------------------------------------------------
// struct _cef_client_t
// ----------------------------------------------------------------------------

///
// Implement this structure to provide handler implementations.
///

///
// Return the handler for context menus. If no handler is provided the default
// implementation will be used.
///

struct _cef_context_menu_handler_t* CEF_CALLBACK get_context_menu_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_context_menu_handler\n");
    return NULL;
}

///
// Return the handler for dialogs. If no handler is provided the default
// implementation will be used.
///
struct _cef_dialog_handler_t* CEF_CALLBACK get_dialog_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_dialog_handler\n");
    return NULL;
}

int CEF_CALLBACK cef_display_handler_t_on_console_message(
      struct _cef_display_handler_t* self,
      struct _cef_browser_t* browser, const cef_string_t* message,
      const cef_string_t* source, int line) {
    go_OnConsoleMessage(browser, message, source, line);
    return 1;
}

///
// Return the handler for browser display state events.
///
struct _cef_display_handler_t* CEF_CALLBACK get_display_handler(
        struct _cef_client_t* self) {
    cef_display_handler_t* displayHandler = (cef_display_handler_t*)calloc(1, sizeof(cef_display_handler_t));
    displayHandler->base.size = sizeof(cef_display_handler_t);
    initialize_cef_base((cef_base_t*) displayHandler);
    // callbacks
    displayHandler->on_console_message = cef_display_handler_t_on_console_message;
    return displayHandler;
}

///
// Return the handler for download events. If no handler is returned downloads
// will not be allowed.
///
struct _cef_download_handler_t* CEF_CALLBACK get_download_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_download_handler\n");
    return NULL;
}

///
// Return the handler for drag events.
///
struct _cef_drag_handler_t* CEF_CALLBACK get_drag_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_drag_handler\n");
    return NULL;
}

///
// Return the handler for focus events.
///
struct _cef_focus_handler_t* CEF_CALLBACK get_focus_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_focus_handler\n");
    return NULL;
}

///
// Return the handler for geolocation permissions requests. If no handler is
// provided geolocation access will be denied by default.
///
struct _cef_geolocation_handler_t* CEF_CALLBACK get_geolocation_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_geolocation_handler\n");
    return NULL;
}

///
// Return the handler for JavaScript dialogs. If no handler is provided the
// default implementation will be used.
///
struct _cef_jsdialog_handler_t* CEF_CALLBACK get_jsdialog_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_jsdialog_handler\n");
    return NULL;
}

///
// Return the handler for keyboard events.
///
struct _cef_keyboard_handler_t* CEF_CALLBACK get_keyboard_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_keyboard_handler\n");
    return NULL;
}

void CEF_CALLBACK cef_life_span_handler_t_on_after_created(
        struct _cef_life_span_handler_t* self,
        struct _cef_browser_t* browser) {
    DEBUG_CALLBACK("client->LifeSpanHandler->on_after_created\n");
    go_OnAfterCreated(self, browser->get_identifier(browser), browser);
}

///
// Return the handler for browser life span events.
///
struct _cef_life_span_handler_t* CEF_CALLBACK get_life_span_handler(
        struct _cef_client_t* self) {
    cef_life_span_handler_t* lifeHandler = (cef_life_span_handler_t*)calloc(1, sizeof(cef_life_span_handler_t));
    DEBUG_CALLBACK("client->initialize_life_span_handler\n");
    lifeHandler->base.size = sizeof(cef_life_span_handler_t);
    initialize_cef_base((cef_base_t*) lifeHandler);
    // callbacks
    lifeHandler->on_after_created = cef_life_span_handler_t_on_after_created;
    return lifeHandler;
    // return NULL;
}

///
// Return the handler for browser load status events.
///
struct _cef_load_handler_t* CEF_CALLBACK get_load_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_load_handler\n");
    return NULL;
}

int CEF_CALLBACK cef_render_handler_t_get_root_screen_rect(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_rect_t* rect) {
      DEBUG_CALLBACK("render_handler->get_root_screen_rect");
      return go_RenderHandlerGetRootScreenRect(browser->get_identifier(browser), rect);
}

int CEF_CALLBACK cef_render_handler_t_get_view_rect(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_rect_t* rect) {
      DEBUG_CALLBACK("render_handler->get_view_rect");
      return go_RenderHandlerGetViewRect(browser->get_identifier(browser), rect);
}

int CEF_CALLBACK cef_render_handler_t_get_screen_point(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, int viewX, int viewY, int* screenX, int* screenY) {
      DEBUG_CALLBACK("render_handler->get_screen_point");
      return go_RenderHandlerGetScreenPoint(browser->get_identifier(browser), viewX, viewY, screenX, screenY);
}

int CEF_CALLBACK cef_render_handler_t_get_screen_info(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, struct _cef_screen_info_t* info) {
      DEBUG_CALLBACK("render_handler->get_screen_info");
      return go_RenderHandlerGetScreenInfo(browser->get_identifier(browser), info);
}

void CEF_CALLBACK cef_render_handler_t_on_popup_show(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, int show) {
      DEBUG_CALLBACK("render_handler->on_popup_show");
      go_RenderHandlerOnPopupShow(browser->get_identifier(browser), show);
}

void CEF_CALLBACK cef_render_handler_t_on_popup_size(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, const cef_rect_t* rect) {
      DEBUG_CALLBACK("render_handler->on_popup_size");
      go_RenderHandlerOnPopupSize(browser->get_identifier(browser), rect);
}

void CEF_CALLBACK cef_render_handler_t_on_paint(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_paint_element_type_t type,
      size_t dirtyRectsCount, cef_rect_t const* dirtyRects, const void* buffer,
      int width, int height) {
      DEBUG_CALLBACK("render_handler->on_paint");
      go_RenderHandlerOnPaint(browser->get_identifier(browser), type, dirtyRectsCount, dirtyRects, buffer, width, height);
}

void CEF_CALLBACK cef_render_handler_t_on_cursor_change(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser, cef_cursor_handle_t cursor) {
      DEBUG_CALLBACK("render_handler->on_cursor_change");
      go_RenderHandlerOnCursorChange(browser->get_identifier(browser), cursor);
}

void CEF_CALLBACK cef_render_handler_t_on_scroll_offset_changed(struct _cef_render_handler_t* self,
      struct _cef_browser_t* browser) {
      DEBUG_CALLBACK("render_handler->on_scroll_offset_changed");
      go_RenderHandlerOnScrollOffsetChanged(browser->get_identifier(browser));
}

///
// Return the handler for off-screen rendering events.
///
struct _cef_render_handler_t* CEF_CALLBACK get_render_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_render_handler\n");
    cef_render_handler_t* renderHandler = (cef_render_handler_t*)calloc(1, sizeof(cef_render_handler_t));
    renderHandler->base.size = sizeof(cef_render_handler_t);
    initialize_cef_base((cef_base_t*) renderHandler);
    // callbacks
    renderHandler->get_root_screen_rect = cef_render_handler_t_get_root_screen_rect;
    renderHandler->get_view_rect = cef_render_handler_t_get_view_rect;
    renderHandler->get_screen_point = cef_render_handler_t_get_screen_point;
    renderHandler->get_screen_info = cef_render_handler_t_get_screen_info;
    renderHandler->on_popup_show = cef_render_handler_t_on_popup_show;
    renderHandler->on_popup_size = cef_render_handler_t_on_popup_size;
    renderHandler->on_paint = cef_render_handler_t_on_paint;
    renderHandler->on_cursor_change = cef_render_handler_t_on_cursor_change;
    renderHandler->on_scroll_offset_changed = cef_render_handler_t_on_scroll_offset_changed;
    return renderHandler;
}

///
// Return the handler for browser request events.
///
struct _cef_request_handler_t* CEF_CALLBACK get_request_handler(
        struct _cef_client_t* self) {
    // DEBUG_CALLBACK("get_request_handler\n");
    return NULL;
}

///
// Called when a new message is received from a different process. Return true
// (1) if the message was handled or false (0) otherwise. Do not keep a
// reference to or attempt to access the message outside of this callback.
///
int CEF_CALLBACK on_process_message_received(
        struct _cef_client_t* self,
        struct _cef_browser_t* browser, cef_process_id_t source_process,
        struct _cef_process_message_t* message) {
    DEBUG_CALLBACK("on_process_message_received\n");
    return 0;
}

void initialize_client_handler(struct _cef_client_t* client) {
    DEBUG_CALLBACK("initialize_client_handler\n");
    client->base.size = sizeof(cef_client_t);
    initialize_cef_base((cef_base_t*)client);
    // callbacks
    client->get_context_menu_handler = get_context_menu_handler;
    client->get_dialog_handler = get_dialog_handler;
    client->get_display_handler = get_display_handler;
    client->get_download_handler = get_download_handler;
    client->get_drag_handler = get_drag_handler;
    client->get_focus_handler = get_focus_handler;
    client->get_geolocation_handler = get_geolocation_handler;
    client->get_jsdialog_handler = get_jsdialog_handler;
    client->get_keyboard_handler = get_keyboard_handler;
    client->get_life_span_handler = get_life_span_handler;
    client->get_load_handler = get_load_handler;
    client->get_render_handler = get_render_handler;
    client->get_request_handler = get_request_handler;
    client->on_process_message_received = on_process_message_received;
}

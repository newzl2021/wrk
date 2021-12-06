#ifndef JS_SCRIPT_H
#define JS_SCRIPT_H

#include <stdbool.h>
#include <unistd.h>
#include "stats.h"
#include "wrk.h"

JSContext *js_script_create(char *, char *, char **);

bool js_script_resolve(JSContext *, char *, char *);
void js_script_done(JSContext *, stats *, stats *);

void js_script_init(JSContext *, thread *, int, char **);
uint64_t js_script_delay(JSContext *);
void js_script_request(JSContext *, char **, size_t *);
void js_script_response(JSContext *, int, buffer *, buffer *);
size_t js_script_verify_request(JSContext *L);

bool js_script_is_static(JSContext *);
bool js_script_want_response(JSContext *L);
bool js_script_has_delay(JSContext *L);
bool js_script_has_done(JSContext *L);
void js_script_summary(JSContext *, uint64_t, uint64_t, uint64_t);
void js_script_errors(JSContext *, errors *);

void script_setup(JSContext *, thread *);

void script_copy_value(JSContext *, JSContext *, int);
int script_parse_url(char *, struct http_parser_url *);

void buffer_append(buffer *, const char *, size_t);
void buffer_reset(buffer *);
char *buffer_pushlstring(JSContext *, char *);

#endif /* JS_SCRIPT_H */
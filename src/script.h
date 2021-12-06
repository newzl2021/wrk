#ifndef SCRIPT_H
#define SCRIPT_H

#include "lua_script.h"

ScriptContext script_create(char *, char *, char **);

bool script_resolve(ScriptContext, char *, char *);
void script_done(ScriptContext, stats *, stats *);

void script_init(ScriptContext, thread *, int, char **);
uint64_t script_delay(ScriptContext);
void script_request(ScriptContext, char **, size_t *);
void script_response(ScriptContext, int, buffer *, buffer *);
size_t script_verify_request(ScriptContext);

bool script_is_static(ScriptContext);
bool script_want_response(ScriptContext);
bool script_has_delay(ScriptContext);
bool script_has_done(ScriptContext);
void script_summary(ScriptContext, uint64_t, uint64_t, uint64_t);
void script_errors(ScriptContext, errors *);

#endif
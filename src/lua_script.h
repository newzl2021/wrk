#ifndef LUA_SCRIPT_H
#define LUA_SCRIPT_H

#include <stdbool.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <unistd.h>
#include "stats.h"
#include "wrk.h"

lua_State *lua_script_create(char *, char *, char **);

bool lua_script_resolve(lua_State *, char *, char *);
void lua_script_done(lua_State *, stats *, stats *);

void lua_script_init(lua_State *, thread *, int, char **);
uint64_t lua_script_delay(lua_State *);
void lua_script_request(lua_State *, char **, size_t *);
void lua_script_response(lua_State *, int, buffer *, buffer *);
size_t lua_script_verify_request(lua_State *L);

bool lua_script_is_static(lua_State *);
bool lua_script_want_response(lua_State *L);
bool lua_script_has_delay(lua_State *L);
bool lua_script_has_done(lua_State *L);
void lua_script_summary(lua_State *, uint64_t, uint64_t, uint64_t);
void lua_script_errors(lua_State *, errors *);

void script_setup(lua_State *, thread *);

void script_copy_value(lua_State *, lua_State *, int);
int script_parse_url(char *, struct http_parser_url *);

void buffer_append(buffer *, const char *, size_t);
void buffer_reset(buffer *);
char *buffer_pushlstring(lua_State *, char *);

#endif /* LUA_SCRIPT_H */
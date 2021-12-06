#include "script.h"

ScriptContext script_create(char *file, char *url, char **headers) {
    ScriptContext ctx;
    ctx.L = lua_script_create(file, url, headers);
    return ctx;
}

bool script_resolve(ScriptContext ctx, char *host, char *service) {
    return lua_script_create(ctx.L, host, service);
}

void script_done(ScriptContext ctx, stats *latency, stats *requests) {
    return lua_script_done(ctx.L, latency, requests);
}

void script_init(ScriptContext ctx, thread *t, int argc, char **argv) {
    return lua_script_init(ctx.L, t, argc, argv);
}

uint64_t script_delay(ScriptContext ctx) {
    return lua_script_delay(ctx.L);
}

void script_request(ScriptContext ctx, char **buf, size_t *len) {
    return lua_script_request(ctx.L, buf, len);
}

void script_response(ScriptContext ctx, int status, buffer *headers, buffer *body) {
    return lua_script_response(ctx.L, status, headers, body);
}

size_t script_verify_request(ScriptContext ctx) {
    return lua_script_verify_request(ctx.L);
}

bool script_is_static(ScriptContext ctx) {
    return lua_script_is_static(ctx.L);
}

bool script_want_response(ScriptContext ctx) {
    return lua_script_want_response(ctx.L);
}

bool script_has_delay(ScriptContext ctx) {
    return lua_script_has_delay(ctx.L);
}

bool script_has_done(ScriptContext ctx) {
    return lua_script_has_done(ctx.L);
}

void script_summary(ScriptContext ctx, uint64_t duration, uint64_t requests, uint64_t bytes) {
    return lua_script_summary(ctx.L, duration, requests, bytes);
}

void script_errors(ScriptContext ctx, errors *errors) {
    return lua_script_errors(ctx.L, errors);
}

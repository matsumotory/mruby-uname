/*
** mrb_uname.c - Uname class
**
** Copyright (c) MATSUMOTO Ryosuke 2014
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_uname.h"
#include <sys/utsname.h>

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  struct utsname uname_b;
} mrb_uname_data;

static const struct mrb_data_type mrb_uname_data_type = {
  "mrb_uname_data", mrb_free,
};

static mrb_value mrb_uname_init(mrb_state *mrb, mrb_value self)
{
  mrb_uname_data *data;
  struct utsname uname_b;

  data = (mrb_uname_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_uname_data_type;
  DATA_PTR(self) = NULL;

  data = (mrb_uname_data *)mrb_malloc(mrb, sizeof(mrb_uname_data));
  if (uname(&uname_b) != 0) {
    mrb_raise(mrb, E_RUNTIME_ERROR, "uname failed");
  }

  data->uname_b = uname_b;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_uname_sysname(mrb_state *mrb, mrb_value self)
{
  mrb_uname_data *data = DATA_PTR(self);

  return mrb_str_new_cstr(mrb, data->uname_b.sysname);
}

void mrb_mruby_uname_gem_init(mrb_state *mrb)
{
    struct RClass *uname;
    uname = mrb_define_class(mrb, "Uname", mrb->object_class);
    mrb_define_method(mrb, uname, "initialize", mrb_uname_init, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, uname, "sysname", mrb_uname_sysname, MRB_ARGS_NONE());
    DONE;
}

void mrb_mruby_uname_gem_final(mrb_state *mrb)
{
}


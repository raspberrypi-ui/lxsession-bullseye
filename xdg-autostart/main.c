/* main.c generated by valac 0.56.3, the Vala compiler
 * generated from main.vala, do not modify */

/* 
 *      Copyright 2014 Julien Lavergne <gilir@ubuntu.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <xdg-autostart/xdg-autostart.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define LXSESSION_TYPE_MAIN (lxsession_main_get_type ())
#define LXSESSION_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LXSESSION_TYPE_MAIN, LxsessionMain))
#define LXSESSION_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LXSESSION_TYPE_MAIN, LxsessionMainClass))
#define LXSESSION_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LXSESSION_TYPE_MAIN))
#define LXSESSION_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LXSESSION_TYPE_MAIN))
#define LXSESSION_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LXSESSION_TYPE_MAIN, LxsessionMainClass))

typedef struct _LxsessionMain LxsessionMain;
typedef struct _LxsessionMainClass LxsessionMainClass;
typedef struct _LxsessionMainPrivate LxsessionMainPrivate;
enum  {
	LXSESSION_MAIN_0_PROPERTY,
	LXSESSION_MAIN_NUM_PROPERTIES
};
static GParamSpec* lxsession_main_properties[LXSESSION_MAIN_NUM_PROPERTIES];
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _LxsessionMain {
	GObject parent_instance;
	LxsessionMainPrivate * priv;
};

struct _LxsessionMainClass {
	GObjectClass parent_class;
};

static gpointer lxsession_main_parent_class = NULL;
static gchar* lxsession_main_desktop_environnement;
static gchar* lxsession_main_desktop_environnement = NULL;

VALA_EXTERN GType lxsession_main_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (LxsessionMain, g_object_unref)
static gint lxsession_main_main (gchar** args,
                          gint args_length1);
VALA_EXTERN LxsessionMain* lxsession_main_new (void);
VALA_EXTERN LxsessionMain* lxsession_main_construct (GType object_type);
static void lxsession_main_finalize (GObject * obj);
static GType lxsession_main_get_type_once (void);

static const GOptionEntry LXSESSION_MAIN_option_entries[2] = {{"desktop_environnement", 'd', (gint) 0, G_OPTION_ARG_STRING, &lxsession_main_desktop_environnement, "Desktop environment to use for desktop files, like LXDE, KDE ... Defau" \
"lt to LXDE", "NAME"}, {NULL}};

static gint
lxsession_main_main (gchar** args,
                     gint args_length1)
{
	const gchar* _tmp8_;
	GError* _inner_error0_ = NULL;
	gint result;
	{
		GOptionContext* options_args = NULL;
		GOptionContext* _tmp0_;
		GOptionContext* _tmp1_;
		GOptionContext* _tmp2_;
		GOptionContext* _tmp3_;
		_tmp0_ = g_option_context_new ("- Lxsession autostart utility");
		options_args = _tmp0_;
		_tmp1_ = options_args;
		g_option_context_set_help_enabled (_tmp1_, TRUE);
		_tmp2_ = options_args;
		g_option_context_add_main_entries (_tmp2_, LXSESSION_MAIN_option_entries, NULL);
		_tmp3_ = options_args;
		g_option_context_parse (_tmp3_, (gint*) (&args_length1), &args, &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			gint _tmp4_ = -1;
			_g_option_context_free0 (options_args);
			if (_inner_error0_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return _tmp4_;
		}
		_g_option_context_free0 (options_args);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError* e = NULL;
		GError* _tmp5_;
		const gchar* _tmp6_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		g_critical ("main.vala:41: Option parsing failed: %s\n", _tmp6_);
		result = -1;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		gint _tmp7_ = -1;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return _tmp7_;
	}
	_tmp8_ = lxsession_main_desktop_environnement;
	if (_tmp8_ == NULL) {
		const gchar* _tmp9_;
		_tmp9_ = g_getenv ("WAYLAND_DISPLAY");
		if (_tmp9_ != NULL) {
			xdg_autostart ("LXDE-wayland");
		} else {
			xdg_autostart ("LXDE");
		}
		result = 0;
		return result;
	} else {
		const gchar* _tmp10_;
		_tmp10_ = lxsession_main_desktop_environnement;
		xdg_autostart (_tmp10_);
		result = 0;
		return result;
	}
}

int
main (int argc,
      char ** argv)
{
	return lxsession_main_main (argv, argc);
}

LxsessionMain*
lxsession_main_construct (GType object_type)
{
	LxsessionMain * self = NULL;
	self = (LxsessionMain*) g_object_new (object_type, NULL);
	return self;
}

LxsessionMain*
lxsession_main_new (void)
{
	return lxsession_main_construct (LXSESSION_TYPE_MAIN);
}

static void
lxsession_main_class_init (LxsessionMainClass * klass,
                           gpointer klass_data)
{
	lxsession_main_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = lxsession_main_finalize;
}

static void
lxsession_main_instance_init (LxsessionMain * self,
                              gpointer klass)
{
}

static void
lxsession_main_finalize (GObject * obj)
{
	LxsessionMain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, LXSESSION_TYPE_MAIN, LxsessionMain);
	G_OBJECT_CLASS (lxsession_main_parent_class)->finalize (obj);
}

static GType
lxsession_main_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (LxsessionMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) lxsession_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LxsessionMain), 0, (GInstanceInitFunc) lxsession_main_instance_init, NULL };
	GType lxsession_main_type_id;
	lxsession_main_type_id = g_type_register_static (G_TYPE_OBJECT, "LxsessionMain", &g_define_type_info, 0);
	return lxsession_main_type_id;
}

GType
lxsession_main_get_type (void)
{
	static volatile gsize lxsession_main_type_id__once = 0;
	if (g_once_init_enter (&lxsession_main_type_id__once)) {
		GType lxsession_main_type_id;
		lxsession_main_type_id = lxsession_main_get_type_once ();
		g_once_init_leave (&lxsession_main_type_id__once, lxsession_main_type_id);
	}
	return lxsession_main_type_id__once;
}


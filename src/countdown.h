#ifndef _COUNTDOWN_H
#define _COUNTDOWN_H

#include <gtk/gtk.h>
#include <glib.h>

typedef struct
{
  GtkBuilder *builder;
  GtkWindow *countdown;
  GtkComboBoxText *unit_box;
  GtkSpinButton *time_entry;
  GtkButton *about_button;
  GtkButton *cancel_button;
  GtkButton *set_timer_button;
} Countdown;

gboolean run_alarm (gpointer user_data);

void set_timer (GtkButton* button, gpointer user_data);

#endif

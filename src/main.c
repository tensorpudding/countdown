#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib.h>
#include "main.h"

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

gboolean
run_alarm (gpointer user_data)
{
  return FALSE;
}

void
set_timer (GtkButton* button,
           gpointer   user_data)
{
  Countdown *c;
  gchar     *cunits;
  GString   *units;
  gint      mult, x;

  c = (Countdown*) user_data;

  cunits = gtk_combo_box_text_get_active_text (c->unit_box);
  units = g_string_new (cunits);
  
  if (g_string_equal (units, g_string_new("hours")))
    {
      mult = 3600;
    }
  else if (g_string_equal (units, g_string_new("minutes")))
    {
      mult = 60;
    }
  else if (g_string_equal (units, g_string_new("seconds")))
    {
      mult = 1;
    }

  x = gtk_spin_button_get_value_as_int (c->time_entry);
  
  g_timeout_add (x*mult, run_alarm, c);

  gtk_widget_destroy (GTK_WIDGET (c->countdown));
  g_free(cunits);
  g_free(units);
}


int
main (int argc, char *argv[])
{
  Countdown  *c;
  GtkBuilder builder;

  gtk_init (&argc, &argv);
  c = g_new(Countdown, 1);
  c->builder = gtk_builder_new ();
  gtk_builder_add_from_file (c->builder, "./countdown.ui", NULL);
  
  c->countdown = gtk_builder_get_object (c->builder, "countdown");
  g_signal_connect (c->countdown, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  c->unit_box = gtk_builder_get_object (c->builder, "unit_box");

  c->time_entry = gtk_builder_get_object (c->builder, "time_entry");

  //  c->about_button = gtk_builder_get_object (builder, "about_button");
  //  g_signal_connect (c->about_button, "clicked", G_CALLBACK (on_about_clicked), NULL);

  c->cancel_button = gtk_builder_get_object (c->builder,
                                             "cancel_button");
  g_signal_connect (c->cancel_button, "clicked",
                    G_CALLBACK (gtk_main_quit), NULL);

  c->set_timer_button = gtk_builder_get_object (c->builder,
                                                "set_timer_button");
  g_signal_connect (c->set_timer_button, "clicked",
                    G_CALLBACK (set_timer), (gpointer)c);

  gtk_main ();
  g_free((gpointer)c);
  return 0;
}

#include <gtk/gtk.h>
#include <glib.h>

#include "countdown.h"

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
  else
    {
      mult = 1;
    }

  x = gtk_spin_button_get_value_as_int (c->time_entry);
  
  //  g_timeout_add (x*mult, run_alarm, c);
  g_print ("The seconds to wait is %d\n", x*mult);

  gtk_widget_destroy (GTK_WIDGET (c->countdown));
  //  g_free(cunits);
  //  g_free(units);
}

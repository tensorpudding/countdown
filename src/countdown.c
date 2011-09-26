#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <notify.h>

#include "countdown.h"

gboolean
run_alarm (gpointer user_data)
{
  time_t now;
  struct tm *ts;
  char buf[80];
  Countdown *c;
  NotifyNotification *notify;

  c = (Countdown*) user_data;

  notify_init ("countdown");
  notify = notify_notification_new ("Times Up!",
                                    NULL,
                                    NULL);
  notify_notification_set_timeout (notify, NOTIFY_EXPIRES_NEVER);
  notify_notification_set_urgency (notify, NOTIFY_URGENCY_CRITICAL);
  notify_notification_show (notify, NULL);

  g_print ("Here we are!\n");
  now = time (NULL);
  ts = localtime (&now);
  strftime (buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
  puts (buf);


  
  gtk_widget_destroy (GTK_WIDGET (c->countdown));
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
  time_t    now;
  struct tm *ts;
  char buf[80];

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
  
  
  g_timeout_add_seconds (x*mult, run_alarm, (gpointer)c);
  g_print ("Wait %d seconds.\n", x*mult);
  now = time (NULL);
  ts = localtime (&now);
  strftime (buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
  puts (buf);

  gtk_widget_hide (GTK_WIDGET (c->countdown));
  //  g_free(cunits);
  //  g_free(units);
}

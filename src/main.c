#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib.h>
#include "countdown.h"

int
main (int argc, char *argv[])
{
  Countdown  *c;

  gtk_init (&argc, &argv);
  c = g_new(Countdown, 1);
  c->builder = gtk_builder_new ();
  gtk_builder_add_from_file (c->builder, "./countdown.ui", NULL);
  
  c->countdown = GTK_WINDOW (gtk_builder_get_object (c->builder,
                                                     "countdown"));
  g_signal_connect (c->countdown, "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);

  c->unit_box = GTK_COMBO_BOX_TEXT (gtk_builder_get_object (c->builder,
                                                            "unit_box"));

  c->time_entry = GTK_SPIN_BUTTON (gtk_builder_get_object (c->builder,
                                                           "time_entry"));

  //  c->about_button = gtk_builder_get_object (builder, "about_button");
  //  g_signal_connect (c->about_button, "clicked", G_CALLBACK (on_about_clicked), NULL);

  c->cancel_button = GTK_BUTTON (gtk_builder_get_object (c->builder,
                                                         "cancel_button"));
  g_signal_connect (c->cancel_button, "clicked",
                    G_CALLBACK (gtk_main_quit), NULL);

  c->set_timer_button = GTK_BUTTON (gtk_builder_get_object (c->builder,
                                                            "set_timer_button"));
  g_signal_connect (c->set_timer_button, "clicked",
                    G_CALLBACK (set_timer), (gpointer)c);


  gtk_widget_show (GTK_WIDGET (c->countdown));
  gtk_main ();
  //  g_free((gpointer)c);
  return 0;
}

// Import GTK
#include "glib.h"
#include "glibconfig.h"
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *question;
    GtkWidget *label;
    GtkWidget *pass;
}MakeWidget;

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 250, 100);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    widget.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    gchar *str = g_strconcat("What is the password for ", g_get_user_name(), "?", NULL);
    widget.question = gtk_label_new(str);
    widget.label = gtk_label_new("Pasword: ");

    /* Create a new GtkEntry widget and hide its content from view. */
    widget.pass = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(widget.pass), FALSE);
    gtk_entry_set_invisible_char(GTK_ENTRY(widget.pass), '*');

    gtk_box_pack_start(GTK_BOX(widget.hbox), GTK_WIDGET(widget.label), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.hbox), GTK_WIDGET(widget.pass), TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.question), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.hbox), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

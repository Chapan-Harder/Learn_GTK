// Import GTK
#include "glib-object.h"
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *expander;
    GtkWidget *label;
}MakeWidget;

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), "02-contaianer-widgets [EXPANDER]");
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 200, 100);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.expander = gtk_expander_new_with_mnemonic("Click Me for more!?");
    widget.label = gtk_label_new("Hide me or show me,\nthat is your choice.");

    gtk_container_add(GTK_CONTAINER(widget.expander), GTK_WIDGET(widget.label));
    gtk_expander_set_expanded(GTK_EXPANDER(widget.expander), true);
    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.expander));

    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();

    return 0;
}

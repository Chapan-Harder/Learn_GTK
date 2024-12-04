// Import GTK
#include "gio/gio.h"
#include <gtk/gtk.h>

// Import GLIB
#include <glib.h>
#include <glib-object.h>

#define NUM_NAMES 4
const gchar *names[] = {"Chapan Harder", "Mamad Mamady", "Jon Rummis", "JackAss"};

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *exit_button;
}MakeWidget;

static void destroy(GtkWidget *, gpointer);

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);
    
    gint i;

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), "02_contaianer-widgets [BOXES]");
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 20);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 350, 420);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);

    /* Add four buttons to the vertical box. */
    for (i = 0; i < NUM_NAMES; i++) {
        widget.button = gtk_button_new_with_label(names[i]);
        gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.button),TRUE , TRUE, 5);

        g_signal_connect_swapped(G_OBJECT(widget.button), "clicked", G_CALLBACK(gtk_widget_destroy), widget.button);
    }
    widget.exit_button = gtk_button_new_with_label("-EXIT-");
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.exit_button), TRUE, TRUE, 5);
    g_signal_connect_swapped(G_OBJECT(widget.exit_button), "clicked", G_CALLBACK(destroy), widget.window);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(destroy), NULL);

    gtk_main();
    return 0;
}

static void destroy(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}

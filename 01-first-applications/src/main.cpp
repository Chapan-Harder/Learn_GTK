#include "includes.h"

static void destroy(GtkWidget*, gpointer);
static gboolean delet_event(GtkWidget*, GdkEvent*, gpointer);

// The main function
// ---------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    // Make the "GTK_Widget"
    GtkWidget *window, *label;

    // Initialization The "GTK"
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Chapan Window [HELLO WORLD]");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 200);

    // Connect the main window to the destroy and delete-event signals.
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), nullptr);
    g_signal_connect(G_OBJECT(window), "delet_event", G_CALLBACK(delet_event), nullptr);

    // Create a new GtkLabel widget that is selectable.
    label = gtk_label_new("Hello World");
    gtk_label_set_selectable(GTK_LABEL(label), true);

    // Add the label as a child widget of the window.
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
// ---------------------------------------------------------------------------------------

// Stop the GTK+ main loop function when the window is destroyed.
// ---------------------------------------------------------------------------------------
static void destroy(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}
// ---------------------------------------------------------------------------------------

/* Return FALSE to destroy the widget. By returning TRUE, you can cancel
* a delete-event. This can be used to confirm quitting the application. */
// ---------------------------------------------------------------------------------------
static gboolean delet_event(GtkWidget *window, GdkEvent *event, gpointer data) {
    return FALSE;
}
// ---------------------------------------------------------------------------------------

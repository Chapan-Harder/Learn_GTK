#include "includes.h"

static void destroy(GtkWidget*, gpointer);

int main(int argc, char *argv[]){
    GtkWidget *window, *button;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Chapan Window [BUTTON]");
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    gtk_widget_set_size_request(window, 400, 200);

    g_signal_connect(GTK_WINDOW(window), "destroy", G_CALLBACK(destroy), nullptr);

    // Button Widget
    button = gtk_button_new_with_mnemonic("!EXIT!");
    gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);

    /* Connect the button to the clicked signal. The callback function recieves the
    * window followed by the button because the arguments are swapped. */
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), (gpointer) window);

    // Add the label as a child widget of the window.
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

static void destroy(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}

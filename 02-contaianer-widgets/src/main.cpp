// Import GTK
#include <gtk/gtk.h>

// Import GLIB
#include <glib.h>
#include <glib-object.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *hpaned;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *exit;
}MakeWidget;

static void destroy(GtkWidget *, gpointer);

int main(int argc, char *argv[]) {
    MakeWidget widget;
    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), "02-Window [GTK]");
    gtk_window_set_position(GTK_WINDOW(widget.window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 450, 350);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 10);

    g_signal_connect(GTK_WINDOW(widget.window), "destroy", G_CALLBACK(destroy), nullptr);

    widget.hpaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    widget.vpaned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    widget.button1 = gtk_button_new_with_label("Resize");
    widget.button2 = gtk_button_new_with_label("LOOK AT ME");
    widget.exit = gtk_button_new_with_label("-! EXIT !-");

    g_signal_connect_swapped(G_OBJECT(widget.button1), "clicked", G_CALLBACK(gtk_widget_destroy), widget.button1);
    g_signal_connect_swapped(G_OBJECT(widget.button2), "clicked", G_CALLBACK(gtk_widget_destroy), widget.button2);
    g_signal_connect_swapped(G_OBJECT(widget.exit), "clicked", G_CALLBACK(destroy), widget.window);

    /* Pack both buttons as the two children of the GtkHPaned widget. */
    gtk_paned_add1(GTK_PANED(widget.hpaned), GTK_WIDGET(widget.button1));
    gtk_paned_add2(GTK_PANED(widget.hpaned), GTK_WIDGET(widget.button2));
    
    gtk_paned_add1(GTK_PANED(widget.vpaned), GTK_WIDGET(widget.exit));
    gtk_paned_add2(GTK_PANED(widget.vpaned), GTK_WIDGET(widget.hpaned));

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vpaned));
    
    gtk_widget_set_margin_end(GTK_WIDGET(widget.button1), 5);
    gtk_widget_set_margin_start(GTK_WIDGET(widget.button2), 5);
    gtk_widget_set_margin_top(GTK_WIDGET(widget.hpaned), 5);
    gtk_paned_set_position(GTK_PANED(widget.hpaned), 120);
    gtk_paned_set_position(GTK_PANED(widget.vpaned), 70);
    
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

static void destroy(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}

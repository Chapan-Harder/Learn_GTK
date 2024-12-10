// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *check_button1;
    GtkWidget *check_button2;
    GtkWidget *close_button;
}MakeWidget;

static void check_toggled(GtkToggleButton*, GtkWidget*);

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 450, 200);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.check_button1 = gtk_check_button_new_with_label("I am the main option.");
    widget.check_button2 = gtk_check_button_new_with_label("I rely on the other guy.");

    /* Only enable the second check button when the first is enabled. */
    gtk_widget_set_sensitive(GTK_WIDGET(widget.check_button2), FALSE);
    g_signal_connect(G_OBJECT(widget.check_button1), "toggled", G_CALLBACK(check_toggled), widget.check_button2);

    widget.close_button = gtk_button_new_with_label("?!CLOSE THE WINDOW!?");
    g_signal_connect(G_OBJECT(widget.close_button), "clicked", G_CALLBACK(gtk_main_quit), widget.window);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.check_button1), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.check_button2), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.close_button), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

/* If the main check button is active, enable the other. Otherwise, disable
* the supplementary check button. */
static void check_toggled(GtkToggleButton *check_button1, GtkWidget *check_button2) {
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check_button1)))
        gtk_widget_set_sensitive(GTK_WIDGET(check_button2), TRUE);
    else
        gtk_widget_set_sensitive(GTK_WIDGET(check_button2), FALSE);
}

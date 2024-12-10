// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *toggle1;
    GtkWidget *toggle2;
}MakeWidget;

static void button_toggled(GtkToggleButton*, GtkWidget*);

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 20);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 450, 200);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    widget.toggle1 = gtk_toggle_button_new_with_mnemonic("_Deactivate the other one!");
    widget.toggle2 = gtk_toggle_button_new_with_mnemonic("_No! Deactivate that one!");

    g_signal_connect(G_OBJECT(widget.toggle1), "toggled", G_CALLBACK(button_toggled), widget.toggle2);
    g_signal_connect(G_OBJECT(widget.toggle2), "toggled", G_CALLBACK(button_toggled), widget.toggle1);

    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.toggle1), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.toggle2), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

/* If the toggle button was activated, set the other as disabled. Otherwise,
* enable the other toggle button. */
static void button_toggled(GtkToggleButton *toggle, GtkWidget *other_toggle) {
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(toggle)))
        gtk_widget_set_sensitive(GTK_WIDGET(other_toggle), FALSE);
    else
        gtk_widget_set_sensitive (other_toggle, TRUE);
}

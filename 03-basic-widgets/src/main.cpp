// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *radio_button1;
    GtkWidget *radio_button2;
    GtkWidget *radio_button3;
    GtkWidget *radio_button4;
}MakeWidget;

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 450, 400);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    widget.radio_button1 = gtk_radio_button_new_with_label(nullptr, "I want to be clicked!");
    widget.radio_button2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(widget.radio_button1), "Click me instead!");
    widget.radio_button3 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(widget.radio_button2), "NO! Click me!");
    widget.radio_button4 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(widget.radio_button3), "NO! Click me instead!");

    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.radio_button1), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.radio_button2), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.radio_button3), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.radio_button4), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}


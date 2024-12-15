// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *hbox;
}MakeWidget;

typedef struct {
    GdkColor color;
}MakeStyle;

static void color_changed(GtkColorButton*, GtkWidget*);

int main(int argc, char *argv[]) {
    MakeWidget widget;
    MakeStyle style;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 300, 100);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    /* Set the initial color as #003366 and set the dialog title. */
    gdk_color_parse("#003366", &style.color);
    widget.button = gtk_color_button_new_with_color(&style.color);
    gtk_color_button_set_title(GTK_COLOR_BUTTON(widget.button), "Select The Color");

    widget.label = gtk_label_new("Look At My Color!");
    gtk_widget_modify_fg(GTK_WIDGET(widget.label), GTK_STATE_NORMAL, &style.color);

    g_signal_connect(G_OBJECT(widget.button), "color_set", G_CALLBACK(color_changed), widget.label);

    gtk_box_pack_start(GTK_BOX(widget.hbox), GTK_WIDGET(widget.button), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.hbox), GTK_WIDGET(widget.label), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.hbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

static void color_changed(GtkColorButton *button, GtkWidget *label) {
    MakeStyle style;
    gtk_color_button_get_color(GTK_COLOR_BUTTON(button), &style.color);
    gtk_widget_modify_fg(GTK_WIDGET(label), GTK_STATE_NORMAL, &style.color);
}

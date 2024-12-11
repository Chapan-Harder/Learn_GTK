// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *spin_int;
    GtkWidget *spin_float;
    GtkWidget *vbox;
}MakeWidget;

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 150, 100);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    /* Create two new adjustments. The first spans between 0 and 10, starting at 5 and
    * moves in increments of 1. The second spans between 0 and 1, starting at 0.5 and
    * moves in increments of 0.1. */
    GtkAdjustment *integer = GTK_ADJUSTMENT(gtk_adjustment_new(5.0, 0.0, 10.0, 1.0, 2.0, 0.0));
    GtkAdjustment *float_pt = GTK_ADJUSTMENT(gtk_adjustment_new(0.5, 0.0, 1.0, 0.1, 0.2, 0.0));

    /* Create two new spin buttons. The first will display no decimal places and the
    * second will display one decimal place. */
    widget.spin_int = gtk_spin_button_new(GTK_ADJUSTMENT(integer), 1.0, 0);
    widget.spin_float = gtk_spin_button_new(GTK_ADJUSTMENT(float_pt), 0.1, 1);

    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.spin_int), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.spin_float), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

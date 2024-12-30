// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "04-Dialogs"

typedef struct {
    GtkWidget *window;
    GtkWidget *button;
}MakeBaseWindow;

typedef struct {
    GtkWidget *dialog;
    GtkWidget *label;
    GtkWidget *image;
    GtkWidget *hbox;
    GtkWidget *content_area;
}MakeDialogWindow;

static void button_clicked(GtkButton*, GtkWindow*);

int main(int argc, char *argv[]) {
    MakeBaseWindow widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 400, 350);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.button = gtk_button_new_with_mnemonic("_Click Me");

    g_signal_connect(G_OBJECT(widget.button), "clicked", G_CALLBACK(button_clicked), widget.window);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.button));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

/* Create a new GtkDialog that will tell the user that the button was clicked. */
static void button_clicked(GtkButton *buton, GtkWindow *parent) {
    MakeDialogWindow dialog_widge;

    /* Create a new dialog with one OK button. */
    dialog_widge.dialog = gtk_dialog_new_with_buttons("Information", parent, GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_OK, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(dialog_widge.dialog), 10);
    gtk_window_set_resizable(GTK_WINDOW(dialog_widge.dialog), false);

    dialog_widge.label = gtk_label_new("The button was clicked!?");
    dialog_widge.image = gtk_image_new_from_stock(GTK_STOCK_DIALOG_INFO, GTK_ICON_SIZE_DIALOG);

    dialog_widge.hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(dialog_widge.hbox), GTK_WIDGET(dialog_widge.image), true, true, 0);
    gtk_box_pack_start(GTK_BOX(dialog_widge.hbox), GTK_WIDGET(dialog_widge.label), true, true, 0);

    /* Get the dialog's content area and add the custom content to it. */
    dialog_widge.content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog_widge.dialog));
    gtk_box_pack_start(GTK_BOX(dialog_widge.content_area), GTK_WIDGET(dialog_widge.hbox), true, true, 0);
    gtk_widget_show_all(GTK_WIDGET(dialog_widge.dialog));

    /* Create the dialog as modal and destroy it when a button is clicked. */
    gtk_dialog_run(GTK_DIALOG(dialog_widge.dialog));
    gtk_widget_destroy(GTK_WIDGET(dialog_widge.dialog));
}

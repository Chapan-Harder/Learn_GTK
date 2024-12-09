// Import GTK
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *note_book;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *child1;
    GtkWidget *child2;
}MakeWidget;

static void switch_page(GtkButton*, GtkNotebook*);

int main(int argc, char *argv[]) {
    MakeWidget widget;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), "02-contaianer-widgets [NOOT_BOOK]");
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 450, 350);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.note_book = gtk_notebook_new();
    widget.label1 = gtk_label_new("Page_One");
    widget.label2 = gtk_label_new("Page_Two");
    widget.child1 = gtk_label_new("Go to page 2 to find the answer.");
    widget.child2 = gtk_label_new("Go to page 1 to find the answer.");

    /* Notice that two widgets were connected to the same callback function! */
    g_signal_connect(G_OBJECT(widget.child1), "clicked", G_CALLBACK(switch_page), widget.note_book);
    g_signal_connect(G_OBJECT(widget.child2), "clicked", G_CALLBACK(switch_page), widget.note_book);

    /* Append to pages to the notebook container. */
    gtk_notebook_append_page(GTK_NOTEBOOK(widget.note_book), GTK_WIDGET(widget.child1), GTK_WIDGET(widget.label1));
    gtk_notebook_append_page(GTK_NOTEBOOK(widget.note_book), GTK_WIDGET(widget.child2), GTK_WIDGET(widget.label2));

    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(widget.note_book), GTK_POS_BOTTOM);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.note_book));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

static void switch_page(GtkButton *button, GtkNotebook *notebook) {
    gint page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));

    if (page == 0)
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 1);
    else
        gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}

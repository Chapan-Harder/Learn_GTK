// Import GTK
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *chooser2;
    GtkWidget *chooser1;
    GtkWidget *label;
    GtkWidget *vbox;
}MakeWidget;

typedef struct {
    GtkFileFilter *filter1;
    GtkFileFilter *filter2;
}MakeFileFilter;

static void folder_changer(GtkFileChooser*, GtkFileChooser*);
static void file_changed(GtkFileChooser*, GtkLabel*);

int main(int argc, char *argv[]) {
    MakeWidget widget;
    MakeFileFilter file_filter;

    gtk_init(&argc, &argv);

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 300, 200);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.label = gtk_label_new("");

    /* Create two buttons, one to select a folder and one to select a file. */
    widget.chooser1 = gtk_file_chooser_button_new("Chooser A Folder", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
    widget.chooser2 = gtk_file_chooser_button_new("Chooser A Folder", GTK_FILE_CHOOSER_ACTION_OPEN);

    /* Monitor when the selected folder or file are changed. */
    g_signal_connect(G_OBJECT(widget.chooser1), "selection_changed", G_CALLBACK(folder_changer), widget.chooser2);
    g_signal_connect(G_OBJECT(widget.chooser2), "selection_changed", G_CALLBACK(file_changed), widget.label);

    /* Set both file chooser buttons to the location of the user's home directory. */
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(widget.chooser1), g_get_home_dir());
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(widget.chooser2), g_get_home_dir());

    /* Provide a filter to show all files and one to show only 3 types of images. */
    file_filter.filter1 = gtk_file_filter_new();
    file_filter.filter2 = gtk_file_filter_new();
    gtk_file_filter_set_name(GTK_FILE_FILTER(file_filter.filter1), "Image Files");
    gtk_file_filter_set_name(GTK_FILE_FILTER(file_filter.filter2), "All Files");
    gtk_file_filter_add_pattern(GTK_FILE_FILTER(file_filter.filter1), "*.png");
    gtk_file_filter_add_pattern(GTK_FILE_FILTER(file_filter.filter1), "*.jpg");
    gtk_file_filter_add_pattern(GTK_FILE_FILTER(file_filter.filter1), "*.gif");
    gtk_file_filter_add_pattern(GTK_FILE_FILTER(file_filter.filter2), "*");

    /* Add both the filters to the file chooser button that selects files. */
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(widget.chooser2), file_filter.filter1);
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(widget.chooser2), file_filter.filter2);

    widget.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.chooser1), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.chooser2), TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget.vbox), GTK_WIDGET(widget.label), TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.vbox));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    gtk_main();
    return 0;
}

/* When a folder is selected, use that as the new location of the other chooser. */
static void folder_changer(GtkFileChooser *chooser1, GtkFileChooser *chooser2) {
    gchar *folder = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser1));
    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser2), folder);
}

/* When a file is selected, display the full path in the GtkLabel widget. */
static void file_changed(GtkFileChooser *chooser2, GtkLabel *label) {
    gchar *file = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser2));
    gtk_label_set_text(GTK_LABEL(label), file);
}

// Import GTK
#include "glib-object.h"
#include <gtk/gtk.h>

#define TITLE_NAME "03-basic-widgets"

typedef struct {
    GtkWidget *window;
    GtkWidget *button;
}MakeWidget;

typedef struct {
    GdkRGBA fg[5];
    GdkRGBA bg[5];
    GdkRGBA light[5];
    GdkRGBA dark[5];
    GdkRGBA mid[5];
    GdkRGBA text[5];
    GdkRGBA base[5];
    GdkRGBA text_aa[5];
    GdkRGBA black, white;
    PangoFontDescription *font_desc;
    gint xthickness, ythickness;
} MakeStyle;

void apply_style(MakeWidget *widget, MakeStyle *theme) {
    // Set the background color of the window to light blue
    gtk_widget_override_background_color(widget->window, GTK_STATE_FLAG_NORMAL, &theme->bg[0]);

    // Set the background color of the button to red
    gtk_widget_override_background_color(widget->button, GTK_STATE_FLAG_NORMAL, &theme->fg[0]);

    // Set the font of the button
    gtk_widget_override_font(widget->button, theme->font_desc);
}

int main(int argc, char *argv[]) {
    MakeWidget widget;
    MakeStyle theme;

    gtk_init(&argc, &argv);

    // Initialize the style structure
    theme.bg[0] = {0.3, 0.3, 1.0, 1.0}; // Light blue background for the window
    theme.fg[0] = {0.0, 0.1, 0.2, 1.0}; // Red background for the button
    theme.font_desc = pango_font_description_from_string("Noto Serif 12"); // Font for the button

    widget.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget.window), TITLE_NAME);
    gtk_container_set_border_width(GTK_CONTAINER(widget.window), 15);
    gtk_widget_set_size_request(GTK_WIDGET(widget.window), 250, 50);

    g_signal_connect(G_OBJECT(widget.window), "destroy", G_CALLBACK(gtk_main_quit), widget.window);

    widget.button = gtk_button_new_with_label("BUTTON");

    g_signal_connect_swapped(G_OBJECT(widget.button), "clicked", G_CALLBACK(gtk_main_quit), widget.window);

    gtk_container_add(GTK_CONTAINER(widget.window), GTK_WIDGET(widget.button));
    gtk_widget_show_all(GTK_WIDGET(widget.window));

    apply_style(&widget, &theme);

    gtk_main();
    return 0;
}

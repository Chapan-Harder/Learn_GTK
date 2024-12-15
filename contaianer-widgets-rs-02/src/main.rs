use ::gtk::{glib, prelude::*, Application, ApplicationWindow, Box, Button};
// use glib::clone;

const TITLE_WINDOW: &str = r#"contaianer-widgets-rs-02"#;
const APP_ID: &str = r#"ir.app"#;

const NAMES: [&str; 4] = ["Andrew", "Joe", "Samantha", "Jonathan"];

struct MakeWidget {
    window: ApplicationWindow,
    vbox: Box,
    button: Button,
}

fn ui_app(app: &Application) {
    let widget: MakeWidget = MakeWidget {
        window: ApplicationWindow::new(app),
        vbox: Box::new(gtk::Orientation::Vertical, 0),
        button: Button::new(),
    };

    widget.window.set_title(Some(TITLE_WINDOW));
    widget.window.set_default_size(300, 200);

    for i in 0..=3 {
        widget.button.set_label(NAMES[i]);
        widget.vbox.append(&widget.button);

        widget.button.connect_destroy(Some(&widget.button));
    }

    widget.window.present();
}

fn main() {
    let app: Application = Application::builder().application_id(APP_ID).build();

    app.connect_activate(|app| {
        ui_app(&app);
    });

    app.run();
}

use gtk::{glib, prelude::*, Application, ApplicationWindow, Box as GtkBox, Button};

const TITLE_WINDOW: &str = r#"container-widgets-rs-02"#;
const APP_ID: &str = r#"ir.app"#;

const NAMES: [&str; 4] = ["Andrew", "Joe", "Samantha", "Jonathan"];

fn ui_app(app: &Application) {
    let window = ApplicationWindow::new(app);
    let vbox = GtkBox::new(gtk::Orientation::Vertical, 0);

    window.set_title(Some(TITLE_WINDOW));
    window.set_size_request(300, 200);

    for i in NAMES.iter() {
        let button = Button::with_label(i);
        button.set_hexpand_set(true);
        button.set_vexpand(true);
        vbox.append(&button);

        let button_clone = button.clone();
        button.connect_clicked(move |_| {
            button_clone.unparent();
        });
    }

    window.set_child(Some(&vbox));
    window.present();
}

fn main() {
    let app = Application::builder().application_id(APP_ID).build();

    app.connect_activate(|app| {
        ui_app(app);
    });

    app.run();
}

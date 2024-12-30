use glib::clone;
use gtk::{glib, prelude::*, Application, ApplicationWindow, Button};

const TITLE_WINDOW: &str = r#"first-applications-rs-01"#;
const APP_ID: &str = r#"ir.app"#;

struct MakeWidget {
    window: ApplicationWindow,
    button: Button,
}

fn ui_app(app: &Application) {
    let widget: MakeWidget = MakeWidget {
        window: ApplicationWindow::new(app),
        button: Button::new(),
    };

    widget.window.set_title(Some(TITLE_WINDOW));
    widget.window.set_size_request(300, 200);

    widget.button.set_label("EXIT_BUTTON");
    widget.button.set_margin_top(15);
    widget.button.set_margin_bottom(15);
    widget.button.set_margin_start(15);
    widget.button.set_margin_end(15);

    let window_clone: ApplicationWindow = widget.window.clone();
    widget
        .button
        .connect_clicked(clone!(@weak window_clone => move |_| window_clone.close();));

    widget.window.set_child(Some(&widget.button));
    widget.window.present();
}

fn main() {
    let app: Application = Application::builder().application_id(APP_ID).build();

    app.connect_activate(|app| {
        ui_app(&app);
    });

    app.run();
}

use std::rc::Rc;

use glib::clone;
use gtk::{glib, prelude::*, Application, ApplicationWindow, Box, Button};

const TITLE: &str = r#"first-applications-rs-01"#;
const APP_ID: &str = r#"ir.app"#;

struct MakeWidget {
    window: Rc<ApplicationWindow>,
    vbox: Rc<Box>,
    button: Rc<Button>,
}

fn ui_section(app: &Application) -> MakeWidget {
    let window: ApplicationWindow = ApplicationWindow::builder()
        .application(app)
        .title(TITLE)
        .default_width(400)
        .default_height(200)
        .build();

    let vbox: Box = Box::builder()
        .orientation(gtk::Orientation::Vertical)
        .spacing(10)
        .build();

    let button: Button = Button::builder().label("EXIT BUTTON").build();

    button.connect_clicked(clone!(@weak window => move |_| window.close()));

    vbox.append(&button);
    window.set_child(Some(&vbox));

    window.present();

    return MakeWidget {
        window: Rc::new(window),
        vbox: Rc::new(vbox),
        button: Rc::new(button),
    };
}

fn main() {
    let app: Application = Application::builder().application_id(APP_ID).build();

    app.connect_activate(|app| {
        ui_section(app);
    });
    app.run();
}

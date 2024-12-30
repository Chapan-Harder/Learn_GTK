use gtk::{/*glib,*/ prelude::*, Application, ApplicationWindow, Button, Paned};

const TITLE_WINDOW: &str = r#"container-widgets-rs-02"#;
const APP_ID: &str = r#"ir.app"#;

fn ui_app(app: &Application) {
    let window: ApplicationWindow = ApplicationWindow::new(app);
    window.set_title(Some(TITLE_WINDOW));
    window.set_default_size(350, 450);

    let hpaned: Paned = Paned::new(gtk::Orientation::Horizontal);
    let button1: Button = Button::with_label("peress me");
    let button2: Button = Button::with_label("resize me");

    let button1_clone = button1.clone();
    button1.connect_clicked(move |_| {
        button1_clone.unparent();
    });
    let button2_clone = button2.clone();
    button2.connect_clicked(move |_| {
        button2_clone.unparent();
    });

    hpaned.set_start_child(Some(&button1));
    hpaned.set_end_child(Some(&button2));

    window.set_child(Some(&hpaned));
    window.present();
}

fn main() {
    let app: Application = Application::builder().application_id(APP_ID).build();

    app.connect_activate(|app| {
        ui_app(app);
    });

    app.run();
}

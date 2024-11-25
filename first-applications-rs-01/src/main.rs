use gtk::{glib, Application, ApplicationWindow};
use gtk::{prelude::*, Button};

const APP_ID: &str = r#"ir.chapan_window"#;

fn main() -> glib::ExitCode {
    // Create a new application
    let app: Application = Application::builder().application_id(APP_ID).build();

    app.connect_activate(window_ui);

    return app.run();
}

fn window_ui(app: &Application) {
    // Create a button with label and margins
    let button: Button = Button::builder()
        .label("Press Me!")
        .margin_top(50)
        .margin_bottom(50)
        .margin_start(50)
        .margin_end(50)
        .build();

    // Connect to "clicked" signal of `button`
    button.connect_clicked(|button: &Button| {
        // Set the label to "Hello World!" after the button has been clicked on
        button.set_label("You Press ME! Why?");
    });

    // Create a window and set the title
    let window: ApplicationWindow = ApplicationWindow::builder()
        .application(app)
        .title("GTK_WITH_RUST")
        .child(&button)
        .default_width(400)
        .default_height(200)
        .build();

    // Present window
    window.present();
}

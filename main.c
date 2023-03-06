
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <gtk/gtk.h>

static void
activate (GtkApplication* app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *EnterUserLabel;
	GtkWidget *EnterPasswordLabel;
	GtkWidget *vbox;
	GtkWidget *UserEntry;
	GtkWidget *PasswordEntry;

	//creating the widgets
	window = gtk_application_window_new (app);
	button = gtk_button_new_with_label ("Click");
	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
	EnterUserLabel = gtk_label_new ("Enter your username");
	EnterPasswordLabel = gtk_label_new("Enter your password");
	UserEntry = gtk_entry_new ();
	PasswordEntry = gtk_entry_new ();
	
	//packing the widgets
	gtk_box_pack_start (GTK_BOX (vbox), EnterUserLabel, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), UserEntry, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), EnterPasswordLabel, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), PasswordEntry, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);
	//setting the window
  	gtk_window_set_title (GTK_WINDOW (window), "Chat app Login Form");
  	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	

  	gtk_widget_show_all (window);

}

int main(int argc, char *argv[]) {
	GtkApplication *app;	
	int status;
	
	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}

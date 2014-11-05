#include <gtk/gtk.h>


void destroy(GtkWidget *widget,gpointer data)
{
	gtk_main_quit();
}


int main(int argc, char  *argv[])
{
	GtkWidget  *window;
	GtkWidget  *label;

	gtk_init(&argc,&argv);

	//create the main,top level,window
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	//give it the title
	gtk_window_set_title(GTK_WINDOW(window),"Hello world");


	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	label=gtk_label_new("Hello,world!");

	gtk_container_add(GTK_CONTAINER(window),label);

	gtk_widget_show_all(window);

	gtk_main();


	return 0;
}
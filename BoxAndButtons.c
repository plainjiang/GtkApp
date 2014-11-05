#include <gtk/gtk.h>

/*function callback_1*/
void callback(GtkWidget *widget,gpointer data)
{
	g_print("Hello !%s was pressed\n",(gchar *)data);
}

/*function callback_2*/
gint delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
	gtk_main_quit();
	return FALSE;

}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box1;


	/*gtk_init() exists in every GTK program*/
	gtk_init(&argc,&argv);

	/*create a new window*/
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	
	/*set the title of this window as "Hello buttons!"*/
	gtk_window_set_title(GTK_WINDOW(window),"Hello buttons!");

	
	/*set a manipulation function for delete_event*/
	g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(delete_event),NULL);

	/*set  border width of container*/
	gtk_container_set_border_width(GTK_CONTAINER(window),10);

	/*package box for arranging widgets*/
	box1=gtk_hbox_new(FALSE,0);

	/*put box into window*/
	gtk_container_add(GTK_CONTAINER(window),box1);
	
	/*create a new button*/
	button=gtk_button_new_with_label("Button1");

	/*invoke function "callback" when the button is pressed*/
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(callback),"button1");
	
	
	/*put the button into package box,which is already in window*/
	gtk_box_pack_start(GTK_BOX(box1),button,TRUE,TRUE,0);

	/*show button*/
	gtk_widget_show(button);


	/*create and set the second button  using similar way*/
	button=gtk_button_new_with_label("Button2");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(callback),"button2");
	gtk_box_pack_start(GTK_BOX(box1),button,TRUE,TRUE,0);
	gtk_widget_show(button);

	/*show box*/
	gtk_widget_show(box1);
	
	/*show window*/
	gtk_widget_show(window);

	/*program will wait for happening of events here */
	gtk_main();

	return 0;
}


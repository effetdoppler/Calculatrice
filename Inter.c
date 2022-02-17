#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "parse.h"

long long a = 0;
long long b;
long long resultat;
long long stockage;
char Buffer[100];
char res[100];
int last;

GtkWidget *window;
GtkLabel *mylabel;

int main(int argc, char * argv[])
{
	GtkBuilder *builder;
	gtk_init(&argc,&argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder,"Interface_save.glade",NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder,"Interface"));
	mylabel = GTK_LABEL(gtk_builder_get_object(builder,"Resultat"));

	gtk_builder_connect_signals(builder,NULL);
	g_object_unref(builder);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;

}

void exit_app()
{
	gtk_main_quit();
}

void Button0()
{
	if (a != 0)
	{
		last = '0';
		//a *= 10;
		strcat(Buffer,"0");
		gtk_label_set_text(mylabel,Buffer);
	}
}

void Button1()
{
	last = '1';
	//a = a*10 + 1;
	strcat(Buffer,"1");
	gtk_label_set_text(mylabel,Buffer);
}

void Button2()
{
	last = '2';
	//a = a*10 +2;
	strcat(Buffer,"2");
	gtk_label_set_text(mylabel,Buffer);
}

void Button3()
{
	last = '3';
	//a = a*10 + 3;
	strcat(Buffer,"3");
	gtk_label_set_text(mylabel,Buffer);
}

void Button4()
{
	last = '4';
	//a = a*10+4;
	strcat(Buffer,"4");
	gtk_label_set_text(mylabel,Buffer);
}

void Button5()
{
	last = '5';
	//a = a*10 + 5;
	strcat(Buffer,"5");
	gtk_label_set_text(mylabel,Buffer);
}

void Button6()
{
	last = '6';
	//a = a*10 + 6;
	strcat(Buffer,"6");
	gtk_label_set_text(mylabel,Buffer);
}

void Button7()
{
	last = '7';
	//a = a*10 + 7;
	strcat(Buffer,"7");
	gtk_label_set_text(mylabel,Buffer);
}

void Button8()
{
	last = '8';
	//a = a*10 + 8;
	strcat(Buffer,"8");
	gtk_label_set_text(mylabel,Buffer);
}


void Button9()
{
	last = '9';
	a = a*10 + 9;
	strcat(Buffer,"9");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonPlus()
{
	last = '1';
	strcat(Buffer," + ");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonMinus()
{
	last = '-';
	strcat(Buffer," - ");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonMultiple()
{
	last = '*';
	strcat(Buffer," * ");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonDivide()
{
	last = '/';
	strcat(Buffer," / ");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonReset()
{
	stockage = resultat;
	resultat = 0;
	a = 0;
	b = 0;
	Buffer[0] = '\0';
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonReturn()
{
	char *lastchar;
	if (last != 10)
	{
		lastchar = strrchr(Buffer,last);
	}
	*lastchar = '\0';
	lastchar--;
	last = 10;

	gtk_label_set_text(mylabel,Buffer);
}

	

void ButtonR_P()
{
	last = ')';
	strcat(Buffer,")");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonL_P()
{
	last = '(';
	strcat(Buffer,"(");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonEqual()
{
	resultat = parse_char(Buffer);
	sprintf(res, "%lld", resultat);
	gtk_label_set_text(mylabel,res);

	Buffer[0] = '\0';
	a = 0;
	b = 0;
	resultat;
}

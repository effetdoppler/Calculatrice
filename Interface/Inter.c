#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "../lib/parser2.h"

long long a = 0;
long long b;
char Buffer[100];
char res[100];
int last;

GtkWidget *window;
GtkWidget *windowFunction;
GtkLabel *mylabel;

int windowfun_open = 0;

int main(int argc, char * argv[])
{
	GtkBuilder *builder;
	gtk_init(&argc,&argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder,"Interface_save.glade",NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder,"Interface"));
	mylabel = GTK_LABEL(gtk_builder_get_object(builder,"Resultat"));
	windowFunction = GTK_WIDGET(gtk_builder_get_object(builder,"Fonction"));

	gtk_builder_connect_signals(builder,NULL);
	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

}


void suppression()
{
	
	char *lastchar;

	lastchar = strrchr(Buffer,last);

	if (lastchar != NULL)
	{
		//if (last > '0' && last < '9')
		//{
			*lastchar = '\0';
			lastchar--;
			
		//}
		/*else
		{
			int c = 3;
			while (c > 0)
			{
				last = ' ';
				lastchar = strrchr(Buffer,last);
				*lastchar = '\0';
				lastchar--;
				c--;
			}
		}*/
		last = *lastchar;
	}
}


void exit_app()
{
	gtk_main_quit();
}

void Button0()
{
	last = '0';
	//a *= 10;
	strcat(Buffer,"0");
	gtk_label_set_text(mylabel,Buffer);
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
	//a = a*10 + 9;
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
	a = 0;
	b = 0;
	Buffer[0] = '\0';
	gtk_label_set_text(mylabel,Buffer);
}

void Buttoncos()
{
	last = 'c';
	strcat(Buffer,"cos(");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonsin()
{
	last = 's';
	strcat(Buffer,"sin(");
	gtk_label_set_text(mylabel,Buffer);
}

void buttonpow()
{
	last = '^';
	strcat(Buffer,"^");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonexp()
{
	last = 'e';
	strcat(Buffer,"exp(");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonln()
{
	last = 'l';
	strcat(Buffer,"log(");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonpi()
{
	last = 'π';
	strcat(Buffer,"π");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonpow()
{
	last = '^';
	strcat(Buffer,"^");
	gtk_label_set_text(mylabel,Buffer);
}

void Buttonvirgule()
{
	last = ',';
	strcat(Buffer,",");
	gtk_label_set_text(mylabel,Buffer);
}

void ButtonReturn()
{
	char *lastchar;

	if (last == 'c' || last == 's' || last == 'e' || last == 'l')
	{
		last = '(';
		for (int i = 0; i < 4; i++)
			suppression();
	}

	else
	{
		suppression();
	}

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

void ButtonOperation()
{

	if (windowfun_open == 0)
	{
		gtk_widget_show(windowFunction);
		windowfun_open = 1;
	}
	else
	{
		gtk_widget_hide(windowFunction);
		windowfun_open = 0;
	}
}


void ButtonEqual()
{
	printf("%s\n", Buffer);
	double a = parse_char(Buffer);
	double b = parse_char("3,3");
	printf ("%.6g\n", a);
	printf ("%.6g\n", b);
	Result resultat = calculate_char(Buffer);
	printf("%f\n",resultat.value);
	if (resultat.err == NULL)
		sprintf(res, "%.6g", resultat.value);
	else
	    sprintf(res, "%s", resultat.err);


	printf("%f\n",resultat.value);
	printf("%s\n",res);

	gtk_label_set_text(mylabel,res);

	Buffer[0] = '\0';
	a = 0;
	b = 0;
}

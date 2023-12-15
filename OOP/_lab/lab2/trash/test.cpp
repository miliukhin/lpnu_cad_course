Student (double av_mark_,   double ex_mark_,
char * name_ = "Noname" );
…
};

// Визначення конструктору класу
Student :: Student (double av_mark_,

double ex_mark_, char * name_)
{
	av_mark = av_mark_;
	ex_mark = ex_mark_;
	strncpy (name, name_, sizeof(name));
	name [sizeof(name)-1] = '\0';
	cout << "Create Student " << name << endl;
}

char c;
while ((c = fin.get ())! = EOF)
if (c == '$')
break;

// читання по рядках

while (! fin.eof ())
{
fin.getline (s, 80);  ... // обробка рядка; 2-гий арг --- довжина
}

// кілька режимів
ofstream fout ("myfile.txt",
ios :: out | ios :: app);

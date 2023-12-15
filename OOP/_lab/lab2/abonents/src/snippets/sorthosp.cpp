	bool sorted;
	for (int i = 0; i < real_size; i++) {
		sorted = true;
		for (int j = 0; j < real_size - i - 1; j++) {
			char * lname_1 = abonents[j].getLname();
			char * lname_2 = abonents[j+1].getLname();
			std::cout << lname_1;
			std::cout << lname_2;
			for (int k = 0; k < N - k; k++) {
			if (lname_1[k] > lname_2[k])
			{
				Abonent temp_abonent = abonents[j];
				abonents[j] = abonents[j+1];
				abonents[j+1] = temp_abonent;
				sorted = false;
			}
			}
		}
		if (sorted)
			return;
	}

void removeNonTwinSTL(list<unsigned long int>* numList)
{
	list<unsigned long int>::iterator previt;
	list<unsigned long int>::iterator currit;
	unsigned long int prev = 0, curr = 0;
	unsigned long int temp = 0;
	bool prevTwin = false;
	bool currTwin = false;
	previt = numList.begin();
	currit = numList.begin();
	currit++;
	prev = *previt;
	curr = *currit;
	previt++;
	currit++;
	while (curr != 0)
	{
		if ((curr - prev != 2) && (prevTwin == false))
		{
			numList.remove(prev);
		}
		else if ((curr - prev == 2))
		{
			prevTwin = true;
			currTwin = true;
		}
		prev = *previt;
		previt++;
		curr = *currit;;
		currit++;

		prevTwin = currTwin;
		currTwin = false;
	}
	if (!prevTwin)
	{
		numList->Remove(prev);
	}
}

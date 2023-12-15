void InsertionSort (int* aTablycia, unsigned uRozmir)
{
unsigned i, j;
int nElement;
// зовнішній цикл, який вибирає по черзі кожний елемент
// (почавши від другого, того, що з індексом 1)
for (i = 1; i < uRozmir; ++i)
{
nElement = aTablycia[i];
// внутрішній цикл має завданням створити місце для
// нашого елементу
for (j = i - 1; i >= 0 && aTablycia[j] > nElement; --j)
// робить це, пересуваючи елементи вперед
	aTablycia[j + 1] = aTablycia[j];
// а коли він вже є, потрібно записати елемент в цьому місці
aTablycia[j + 1] = nElement;
}
}

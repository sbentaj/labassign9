#include <stdio.h>
#include <stdlib.h>

// RecordType
struct RecordType
{
	int	id;
	char	name;
	int	order; 
};

// Fill out this structure
struct HashType
{
	struct RecordType *pData;
	int count;
};

// Compute the hash function
int hash(int x)
{
	return x % hashSz;
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i, j;
	struct RecordType *pRecord;

	for (i=0; i < hashSz; ++i)
	{
		if(pHashArray[i].count > 0)
		{
			printf("Index %d -> ", i);
			pRecord = pHashArray[i].pData;
			for(j = 0; j < pHashArray[i].count; ++j)
			{
				printf("%d %c %d -> ", pRecord[j].id, pRecord[j].name, pRecord[j].order);
				if (j < pHashArray[i].count - 1)
					printf(" -> ");
			}
			printf("\n");
		}
	}
}

int main(void)
{
	struct RecordType *pRecords;
	struct HashType *pHashTable;
	
	int recordSz = 0;
	int hashSz = 10;
	int i, hashindx;
	
	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);
	// Your hash implementation
	
	for (int i = 0; i < recordSz; i++)
	{
		insertRecord(hashTable, pRecords[i]);
	}
			
	return 0;
			       
}









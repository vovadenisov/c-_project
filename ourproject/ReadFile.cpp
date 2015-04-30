#include "ReadFile.h"
#include <fstream>

map<string, map<string, form> >* read_file(char *file_name){
    ifstream pFile;
    pFile.open(file_name);

    if (pFile == NULL)
    {
        perror ("Error opening file");
        return false;
    }
    map<string, map<string, form> > * arr;
    arr = new map<string, map<string, form> >;
    size_t modulSize;
    pFile >> modulSize;
    for (int i = 0; i < modulSize; i++){
        string modName;
        pFile >> modName;
        int size;
        pFile >> size;
        for (int j = 0; j < size; j++){
            string elName;
            pFile >> elName;
            pFile >> (*arr)[modName][elName].x;
            pFile >> (*arr)[modName][elName].y;
            pFile >> (*arr)[modName][elName].path;
        }
    }
    pFile.close();

    return arr;
}


//form* read_file(char *file_name, int& size)
//{
//    ifstream pFile;
//    pFile.open(file_name);
//    form item;

//    if (pFile == NULL)
//    {
//        perror ("Error opening file");
//        return false;
//    }

//    /*if (fscanf(pFile, "%d\n", &size))
//	{
//		printf("total images = %d\n", size);
//	}else{
//        printf("text format is incorrect!\n");
//		fclose(pFile);
//		return NULL;
//    }*/


//    pFile >> size;
//    form* positionList = new form[size];
//    int i = 0;
//    for (int j = 0; j < size; j++){
//        pFile >> positionList[j].x;
//        pFile >> positionList[j].y;
//        pFile >> positionList[j].path;
//    }
//    /*
//	while(!feof(pFile))
//    {
//        if (fscanf(pFile, "%d %d ", &positionList[i].x, &positionList[i].y))
//		{
//			int j = 0;
//			char c = 0;
//			while (true)
//			{
//				c = fgetc(pFile);
//				if (c == '\n' || c == EOF)
//				{
//					positionList[i].path[j] = '\0';
//					break;
//				}
//				positionList[i].path[j++] = c;
//			}
//			//printf("%d %d %s\n", positionList[i].X, positionList[i].Y, positionList[i].path);
//			++i;
//		}else{
//            //printf("text format is incorrect!\n");
//			fclose(pFile);
//			return false;
//		}
//    }
//*/
//    pFile.close();

//	return positionList;
//}

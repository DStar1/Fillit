#include "fillit.h"

char **convert_to_letts(char **src, int tet_nubr_npie)
{
	char **str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = src;
	//str = (char*)malloc((char_size + 1) * sizeof(char));
	while (str[i] != '\0')
	{
	    j = 0;
	    while(str[i][j] != '\0')
	    {
    		if (str[i][j] == '#')
    		{
    			str[i][j] = tet_nubr_npie + 'A';
    		}
    		j++;
	    }
	    i++;
	}
	return (str);
}

char **create_new_box(int size) //change all size to *size when done
{
	//size starts as 4(or 21) and is changed everytime it needs more
	int char_size;
	char **nbox;
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	char_size = size + 3; //adjusts size variable being under 4
	nbox = (char**)malloc((char_size + 1) * sizeof(char*)); //not  sure if supposed to protect this
	while (i < char_size)
		nbox[i++] = ft_strnew(char_size);
	i = 0;
	while (i < char_size)
	{
		j = 0;
		while (j < char_size)
			nbox[i][j++] = '.';
		nbox[i][j] = '\0';
		i++;
	}
	nbox[i] = (char*)malloc(sizeof(char)); //not  sure if supposed to protect this
	nbox[i] = NULL;
	return(nbox);
} //how to free() old 2d array(linked list?, pass back the 2d array and free()?)

/*
** int array is the struct the has the coordinates for the peice that looks like this
** {0, 2}
** {1, 2}
** {2, 2}
** {3, 2}
** navigate by checking the first value as x and the second value as y
*/

int check_if_possible(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int i;
	int x1;
	int y1;

	i = 0;
	//if i = 0 && x1 == 3 && y1 == 3(box_size)
	while (i < 4)
	{
		x1 = x;
		y1 = y;
	
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
			//printf("(%d, %d)", x1, y1);
		if (x1 > 3 || y1 > 3 || two_d_arr[y1][x1] != '.') 	{printf("|");//for testing
			return (0);}
// 		//if (i = 0 && x1 == 3 && y1 == 3)// || ((x1 == 3 && y1 >= 3) || (y1 == 3 && x1 >= 3)))
// 		    //return 0;
		printf("(%d, %d)", x1, y1);
		i++;
	}
	printf("/ ");
	return (1);
}

//added place
char **place(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int i;
	int x1;
	int y1;
	char **two_d_fin;

	i = 0;
	two_d_fin = two_d_arr;
	while (i < 4)
	{
		x1 = x;
		y1 = y;
	
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
		two_d_fin[y1][x1] = '#';
		i++;
	}
	return (two_d_fin);
}


char **backtrack(char **two_d_arr, int box_size, int ***three_d, int tet_cnt, int tet_nbr_npie) //maybe pass size as an int pointer
{
	//int box_size;
	//int tet_cnt; //tet_cnt should start at 0 for the place_piece function
	int j;
	int i;
    int int_arr;
    //int **two_d_int_arr;
    char **two_d_fin;
    //int ***three_d;

	j = 0;
	i = 0;
    int_arr = 0;
    two_d_fin = two_d_arr;
		while (j < box_size + 3) //adds three to get to 4 fo rthe 4x4 array
		{
		    i = 0;
			while (i < box_size + 3)
			{
				if ((check_if_possible(three_d[tet_cnt], two_d_fin, j, i)) && (j != box_size+2 && i != box_size+2))
				{
					printf("place\n");//place_piece //use convert_to_letts(two_d_arr, tet_cnt)
					//if (tet_cnt < tet_nbr_npie){
					    two_d_fin = convert_to_letts((place(three_d[tet_cnt], two_d_fin, j, i)), tet_cnt);
					    ft_putarr(two_d_fin);
					    printf("\nx%d, y%d), ", j, i);
					    tet_cnt++;
					//}
																										// if (tet_cnt < tet_nbr_npie){
																										// 	backtrack(two_d_fin, box_size, three_d, tet_cnt++, tet_nbr_npie);
																										// 	return (two_d_arr);
																										// }
																										// else
																										// {
																										// 	printf("place\n");//place_piece //use convert_to_letts(two_d_arr, tet_cnt)
																										// 	two_d_fin = convert_to_letts((place(three_d[tet_cnt], two_d_fin, j, i)), tet_cnt);
																										//     ft_putarr(two_d_fin);
																										// 	tet_cnt++;
																										// }
					if (tet_cnt - 1 >= tet_nbr_npie)
					{
						backtrack(two_d_fin, box_size, three_d, tet_cnt++, tet_nbr_npie);
						printf("finished\n"); //print/store result
						return (two_d_fin);
					}
					//else//two_d_fin = convert_to_letts((place(three_d[tet_cnt], two_d_fin, x, y)), tet_nbr_npie);
					    //{backtrack(two_d_fin, box_size, three_d, tet_cnt++, tet_nbr_npie); printf("backtrack, ");} //tet_cnt--?
				}
				i++;
			}
			j++;
		}
		return (NULL); //if no solution found
//		box_size++;
//	}
}

char **solver(int ***three_d_int_arr, int tet_nbr_npie)
{
	int box_size;
	int tet_cnt;
	char **two_d_arr;

	box_size = 1;
	tet_cnt = 0;
	two_d_arr = create_new_box(box_size);
// 	while (backtrack(two_d_arr, box_size, three_d_int_arr, tet_cnt, tet_nbr_npie) == NULL)
// 	{
//     tet_cnt = 0; //sets tet_cnt back to the start
// 		box_size++; //increases box size
// 		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say *box_size = 1;
// 	}
	return (backtrack(two_d_arr, box_size, three_d_int_arr, tet_cnt, tet_nbr_npie)); //returns first result that is a solution. Possibly store in a struct to find the right one
}

// int main()
// {
//  int three_d_int_arr[3][4][2] = {
// 			{{0,0}, {1, 0}, {2, 0}, {2, 1}},
// 			{{0,0}, {1, 0}, {2, 0}, {3, 0}},
// 			{{0,0}, {1, 0}, {0, 1}, {1, 1}},
// 		};
// 		//printf("%d", three_d_int_arr[0][1][0]);
// 		char **str = solver(three_d_int_arr, 3);

// 		int i = 0;
//     	while (str[i])
//     	{
//     		printf(str[i]);
//     		printf("\n");
//     		i++;
//     	}
//     		return 0;
// }
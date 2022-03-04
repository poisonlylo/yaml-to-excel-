#include <stdio.h>
#include "xlsxwriter.h"

/* Some data we want to write to the worksheet. */
struct expense {
    char tache[32];
    char entrepot[255];
    lxw_datetime datetime;
}expenses[];

    /*
        struct expense expenses[] = {
            {"tache___1", { .year = 2013, .month = 1, .day = 13 } },
            {"tache___2", { .year = 2013, .month = 1, .day = 14 } },
            {"tache___3", { .year = 2013, .month = 1, .day = 16 } },
            {"tache___4", { .year = 2013, .month = 1, .day = 20 } },
        };
     */

void parser(*file_name){
    FILE  *ptr ;
    int day,month,year;
    ptr = fopen(file_name,"r+");
    while (!feof(ptr)) {
        fscanf(ptr,"%d/%d/%d "
                   "entrepots : %s "
                    "tache : %s",&day,&month,&year,&expenses->entrepot, &expenses->tache);
    }
    printf("%d\n", year);
    printf("%s\n", expenses->entrepot);
    printf("%s", expenses->tache);

    fclose (ptr);

}
int main() {
char yaml_files[2][255] = {"local2.yaml", "local3.yaml"} ;
    for(int i=0; i<2; i++){
    //parser(yaml_files[i]);
        printf("%s", yaml_files[0]);
    }
    /* Create a workbook and add a worksheet. */
    lxw_workbook  *workbook  = workbook_new("tutorial03.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 0;
    int col = 0;
    int i;

    /* Add a bold format to use to highlight cells. */
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);


    /* Add an Excel date format. */
    lxw_format *date_format = workbook_add_format(workbook);
    format_set_num_format(date_format, "mmmm d yyyy");

    /* Adjust the column width. */
    worksheet_set_column(worksheet, 0, 0, 15, NULL);

    /* Write some data header. */
    worksheet_write_string(worksheet, row, col,     "Tache", bold);
    worksheet_write_string(worksheet, row, col + 1, "Date", bold);
    worksheet_write_string(worksheet, row, col + 2,     "Entrepot", bold);

    /* Iterate over the data and write it out element by element. */
    for (i = 0; i < 4; i++) {
        /* Write from the first cell below the headers. */
        row = i + 1;
        worksheet_write_string  (worksheet, row, col,      expenses[i].tache,     NULL);

        worksheet_write_datetime(worksheet, row, col + 1, &expenses[i].datetime, date_format);
        worksheet_write_string  (worksheet, row, col + 2,      expenses[i].entrepot,     NULL);

    }
    /* Save the workbook and free any allocated memory. */
    return workbook_close(workbook);
      }






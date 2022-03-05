#include <stdio.h>
#include "xlsxwriter.h"
 #include "yaml.h"

/* Some data we want to write to the worksheet. */
struct expense {
    char tache[32];
    char entrepot[255];
    int sales;
    lxw_datetime datetime;
}expenses[3];


void parser(){

    FILE  *ptr ;
    int day,month,year;

        char yaml_files[3][255] = {"site1.yaml" , "site2.yaml" , "site3.yaml"} ;

        for (int i; i<3; i++ ){
            ptr = fopen(yaml_files[i],"r+");
            while (!feof(ptr)) {
                fscanf(ptr,"date: %d/%d/%d "
                           "local: %s "
                           "task: %s "
                           "sales: %d "
                           ,&expenses[i].datetime.day, &expenses[i].datetime.month, &expenses[i].datetime.year, expenses[i].entrepot, expenses[i].tache, &expenses[i].sales );
            }
            fclose (ptr);
        }
        printf("%d-%d-%d\n", day, month, year);
        printf("%s\n", expenses[1].entrepot);
        printf("%s\n", expenses[1].tache);
        printf("%d\n", expenses[1].sales);

}

int main() {

//    char yaml_files[3][255] = {"site1.yaml" , "site2.yaml" , "site3.yaml"} ;
  //  for( i=0; i<3; i++){
        parser();
  //  }


    /* Create a workbook and add a worksheet. */
    lxw_workbook  *workbook  = workbook_new("excel_file.xlsx");
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
    worksheet_set_column(worksheet, 0, 0, 18, NULL);

    /* Write some data header. */
    worksheet_write_string(worksheet, row, col, "Date", bold);
    worksheet_write_string(worksheet, row, col + 1,"Entrepot", bold);
    worksheet_write_string(worksheet, row, col + 2,"Tache", bold);
    worksheet_write_string(worksheet, row, col + 3,"Sales", bold);


    /* Iterate over the data and write it out element by element. */
    for (i = 0; i < 3; i++) {
        /* Write from the first cell below the headers. */
        row = i + 1;
        worksheet_write_datetime(worksheet, row, col, &expenses[i].datetime, date_format);
        worksheet_write_string  (worksheet, row, col + 1,expenses[i].entrepot,     NULL);
        worksheet_write_string  (worksheet, row, col + 2,expenses[i].tache,     NULL);
        worksheet_write_number (worksheet, row, col + 3,expenses[i].sales,     NULL);

    }
    /* Save the workbook and free any allocated memory. */
    return workbook_close(workbook);
      }






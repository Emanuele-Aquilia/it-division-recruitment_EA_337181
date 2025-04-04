/* Includes ------------------------------------------------------------------*/
#include "app_gnss.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo.h"



/* Private variables ---------------------------------------------------------*/
static GNSSParser_Data_t GNSSParser_Data;

/* USER CODE BEGIN PV */    //Insert code if necessary

/* USER CODE END PV */




/* Private Functions ---------------------------------------------------------*/



/**	
 * @brief  This function must return a random integer between 0 and the maximum value for an 8-bit integer unsigned (Big Endian representation)
 * @retval an 8-bit integer unsigned value in a 32-bit integer unsigned variable.
 */
static uint32_t getValue() {
    
    /* USER CODE BEGIN 1 */     //Insert code if necessary
    uint8_t LSB;
    LSB = rand() % 256;
    return uint32_t(LSB); //return LSB; the conversion in C automaticaly ADD '0' to the left of the LSB to make it 32 bits.


    //one other implementation of the function could be:
    //uint32_t res = 0;
    //res = res + LSB;
    //return res;
    /* USER CODE END 1 */

}



/**	
 * @brief  This function must check with bit wise operation the content of the variable value and perform
 * the corrispondent actions described in the README.md
 * @param  args generic arguments
 */

void task(void *args){

    uint32_t value;

    /* USER CODE BEGIN 1 */     //Insert code if necessary
    Queue *queue_gpgga = create_queue(10, GPGGA_Info_t);
    Queue *queue_gns = create_queue(10, GNS_Info_t);
    Queue *queue_gprmc = create_queue(10, GPRMC_Info_t);

    /* USER CODE END 1 */

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN 2 */     //Insert code if necessary

    /* Initialization of the Parser*/
    if(GNSS_PARSER_Init(&GNSSParser_Data) != GNSS_PARSER_OK) {
        printf("Error in GNSS_PARSER_Init\n");
        return 1;
    }
    /* USER CODE END 2 */

    while(1){

        value = getValue();
        /* USER CODE BEGIN WHILE */     //Insert code if necessary
        if(value & 0x04) {
            if(GNSS_PARSER_ParseMsg(&GNSSParser_Data, GPGGA) != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_ParseMsg\n");
            } else {
            if(GNSS_PARSER_Print(&GNSSParser_Data, GPGGA) != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_Print\n");
                } else {
                    enqueue(queue_gpgga, &GNSSParser_Data.gpgga_data);
                }
            }
        } 
        else if(value & 0x02) {
            if(GNSS_PARSER_ParseMsg(&GNSSParser_Data, GNS) != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_ParseMsg\n");
            } else {
            if(GNSS_PARSER_Print(&GNSSParser_Data, GNS) != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_Print\n");
                } else {
                    enqueue(queue_gns, &GNSSParser_Data.gns_data);
                }
            }
        } 
        else if(value & 0x01) {
            if(GNSS_PARSER_ParseMsg(&GNSSParser_Data, GPRMC) != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_ParseMsg\n");
            } else {
            if(GNSS_PARSER_Print(&GNSSParser_Data, GPRMC != GNSS_PARSER_OK) {
                printf("Error in GNSS_PARSER_Print\n");
                } else {
                    enqueue(queue_gprmc, &GNSSParser_Data.gprmc_data);
                }
            }
        } 

        /* USER CODE END WHILE */


        HAL_Delay(500); /* Delay of 500 ms */
    }
}

/* USER CODE BEGIN PF */     //Insert code if necessary
    

/* USER CODE END PF */
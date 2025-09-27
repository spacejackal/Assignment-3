/*
* date.x Specification of the remote date and time server
*/
/*
* Define procedures for date/time and array operations
* bin_date_1() returns the binary date and time (no arguments)
* str_date_1() takes a binary time and returns a string
* insert_array() inserts an element at a given index
* retrieve_array() retrieves an element at a given index
* delete_array() deletes an element at a given index
*/

struct insert_args {
    int element;
    int index;
};

program DATE_PROG {
    version DATE_VERS {
        long BIN_DATE(void) = 1; /* procedure number = 1 */
        string STR_DATE(long) = 2; /* procedure number = 2 */
        void INSERT_ARRAY(insert_args) = 3; /* procedure number = 3 */
        int RETRIEVE_ARRAY(int) = 4; /* procedure number = 4 */
        void DELETE_ARRAY(int) = 5; /* procedure number = 5 */
    } = 1; /* version number = 1 */
} = 0x31234567; /* program number = 0x31234567 */
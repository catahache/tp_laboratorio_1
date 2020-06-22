/*
 * \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*: path al archivo a cargar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBook);

/*
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path char*: path al archivo a cargar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListBook);

/*
 * \brief Aniade un empleado a la linkedlist
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_addBook(LinkedList* pArrayListBook);

/*
 * \brief Edita un empleado de la linkedlist
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_editBook(LinkedList* pArrayListBook);

/*
 * \brief Elimina un empleado de la linkedlist
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_removeBook(LinkedList* pArrayListBook);

/*
 * \brief Lista los empleados de la linkedlist
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_ListBook(LinkedList* pArrayListBook);

/*
 * \brief Ordena los empleados de la linkedlist
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_sortBook(LinkedList* pArrayListBook);

/*
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBook);

/*
 * \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path char*: path al archivo a guardar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListBook);



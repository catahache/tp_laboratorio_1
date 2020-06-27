/*
 * \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 * \param path char*, path al archivo a cargar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBook);

/*
 * \brief Carga los datos de los libros desde el archivo data.bin (modo binario).
 * \param path char*: path al archivo a cargar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListBook);

/*
 * \brief Aniade un libro a la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_addBook(LinkedList* pArrayListBook);

/*
 * \brief Edita un libro de la LinkedList
 * \param pArrayListBook LinkedList*: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_editBook(LinkedList* pArrayListBook);

/*
 * \brief Elimina un libro de la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_removeBook(LinkedList* pArrayListBook);

/*
 * \brief Lista los libros de la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_ListBook(LinkedList* pArrayListBook);

/*
 * \brief Ordena los libros de la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_sortBook(LinkedList* pArrayListBook);

/*
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBook);

/*
 * \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path char*: path al archivo a guardar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListBook);

int proximoId();
int obtenerId(int* id);
int actualizarId(int id);
int controller_SecuritySave(char* path, LinkedList* pArrayListBook);
int controller_relocate(LinkedList* pArrayListBook);

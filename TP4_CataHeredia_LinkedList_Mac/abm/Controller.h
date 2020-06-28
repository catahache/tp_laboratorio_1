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

/*
 * \brief Lee el ID guardado en el archivo proximoID.bin
 * \param int* id: puntero a entero id en el que se guardara el id obtenido
 * \param pArrayListBook LinkedList*, LinkedList
 * \return 1 en caso de error y 0 en caso de exito
 */
int obtenerId(int* id);

/*
 * \brief Actualiza sumandole 1 el ID guardado en el archivo proximoID.bin
 * \param int id: id a actualizar
 * \return 1 en caso de error y 0 en caso de exito
 */
int actualizarId(int id);

/*
 * \brief Crea una copia de seguridad del archivo dataLibros
 * \param char* path: path donde se guardara la copia
 * \param LinkedList* pArrayListBook: LinkedList
 * \return -1 en caso de error y 0 en caso de exito
 */
int controller_SecuritySave(char* path, LinkedList* pArrayListBook);

/*
 * \brief Reubica un libro en la posicion indicada
 * \param LinkedList* pArrayListBook: LinkedList
 * \return -1 en caso de error y 0 en caso de exito
 */
int controller_relocate(LinkedList* pArrayListBook);


/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayListBook, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook);

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayListBook, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_BookFromBinary(FILE* pFile , LinkedList* pArrayListBook);

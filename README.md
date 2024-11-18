# GET NEXT LINE - Función para leer archivos con saltos de línea

## Descripción

`Get Next Line` es una función que permite leer archivos de texto línea por línea, manejando correctamente los saltos de línea. Su objetivo principal es proporcionar una forma eficiente de leer un archivo sin cargar todo su contenido en memoria, ideal para trabajar con archivos grandes.

La función es capaz de gestionar la lectura de un archivo, manejando correctamente las interrupciones de línea (`\n`) y asegurando que el contenido se lea de manera ordenada, sin perder el control de la posición dentro del archivo.

## Características

- Lee un archivo línea por línea, sin cargar todo el archivo en memoria.
- Maneja correctamente los saltos de línea, devolviendo una línea a la vez.
- Función eficiente, optimizada para trabajar con archivos grandes.

## Funcionamiento

La función `Get Next Line` se basa en un búfer de tamaño fijo para leer el archivo en fragmentos y luego extraer las líneas completas, manteniendo el estado de lectura para las siguientes invocaciones. A continuación, se detalla cómo funciona:

1. **Lectura del archivo**: La función lee el archivo utilizando una llamada a `read()` o un sistema equivalente, almacenando el contenido en un búfer.
2. **Separación por saltos de línea**: Cada vez que se encuentra un salto de línea (`\n`), la función considera que ha terminado una línea, devolviendo esa porción de texto.
3. **Retorno de la línea**: La función devuelve la línea leída y mantiene el estado de la posición en el archivo para continuar leyendo la siguiente línea en la siguiente llamada.
4. **Finalización**: Cuando ya no quedan más líneas para leer, la función retorna `NULL`, indicando que el final del archivo ha sido alcanzado.

## Instalación

Para utilizar `Get Next Line`, simplemente debes agregar los archivos `.c` y `.h` a tu proyecto. Si estás usando un `Makefile`, puedes incluir la función en el proceso de compilación de la siguiente manera:

### Clonar el repositorio


git clone https://github.com/Deivincci/get_next_line.git

Compilar la función
Si ya tienes un Makefile, simplemente agrega el archivo get_next_line.c a la lista de archivos fuente, o puedes compilarlo por separado con el siguiente comando:


gcc -Wall -Werror -Wextra *.c

Prueba la función
Una vez compilado, puedes ejecutar el programa acompañándolo de un archivo de texto para probar la función:

./a.out cualquier.txt

Archivos de prueba
Se han añadido algunos archivos .txt para probar el funcionamiento de la función. Puedes usarlos directamente para verificar cómo lee las líneas de un archivo de texto.

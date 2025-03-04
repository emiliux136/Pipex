*Hola soy Emilio y este es mi Pipex* 🚀🧪

🔗 Recreación del comportamiento de la tubería (|) en Bash

📝 Descripción
  Pipex simula la ejecución de | en bash, esta herramienta nos ayuda a combinar diferentes comandos enlazando los resultados, como si de una tubería se tratase.
  He realizado un esquema del funcionamiento de mi programa que puede ayudarte a comprender como funciona: 📄 [Ver esquema PDF](./esquema_emilgarc_pipex.pdf)



🛠 Compilación

    make

▶️ Ejecución

    ./pipex f1 "comando1" "comando2" f2

🔹 Equivalente en Bash:

    < f1 comando1 | comando2 > f2

📌 Ejemplo:

    ./pipex f1 "cat" "wc -l" f2

📌 Esto lee input.txt, ejecuta cat, pasa su salida a wc -l, y guarda el resultado en output.txt.



🔧 Proyecto desarrollado en el marco de 42 Málaga.








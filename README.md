🚀 Pipex
🔗 Recreación del comportamiento de la tubería (|) en Bash

🛠 Compilación

make

▶️ Ejecución

./pipex f1 "comando1" "comando2" f2

🔹 Equivalente en Bash:

< f1 comando1 | comando2 > f2

📌 Ejemplo:

./pipex input.txt "cat" "wc -l" output.txt

📌 Esto lee input.txt, ejecuta cat, pasa su salida a wc -l, y guarda el resultado en output.txt.

📝 Descripción
Pipex simula la ejecución de:

< archivo_entrada cmd1 | cmd2 > archivo_salida
Usando redirecciones y pipes en C.

🔧 Proyecto desarrollado en el marco de 42 Málaga.








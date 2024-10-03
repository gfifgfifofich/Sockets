# Build
``` bash
  g++ -o3 ./Source.cpp ./Client.cpp -o Client
  g++ -o3 ./SourceServer.cpp ./Server.cpp -o Server
```
На Windows, либо выполнить аналогичные комманды, либо положить файлы в 2 новых пустых проекта C++, и сбилдить. (Клиент: ./Source.cpp ./Client.cpp ./Client.h   Сервер: ./SourceServer.cpp ./Server.cpp ./Server.h)

Для запуска сервера 
``` bash
  #./Server <port>
  ./Server 3000
```
Для запуска клиента 
``` bash
  #./Client <name> <port> <interval>
  ./Client name1 3000 1
```

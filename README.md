# Этап 1:
 Вывод сериал порта ардуинки в командную строку.
# Этап1.1:
 реализация на баше(наипростейший вариант)
 Полезные ссылки: 
 https://www.opennet.ru/man.shtml?topic=stty&category=1     //о команде stty которая позволяет читать сериалпорт как ввод
 
 Вбиваю в командную строку:
 	
	sudo stty -F /dev/ttyUSB0 | cat /dev/ttyUSB0

Пояснение: первый кусок говорит что будет ввод через компорт, второй кусок этот ввод выводит по мере поступления
 Альтернатива:
 
  	sudo stty -F /dev/ttyUSB0 | cat /dev/ttyUSB0 > 2.txt 
	
 Пояснение: то же самое, но с записью в файл вместо вывода в командную строку.
 
 
# Этап 1.2:
 Реализация срр-шным файлом.
 Полезные ссылки:
 https://purecodecpp.com/archives/2751   // о либе fstream и ее куске про считывание из файла.
 
 Файл 3.cpp
 Содержит код: 
 
    #include <iostream>    
    #include <fstream>    //либа про работу с файлом

    int main () {   

    std::string str;
    std::ifstream file ("/dev/ttyUSB0");  // как файл подгружается сериалпорт
	
      if(file.is_open())     //проверка на доступность и работоспособность файла(необязательный элемент, 
 	{                      // был добавлен на этапе  подрубания сериалпорта как файла)
	std::cout << "open" << std::endl;   
 	}
	else
	{
	 std::cout << "eror" << std::endl;
	 }
	 while(true){     //пока не надоест считывает из файла содержимое и выводит его
	             for(file >> str; !file.eof(); file >> str){ 
 								std::cout << str << std::endl;  //вывод
								}
		     }
    }


Когда сделал Файл 3.cpp используя команду

	sudo g++ -o 3 3.cpp | ./3  
	
Пояснение: перекомпилировал файл 3.cpp в баш-исполняемый файл 3 
(возможно требуется накинуть ему прав но я не сталкивался с этим)
 
 # Важно!
 Ардуиновский файл second.ino есть то что я вгрузил в ардуинку(она пишет это в сериал порт)
 
 
 

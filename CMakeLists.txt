cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_Bandenkov_lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(vector vector) #Переменная с именем библиотеки
set(vectorlib vectorlib) #Переменная с именем библиотеки
set(vectortest vectortest)
set(matrixtest matrixtest)
set(matrixlib matrixlib)
set(stacklib stacklib)
set(queuelib queuelib)
set(multistacklib multistacklib)
set(queuetest queuetest)
set(stacktest stacktest)
set(multistacktest multistacktest)
set(exeptionlib exeptionlib)
set(queue queue)
set(multistack multistack)
set(stack stack)
set(datlink datlink)
set(datlistlib datlistlib)
set(datlist datlist)
set(datlisttest datlisttest)
set(liststacktest liststacktest)
set(liststacklib liststacklib)
set(liststack liststack)
set(arrlistlib arrlistlib)
set(arrlisttest arrlisttest)
set(arrlist arrlist)
set(polinomlib polinomlib)
set(polinomtest polinomtest)
set(polinom polinom)
set(infixtopolish infixtopolish)
set(infixtopolishlib infixtopolishlib)
set(infixtopolishtest infixtopolishtest)
set(ttextlib ttextlib)
set(ttexttest ttexttest)
set(ttext ttext)
set(chartlib chartlib)
set(chart chart)
set(charttest charttest)
set(tablelib tablelib)
set(table table)
set(tabletest tabletest)
set(sorttablelib sorttablelib)
set(sorttable sorttable)
set(sorttabletest sorttabletest)
set(treetablelib treetablelib)
set(treetable treetable)
set(treetabletest treetabletest)
set(hashtablelib hashtablelib)
set(hashtable hashtable)
set(hashtabletest hashtabletest)




set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hashtablelib ${CMAKE_CURRENT_SOURCE_DIR}/treetablelib ${CMAKE_CURRENT_SOURCE_DIR}/sorttablelib ${CMAKE_CURRENT_SOURCE_DIR}/tablelib ${CMAKE_CURRENT_SOURCE_DIR}/chartlib ${CMAKE_CURRENT_SOURCE_DIR}/ttextlib ${CMAKE_CURRENT_SOURCE_DIR}/infixtopolishlib ${CMAKE_CURRENT_SOURCE_DIR}/arrlistlib ${CMAKE_CURRENT_SOURCE_DIR}/polinomlib ${CMAKE_CURRENT_SOURCE_DIR}/liststacklib ${CMAKE_CURRENT_SOURCE_DIR}/datlistlib ${CMAKE_CURRENT_SOURCE_DIR}/vectorlib ${CMAKE_CURRENT_SOURCE_DIR}/datlink  ${CMAKE_CURRENT_SOURCE_DIR}/matrixlib ${CMAKE_CURRENT_SOURCE_DIR}/stacklib ${CMAKE_CURRENT_SOURCE_DIR}/multistacklib ${CMAKE_CURRENT_SOURCE_DIR}/queuelib ${CMAKE_CURRENT_SOURCE_DIR}/exeptionlib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(vector)
add_subdirectory(vectorlib)
add_subdirectory(gtest)
add_subdirectory(vectortest)
add_subdirectory(matrixtest)
add_subdirectory(matrixlib)
add_subdirectory(stacklib)
add_subdirectory(multistacklib)
add_subdirectory(queuelib)
add_subdirectory(stacktest)
add_subdirectory(multistacktest)
add_subdirectory(queuetest)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(multistack)
add_subdirectory(exeptionlib)
add_subdirectory(datlistlib)
add_subdirectory(datlink)
add_subdirectory(datlisttest)
add_subdirectory(datlist)
add_subdirectory(liststacktest)
add_subdirectory(liststacklib)
add_subdirectory(liststack)
add_subdirectory(arrlistlib)
add_subdirectory(arrlisttest)
add_subdirectory(arrlist)
add_subdirectory(polinomlib)
add_subdirectory(polinomtest)
add_subdirectory(polinom)
add_subdirectory(infixtopolishlib)
add_subdirectory(infixtopolishtest)
add_subdirectory(infixtopolish)
add_subdirectory(ttextlib ttextlib)
add_subdirectory(ttexttest ttexttest)
add_subdirectory(ttext ttext)
add_subdirectory(chartlib)
add_subdirectory(charttest)
add_subdirectory(chart)
add_subdirectory(tablelib)
add_subdirectory(tabletest)
add_subdirectory(table)
add_subdirectory(sorttablelib)
add_subdirectory(sorttabletest)
add_subdirectory(sorttable)
add_subdirectory(treetablelib)
add_subdirectory(treetabletest)
add_subdirectory(treetable)
add_subdirectory(hashtablelib)
add_subdirectory(hashtabletest)
add_subdirectory(hashtable)

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}
/** 
 * @file modifedTableCipher.h
 * @author Бакаев Владислав Геннадьевич
 * @version 3.0
 * @date 13.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Описание класса modAlphaCipher
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
 /// @brief Класс для шифрования и расшифрования шифра табличной маршрутной перестановки
 /** 
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * Конструктор без параметров создать нельзя
 * @warning Реализация только для русского языка
 */
class TableCipher
{
public:
     ///@brief Параметризованный конструктор для инициализации ключа
     /**
     * @param skey Ключ в виде строки
     */
    TableCipher(const int &skey);
  ///@brief Зашифровывание
/**
 * @param [in] open_text Текст который нужно зашифровать. Не должен быть пустой строкой. 
 * Задается как прописными буквами, так и строчными.
 * Если есть другие символы, то будут возбуждаться исключения
 * @return Зашифрованная строка
 * @throw cipher_error, если текст пустой или содержит что-то кроме букв русского алфавита 
 */
    string encrypt(const string &open_text);
 /**
 * @brief Расшифровка
 * @param [in] cipher_text Текст который нужно расшифровать. Не должен быть пустой строкой. 
 * Задается как прописными буквами, так и строчными.
 * Если есть другие символы, то будут возбуждаться исключения
 * @return Расшифрованная строка
 * @throw cipher_error, если текст пустой или содержит что-то кроме букв русского алфавита 
 */
    string decrypt(const string &cipher_text);
 /// @brief Запрещающий конструктор без параметров
    TableCipher()=delete;
 /**
 * @brief Проверка символа
 * @param [in] c Символ который нужно проверить, является ли он русской буквой.
 * Если есть другие символы, то будут возбуждаться исключения
 * @return True если символ является русской буквой, False если не является русской буквой   
 */
    bool isRussianChar(wchar_t c);
private:
    int key;   // Ключ для шифрования на основе таблицы
};
/// @brief Класс обработки исключений.
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};

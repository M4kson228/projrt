#include <iostream>
#include <string>

using namespace std;

// Класс для представления контакта
class Contact {
public:
    string name;        // Имя контакта
    string phoneNumber; // Номер телефона контакта

    // Конструктор для инициализации контакта
    Contact(const string& n, const string& p) : name(n), phoneNumber(p) {}
};

// класс для управления списком контактов
class ContactList {
private:
    Contact* contacts[100]; // Массив для хранения указателей на контакты (максимум 100)
    int count;              // Текущее количество контактов

public:
    // Конструктор для инициализации списка контактов
    ContactList() : count(0) {}

    // Метод для добавления нового контакта
    void addContact(const string& name, const string& phoneNumber) {
        if (count < 100) { // Проверяем, есть ли место в списке
            contacts[count++] = new Contact(name, phoneNumber); // Создаем новый контакт и добавляем его в массив
        }
        else {
            cout << "Список контактов полон." << endl; // Если список полон, выводим сообщение
        }
    }

    // Метод для отображения всех контактов
    void displayContacts() const {
        if (count == 0) { // Проверяем, есть ли контакты в списке
            cout << "Список контактов пуст." << endl;
            return;
        }
        cout << "Список контактов:" << endl;
        for (int i = 0; i < count; ++i) { // Проходим по всем контактам и выводим их
            cout << "Имя: " << contacts[i]->name << ", Телефон: " << contacts[i]->phoneNumber << endl;
        }
    }

    // Метод для удаления контакта по имени
    void removeContact(const string& name) {
        for (int i = 0; i < count; ++i) { // Ищем контакт по имени
            if (contacts[i]->name == name) {
                delete contacts[i]; // Освобождаем память, выделенную под контакт
                contacts[i] = contacts[--count]; // Сдвигаем последний контакт на место удаленного
                cout << "Контакт " << name << " удален." << endl;
                return;
            }
        }
        cout << "Контакт с именем " << name << " не найден." << endl; // Если контакт не найден, выводим сообщение
    }

    // Деструктор для освобождения памяти при уничтожении списка контактов
    ~ContactList() {
        for (int i = 0; i < count; ++i) {
            delete contacts[i]; // Освобождаем память для каждого контакта
        }
    }
};

// Главная функция программы
int main() {
    setlocale(LC_ALL, "Russian");
    ContactList contactList; // Создаем экземпляр списка контактов
    int choice;              // Переменная для выбора действия
    string name, phoneNumber; // Переменные для хранения имени и номера телефона

    do {
        // Вывод меню действий
        cout << "1 Добавить контакт. 2 Показать контакты. 3 Удалить контакт. 4 Выход. ";
        cout << "Выберите действие: ";
        cin >> choice; // Считываем выбор пользователя

        switch (choice) {
        case 1: // Добавление контакта
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            contactList.addContact(name, phoneNumber); // Добавляем контакт в список
            break;
        case 2: // Отображение контактов
            contactList.displayContacts(); // Вызываем метод для отображения списка контактов
            break;
        case 3: // Удаление контакта
            cout << "Введите имя для удаления: ";
            cin >> name;
            contactList.removeContact(name); // Вызываем метод для удаления контакта по имени
            break;
        case 4: // Выход из программы
            cout << "Выход из программы." << endl;
            break;
        default: // Обработка неверного выбора
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 4); // Цикл продолжается до тех пор, пока пользователь не выберет выход

    return 0; // Завершение программы
}

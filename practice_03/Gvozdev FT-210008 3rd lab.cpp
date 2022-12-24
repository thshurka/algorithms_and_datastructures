#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Создаем стек для хранения открывающих скобок
  stack<char> st;

  // Считываем символы скобок по одной в строку
  char c;
  while (cin >> c) {
    // Если символ является открывающей скобкой, добавляем его в стек
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else {
      // Если символ является закрывающей скобкой
      if (st.empty()) {
        // Если стек пуст, значит последовательность скобок неправильная
        cout << "false" << endl;
        return 0;
      }

      // Берем верхний элемент стека
      char top = st.top();
      st.pop();

      // Проверяем, соответствует ли текущая закрывающая скобка
      // соответствующей открывающей скобке
      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        cout << "false" << endl;
        return 0;
      }
    }
  }

  // Если стек пуст, значит последовательность скобок правильная
  cout << (st.empty() ? "true" :"false") << endl;
  return 0;
}


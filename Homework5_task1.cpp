#include <iostream>
enum EnumTest{
  PRINT = 1,
  SELECT,
  COPY,
  PASTE,
  MOVE,
  CUT,
  SHOW
};
int strcmp (const char* str1, const char* str2) {
while (*str1 && *str1 == *str2) {
    ++str1;
    ++str2;
  }
  return (*str1 - *str2);
}
size_t check (const char *str ) {
  if (strcmp(str,"print") == 0) {
    return PRINT;
  } else if (strcmp(str,"select") == 0) {
    return SELECT;
  } else if (strcmp(str,"copy") == 0) {
    return COPY;
  } else if (strcmp(str,"paste") == 0) {
    return PASTE;
  } else if (strcmp(str,"move") == 0) {
    return MOVE;
  } else if (strcmp(str,"cut") == 0) {
    return CUT;
  } else if (strcmp(str,"show") == 0) {
    return SHOW;
  }
  return 0;
}
size_t arr_len (const char* temp) {
  size_t count = 0;
  while (*temp++) {
    ++count;
  }
  return count;
}
char* print (char *start, char *end) {
  const uint32_t TEMP_FOR_TEXT = 300;
  char arr[TEMP_FOR_TEXT] {};
  std::cin >> arr;
  char *begin_arr = arr;
  char *end_arr = arr + arr_len(begin_arr);
  if (*begin_arr != '\0' && *start == '\0') {
    while (begin_arr != end_arr) {
      *start++ = *begin_arr++;
    }
    return start;
  }
  if (*begin_arr != '\0' && *start != '\0') {
    const uint32_t TEMP_FOR_COPY = 300;
    char temp_print_arr [TEMP_FOR_COPY] {};
    char *first_of_temp = temp_print_arr;
    char *last_of_temp = temp_print_arr + arr_len(start);
    char *iter_main_buff = start;
    while (first_of_temp != last_of_temp) {
      *first_of_temp++ = *iter_main_buff++;
    }
    while (begin_arr != end_arr) {
      *start++ = *begin_arr++;
    }
    first_of_temp = temp_print_arr;
    while (first_of_temp != last_of_temp) {
      *start++ = *first_of_temp++;
    }
     return (iter_main_buff - 1);
  }
  return 0;
}
char* copy(char* dst, const char* src, char* end_of_src) {
    char *temp_Ptr = dst;
    while (*src && src != end_of_src) {
      *temp_Ptr++ = *src++;
    }
  *temp_Ptr++ = '\0';
  return dst;
}
void paste (char *copy_start, char *start, char *end) {
  while (start != end) {
    *start++ = *copy_start++;
  }
}
char *move (char *start) {
  char way[5] {};
  uint32_t num;
  std::cin >> way >> num;

  if (strcmp(way, "left") == 0) {
    start -= num;
    return start;
  } 
  if (strcmp(way, "right") == 0) {
    start += num;
    return start;
  }
  return 0; 
}
char* cut (char *start, char *end) {
  char *temp_for_end = end - 1;
  char *new_end = start + arr_len(start);
  while (start != new_end) {
    *start++ = *end++;
  }
  return temp_for_end;
}
int main () {
  const uint32_t ARRAY_SIZE = 300;
  const uint32_t TEMP_ARRAY_SIZE = 300;
  char user_arr[ARRAY_SIZE] {};
  char *begin = user_arr;
  char *end = user_arr + ARRAY_SIZE;
  auto &start_of_buffer = begin;
  auto &end_of_buffer = end;
  char temp_arr [TEMP_ARRAY_SIZE] {};
  char *copy_begin = temp_arr;
  while (true) {
    std::cout << "Enter you commnad and text: ";
    char command[10] {};
    std::cin >> command;
    size_t type = check(command);
    
    switch (type) {
    case PRINT: {
      char* iter = nullptr;
      iter = print(start_of_buffer, end_of_buffer);
      start_of_buffer = iter;
    } break;
    case SELECT:  
      uint32_t start_position ;
      uint32_t end_position;
      std::cin >> start_position >> end_position;
      break;
    case COPY: {
      start_of_buffer = user_arr + start_position;
      end_of_buffer = start_of_buffer + end_position;
      copy(temp_arr, start_of_buffer, end);
      start_of_buffer += arr_len(start_of_buffer);
      end_of_buffer = user_arr + ARRAY_SIZE;
    } break;
    case PASTE: {
      paste(copy_begin, start_of_buffer, end_of_buffer);
      start_of_buffer += arr_len(start_of_buffer);
    } break;
    case MOVE: {
      start_of_buffer = move(start_of_buffer);
    } break;
    case CUT: {
      start_of_buffer = user_arr + start_position;
      end_of_buffer = start_of_buffer + end_position;
      char* temp_for_begin = nullptr;
      temp_for_begin = cut(start_of_buffer, end_of_buffer);
      start_of_buffer = temp_for_begin;
    } break;
    case SHOW: {
      std::cout << user_arr << std::endl;
    } break;
    default:
    std::cout << "You entered wrong command";
    return 0;
      break;
    }
  }
}

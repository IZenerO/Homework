#include <iostream>
const uint32_t SIZE_FOR_ARRAYS = 300;
enum EnumTest{
  PRINT = 1,
  SELECT,
  COPY,
  PASTE,
  MOVE,
  CUT,
  SHOW
};
size_t arr_len (const char* temp) {
  size_t count = 0;
  if (temp != nullptr) {
    while (*temp++) {
      ++count;
    }
  }
  return count;
}
int strcmp (const char* str1, const char* str2) {
  if (str1 != nullptr && str2 != nullptr) {
    while (*str1 && *str1 == *str2) {
      ++str1;
      ++str2;
    }
  }
  return (*str1 - *str2);
}
EnumTest check (const char *str ) {
  if (str != nullptr) {
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
  }
}
char* copy(char* dst, char* src, char* end_of_src) {
  if ((dst != nullptr && src != nullptr && end_of_src != nullptr)) {
      while (src != end_of_src) { 
        *dst++ = *src++;
      }
    return dst;
  }
}
char* print (char *start, char *end) {
  if (start != nullptr && end != nullptr && start != end) {
    char arr[SIZE_FOR_ARRAYS] {};
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
      char temp_print_arr [SIZE_FOR_ARRAYS] {};
      char *first_of_temp = temp_print_arr;
      char *last_of_temp = temp_print_arr + arr_len(start);
      char *iter_main_buff = start;
      copy(first_of_temp, iter_main_buff, end);
      while (begin_arr != end_arr) {
        *start++ = *begin_arr++;
      }
      first_of_temp = temp_print_arr;
      copy(start, first_of_temp, last_of_temp);
      return start;
    }
  }
}
char *move (char *start, char *end) {
  if (start != nullptr && end != nullptr) {
    char way[] {};
    uint32_t num;
    std::cin >> way >> num;
    if (strcmp(way, "left") == 0) {
      start -= num;
    } else if (strcmp(way, "right") == 0) {
      start += num;
      }
  }
  if (start >= end) {
    std::cout << "Out of range!" << std::endl;
    return 0;
  }
  return start; 
}
char* cut (char *start, char *end) {
  if (start != nullptr && end != nullptr) {
    char *returned_end = end - 1;
    char * const new_end = start + arr_len(start);
    while (start != new_end) {
      *start++ = *end++;
    }
  return returned_end;
  }
}
int main () {
  char user_arr[SIZE_FOR_ARRAYS] {};
  char *begin = user_arr;
  char *end = user_arr + SIZE_FOR_ARRAYS;
  char temp_arr [SIZE_FOR_ARRAYS] {};
  uint32_t start_position;
  uint32_t end_position;
  while (true) {
    std::cout << "Enter you command and text: ";
    char command[10] {};
    std::cin >> command;
    size_t type = check(command);
    
    switch (type) {
    case PRINT: {
      start_position = 0;
      end_position = 0;
      begin = print(begin, end);
    } 
    break;
    case SELECT: {
      std::cin >> start_position >> end_position;
      if (start_position >= SIZE_FOR_ARRAYS || end_position >= SIZE_FOR_ARRAYS) {
        std::cout << "Your position is out of range!";
        start_position = 0;
        end_position = 0;
      }
    }  
    break;
    case COPY: {
      if (start_position != 0 && end_position != 0) {
        copy(temp_arr, user_arr + start_position, user_arr + start_position + end_position);
      } else {
        std::cout << "You didn`t select word!" << std::endl;
      }
    } 
    break;
    case PASTE: {
      if (*temp_arr != '\0') {
        start_position = 0;
        end_position = 0;
        char *end_of_temp = temp_arr + arr_len(temp_arr);
        copy(begin, temp_arr, end_of_temp);
        begin += arr_len(begin);
      } else {
        std::cout << "You didn`t copy any word, unable to paste." << std::endl;
      }
    } 
    break;
    case MOVE: {
      start_position = 0;
      end_position = 0;
      begin = move(begin, end);
    } 
    break;
    case CUT: {
      begin = user_arr + start_position;
      end = begin + end_position;
      begin = cut(begin, end);
    } 
    break;
    case SHOW: {
      std::cout << user_arr << std::endl;
    } 
    break;
    default:
      std::cout << "You entered wrong command";
      return 0;
      break;
    }
  }
}

#ifndef U_Macros_H
#define U_Macros_H

#include <stdio.h>

#define log$($message)                                                         \
  printf("[\e[1;32mLOG\e[0m] " __FILE__ ":%s:%i"                               \
         "\n\t" $message "\n",                                                 \
         __FUNCTION__, __LINE__)
#define task$($description)                                                    \
  do {                                                                         \
    printf("[\e[1;33mTASK\e[0m] " __FILE__ ":%s:%i"                            \
           "\n\t" $description "\n",                                           \
           __FUNCTION__, __LINE__);                                            \
    exit(1);                                                                   \
  } while (0)

#endif // U_Macros_H

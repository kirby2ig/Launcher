#ifndef DIR_H
#define DIR_H
int exists(const char* path)
{
    if ( access( path, 0 ) == 0 )
   {
      struct stat status;
      stat( path, &status );

      if ( status.st_mode & S_IFDIR )
      {
         return 1;
      }
      else
      {
         return -1;
      }
   }
   else
   {
      return 0;
   }
}
#endif

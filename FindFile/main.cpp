#include <iostream>
#include <io.h>

int main()
{
    _finddata_t file;
     int k;
     long HANDLE;
     k = HANDLE = _findfirst( "music/*.mp4", &file );
     while( k != -1 ){
      std::cout << file.name << std::endl;
      k = _findnext( HANDLE, &file );
     }
     _findclose( HANDLE );
     return 0;
}

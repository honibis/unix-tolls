# unix-tolls
a repository to share little apps and experiences while using linux


Memchech.c

My server had memory allocation problems while free and htop commands were showing lots of available memory.
I decided to write a program that just allocates memory and see where it fails to actually see what is the unreserved memory.
When i only allocated memory free and htop did not show any increase in usage, only after i used the memory with memset it started to show. However despite not being recognised by free and htop the memory is reserved and prevents apps to allocate.
So i changed the program to allocate and this way could see how much memory is actually available for allocation.
There might be many better ways for this tho since i am no expert in unix systems.

#include <cstdlib>
#include <iostream>
#include <string>

int main(int argv, char *argc[]) {
  std::string mkfat = "sudo mkfs.vfat -F 32 /dev/";
  mkfat += argc[1];
  std::string wipe = "sudo dd if=/dev/zero of=/dev/";
  wipe += argc[1];
  wipe += +"bs=1M";
  std::string umount = "sudo umount /dev/";
  umount += argc[1];
  system(umount.c_str());
  system("clear");
  system(wipe.c_str());
  system("clear");
  system(mkfat.c_str());
  system("clear");
  std::cout << "Formatted /dev/" << argc[1] << " to fat32 successfully!"
            << std::endl;
  return 0;
}

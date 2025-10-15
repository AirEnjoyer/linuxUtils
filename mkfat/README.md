To use it, build it and make sure the executable is named mkfat. Then, sudo cp mkfat /usr/local/bin. If that directory doesnt exist,
make it and add it to your path. Then run "mkfat theDeviceToFormat". Do not add dev, just the device. For example, mkfat sda, not
mkfat /dev/sda. Partitions will also work, such as sda1. Make sure you have dosftools installed.

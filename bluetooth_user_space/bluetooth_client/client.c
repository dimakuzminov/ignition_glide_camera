#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    int soc, status;
    //char device_dest[18] = "1C:E2:CC:A3:23:E0";
    //char command[100] = "/usr/bin/push_h264.sh 192.168.1.16";
    char device_dest[18] = {}; 
    char command[100] = {};
    sprintf(device_dest, "%s", argv[1]);
    sprintf(command, "/usr/bin/push_h264.sh %s", argv[2]);
    // allocate a socket
    soc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 3;
    str2ba( device_dest, &addr.rc_bdaddr );
    // connect to server
    status = connect(soc, (struct sockaddr *)&addr, sizeof(addr));
    // send message len
    int size = strlen(command)+1;
    if( status == 0 ) {
        status = write(soc, &size, sizeof(size));
    }
    // send a message
    if( status == 0 ) {
        status = write(soc, command, size);
    }
    if( status < 0 ) {
        perror("we failed");
    }
    close(soc);
    return 0;
}

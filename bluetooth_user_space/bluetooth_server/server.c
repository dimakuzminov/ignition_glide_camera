#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    char buf[1024] = { 0 };
    int s, client, bytes_read;
    socklen_t opt = sizeof(rem_addr);
    char command[100] = {};
    // allocate socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    // bind socket to port 1 of the first available 
    // local bluetooth adapter
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY;
    loc_addr.rc_channel = (uint8_t) 3;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));
    // put socket into listening mode
    listen(s, 1);
    // accept one connection
    while(1) {
        int size = 0;
        client = accept(s, (struct sockaddr *)&rem_addr, &opt);
        ba2str( &rem_addr.rc_bdaddr, buf );
        fprintf(stderr, "accepted connection from %s\n", buf);
        memset(buf, 0, sizeof(buf));
        // read command size
        bytes_read = read(client, &size, sizeof(size));
        if( bytes_read != sizeof(size) ) {
            close(client);
            continue;
        }
        // read command size
        bytes_read = read(client, command, size);
        if( bytes_read != size ) {
            close(client);
            continue;
        }
        // execute command
        system(command);
    }
    close(s);
    return 0;
}

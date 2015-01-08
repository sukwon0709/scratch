#include <iostream>
#include <lxc/lxccontainer.h>
using namespace std;

int main(int argc, char* argv[]) {

    /**
     * Simply queries a list of lxc containers in the system,
     * and their ip addresses.
     */
    const char* lxcpath = lxc_get_global_config_item("lxc.lxcpath");
    cout << "lxc.lxcpath = " << lxcpath << endl;
    char** names;
    lxc_container** containers;
    int ret = list_active_containers(lxcpath, &names, &containers);
    if (ret != -1) {
        cout << ret << " containers found!\n";
        for (int i = 0; i < ret; i++) {
            char** interfaces = containers[i]->get_interfaces(containers[i]);
            if (interfaces) {
                int j = 0;
                while (interfaces[j] != NULL) {
                    cout << "interface: " << interfaces[j] << endl;
                    char **ips = containers[i]->get_ips(containers[i], interfaces[j], "inet", 0);
                    if (ips) {
                        int k = 0;
                        while (ips[k] != NULL) {
                            cout << "ip: " << ips[k] << endl;
                            k += 1;
                        }
                    }
                    j += 1;
                    free(ips);
                }
                free(interfaces);
            }
        }
        free(names);
        free(containers);
    } else {
        cout << "error occurred!\n";
    }

    return 0;
}

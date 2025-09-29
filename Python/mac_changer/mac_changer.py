#!/usr/bin/env python  

import subprocess  # subprocess module for running system commands
import optparse  # optparse for parsing command line options

def get_arguments():  
    parser = optparse.OptionParser()  
    parser.add_option("-i", "--interface", dest="interface", help="Interface to change its mac address")  # adds option for interface
    parser.add_option("-m", "--mac", dest="new_mac", help="New MAC address")  # adds option for new mac
    (options, arguments) = parser.parse_args()  
    if not options.interface:  # checks if values for interface is provided
        parser.error("[-] Please specify an interface, use --help for more information.") 
    if not options.new_mac:  # checks if value for mac address is provided
        parser.error("[-] Please specify a new MAC address, use --help for more information.")  
    return options  

def change_mac(interface, new_mac): 
    print(f"[+]Changing interface for {interface} to {new_mac}")  
    subprocess.call(["ifconfig", interface, "down"])  # brings the interface down
    subprocess.call(["ifconfig", interface, "hw", "ether", new_mac])  # sets the new mac
    subprocess.call(["ifconfig", interface, "up"])  # brings the interface up again after implementing changes

options = get_arguments()  
change_mac(options.interface, options.new_mac)  
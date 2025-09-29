#!/usr/bin/env python  # Specifies the interpreter

import subprocess  # subprocess module for running system commands
import optparse  # optparse for parsing command line options

def get_arguments():  # function to get command line arguments
    parser = optparse.OptionParser()  # creates an option parser
    parser.add_option("-i", "--interface", dest="interface", help="Interface to change its mac address")  # adds option for interface
    parser.add_option("-m", "--mac", dest="new_mac", help="New MAC address")  # adds option for new mac
    (options, arguments) = parser.parse_args()  # parses the arguments
    if not options.interface:  # checks if values for interface is provided
        parser.error("[-] Please specify an interface, use --help for more information.")  # error if not
    if not options.new_mac:  # checks if value for mac address is provided
        parser.error("[-] Please specify a new MAC address, use --help for more information.")  # shows error if not
    return options  # returns input values as options

def change_mac(interface, new_mac):  #  function to change mac address
    print(f"[+]Changing interface for {interface} to {new_mac}")  # prints the values
    subprocess.call(["ifconfig", interface, "down"])  # brings the interface down
    subprocess.call(["ifconfig", interface, "hw", "ether", new_mac])  # sets the new mac
    subprocess.call(["ifconfig", interface, "up"])  # brings the interface up again after implementing changes

options = get_arguments()  # gets the arguments
change_mac(options.interface, options.new_mac)  # calls the change_mac function with the arguments
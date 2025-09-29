#!/usr/bin/env python

import subprocess

interface = input("Interface Name: ")
new_mac = input("New mac address: ")

print(f"[+]Changing interface for {interface} to {new_mac}")

subprocess.call("ifconfig " + interface + " down", shell=True)
subprocess.call("ifconfig " + interface + " hw ether " + new_mac, shell=True)
subprocess.call("ifconfig " + interface + " up", shell=True)
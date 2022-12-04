## Passwords

Password (encryption) :

Lausanne42s

Password (saeby, saeby2, su)

Qwertyuiop15


Qwerty15

## VM

Software that emulates physcial components such as cpu / disks / etc

- multiple VMs on one host machine
- each VM is in its own environment
- lets us test in a safe enironment
- ...

## Why Debian

Debian is easier to configure for a personnal use like this one, a simple personnal server

## Basic differences Debian CentOS

- Debian :
	- a lot of packages available
	- use apt as package manager
	- easy to upgrade from one version to a new version
- CentOS :
	- few packages available
	- use YUM as packet manager
	- easier to install a new version from scratch than upgrading existing one

## Difference between apt and aptitude

APT and Aptitude are both package managers, Aptitude is based on APT but provides a graphical interface, which you do not have with apt. APT is only usable via command line

## AppArmor ?

AppArmor is a security system to protect applications and the os from differents attack types.
It enforces a good behavior, so that you can only use apps in ways that were marked as correct.

## Password policy

A strong password policy ensures better password, this means password are harder to "find" for someone else. Using bruteforce or any other means

One of the biggest disadvantage is that it's harder for a user to find a password that meets the policy requirements, usually, this also means the password is harder to remember and more easily forgotten

## What is a partition ?

- part of a phyical (or virtual) disk separated from the other
	- I.E on Windows we generlly have the C: && D: partitions

## How does lvm work ?

LVM := Logical Volume Manager
Allows us to easily manipulate the partitions or logical volume on a storage device.

## What's an UFW and what's the value of using it ?

UFW is a simple firewall. It let's us block some network ports.

Imagine a big wall being built around your virtual machine, and on this wall is alot of doors. Each door is a port and you can tell UFW which doors are locked or not.
That's what we did for b2br, we set the door 4242 opened for everyone from everywhere going in or out. You could only let people enter through this door but not going out, or the other way around.
Adding a friewall is a security practice, because you can specify exactly where you want things to go, and from where they come, all the other routes are locked.

## What is ssh and what's the value of using it ?

SSH (Secure SHell) is an authentication mechanism between a client and a host.
It uses encryption so that all communication between clients and hosts is encrypted.
We can work on our vm directly from the terminal on our Mac by connecting to it via ssh.
We can either configure a key (like we did for vogsphere to push our project), or just specify a username when connecting and the host will ask for our password before giving us access.

## What is CRON ?

Cron is command line utility to schedule commands or scripts to happen at specific time (i.e. every first monday of the month) or time intervals (i.e. every 10 minutes)

---

## Commands

- See the partitions 
	lsblk
- Check AppArmor status
	sudo aa-status
- UFW numbered rules
	sudo ufw status numbered
- UFW allow new port
	sudo ufw allow <port>
- UFW delete rule
	sudo ufw delete rule_id
	(run sudo ufw status numbered to get rule ids)
- SSH service status
	sudo systemctl status ssh
- Delete a user
	sudo userdel username
- Create a new user
	sudo adduser new_username
- Check group_name group members
	getent group group_name
- Password complexity settings file
	sudo vim /etc/pam.d/common-password
- Password "time" settings file
	sudo vim /etc/login.defs
- Create a group
	sudo groupadd group_name
- Add user to group
	sudo usermod -aG group_name username
- Check hostname
	hostnamectl
- Change hostname
	hostnamectl set-hostname new_hostname
	sudo reboot
	sudo vim /etc/hosts -> change old hostname to new
- Check if sudo is installed
	(we already used it for the other commands)
	dpkg -l | grep sudovi
- CRON
	cd /usr/local/bin -> show monitoring.sh
	sudo crontab -u root -e -> to edit the cron job
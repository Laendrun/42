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

LVM is used to combine multiple physical volumes (multiples disks) into volume group so that it unifies the storage available to the total of all physical volumes.
Then we can set partitions on top of these volume group. These partitions can be dynamic as we have access to all the available space from multiple physical volumes.
I.E. we have 2 200GB disks, LVM will combine them into a 400GB volume. Most times when we assign partitions to disks, we have to use all the available space, it's not the case with LVM.
We could attribute a 12GB partition, and when we need more, we could simply tell LVM to change it to add 12GB more to it. This will have no effect on the user currently on the disk, all his files will still be available and usable during the modification of the partition.

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
	dpkg -l | grep sudo

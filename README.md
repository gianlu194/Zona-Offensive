This project contains a compact lab report for the Vancouver (2018) vulnerable VM.
It was built to show a clear attack path from initial discovery to full compromise and to store the write-up on GitHub.

Components

Target VM (Vancouver): vulnerable Linux machine with an outdated WordPress site.

Web (HTTP/WordPress): primary attack surface — old WP, exposed backups and XML-RPC.

FTP: weak credentials or exposed backup files in webroot.

SSH: account access after credential discovery for foothold.

Tools used: nmap, gobuster/wpscan, hydra, curl, basic webshell/plugin upload.

Goal

Find and exploit weaknesses to obtain user and root flags; document the steps and simple mitigations.

High-level flow

Port/service enumeration (nmap).

Web enumeration (dirs, robots, backups).

WordPress user discovery and access (XML-RPC / admin).

Upload/editor → webshell → RCE.

Local privilege escalation to root.

Quick remediation

Update WordPress, PHP and plugins; remove unused themes.

Remove backups from webroot and secure FTP.

Disable theme/plugin editor; enforce strong passwords and MFA.

Audit permissions, sudoers and running services.

Disclaimer

For educational use only in a controlled lab. Do not test on systems you don't own or have permission to test.

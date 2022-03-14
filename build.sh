#!/bin/bash
flags=""
run=false
prerun=""
while getopts "dr" o; do
	case $o in
		d)
			flags="-g"
			prerun="gdb"
		;;
		r)
			run=true
		;;
	esac
done

gcc barc.c segments/*.c -o barc $flags
if [ "$run" = true ]; then
	$prerun ./barc
fi

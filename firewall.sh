#!/bin/bash

function and_clause(){
	
	# Read all packets from stdin into “$packets”
	packets=$(cat -) #result
	#echo "DEBUG TEST-packets before filter: ${packets}">&2;
	# Read rule file, convert commas to whitespace
	fields=$(echo "$1" | sed 's/,/ /g')
	#echo "DEBUG TEST-Fields: ${fields}">&2;
	# In each iteration, keep only the packets that match the field
	for field in $fields; do
		#echo "DEBUG TEST-Field:${field}" >&2;
		packets=$(echo "$packets" | ./firewall.exe "$field" 2>/dev/null)
		#echo "DEBUG TEST-Packets after filter:${packets}">&2;
	done
	echo "$packets"
	
}


# Assume the previous script code is written in a function called and_clause
packets=$(cat -) # Read all packets from stdin into “$packets”
rules=$(cat $1) # Read all rules
rules=$(echo "$rules" | sed 's/#.*/ /')
rules=$(echo "$rules" | sed 's/ //g')
pkts= # Holds all matched packets

# In each iteration, append to total packets only those that matched the
# current rule
for rule in $rules; do
 pkts+=$(echo "$packets" | and_clause "$rule")
 pkts+="\n"
done
# Echo the final list of packets. Sort and remove duplicates
#delete all spaces
pkts=$(echo "$pkts" | sed 's/ //g')
#delete empty rows
pkts=$(echo -e "$pkts" | sed '/^$/d')
echo -e "$pkts" | sort | uniq

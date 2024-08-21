#!/bin/bash

function and_clause(){
	# Read all packets from stdin into “$packets”
	#packets=$(cat -)
	# Read rule file, convert commas to whitespace
	fields=$(cat $1 | sed 's/,/ /g')
	# In each iteration, keep only the packets that match the field
	for field in $fields; do
	packets=$(echo "$packets" | ./firewall.exe "$field")
	done
	return packets
}


# Assume the previous script code is written in a function called and_clause
packets=$(cat -) # Read all packets from stdin into “$packets”
rules=$(cat $1) # Read all rules

rules=$(echo "$rules" | sed 's/#.*//')
pkts= # Holds all matched packets

# In each iteration, append to total packets only those that matched the
# current rule
for rule in $rules; do
 pkts+=$(echo "$packets" | and_clause "$rule")
 pkts+="\n"
done
# Echo the final list of packets. Sort and remove duplicates
echo -e "$pkts" | sort | uniq

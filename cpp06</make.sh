#!/bin/bash

rule=$1

# Get list of directories
directories=$(find ./ex* -maxdepth 0 -type d)

# Loop over directories
for dir in $directories
do
    # Change to directory
    cd $dir

    # Execute make command
    printf "\033[48;5;39m [ INFORMATION ]\033[0m \033[38;5;123m Executing make in directory: $dir\n\033[0m"
    make $rule

    # Change back to the parent directory
    cd ..
done

#!/bin/sh
ifconfig | grep "lladr\|ether" | sed 's/.*ether//' | sed 's/.*lladdr//' | tr -d ' '

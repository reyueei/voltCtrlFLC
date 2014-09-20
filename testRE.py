#!/usr/bin/python
import re

line = "ikaw ug ako kay gwapa, 1   234, dayum, romarie"

splitObj = re.split( r"\s*[;]\s*",line.strip())


print(splitObj)

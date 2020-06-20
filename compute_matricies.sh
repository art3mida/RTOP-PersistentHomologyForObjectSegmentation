#!/bin/sh

for f in data/models/*.off ; do ./main $f data/distance_matricies/$(basename "$f").csv; done

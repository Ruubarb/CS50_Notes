# Recover Code Summary

## Pseudocode

**headerCheck**: When it's set to 1, program knows a JPEG header has been detected. 
**jpegCheck**: When it's set to 1, program knows a valid JPEG block, that's not a header, has been detected.

	open raw file as read-only
	while loop through each block that equals 512
		if the block[0], [1], [2], [3] equal a jpeg header
			headerCheck variable is set to 1
			if the jpegCheck variable equals 1
				close the current jpeg being written
				save that jpeg as a new file
				jpegCheck is set to 0
				open write-only file
				write to new file
			else
				open write-only file
				write to new file
		if the headerCheck variable equals 1
			jpegCheck variable is set to 1
			write jpeg block
	close last file
	save file to jpeg
	close raw file
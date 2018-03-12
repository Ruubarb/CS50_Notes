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
				jpegCheck is set to 0
				create a new jpeg file
				open new jpeg file as write-only
				
			else
				create a new jpeg file
				open new jpeg file as write-only
				
		if the headerCheck variable equals 1
			jpegCheck variable is set to 1
			write to jpeg file
			
	close last file
	close raw file
# Recover Code Summary

## Pseudocode

	open raw file as read-only
	while loop through each 512-byte sized block
		if the block[0], [1], [2], [3] equal a jpeg header
			headerCheck variable is set to 1
			if the jpegCheck variable equals 1
				close the current jpeg being written
				save that jpeg
			else
				write a new jpeg file
			if the headerCheck variable equals 1
				jpegCheck variable is set to 1
				write jpeg block
	close last jpeg
	close raw file
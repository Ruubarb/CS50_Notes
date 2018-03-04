# Recover Code Summary

## Pseudocode

    fopen raw file as read-only
    while fread buffer == 512 bytes
    	if block == jpeg_header
        	headerCheck == 1 //means a header has been found
            if jpgCheck == 1
            	fclose jpeg
            	sprintf jpeg
        	else 
        		fwrite new jpeg
    	if headerCheck == 1
    		jpgCheck == 1 //means this belongs to current jpeg file
    		fwrite block
	fclose last jpeg
	fclose memcard 
           

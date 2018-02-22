# Recover Code Summary

## Pseudocode

    fopen raw file as read-only
    within loop
        fread 512 file blocks
        check if previous block == jpeg_header
            if jpeg_header, fclose previous jpeg, fwrite a new jpeg
            if !jpeg_header, found first jpeg, fwrite new jpeg
        check if jpeg header already found
           if not, continue with loop above
           if already found, this block belongs to current jpeg
       if block < 512, fclose raw
# Resize Summary

## General Notes

### On Image Resize
The pixel width and pixel height are changed when the resize program runs. The outfile dimensions are n * infile dimensions. If the infile is 100x100 pixels and n is 2, the outfile will be 200x200 pixels. 

The image file size (in bytes) and the padding will also be taken into account for the resize. Since more pixels are needed for the outfile, more memory needs to be allocated. The outfile padding will also be different from the infile's. I'm still not sure how I'll allocate the memory for the resized file and account for it, but the outfile padding will still follow the multiple of 4 formula (it just won't take the infile's padding into account for the resize).


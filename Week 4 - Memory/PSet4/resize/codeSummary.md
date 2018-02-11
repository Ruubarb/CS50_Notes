# Resize Summary

## Notes

### On Image Resize
The pixel width and pixel height are changed when the resize program runs. The outfile dimensions are n * infile dimensions. If the infile is 100x100 pixels and n is 2, the outfile will be 200x200 pixels. 

The image file size (in bytes) and the padding will also be taken into account for the resize. Since more pixels are needed for the outfile, more memory needs to be allocated. The outfile padding will also be different from the infile's. I'm still not sure how I'll allocate the memory for the resized file and account for it, but the outfile padding will still follow the multiple of 4 formula (it won't fread the infile's padding into account for the resize).

### Horizontal resize
The walkthrough says to make sure a horizontal resize works first. 

From my understanding, each pixel is resized n times within the inner loop. In the outer loop padding is written (if necessary), and the infile padding is skipped. This is repeated for each row until the outfile is resized horizontally. 

### Vertical resize
There are two methods for this. The first method rewrites each row, and the second method recopies each one.

### General Observations
Not only does the outfile increase in terms of dimensions (pixel width and height), but more memory is needed for each new pixel. The hints say malloc() is a *possibility*, but I see it as a necessity or how else can memory be allocated for the extra amount of pixels.
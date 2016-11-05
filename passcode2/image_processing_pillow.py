from PIL import Image, ImageFilter
# Read image
im = Image.open('1.bmp')
# Display image

# Applying a filter to the image
# im_sharp = im.filter(ImageFilter.SHARPEN)
# Saving the filtered image to a new file
# im_sharp.save('1blue_thresholded.bmp', 'bmp')

# Splitting the image into its respective bands, i.e. Red, Green,
# and Blue for RGB
r, g, b = im.split()
px = b.load()
for x in range(im.size[0]):
    for y in range(im.size[1]):
        if px[x, y] < 255:
            px[x, y] = 0
b.show()
b.save('2blue.bmp', 'bmp')

# Viewing EXIF data embedded in image
# exif_data = im._getexif()
# exif_data

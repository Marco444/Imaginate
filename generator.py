from PIL import Image, ImageEnhance
import random

def overlay_images(background_image, overlay_image, position):
	modified_image = background_image.copy()
	overlay_with_alpha = Image.new("RGBA", overlay_image.size)
	overlay_with_alpha = Image.blend(overlay_with_alpha, overlay_image, 1)
	modified_image.paste(overlay_with_alpha, position, overlay_with_alpha)
	return modified_image

def function(images, parametro1, parametro2):

<<<<<<< HEAD
	# ADD_GRAY_SCALE 
	images = [ ImageEnhance.Contrast(image.convert('L')).enhance(1.5).convert("RGBA") for image in images]

file_paths = ["src/backend/code-generation/python/focos/luna.png"]
images = [Image.open(name).convert("RGBA") for name in file_paths]
=======
	# ADD_CONTRAST 
	images = [ ImageEnhance.Contrast(image).enhance(0) for image in images]
>>>>>>> 6a9b7dd9fb103d14cdf90852885e5c53593887a6


	# ADD_GRAY_SCALE 
	images = [ ImageEnhance.Contrast(image.convert('L')).enhance(1.5).convert("RGBA") for image in images]

def function2(images, parametro10, paramentro20, paramentro30):

	# Optional
	if random.randint(0, 1) == 1:
		# ADD_CONTRAST 
		images = [ ImageEnhance.Contrast(image).enhance(0) for image in images]


	# ADD_GRAY_SCALE 
	images = [ ImageEnhance.Contrast(image.convert('L')).enhance(1.5).convert("RGBA") for image in images]


file_paths = ["src/backend/code-generation/python/background/Bricks.png"]
images = [Image.open(name).convert("RGBA") for name in file_paths]

<<<<<<< HEAD
<<<<<<< Updated upstream
# ADD_GRAY_SCALE 
images = [ ImageEnhance.Contrast(image.convert('L')).enhance(1.5).convert("RGBA") for image in images]
>>>>>>> 99934fd0a7fadcf9208b4b977cd091e244495921
=======

function(images, 1, "2")


function2(images, 1, "2", "3")
>>>>>>> 6a9b7dd9fb103d14cdf90852885e5c53593887a6


# ADD_CONTRAST 
images = [ ImageEnhance.Contrast(image).enhance(2) for image in images]


=======
>>>>>>> Stashed changes
# SAVE_IMAGES 
count = 0
for image, file_path in zip(images, file_paths):
	image.save("exported-" + str(count) + ".png")
	count = count + 1


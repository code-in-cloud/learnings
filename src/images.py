import numpy as np
from PIL import Image

def get_image(p: str):
    img = Image.open(p)
    img = np.array(img)
    print(img)



if __name__ =="__main__":
    img = get_image("data/butterfly.jpg")
    

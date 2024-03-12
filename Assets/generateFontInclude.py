import glob
import os
os.chdir("/home/rahulvadhyar/Documents/StreetChase/ThirdParty/Chronos/ThirdParty/fonts/latin1/")
fonts = glob.glob("*")
paths = []

for font in fonts:
    os.chdir("/home/rahulvadhyar/Documents/StreetChase/ThirdParty/Chronos/ThirdParty/fonts/latin1/" + font)
    font_sizes = glob.glob("*.inl")
    for size in font_sizes:
        paths.append(size)


with open("/home/rahulvadhyar/Documents/StreetChase/ThirdParty/Chronos/Source/Engine/Headers/multiFontInclude.hpp", "w") as file:
    for path in paths:
        file.write("#include \"" + path + "\"\n")

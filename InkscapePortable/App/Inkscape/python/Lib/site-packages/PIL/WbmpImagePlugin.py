#
# The Python Imaging Library.
# $Id$
#
# WBMP file handling
#
# This format is used by mobile phones supporting the WAP protocol.
#

__version__ = "0.1"

import Image, ImageFile, ImagePalette
import string

def _tomb(val):
    ''' Convert val to a multi-byte encoded string. '''
    l = [chr(val & 0x7f)]
    val = val >> 7
    while val != 0:
        l.append(chr((val & 0x7f)|0x80))
        val = val >> 7
    l.reverse()
    return string.join(l, '')

def _frommb(s, index = 0):
    ''' Read multibyte value from string, returns value and index to
    rest of string. '''
    val, cont = 0, 1
    while cont:
        ch = ord(s[index])
        index = index + 1
        cont = ch & 0x80
        val = val << 7 | (ch & 0x7f)
    return val, index

def _accept(prefix):
    ''' The type field is multibyte, but only type 0 exists. '''
    type, index = _frommb(prefix)
    header = ord(prefix[index])
    if type != 0 or header != 0:
        # Cannot handle extension header fields yet.
        return 0
    return 1

##
# (Internal) Image plugin for the WBMP format.

class WbmpImageFile(ImageFile.ImageFile):

    format = "WBMP"
    format_description = "Wireless"

    def _open(self):
        # Read header...
        # Image type --- must be 0.
        # Fixheader field
        # ExtFields
        # Width Height
        s = self.fp.read(128)
        if not _accept(s):
            raise SyntaxError("not a WBMP file")

        # Set size in pixels
        width, index = _frommb(s, 2)
        height, index = _frommb(s, index)
        self.size = width, height

        # Set image mode.
        # 1-bit bilevel, stored with the leftmost pixel in the most
        # significant bit. 0 means black, 1 means white.
        self.mode = "1"

        # Tell the system how to read the image
        self.tile = [("raw", (0, 0) + self.size, index, (self.mode, 0, 1))]

SAVE = {
    # mode: (version, bits, planes, raw mode)
    "1": (2, 1, 1, "1"),
}

##
# (Internal) Image save plugin for the WBMP format.

def _save(im, fp, filename, check=0):
    try:
        version, bits, planes, rawmode = SAVE[im.mode]
    except KeyError:
        raise ValueError("Cannot save %s images as WBMP" % im.mode)

    if check:
        return check

    width, height = im.size
    # Write header
    fp.write (chr(0) + chr(0) + _tomb(width) + _tomb(height))
    # Write data
    ImageFile._save(im, fp, [("raw", (0,0) + im.size, 0, (rawmode, 0, 1))])


# --------------------------------------------------------------------
# registry

Image.register_open("WBMP", WbmpImageFile, _accept)
Image.register_save("WBMP", _save)
Image.register_extension("WBMP", ".wbmp")

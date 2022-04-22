from pynq import Overlay

overlay = Overlay('abs_diff.bit')
overlay?

ad_ip = overlay.abs_diff
ad_ip?
ad_ip.register_map

ad_ip.write(0x200, 2)
ad_ip.write(0x400, 8)
ad_ip.read(0x600)

frame1 = '0x200'
frame2 = '0x400'
adframe = '0x600'
result = []

# initialize the 2 frame arrays
for i in 100:
    ad_ip.write('{:X}'.format(int(frame1, 16)+i), i)
    ad_ip.write('{:X}'.format(int(frame2, 16)+i), 100-i)

# compare the absolute difference between 2 frames
for i in 100:
    result.append(ad_ip.read('{:X}'.format(int(adframe, 16)+i)))

from tkinter import *
from painel import *

import serial
class Janela:
    def __init__(self, janela):
        self.fr1 = Frame(janela)
        self.fr1.pack()
        self.msg = Label(self.fr1, text = 'Procurando arduino ...')
        self.msg['width']=26
        self.msg['height']=3
        self.msg.pack()
        self.usb = self.usbBusca()
        pass
    
   
'''
raiz=Tk()
Janela(raiz)
raiz.mainloop()
'''

def usbBusca():
        usbList = 'COM0','COM1','COM2','COM4','COM5','COM6','COM7','COM8','COM9','COM10','COM11','COM12','COM13'
        i = 0
        con = False
        print("procurando arduino ...")
        for usb in usbList:
            try:
                serialusb = serial.Serial(usb)
                print(usb)
                serialusb.close()
                return usb
            except:
                i = i + 1
                if(i == 15):
                    print('Arduino nao encontrado')
                    usb = 0
                    
        


tk = Tk()

a= usbBusca()

Painel(tk ,a)
tk.mainloop()

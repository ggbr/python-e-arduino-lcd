from tkinter import *
from serial import *

class Painel:

    def __init__(self,janela, usb):
        self.usb = usb
        self.fr1 = Frame(janela)
        self.fr1.pack()

        self.bt1 = Button(self.fr1, text = "enviar menssagem")
        self.bt1.pack()

        self.bt2 = Button(self.fr1, text = "Ir para linha de cima")
        self.bt2.pack()

        self.bt3 = Button(self.fr1, text = "Ir para linha de baixo")
        self.bt3.pack()

        self.bt4 = Button(self.fr1, text = "Limpar LCD")
        self.bt4.pack()

        self.btSair = Button(self.fr1, text = "Sair")
        self.btSair.pack()


        pass

    def enviarmsg(self,):
        #implementar enviar msg
        pass
        
    
    def cima(self,):
        self.usb.write(b'2')

    def baixo(self,):
        self.usb.write(b'3')
        pass

    def lcd(self,):
        self.usb.write(b'4')
        pass

    def sair(self,):
        #implementar a função sair 
        pass



tk = Tk()

Painel(tk)
tk.mainloop()



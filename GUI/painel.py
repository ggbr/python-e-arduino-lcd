from tkinter import *
import serial 

class Painel:

    def __init__(self,janela,usb):
        self.usb = serial.Serial(usb)
        print('arduino conectado')
        self.fr1 = Frame(janela)
        self.fr1.pack()

        self.msg = Entry(self.fr1,text = 'Menssagem')
        self.msg.pack()

        self.bt1 = Button(self.fr1, text = "enviar menssagem")
        self.bt1.pack()
        self.bt1.bind("<Button-1>", self.print)

        self.bt2 = Button(self.fr1, text = "Ir para linha de cima")
        self.bt2.pack()
        self.bt2.bind("<Button-1>", self.cima)


        self.bt3 = Button(self.fr1, text = "Ir para linha de baixo")
        self.bt3.pack()
        self.bt3.bind("<Button-1>", self.baixo)
        

        self.bt4 = Button(self.fr1, text = "Limpar LCD")
        self.bt4.pack()
        self.bt4.bind("<Button-1>", self.lcd)
        

        self.btSair = Button(self.fr1, text = "Sair")
        self.btSair.pack()
        self.btSair.bind("<Button-1>", self.print)
        


        pass

    def enviarmsg(self, event):
        #implementar enviar msg
        pass
        
    
    def cima(self, event):
        self.usb.write(b'2')

    def baixo(self, event):
        self.usb.write(b'3')
        pass

    def lcd(self, event):
        self.usb.write(b'4')
        pass

    def sair(self, event):
        #implementar a função sair 
        pass

    def print(self, event):
        msg = self.msg.get()
        self.usb.write(bytes(msg.encode(encoding='UTF-8')))


#foma de se usar





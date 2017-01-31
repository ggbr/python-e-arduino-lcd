#importando bibliotecas do projeto 
import serial
#buscando porta USB 

usbList = 'COM0','COM1','COM2','COM4','COM5','COM6','COM7','COM8','COM9','COM10','COM11','COM12','COM13'

i = 0
loopUsb = True
print("procurando arduino ...")
while(loopUsb):
    try:
        usb = serial.Serial(usbList[i])
        print(usbList[i])
        loopUsb = False
        
    except:
        i = i + 1
        if(i == 15):
            print('Arduino nao encontrado')




loop = True # Variavel que mantem a aplicação rodando 

while(loop):
    # Menu inicial
    print('Escolha uma opção:')
    print('1 -  Enviar mensagem para o Arduino')
    print('2 - Sair')
    op = int(input())

    #seleção das opções 

    if(op == 1):# Enviar dados para o arduino 
        print("Digite a menssagem:")
        msg = input()
        
        usb.write(bytes(msg.encode(encoding='UTF-8')))
    elif (op == 2):#Ensera a aplicação
        loop =  False
        usb.close()# feicha a conexao da porta USB do arduino
    else:
        print("Comando é invalido")





#importando bibliotecas do projeto 
import serial
import os
# ---------    Funçoes --------------- 

#limpa a tela
def cls():
    os.system('cls')


#buscando porta USB 
def usbBusca():
    usbList = 'COM0','COM1','COM2','COM4','COM5','COM6','COM7','COM8','COM9','COM10','COM11','COM12','COM13'
    i = 0
    con = False
    print("procurando arduino ...")
    for usb in usbList:
        try:
            con = serial.Serial(usb)
            print(usb)
            
        except:
            i = i + 1
            if(i == 15):
                print('Arduino nao encontrado')
                com = 0
                
    return con



def painel(usb):
    loop = True # Variavel que mantem a aplicação rodando 

    while(loop == True):
        # Menu inicial
        
        print('Escolha uma opção:')
        print('1 -  Enviar mensagem para o Arduino')
        print('2 -  (Comando a ser implementado)')
        print('3 -  (Comando a ser implementado)')
        print('4 -  (Comando a ser implementado)')
        print('5 -  (Comando a ser implementado)')
        print('6 -  (Comando a ser implementado)')
        print('7 -  (Comando a ser implementado)')
        print('8 -  Limpar tela')
        
        print('9 -  Sair')
        


       
        try:
            op = int(input())
        except:
            print('Opção escolhida é invalida !!!')
            op =  False
        
        if(op):
             #seleção das opções 

            if(op == 1):# Enviar dados para o arduino 
                print("Digite a menssagem:")
                msg = input()
                usb.write(bytes(msg.encode(encoding='UTF-8')))
               
            elif (op == 2):
                print('comando esta sendo implementado ...')
            elif (op == 3):
                print('comando esta sendo implementado ...')                
            elif (op == 4):
                print('comando esta sendo implementado ...')
            elif (op == 5):
                print('comando esta sendo implementado ...')            
            elif (op == 6):
                print('comando esta sendo implementado ...')
            elif (op == 7):
                print('comando esta sendo implementado ...')
            elif (op == 8):
                cls()
            elif (op == 9):
                cls()                
                print("Desligando porta USB")
                usb.close()# feicha a conexao da porta USB do arduino
                loop =  False   
                print("Encerrando ...")      
            else:
                print("Comando é invalido")
       



       


usb  = usbBusca()
cls()
painel(usb)






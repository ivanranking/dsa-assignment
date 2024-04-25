print("1 addition")
print("2 multiplication")
print("3 subtraction")
print("4 division")
choice  =input("enter your choice")
num1 =input('enter num1, :')
num2 =input('enter num2, :')
if choice == '1':
    print('num1', '+', 'num2' '=' 'num1 + num2')
elif choice == '2':
     print('num1', '*', 'num2' '=' 'num1 * num2')
elif choice == '3':
     print('num1', '-', 'num2' '=' 'num1 - num2')
    elif choice == '4':
        if num2 == 0:
            print('math error')
        else:
            print('num1', '/', 'num2' '=' 'num1 / num2')

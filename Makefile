OBJ = main.o InvControl.o Store.o Product.o UI.o ProdList.o Customer.o Purchase.o PurchaseArray.o Date.o Perishable.o NonPerishable.o Taxable.o NonTaxable.o Dairy.o CoffeeTea.o Bakery.o Meat.o MiscGoods.o TaxationBehaviour.o ExpirationBehaviour.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h
	g++ -g -c UI.cc

Store.o:	Store.cc Store.h
	g++ -g -c Store.cc

Product.o:	Product.cc Product.h
	g++ -g -c Product.cc

Customer.o:	Customer.cc Customer.h
	g++ -g -c Customer.cc

Purchase.o: Purchase.cc Purchase.h defs.h
	g++ -g -c Purchase.cc

PurchaseArray.o:	PurchaseArray.cc PurchaseArray.h
	g++ -c PurchaseArray.cc
	
ProdList.o: ProdList.cc ProdList.h defs.h
	g++ -g -c ProdList.cc
Date.o: Date.cc Date.h defs.h
	g++ -g -c Date.cc

Perishable.o: Perishable.cc Perishable.h defs.h
	g++ -g -c Perishable.cc

NonPerishable.o: NonPerishable.cc NonPerishable.h defs.h
	g++ -g -c NonPerishable.cc

Taxable.o: Taxable.cc Taxable.h defs.h
	g++ -g -c Taxable.cc

NonTaxable.o: NonTaxable.cc NonTaxable.h defs.h
	g++ -g -c NonTaxable.cc

Dairy.o: Dairy.cc Dairy.h defs.h
	g++ -g -c Dairy.cc

CoffeeTea.o: CoffeeTea.cc CoffeeTea.h defs.h
	g++ -g -c CoffeeTea.cc

Bakery.o: Bakery.cc Bakery.h defs.h
	g++ -g -c Bakery.cc

Meat.o: Meat.cc Meat.h defs.h
	g++ -g -c Meat.cc

MiscGoods.o: MiscGoods.cc MiscGoods.h defs.h
	g++ -g -c MiscGoods.cc

TaxationBehaviour.o: TaxationBehaviour.cc TaxationBehaviour.h defs.h
	g++ -g -c TaxationBehaviour.cc

ExpirationBehaviour.o: ExpirationBehaviour.cc ExpirationBehaviour.h defs.h
	g++ -g -c ExpirationBehaviour.cc
	
clean:
	rm -f $(OBJ) cushop

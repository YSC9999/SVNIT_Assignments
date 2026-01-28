#!/bin/bash
ADDRESS_BOOK=address_book.txt
while true; do
  echo "\nAddress Book Menu:"
  echo "1. Create address book"
  echo "2. View address book"
  echo "3. Insert a record"
  echo "4. Delete a record"
  echo "5. Modify a record"
  echo "6. Exit"
  read -p "Enter your choice: " choice
  case $choice in
    1)
      > $ADDRESS_BOOK
      echo "Address book created."
      ;;
    2)
      if [ -f $ADDRESS_BOOK ]; then
        cat $ADDRESS_BOOK
      else
        echo "Address book does not exist."
      fi
      ;;
    3)
      read -p "Enter Name: " name
      read -p "Enter Phone: " phone
      echo "$name,$phone" >> $ADDRESS_BOOK
      echo "Record inserted."
      ;;
    4)
      read -p "Enter Name to delete: " name
      if [ -f $ADDRESS_BOOK ]; then
        grep -v "^$name," $ADDRESS_BOOK > temp && mv temp $ADDRESS_BOOK
        echo "Record deleted."
      else
        echo "Address book does not exist."
      fi
      ;;
    5)
      read -p "Enter Name to modify: " name
      if [ -f $ADDRESS_BOOK ]; then
        grep -v "^$name," $ADDRESS_BOOK > temp && mv temp $ADDRESS_BOOK
        read -p "Enter new Phone: " phone
        echo "$name,$phone" >> $ADDRESS_BOOK
        echo "Record modified."
      else
        echo "Address book does not exist."
      fi
      ;;
    6)
      echo "Exiting..."
      break
      ;;
    *)
      echo "Invalid choice."
      ;;
  esac
done
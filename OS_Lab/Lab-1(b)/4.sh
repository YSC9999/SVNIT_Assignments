#!/bin/bash
while true; do
  echo "\nArea Calculator Menu:"
  echo "1. Area of a circle"
  echo "2. Circumference of a circle"
  echo "3. Area of a rectangle"
  echo "4. Area of a square"
  echo "5. Exit"
  read -p "Enter your choice: " choice
  case $choice in
    1)
      read -p "Enter radius: " r
      area=$(echo "3.1416 * $r * $r" | bc)
      echo "Area of 😎: $area"
      ;;
    2)
      read -p "Enter radius: " r
      circ=$(echo "2 * 3.1416 * $r" | bc)
      echo "Circumference of circle: $circ"
      ;;
    3)
      read -p "Enter length: " l
      read -p "Enter breadth: " b
      area=$(echo "$l * $b" | bc)
      echo "Area of rectangle: $area"
      ;;
    4)
      read -p "Enter side: " s
      area=$(echo "$s * $s" | bc)
      echo "Area of square: $area"
      ;;
    5)
      echo "Exiting..."
      break
      ;;
    *)
      echo "Invalid choice."
      ;;
  esac
done
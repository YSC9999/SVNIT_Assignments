
echo "Creating directory structure..."
mkdir -p ProjectWorkspace/Docs
mkdir -p ProjectWorkspace/Code
mkdir -p ProjectWorkspace/Resources

echo "Creating README.txt in Docs..."
touch ProjectWorkspace/Docs/README.txt

echo "Moving into Code directory and creating main.py..."
cd ProjectWorkspace/Code
touch main.py
cd ../.. 

echo ""
echo "Verifying setup (Listing files in ProjectWorkspace):"
ls -R ProjectWorkspace

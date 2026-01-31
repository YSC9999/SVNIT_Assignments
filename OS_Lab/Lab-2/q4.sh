
echo "Creating files..."
touch old_report1.txt old_report2.txt current_report.txt

echo "Creating OldReports directory..."
mkdir -p OldReports

echo "Moving old_ files to OldReports..."

mv old_* OldReports/

echo ""
echo "Verifying content of OldReports:"
ls OldReports

<#
This is my über-awesome powershell script for compiling the project.
#>
$fileName = "TTCP_32bit.exe"
$outputFile = "output.txt"
echo "Checking whether the project has already been compiled."
if ( Test-Path ./$fileName )
{
	echo "Build file found. Removing."
	rm .\$fileName
	echo "Build file removed."
}
echo "Compiling project."
gcc.exe .\HelloWorld.c .\firstHeader.c -o $fileName
if ( $? )
{
	echo "Project compiled succesfully." "Checking for output file."
	if ( Test-Path .\$outputFile )
	{
		echo "Output file found. Clearing previous output data."
		Clear-Content .\$outputFile
		echo "Previous output data cleared." "Running program. Sending data to output file."
		$fileName > .\$outputFile
		echo "Finished running program. You may now read the output in '$outputFile'."
	}
	else
	{
		echo "Could not find output file. Going to send output to this terminal."
		echo "Clearing terminal."
		clear
		echo "Terminal cleared. Running program."
		.\$fileName
		echo "Finished running program."
	}
}
else
{
	echo "Compilation was not succesful. Check your source code or leave this project."
}

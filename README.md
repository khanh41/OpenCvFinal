# Clean Image 🛠
- Remove image noise with median algorithm 🧼️.

1) download OpenCV: https://opencv.org/releases.html
2) Tại giao diện của Visual Studio, chọn Project Properties > Configuration Properties > C/C++ > General > Addition Include Directories, 
ta thêm đường dẫn $(ProjectDir)\Lib\opencv\include 
3) Tiếp đến: Linker > General > Addition Library Directories, thêm vào đường dẫn $(ProjectDir)\Lib\opencv\lib 
4) Tiếp đến: Linker > Input > Additional Dependencies, thêm vào thư viên opencv_world300d.lib ở trong đường dẫn ở bước 3
5) copy file opencv_world300d.dll trong Lib\opencv\bin vào folder Debug của project.

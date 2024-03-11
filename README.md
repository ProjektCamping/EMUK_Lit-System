# EMUK_LIT System

## HTML Server anpassen
- Die page für den Webserver und das Webfront ist in [index.html](data/index.html) definerit
### How to upload
Das [index.html](data/index.html) liegt im FileSytem des ESP32. Dieses wird nicht automatisch mit dem Upload akutalisert und muss zusätzlich angestoßen werden. 
Hierzu im Visual Code: 
- Platform IO Prjektansicht auf der linken seite wählen
- Unter dem Project Task des gewählen Controlers (z.B. "az-devliery-devkit-v4")
    - "Platform" -> "Build Filesystem Image" um das Image mit allen Files zu erstellen (alles was ich sich in dem Folder "data" befindet wird als Image gepackt)
    - dann: "Upload Filesystem Image"

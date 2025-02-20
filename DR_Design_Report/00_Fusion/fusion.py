from PyPDF2 import PdfFileMerger
from os import listdir


input_dir = "D:/Robin Niermaréchal/Documents/EPSA/03-GIT/Valkyriz/ELIZ-2021/DR_Design_Report/00_Fusion/" #your input directory path


merge_list = []

for x in listdir(input_dir):
    if not x.endswith('.pdf'):
        continue
    merge_list.append(input_dir + x)

merger = PdfFileMerger()

for pdf in merge_list:
    merger.append(pdf)

merger.write("D:/Robin Niermaréchal/Documents/EPSA/03-GIT/Valkyriz/ELIZ-2021/DR_Design_Report/00_Fusion/281_Ecurie Piston Sport Auto_Design_Report.pdf") #your output directory
merger.close()
import pyttsx3
import PyPDF2

book = open("SOC.pdf","rb")

porar = pyttsx3.init()
for num in range(0,5):
    page = PyPDF2.PdfReader.getPage(3)
    text = page.extractText()
    porar.say(text)
    porar.runAndWait()
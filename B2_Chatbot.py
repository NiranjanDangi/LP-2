import gradio as gr
from nltk.chat.util import Chat,reflections

pairs = [

    [
        r"(hi|hello|hey)",
        ["Hello!, How I can help you with train booking today ?"]
    ],

    [
        r"i want to book a train",
        ["Sure ! Where would you love to travel from and to ?"]
    ],

    [
        r"from ([\w\s]+) to ([\w\s]+)",
        ["Great! On what date you want to travel from %1 to %2 ?"]
    ],

    [
        r"on ([\w\s\d]+)",
        ["Noted. How many tickets would you like to book on %1 ?"]
    ],

    [
        r"(\d+)\s*tickets?",
        ["Got it! %1 tickets booked. You will receive tickets soon."]
    ],

    [
        r"(thanks|thank you)",
        ["You're Welcome ! Have a safe journey !"]
    ],

    [
        r"(bye|goodbye|quit)",
        ["Goodbye ! Have a nice day :)"]
    ],

    [
        r"(.*)",
        ["I'm not able to understand. Can you please rephrase that ?"]
    ],
]

chatbot = Chat(pairs,reflections)

def respond(message,history):
    return chatbot.respond(message)

demo = gr.ChatInterface(
    fn = respond,
    title= "Train Booking Bot !",
    description="Chat with me to book your train tickets !",
    theme = "soft"
)

if __name__ == "__main__":
    demo.launch() #here launch

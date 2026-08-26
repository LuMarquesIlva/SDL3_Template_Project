from typing import override

import kivy
kivy.require('2.3.1') # replace with your current kivy version !

from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout

class AppButton(Button):

    object = None

    def __init__(self, ButName:str, **kwargs):
        super().__init__(**kwargs)

        self.object = Button(text=ButName, font_size=14)

    def call(self):
        return self

class MainScreen:

    objects = []

    BoxLayoutScreen = BoxLayout(orientation='vertical')

    def AddWidgets(self):
        for Widget in self.objects:
            self.BoxLayoutScreen.add_widget(Widget)

    def __init__(self):
        self.objects.append(AppButton("Build Dir"))
        self.objects.append(AppButton("Wipe"))
        self.objects.append(AppButton("Reconfigure"))
        self.objects.append(AppButton("Download Subprojects"))

        self.AddWidgets()

    def __call__(self):
        return self

class BuildSettings(App):

    @override
    def build(self):
        return MainScreen().BoxLayoutScreen


if __name__ == '__main__':
    BuildSettings().run()

# main.py

from kivy.app import App
from kivy.lang import Builder
from kivy.uix.screenmanager import Screen, ScreenManager

from led_control import LedControl

Builder.load_file("kv_files/app_colors.kv")
Builder.load_file("kv_files/components.kv")
Builder.load_file("kv_files/scr_one.kv")
Builder.load_file("kv_files/scr_two.kv")


class ScrOne(Screen):
    """
    A Kivy screen that displays the main interface of the app.
    """
    pass
class ScrTwo(Screen):
    """
    A Kivy screen that displays and allows the user to update the app's settings.
    """
    pass

class MainApp(App):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.scr_man, self.scr_one, self.scr_two = (None,) * 3
        self.led_control = LedControl(base_url='http://192.168.1.1')

    def build(self):
        self.title = "Help-E 1.0"
        self.scr_man = ScreenManager()

        self.scr_one = ScrOne()
        screen = Screen(name="scr_one")
        screen.add_widget(self.scr_one)
        self.scr_man.add_widget(screen)

        self.scr_two = ScrTwo()
        screen = Screen(name="scr_two")
        screen.add_widget(self.scr_two)
        self.scr_man.add_widget(screen)

        return self.scr_man

    def change_screen(self, new_transition: str, new_scr_name: str) -> None:
        """
        Changes the current screen displayed by the application.

        :param new_transition: The transition direction for the screen change.
        :type new_transition: str
        :param new_scr_name: The name of the new screen to display.
        :type new_scr_name: str
        :return: None.
        :rtype: None
        """
        self.scr_man.transition.direction = new_transition
        self.scr_man.current = new_scr_name


if __name__ == "__main__":
    app = MainApp()

    app.run()

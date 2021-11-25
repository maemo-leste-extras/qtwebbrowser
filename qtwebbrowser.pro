TEMPLATE = subdirs

SUBDIRS = \
    doc \
    src

desktop.path = $$INSTALL_PREFIX/usr/share/applications/hildon/
desktop.files = qtwebbrowser.desktop

icon.path = $$INSTALL_PREFIX/usr/share/icons/
icon.files = qtwebbrowser.png

INSTALLS += desktop icon
requires(qtHaveModule(webengine))


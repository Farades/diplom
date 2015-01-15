package ru.mtplab.gui;

import ru.mtplab.logic.Manager;

import javax.swing.*;

/**
 * Абстрактный класс WindowPanel - предок для всех панелей в приложении.
 */
public abstract class WindowPanel extends JPanel {
    protected JFrame mainFrame; // Указатель на фрейм нужен для смены панели при навигации внутри приложения
    protected Manager manager;  // Менеджер - основной  класс для работы с данными и логикой приложения

    /**
     *
     * @param manager   Указатель на основной класс для работы с данными и логикой
     * @param mainFrame Указатель на главный фрейм
     */
    public WindowPanel(Manager manager, JFrame mainFrame) {
        this.manager = manager;
        this.mainFrame = mainFrame;
    }
}

package ru.mtplab.gui;

import ru.mtplab.logic.ComObserver;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;

/**
 * Created by tess on 15.01.2015.
 */
public class TerminalPanel extends WindowPanel implements ComObserver {
    private JTextArea textArea;
    private JScrollPane scrollPane;
    private JScrollBar vertical;

    public TerminalPanel(Manager manager, JFrame frame) {
        super(manager, frame);
        setLayout(new BorderLayout());

        textArea = new JTextArea();
        textArea.setEditable(false);
        Font font = new Font("Verdana", Font.PLAIN, 14);
        textArea.setFont(font);
        scrollPane = new JScrollPane(textArea);
        vertical = scrollPane.getVerticalScrollBar();
        add(BorderLayout.CENTER, scrollPane);
    }

    @Override
    public void redraw() {

    }

    @Override
    public void onComRecieve(String recieveString) {
        textArea.append(recieveString);
        vertical.setValue(vertical.getMaximum());
    }
}

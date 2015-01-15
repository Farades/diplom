package ru.mtplab.gui;

import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;

/**
 * Created by tess on 15.01.2015.
 */
public class TerminalPanel extends WindowPanel {

    public TerminalPanel(Manager manager, JFrame frame) {
        super(manager, frame);
        setLayout(new BorderLayout());
        add(new JLabel("Терминал"));
    }

    @Override
    public void redraw() {

    }
}

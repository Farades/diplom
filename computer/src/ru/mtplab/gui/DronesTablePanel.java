package ru.mtplab.gui;

import ru.mtplab.logic.Drone;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;
import java.util.ArrayList;

/**
 * Created by tess on 15.01.2015.
 */
public class DronesTablePanel extends WindowPanel {
    private DronesTableModel droneModel;
    private JTable dronesJTable;
    private JScrollPane dronesScroll;
    private MainWindow mainWindow;

    public DronesTablePanel(Manager manager, JFrame frame, MainWindow mainWindow) {
        super(manager, frame);
        setLayout(new BorderLayout());
        this.mainWindow = mainWindow;

        setDronesTable();
    }

    private void setDronesTable() {
        droneModel = new DronesTableModel(manager.getBs().getDrones());
        dronesJTable = new JTable(droneModel);
        dronesJTable.setRowHeight(40);
        dronesJTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        dronesJTable.getColumnModel().getColumn(0).setPreferredWidth(15);
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(SwingConstants.CENTER);
        dronesJTable.getColumnModel().getColumn(0).setCellRenderer(centerRenderer);
        dronesJTable.getColumnModel().getColumn(1).setCellRenderer(centerRenderer);
        dronesJTable.getColumnModel().getColumn(2).setCellRenderer(centerRenderer);
        dronesJTable.getColumnModel().getColumn(3).setCellRenderer(centerRenderer);
        dronesJTable.getColumnModel().getColumn(4).setCellRenderer(centerRenderer);
        dronesScroll = new JScrollPane(dronesJTable);

        dronesJTable.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if(e.getValueIsAdjusting())
                    mainWindow.setDronePanel(droneModel.getDrone((dronesJTable.getSelectedRow())));
            }
        });

        this.add(BorderLayout.CENTER, dronesScroll);
    }

    @Override
    public void redraw() {
        dronesJTable.repaint();
        dronesScroll.getViewport().revalidate();
    }

    private class DronesTableModel extends AbstractTableModel {
        private ArrayList<Drone> droneList;

        public DronesTableModel(ArrayList<Drone> droneList) {
            this.droneList = droneList;
        }

        public Drone getDrone(int i) {
            return droneList.get(i);
        }

        @Override
        public int getRowCount() {
            return manager.getBs().getDrones().size();
        }

        @Override
        public int getColumnCount() {
            return 5;
        }

        @Override
        public String getColumnName(int columnIndex) {
            switch (columnIndex) {
                case 0:
                    return "Id";

                case 1:
                    return "Latitude";

                case 2:
                    return "Longitude";

                case 3:
                    return "Состояние";

                case 4:
                    return "Задание";
            }
            return null;
        }

        @Override
        public Class<?> getColumnClass(int columnIndex) {
            return String.class;
        }

        @Override
        public boolean isCellEditable(int rowIndex, int columnIndex) {
            return false;
        }

        @Override
        public Object getValueAt(int rowIndex, int columnIndex) {
            Drone drone = droneList.get(rowIndex);
            switch (columnIndex) {
                case 0:
                    return drone.getId();

                case 1:
                    return drone.getLatitude();

                case 2:
                    return drone.getLongitude();

                case 3:
                    return drone.getState();

                case 4:
                    return drone.getJob();
            }
            return null;
        }

        @Override
        public void setValueAt(Object aValue, int rowIndex, int columnIndex) {

        }

        @Override
        public void addTableModelListener(TableModelListener l) {

        }

        @Override
        public void removeTableModelListener(TableModelListener l) {

        }
    }
}

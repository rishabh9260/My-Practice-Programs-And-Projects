import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
 
public class MidpointCircle {
 
    public static void main(String[] args) {
        SwingUtilities.invokeLater(MidpointCircle::run);
    }
 
    private static void run() {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        f.setTitle("Midpoint Circle");
 
        f.getContentPane().add(new MidpointCirclePanel());
        f.pack();
 
        f.setLocationRelativeTo(null);
        f.setVisible(true);
    }
}
 
class MidpointCirclePanel extends JPanel {
 
    private static final long serialVersionUID = 1L;
    private final int pixelSize = 1;
 
    MidpointCirclePanel() {
        setPreferredSize(new Dimension(1000, 1000));
        setBackground(Color.WHITE);
    }
 
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        int xc = Integer.parseInt(JOptionPane.showInputDialog(getParent(), "Enter Xc: "));
        int yc = Integer.parseInt(JOptionPane.showInputDialog(getParent(), "Enter Yc: "));
        int r = Integer.parseInt(JOptionPane.showInputDialog(getParent(), "Enter Radius: "));
        
        int x1 = 0;
        int y1 = r;
 
        drawCircle(g, r, x1, y1, xc, yc);
    }
 
    private void plot(Graphics g, int x, int y) {
        int w = (getWidth() - 1) / pixelSize;
        int h = (getHeight() - 1) / pixelSize;
        int maxX = (w - 1) / 2;
        int maxY = (h - 1) / 2;
 
        int borderX = getWidth() - ((2 * maxX + 1) * pixelSize + 1);
        int borderY = getHeight() - ((2 * maxY + 1) * pixelSize + 1);
        int left = (x + maxX) * pixelSize + borderX / 2;
        int top = (y + maxY) * pixelSize + borderY / 2;
 
        g.setColor(Color.BLACK);
        g.drawOval(left, top, pixelSize, pixelSize);
    }
 
    private void drawCircle(Graphics g, int r, int x1, int y1, int xc, int yc) {
        int p = 1 - r;
        while(x1<=y1)
        {
            plot(g,x1+xc,y1+yc);
            plot(g,-x1+xc,y1+yc);
            plot(g,x1+xc,-y1+yc);
            plot(g,-x1+xc,-y1+yc);
            plot(g,y1+xc,x1+yc);
            plot(g,-y1+xc,x1+yc);
            plot(g,y1+xc,-x1+yc);
            plot(g,-y1+xc,-x1+yc);

            if(p<0)
            {
                x1++;
                p = p + 2*x1 + 1;
            }
            else
            {
                x1++;
                y1--;
                p = p + 2*(x1-y1) + 1;
            }
        }
    }
}

// Aplicativo para exibir uma DrawPanel.
import javax.swing.JFrame;

public class DesenhoPainelAplicativo
{
   public static void main( String args[] )
   {
      // cria um painel que cont�m nosso desenho
      DesenhoPainel panel = new DesenhoPainel();

      // cria um novo quadro para armazenar o painel
      JFrame aplicacao = new JFrame();

      // configura o frame para ser encerrado quando ele � fechado
      aplicacao.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );

      aplicacao.add( panel ); // adiciona o painel ao frame
      aplicacao.setSize( 250, 250 ); // configura o tamanho do frame
      aplicacao.setVisible( true ); // torna o frame vis�vel
   } // fim de main
} // fim da classe DesenhoPainelAplicativo


/**************************************************************************
 * Modificado de : Deitel, H. M.; Deitel, P.J. Java Como Programar.         *
 * Porto Alegre:Bookman,2005.                                               *
 ***************************************************************************/
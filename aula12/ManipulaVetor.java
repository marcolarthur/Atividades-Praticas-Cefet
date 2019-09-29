/*
/*
/*
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package execao_aula12;

import java.util.Random;

/**
 *
 * @author Ingrid Lysei
 */
public class ManipulaVetor {
    private int[] vetor = new int[20];
    Random rand = new Random();
    public ManipulaVetor() {
        for(int i = 0; i< vetor.length; i++){
            vetor[i] = rand.nextInt(20) + 1 ;
        }
    }

    public int[] getVetor() {
        return vetor;
    }

    public void setVetor(int posicao, int valor) {
        vetor[posicao] = valor;
    }
    
    
    public int posMen(){
      int menor = vetor[0];
      int pos = 0;
      for(int i = 0; i < vetor.length; i++){
          if(vetor[i] < menor){
              menor = vetor[i];
              pos = i;
          }
      }
        return pos;
    }
    
    public int posMai(){
       int maior = vetor[0];
       int pos = 0;
      for(int i = 0; i < vetor.length; i++){
          if(vetor[i] > maior){
              maior = vetor[i];
              pos = i;
          }
      }
        return pos;
    }
    
    public int primeiraOcorrencia(int x){
        int resultado = 0;
        for(int i = 0; i < vetor.length; i++){
          if(vetor[i] == x){
               resultado = i;
               break;
          }
      }
        return resultado;
    }
    
     public String todasOcorrencia(int x){
        String resultado = "";
        for(int i = 0; i < vetor.length; i++){
          if(vetor[i] == x){
               resultado += i + ", ";
               
          }
      }
        return resultado;
    }
    
     public int numOcorrencia(int x){
        int resultado = 0;
        for(int i = 0; i < vetor.length; i++){
          if(vetor[i] == x){
               resultado ++;
               
          }
      }
        return resultado;
    }
     
    @Override
    public String toString(){
        String resultado = "";
        for(int i = 0; i<vetor.length; i++){
            resultado += "Vetor [" + i + "] = " + vetor[i] + "\n";
        }
        return resultado;
    }
     
     
     
     
    
    
    
    
}

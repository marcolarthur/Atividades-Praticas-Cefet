/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula03;

import javax.swing.*;

/**
 *
 * @author Aluno
 */
public class Aludno {
    private double nota;
    private int frequencia;
    private int naulasf;
    private char conceito;
    
    public void Aludno(){
       nota = 0;
       frequencia = 0;
       naulasf = 0;
    }
    Aludno(int a, double n, int f){
        setNota(n);
        setFrequencia(f);
        setNaulasf(a);
   
    }
    
    public void setNota(double nota){
        this.nota = nota;
    }
    public void setFrequencia(int frequencia){
        this.frequencia = frequencia;
    }
    public void setNaulasf(int naulasf){
        this.naulasf = naulasf;
    }
    public double getNota(){
        return this.nota;
    }
    
    public void setConceito(char conceito){
        this.conceito = conceito;
    }
    public double getConceito(){
        return this.conceito;
    }
    
    public int getFrequencia(){
        return this.frequencia;
    }
    public int getNaulasf(){
        return this.naulasf;
    }
    public String toString(){
        return "A nota do aluno foi:" + nota + "\nSua frequencia foi:" + frequencia + "\nNumero de aulas frequentadas foi:\n";
    }
}


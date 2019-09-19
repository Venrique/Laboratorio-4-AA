/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Una función para cambiar dos elementos
void swap(int* a, int* b){
int t = *a;
*a = *b;
*b = t;
}

/* Esta función toma el último elemento como pivote, lo coloca en su posición
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo*/
int partition (int arr[], int low, int high){
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    for (int j = low; j <= high - 1; j++){
// Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot){
        i++; // incrementar el index del menor elemento
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* La función principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> límite inicial,
high --> límite final */
void quickSort(int arr[], int low, int high){
    if (low < high){
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la
        // partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Función para imprimir arreglo */
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void problema(int arr[],int size){
    int contador = 1;
    for (int i = 0; i < size; i++){
        bool bandera = 0;
        while (arr[i] >= 2*contador){
            arr[i]-=1;
            bandera = 1;
        }
        if (bandera == 1){
            contador++;
        }
        
    }
    cout<<"El menor multiplo de 2 que no esta en el array es: "<<2*contador<<endl;
}

// Código principal para utilizarlo
int main(){
    int casos;
    cout << "Ingrese la cantidad de casos a probar (max 10)"<<endl;
    cin >> casos;

    int n;
    int res[casos];

    for (int e = 0; e < casos; e++){
        cout<<"Ingrese el tamanio del array "+e<<endl;
        cin>>n;
        int arr[n];
        for (int a = 0; a < n; a++){
            cout<<"Ingrese los datos del array"<<endl;
            cin>>arr[a];
        }
        quickSort(arr,0,n-1);
        printArray(arr,n);
        problema(arr,n);
    }
    

    /*int arrnum[] = {6,3};
    int arr0[] = {1,3,3,3,6,7};
    int arr1[] = {3,0,1};
    int *arr[] = {arr0,arr1};
    for (int i = 0; i < casos; i++){
        quickSort(arreglos.at(i),0,sizes.at(i)-1);
        printArray(arreglos.at(i),sizes.at(i));
        problema(arreglos.at(i),sizes.at(i));
    }*/
    

    
    /*int arr[] = {10, 7, 8, 6 ,6, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);*/
    return 0;
}

import java.util.Scanner;
public class heap{
    public static void swap(int a,int b){
        int c=a;
        a=b;
        b=c;
    }
    public static void heapify(int[] arr,int size,int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=index){
            int temp=arr[largest];
            arr[largest]=arr[index];
            arr[index]=temp;
            heapify(arr,size, largest);
        }
    }
    public static void  make_heap(int[] arr,int size){
        for(int i=(size/2)-1;i>=0;i--){
            heapify(arr, size, i);
        }
    }
    public static void heap_sort(int[] arr,int size){
        make_heap(arr, size);
        for(int i=size-1;i>=0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapify(arr, i, 0);
        }
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        System.out.print("Enter the number of elements in array : ");
        int a=s.nextInt();
        int[] arr=new int[a];
        for(int i=0;i<a;i++){
            System.out.print("Enter the "+(i+1)+" of the array : ");
            arr[i]=s.nextInt();
        }
        heap_sort(arr, a);
        System.out.print("The sorted array is : ");
        for(int i=0;i<a;i++){
            System.out.print(arr[i]+" ");
        }
        s.close();
    }
}
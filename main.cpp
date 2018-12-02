#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
long int merge_count_inversion(int* input,int a,int middle,int b){
   int size=b-a+1;
   int* temparray=new int[size];
   int i=a;
   int j=middle+1;
   long int count=0;
   for(int k=0;k<size;k++){
      if(i<middle+1 && j < b+1){
      if(input[i]<input[j]){
         temparray[k]=input[i];
         i++;
      }
      else{
         temparray[k]=input[j];
         j++;
         count=count+middle-i+1;
      }
      }
      else if(i>middle && j<b+1){
         temparray[k]=input[j];
         j++;
      }
      else if(i<middle+1 && j>b){
         temparray[k]=input[i];
         i++;
      }
      else{
      }
   }
   for(int k=0;k<size;k++){
      input[a+k]=temparray[k];
   }
   delete [] temparray;
   return count;
}
long int mergesort_count_inversion(int* input,int a,int b){
   int middle=floor((b+a)/2.0);
   long int count1;
   long int count2;
   long int count3;
   if(b-a==0){
      return 0;
   }
   else{
      count1=mergesort_count_inversion(input,a,middle);
      count2=mergesort_count_inversion(input,middle+1,b);
      count3=merge_count_inversion(input,a,middle,b);
      return count1+count2+count3;
   }
}
int main(){
   std::fstream fs;
   fs.open("IntegerArray.txt",std::fstream::in);
   int temp;
   std::list<int> rawdata;
   while(!fs.eof()){
      fs>>temp;
      rawdata.push_back(temp);
   }
   int* data=new int[rawdata.size()];
   int count=0;
   for(std::list<int>::iterator a=rawdata.begin();a!=rawdata.end();a++){
      data[count]=*a;
      count++;
   }
   count=rawdata.size()-1;
   std::cout<<mergesort_count_inversion(data,0,count-1)<<std::endl;
}

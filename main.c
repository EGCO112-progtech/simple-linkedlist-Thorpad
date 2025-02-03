#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node d;
    d.value=11;
    b.next=&d;
    /* alternative of the above line
    b.next->value=11; 
    a.next->next->value=11
    */
    printf("%d\n", head ->next->next->value ); //what value for 11
    d.next = NULL;

    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)

*/

    struct node f;
    f.next=&a;
    head=&f;
    f.value=2;
    printf("\n%d\n", head -> value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5
    printf("%d\n", head ->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->value ); //what value for 11


    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }

        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", *(tmp+i)->value);
        }
        plus plus mai dai :( 
        it's not an array ตำแหน่งไม่ได้อยู่ติดกัน

    */
        printf("\n\n");
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }
        printf("\n\n");
        

    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    tmp=head;
    while(tmp != NULL){
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }

    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    printf("\n\n");
     //typedef struct node* NodePtr; อยู่ข้างบน
     typedef struct node NODE;
     head = (NodePtr) malloc(sizeof(struct node));
     tmp=head;
     //อยากสร้างอีก 3 node ต่อท้าย
     tmp=head;
     for(i=0; i<3; i++) {
        tmp->value = i+3; //ใส่ค่า i+3 ใน value
        tmp->next=(NodePtr)malloc(sizeof(struct node));
        tmp=tmp->next;
     }
     tmp->value = i+3;
     tmp->next=NULL;
    

    tmp=head;
    while(tmp != NULL){
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }

    printf("\n\n");
    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */


     for(tmp=head; tmp!=NULL; tmp=head){
        head=head->next;
        printf("Freeing %d \n",tmp->value);
        free(tmp);
     }
    
    return 0;
}

#include<iostream>

struct KT{
    int data;
    KT*Lnext, *Rnext;
};
typedef KT element;
class STACK{
    int size = 11;
    element **arr = (element**)malloc(sizeof(element*)*size);

public:
    int top;
    bool isfull(){
        return top == size-1;
    }
    bool isempty(){
        return top == -1;
    }
    void push(element* node){
        arr[++top] = node;
    }
    element* pop(){
        return arr[top--];
    }
    element* peek(){
        return arr[top];
    }
};


int main(){
    KT arr[12];
//    arr[0] = {0, NULL, NULL};
//    arr[1] = {1, NULL, NULL};
//    arr[2] = {2, NULL, NULL};
//    arr[3] = {3, NULL, NULL};
//    arr[4] = {4, NULL, NULL};
//    arr[5] = {5, NULL, NULL};
//    arr[6] = {6, NULL, NULL};
//    arr[7] = {7, NULL, NULL};
//    arr[8] = {8, NULL, NULL};
//    arr[9] = {9, NULL, NULL};
//    arr[10] = {10, NULL, NULL};
//    arr[11] = {11, NULL, NULL};
//
//    arr[0].Lnext = &arr[1];
//    arr[0].Rnext = &arr[2];
//    arr[1].Lnext = &arr[3];
//    arr[2].Lnext = &arr[4];
//    arr[2].Rnext = &arr[5];
//    arr[3].Rnext = &arr[6];
//    arr[5].Lnext = &arr[7];
//    arr[5].Rnext = &arr[11];
//    arr[6].Lnext = &arr[8];
//    arr[6].Rnext = &arr[9];
//    arr[7].Rnext = &arr[10];

//        arr[0] = {0, NULL, NULL};
//        arr[1] = {1, NULL, NULL};
//        arr[2] = {2, NULL, NULL};
//        arr[3] = {3, NULL, NULL};
//        arr[4] = {4, NULL, NULL};
//        arr[5] = {5, NULL, NULL};
//        arr[6] = {6, NULL, NULL};
//        arr[7] = {7, NULL, NULL};
//        arr[8] = {8, NULL, NULL};
//
//        arr[0].Lnext = &arr[1];
//        arr[0].Rnext = &arr[2];
//        arr[1].Lnext = &arr[3];
//        arr[1].Rnext = &arr[4];
//        arr[2].Rnext = &arr[5];
//        arr[4].Lnext = &arr[6];
//        arr[4].Rnext = &arr[7];
//        arr[5].Lnext = &arr[8];

        arr[0] ={40,NULL,NULL};
        arr[1] ={4,NULL,NULL};
        arr[2] ={45,NULL,NULL};
        arr[3] ={34,NULL,NULL};
        arr[4] ={55,NULL,NULL};
        arr[5] ={14,NULL,NULL};
        arr[6] ={48,NULL,NULL};
        arr[7] ={13,NULL,NULL};
        arr[8] ={15,NULL,NULL};
        arr[9] ={47,NULL,NULL};
        arr[10] ={49,NULL,NULL};
    
        arr[0].Lnext = &arr[1];
        arr[0].Rnext = &arr[2];
        arr[1].Rnext = &arr[3];
        arr[2].Rnext = &arr[4];
        arr[3].Lnext = &arr[5];
        arr[4].Lnext = &arr[6];
        arr[5].Lnext = &arr[7];
        arr[5].Rnext = &arr[8];
        arr[6].Lnext = &arr[9];
        arr[6].Rnext = &arr[10];

    std::cout<<"전위순회로 노드를 방문한다."<<std::endl;
    KT* cp = &arr[0];
    STACK stack, TempStack;
    if(cp != NULL){
        while(1){
            std::cout<<cp->data<<" ";
            if(cp->Lnext != NULL){
                if(cp->Rnext != NULL)
                    stack.push(cp->Rnext);
                cp = cp->Lnext;
            }
            else if(cp->Lnext == NULL){
                if(cp->Rnext == NULL){
                    cp = stack.pop();
                }
                else{
                    cp = cp->Rnext;
                }
            }
            if(stack.isempty())
                break;
        }
    }
    else{
        std::cout<<"빈 트리"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"중위순회로 노드를 방문한다."<<std::endl;
    cp = &arr[0];

    while(1){
        while(cp != NULL){
            stack.push(cp);
            cp = cp->Lnext;
        }

        if(stack.isempty())
            break;
        else{
            cp = stack.pop();
            std::cout<<cp->data<<" ";
            cp = cp->Rnext;
        }


    }
    std::cout<<std::endl;
    std::cout<<"후위순회로 노드를 방문한다."<<std::endl;
    cp = &arr[0];
    
    while(1){
        while(cp != NULL){
            stack.push(cp);
            if(cp->Rnext != NULL && cp->Lnext != NULL){
                stack.push(cp->Rnext);
                TempStack.push(cp->Rnext);
                cp = cp->Lnext;
            }
            else if(cp->Lnext != NULL){
                cp = cp->Lnext;
            }
            else if(cp->Rnext != NULL){
                cp = cp->Rnext;
            }
            else{
                cp = cp->Rnext;
            }
        }
        while(!stack.isempty()){
            cp = stack.pop();
            std::cout<<cp->data<<" ";
            if(TempStack.peek() == stack.peek() && !TempStack.isempty()){
                cp = TempStack.pop();
                if(!stack.isempty())
                    stack.pop();
                break;
            }
        }
        if(stack.isempty()){
            std::cout<<std::endl;
            break;
        }
    }
}

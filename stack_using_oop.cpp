#include <iostream>

class Stack{
    public: int arr[7];
        int top = -1;
        void push(int n){
            arr[++top] = n;
        }
        void pop(){
            top--;
        }
};

int main(){
    char s;
    Stack st;
    while(true){
        std::cout<<"Enter operation: ";
        std::cin>>s;
        switch(s){
            case 'p': {
                if(st.top == 6){
                    std::cout<<"Stack Overflow\n";
                    break;
                }
                int l;
                std::cout<<"Enter value: ";
                std::cin>>l;
                st.push(l);
                std::cout<<"Elements of stack: ";
                for(int i = 0; i <= st.top; i++) std::cout<<st.arr[i]<<" ";
                std::cout<<"\n";
                break;
            }
            case 'o': {
                if(st.top == -1){
                    std::cout<<"Stack Underflow\n";
                    break;
                }
                st.pop();
                std::cout<<"Elements of stack: ";
                for(int i = 0; i <= st.top; i++) std::cout<<st.arr[i]<<" ";
                std::cout<<"\n";
                break;
            }
            case 'q': {
                return 0;
            }
        }
    }

    return 0;
}

#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        Node* next = NULL;
    }
};
int length(Node*& head){
    //Step 1 - pehle mein ek jaali temporary pointer bna dena taaki mere head ch koi dikkat na aava ta oh apni jagah te rah 
    // kyuki maanu bacho vi ohdi value di lodd pa skdi hai 
    Node* temp = head;
    //ek variable bnana length name da taaki length find kr ska okkkk
    int length = 0;
    //mein eh loop td tak chlaunga jab tak null nhi aa janda jida hi null aaya oh aaga nhi aayga ta oh hi apni length di value hoygi
    while(temp!=NULL){
        //length lagatar bdd rhi hai 
        length++;
        //pointer next nu assign ho reha
        temp = temp->next;
    }
    //length return krti hai 
    return length;
}
void printll(Node*& head){
//Step 1 - pehle mein ek jaali temporary pointer bna dena taaki mere head ch koi dikkat na aava ta oh apni jagah te rah 
// kyuki maanu bacho vi ohdi value di lodd pa skdi hai 
    Node* temp = head;
//loop jad tak null nhi aa janda
    while(temp != NULL){
        //print kdi ja value ohdi linked list di 
        cout<<temp->data<<" ";
        //temp nu aaga vdada 
        temp = temp->next;
    }   
}
void insertathead(Node*& head,Node*& tail,int data){
    //Agr head null hoya phir 
    if(head==NULL){
        //step 1 - create new node
        Node* newNode = new Node(data);
        //step 2 - kyuki head null si esliye head nu vi new node de brabar kr de and also tere kol tail vi byrefrence aa reha ta ohnu vi update kr de
        head = newNode;
        tail = newNode;
        //finished agr head tail null si taah bss ehna hi hai 
    }
    else{
        //step 1 = create new node
        Node* newNode = new Node(data);
        //step 2  = newNode de next nu mein head naal attach kr dena
        newNode->next = head;
        //step 3 = mein head nu hi new node bna dena
        head = newNode;
    }
}
void insertattail(Node*& head,Node*& tail,int data){
    //agr head null hoya phir tail automatically hi kuch nhi hoyga??
    if(head == NULL){
        //step 1 = create krde navi node
        Node* newNode = new Node(data);
        //step 2 = null si esliye head tail dona de andar new value nu assign krde 
        head = newNode;
        tail = newNode;
    }
    else{
        //agr null nhi h phir??
        //phir eh step kr
        //step 1 = create krla new node
        Node* newNode = new Node(data);
        //step 2 = tail de next vich lga de new node
        tail->next = newNode;
        //step 3 = newNode nu hi tail keh de
        tail = newNode;
    }
}
void insertatanypos(Node*& head,Node*& tail,int data,int position){
    int len = length(head);
    //sidhi ji gal hai ja ta position 1 aayi chup chap insert at head krde
    if(position==1) insertathead(head,tail,data);
    //te dooji sidhi ji gal eh hai ki ja position length to jaada chay phir oh jedi mrji aay us node nu tail te place krde
    else if(position > len) insertattail(head,tail,data);
    //hun aayga mja kyuki ja es case tak aayaa matlab position koi vichkarli aa gyi hai 
    #if 0
    else{
        //insert matlab kithe middle vich krna okkk
        //pehle step ta same hi rhega node create kr 
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //step 2 = mein do pointer bna lunga prev and curr jo ki maanu help kranga insert krn da layi
        //prev nu mein null krdunga
        //ta curr nu head de brabar 
        Node* prev = NULL;
        Node* curr = head;
        //step3 = mein  loop chlaunga jad tak position != 1 na hojava taaki curr mera mein jithe insert krna us to aaga hove ta prev usi de picha hova
        // then apply loop
        while(position != 1){
            //pehle mein position ktaunga par position bacho vi ja katai ta vi dikkat koi nhi hai 
            position--;
            //but pehle maanu prev nu curr de brabaar krna then  curr nu curr de next nhi ta prev ki curr vali node nu hi point krn lag jega jo ki glt hai 
            prev = curr;
            //hun mein current nu current da next krunga
            curr = curr->next;
        }
        //hun mera prev us node ta khra jis node de aaga insert krna 
        //te mera current us node ta khra jis node de piche insert krna 
        //so firstly mein prev de next nu new node ta point krwa dunga
        prev->next = newNode;
        //and secondly mein newnode de next nu current ta point krwa dunga
        //and at the end my linked list is ready 
        newNode->next = curr;
    }
    #endif
    //ab maanlo hmko do pointer nhi bnanana hme ek hi pointer se krna ho toh??
    else{
         //insert matlab kithe middle vich krna okkk
        //pehle step ta same hi rhega node create kr 
        //Step 1 = create new node
        Node* newNode = new Node(data);
        //Step 2 - hm ek current pointer bna lete hai jisko hm head se initialize kr denge
        Node* curr = head;
        //ab hme position tak phuncha hai toh
        while(position != 2){
            position--;
            //tab tak current mein current ka next krte jao jai mata dii krke
            curr =  curr->next;
        }
        //or we can also apply for loop 
        // for(int i = 0; i < position - 1; i++){
        //     curr = curr->next;
        // }
        //jab yeh sb ho jaay to newnode ke next ko curr ke next ke equal krdo 
            newNode->next = curr->next;
            //and uske baad curr ke next ko newnode se point krwado
            curr->next = newNode;
    }
}
void deletenodeinsll(Node*& head,Node*& tail,int position){
//agr head hi null hua phir ?
    if(head == NULL) {
        cout<<"cannot delete, because LL is empty"<<endl;
        return ;
    }
    //Agr ek hi node hui phir
    if(head == tail){
        //single element ;
        //step 1 - mein pehle ek temporary node lelunga
        //hmesha temp lo yeh achi  practice hoti hai testcase nhi phsenge
        Node* temp = head;
        //step 2 - then mein delete krdunga us temporary node nu 
        delete temp;
        //head nu null krdunga
        head = NULL;
        //tail nu vi null krdunga
        tail = NULL;
        //then return krdunga
        return ;
    }
    
    //pehle mein lenght find krlunga aaga kaam aaygi
    int len = length(head);
    if(position == 1){
        //matlab head node delete krni hai 
        //Step 1 - create the temporary node and usme head assign krdo
        Node* temp = head;
        //Step 2 - head ko temporary ke next set krdo kyuki hmna temporary delete krni hai 
        head = temp->next;
        //Step 3 - hun ta assi delete kr skde aa temp nu
        //yeh hmari glti hogi hm temp ko temp->next = null krna se pehle hi delete kr denge to poori linked list ka main end delete ho jayga
        //so avoid mistake and then do step 3
        //Step 3 - make next of temp null
        temp->next = NULL;
        //Step 4 - hun asi temp nu delete kr daanga
        delete temp;
        //Te eh saadi head te deletion done ho gyi
    }
    //Now saada second case agr position length de brabar aagyi phir ek tarah to delete at tail
    else if(position == len){
        //sb to pehle assi traverse kranga te tail de previous node tak phunchanga
        //Step 1 = create temporary pointer to traverse for find the previous node of tail pointer
        Node* temp = head;
        //Step 2 = now start traversing
        while(temp->next != tail){
            temp = temp->next;
        }
        //Step 3 - temp node nu assi null kr daanga
        temp->next = NULL;
        //hun assi tail nu delete kr daanga kyuki ja assi pehle hi tail nu bula laya ta dikkat eh hai jehri last node assi delete krni hai oh delete hi ni
        //kr pavange 
        //esliye
        //Step 4 - delete tail
        delete tail;
        //Step 5 - assi tail nu prev naal initialize kr daanga assi esliye hi previous pointer lyaya si taaki tail nu bcha skiya 
        //ehda naal do fayda tail delete krn naal linked list ta koi asaar nhi plus
        //tail delete hun toh baad vi tail nu phir initialize krn lyi pehla hi temporary pointer khra hai 
        tail = temp;
    }
    else{
        //Beta ji etha tak phunch gaay matlab 
        //1.) naa hi linked list khali hai 
        //2.) naa hi single element hai 
        //3.) naa hi position 1 vali hai 
        //4.) naa hi last position hai 
        //Matlab hun vaari aa hi gyi middle positions vaaalya dii
        //chlo phir hoyiye shuru

        //oh vi prev ta curr pointer vaali approach laana hai etha
        //Step 1 = pehle do pointer bna le prev ta curr prev nu null naal initialize kr le te curr nu head naal
        Node*  prev = NULL;
        Node* curr = head;
        //Step 2 - loop travel kr la jad tak position di value 1 nhi ho jaandi 
        while(position != 1){
            position--;
            //ehda naal jehri node delete krni hai prev ohdi just pichli vaali node hai 
            prev = curr;
            //curr oh node hai jo delete honi hai 
            curr = curr->next;
        }
        //Step 3 = hun kyuki assi curr nu ta delete krna ta prev de next vich curr da next paa dene hai 
        prev->next = curr->next;
        //Step 4 = ta assi current de next nu null krdene hai taaki linked list ta asar na pava
        curr->next = NULL;
        //step 5 - hun assi delete kr dene hai current nu 
        delete curr;
    }


}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,78);
    insertathead(head,tail,32);
    insertattail(head,tail,39);
    insertattail(head,tail,37);
    insertatanypos(head,tail,398,2);
    deletenodeinsll(head,tail,3);
    //print kr dena hai linked list nu
    int len = length(head);
    cout<<"Length of linked list is : "<<len<<endl;
    printll(head);
    return 0;
}
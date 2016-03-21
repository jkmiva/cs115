Node* reverseNode(Node * rNode){
    if(rNode == NULL || rNode->next == NULL){
	return rNode;
    }
    else{
	Node* temp = reverseNode(rNode->next);
        rNode->next->next = rNode;
	rNOde->next = NULL;
	return temp;
    }
}

//E2
void destroyNode(Node *rNode){
//pre::rNode: a reference to Node
//post:: recursively destroy the Node
//return:: nothing
    if (rNode == NULL) return;
    destroyNode(rNode->next);
    delete rNode;
}

//E3
struct Class{
    const char *className;
    int capacity;
    List *enrolled;
    Queue *waitList;
}

Class *createClass(char *name, int cap){
    Class *newClass = new Class;
    newClass->className = name;
    newClass->capacity = cap;
    newClass->enrolled = createList();
    newClass->waitList = createQueue();
    return newClass;
}

void destroyClass(Class *p){
    destroyList(p->enrolled);
    destroyQueue(p->waitList);
    delete p;
}

void addStudent(Class *p,Student stu){
    int currentStu = listCount(p->enrolleds);
    if(currentStu < p->capacity)
	insertTail(p->enrolled, stu);
    else
	enQueue(p->waitList,stu);
}

void dropStudent(Class *p,int stuID){
    Student stuDel,stuAdd;
    deleteElement(p->enrolled,stuID,&stuOut);
    deQueue(p->waitList,&stuAdd);
    addStudent(p,stuAdd);
}
    

    



	

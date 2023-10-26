//C 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct TNode {
    char name[20];
    struct TNode* firstChild;
    struct TNode* nextSibling;
}TNode;

TNode* node[MAX_NODES];
int k = 0;

TNode* makeNewNode(char in[]) {
    TNode* nNode = (TNode*)malloc(sizeof(TNode));
    strcpy(nNode->name, in);
    nNode->firstChild = NULL;
	nNode->nextSibling = NULL;
    return nNode;
}

int checkNode(char in[]) {
	for (int i = 0; i < k; i++) {
		if (strcmp(node[i]->name, in) == 0) {
			return i;
		}
	}
	return -1;
}

void insertNewNode(char p[], char c[]) {
    TNode* parent = NULL;
    TNode* child = NULL;
    
    int nump = checkNode(p);
    int numc = checkNode(c);
    if (nump != -1) {
    	parent = node[nump];
	} else {
		parent = makeNewNode(p);
		node[k] = parent;
		k++;
	}
	if (numc != -1) {
    	child = node[numc];
	} else {
		child = makeNewNode(c);
		node[k] = child;
		k++;
	}
    
    if (parent->firstChild == NULL) {
           parent->firstChild = child;
    } else {
        TNode* t = parent->firstChild;
        while (t->nextSibling != NULL) {
            t = t->nextSibling;
        }
        t->nextSibling = child;
    }
    
}

TNode* findNode(char in[]) {
	for (int i = 0; i < k; i++) {
		if (strcmp(node[i]->name, in) ==0) {
			return node[i];
		}
	}
}

int countnode(TNode *h){
	TNode*p = h->firstChild;
	if(p==NULL)return 1;
	int count=0;

	while(p!=NULL){
		count+=countnode(p);
		p=p->nextSibling;
	}
	return count+1;
}
int generation(TNode *h){
	if(h==NULL)return 0;
	int count=0;
	TNode *p = h->firstChild;
	while(p!=NULL){
		int k=generation(p);
		if(count<k)count=k;
		p=p->nextSibling;
	}
	return count+1;
}

int countD(char in[]) {
    int num = 0;
    TNode* root = findNode(in);
    num = countnode(root) - 1;
    return num;
}

int countN(char in[]) {
    int num = 0;
    TNode* root = findNode(in);
    num = generation(root) -1;
    return num;
}
int main() {
    char childName[MAX_NODES][20];
    char parentName[MAX_NODES][20];
    int i = 1;
    char in[40];
    fgets(in, 40, stdin);
    if (in[strlen(in) - 1] == '\n') in[strlen(in) - 1] = '\0';
    sscanf(in, "%s %s", childName[0], parentName[0]);
    node[k] = makeNewNode(parentName[0]);
    TNode* p = makeNewNode(childName[0]);
    node[k]->firstChild = p;
    k++;
    node[k] = p;
    k++;
    
    while (1) {
        fgets(in, 40, stdin);
        if (in[0] == '*') {
            break;
        }
        
        if (in[strlen(in) - 1] == '\n') in[strlen(in) - 1] = '\0';
    	sscanf(in, "%s %s", childName[i], parentName[i]);
    	
        insertNewNode(parentName[i], childName[i]);
        i++;
    }
    
    while (1) {
        char in[40];
        fgets(in, 40, stdin);
        if (in[0] == '*') {
            break;
        }
        
        if (in[strlen(in) - 1] == '\n') in[strlen(in) - 1] = '\0';
    	sscanf(in, "%s %s", childName[i], parentName[i]);
    	
        if (childName[i][0] == 'd') {
            printf("%d\n", countD(parentName[i]));
        } else printf("%d\n", countN(parentName[i]));
        i++;
    }
    return 0;
}


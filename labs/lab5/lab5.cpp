
#include "List.h"
#include <iostream>

int main(){
	LinkedList* list = new LinkedList();

	list->appendNode("boogeyman");
	list->appendNode("ghost");
	list->appendNode("scarecrow");
	list->appendNode("witch");
	list->appendNode("zombie");


	std::cout << "I am appending several strings to the list.\n\n";
	list->displayList();
	
	list->insertNode("vampire", 3);
	std::cout << "I am inserting vampire in the list.\n\n";
	list->displayList();

	list->deleteNode(1);
	std::cout << "I am deleting ghost from the list.\n\n";
	list->displayList();
}
#include "doubly_linked_list.hpp"
#include <iostream>

using gra::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	for (Node* current = begin; current != nullptr; ) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	begin = nullptr;
	end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t size = 0;
	for (Node* current = begin; current != nullptr; current = current->next) {
		size++;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	for (Node* current = begin; current != nullptr; current = current->next) {
		if (current->value == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	for (Node* current = begin; current != nullptr; current = current->next) {
		std::cout << current->value << " ";
	}
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* new_node = new Node(value);
	if (begin == nullptr) {
		begin = new_node;
		end = new_node;
	} else {
		end->next = new_node;
		new_node->prev = end;
		end = new_node;
	}
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	for (Node* cur = begin; cur; cur = cur->next) {
        if (cur->value == value) {
            // переподвязываем соседей
            if (cur->prev) {
                cur->prev->next = cur->next;
			} else {
                begin = cur->next; // удаляем первый
			}

            if (cur->next) {
                cur->next->prev = cur->prev;
			} else {
                end = cur->prev; // удаляем последний
			}

            delete cur;
            return true;
        }
	}
    return false;
}

template class DoublyLinkedList<int>;
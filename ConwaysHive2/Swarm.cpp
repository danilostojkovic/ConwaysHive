template <class T>
class Swarm
{
private:
    class node{
    public:
        T* info;
        node* next;
        node(T*, node* n=nullptr);
        node(node& n);
        node& operator==(const node& n){
            return new node(n.info, n.next);
        }
        ~node();
    };
    node* first;
    void deepCopy(node* s);
    void destroy(node* s);
    class iterator{
        friend Swarm<T>;
        private:
            node* ptr;
            bool pte;          //past-the-end
            iterator(node* p, bool past=false):ptr(p), pte(past){}
        public:
            iterator& operator++(){        //prefisso
                if(ptr!=nullptr && !pte){
                    if(!ptr->next){
                        ptr=nullptr;
                        pte=true;
                    }
                    else
                        ptr=ptr->next;
                }
                return *this;
            }
            iterator operator++(int){      //postfisso
                iterator aux(*this);
                if(ptr!=nullptr && !pte){
                    if(!ptr->next){
                        ptr=nullptr;
                        pte=true;
                    }
                    else
                        ptr=ptr->next;
                }
                return aux;
            }
            bool operator==(const iterator& c) const{
                return ptr==c.ptr;
            }
            bool operator!=(const iterator& c) const{
                return ptr!=c.ptr;
            }
            T* operator->() const{
                return ptr->info;
            }
            T* operator*() const{
                return ptr->info;
            }
    };
public:
    Swarm();
    Swarm(const Swarm&);
    Swarm& operator=(const Swarm&);
    ~Swarm();
    void insert(T*);
    void remove(T*);
    iterator begin() const { return iterator(first); }
    iterator end() const { return iterator(nullptr, true); }
};

template <class T>
Swarm<T>::node::node(T* t, node* n):info(t), next(n) { }
template <class T>
void Swarm<T>::deepCopy(node* s){
    first=new node(*s);
    node* a=first;
    s=s->next;
    while(s){
        a=a->next=new node(*s);
        s=s->next;
    }
}
template <class T>
void Swarm<T>::destroy(node* s){
    if(s->next)
        destroy(s->next);
    delete s;
}
template <class T>
Swarm<T>::Swarm():first(nullptr){ }
template <class T>
Swarm<T>::Swarm(const Swarm<T>& s){
    deepCopy(s.first);
}
template <class T>
Swarm<T>& Swarm<T>::operator=(const Swarm<T>& s){
    if(this!=&s){
        destroy(first);
        deepCopy(s.first);
    }
    return *this;
}
template <class T>
Swarm<T>::~Swarm<T>(){
    destroy(first);
}
template <class T>
void Swarm<T>::insert(T* t){                     //inserisce in testa per ottimizzare
    first=new node(t, first);
}
template <class T>
void Swarm<T>::remove(T* t){
    node* f=first;
    if((f->info)==(t)){
        first=f->next;
        delete f;
        return;
    }
    while(f->next){
        if((f->next->info)==(t)){
            node* a=f->next;
            f->next=a->next;
            delete a;
            return;
        }
        f=f->next;
    }
}

template<class T>
Swarm<T>::node::~node(){
    delete info;
}

template<class T>
Swarm<T>::node::node(Swarm::node &n)
{
    info=n.info;
    next=n.next;
}

template <class T>
class DeepPtr
{
public:
    T* info;      //puntatore polimorfo
    DeepPtr(T*);
    DeepPtr(const DeepPtr&);
    DeepPtr& operator=(const DeepPtr&);
    ~DeepPtr();
    const T& operator*() const;
    bool operator==(const DeepPtr&) const;
};
template <class T>
DeepPtr<T>::DeepPtr(T* a){
    info=a;                            //DeepPtr punterà all'oggetto di tipo T passato al costruttore
}
template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& a){            //deep copy perché invoca il costruttore di copia di T
    info=new T(*(a.info));           //l'oggetto di tipo T a cui punta a verrà copiato in un nuovo oggetto il cui puntatore andrà in info
}
template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& a){
    if(&info!=&a.info){                      //come il costruttore di copia ma controlla che non puntino già allo stesso oggetto
        delete info;
        info=new T(*(a.info));
    }
    return *this;
}
template <class T>
DeepPtr<T>::~DeepPtr<T>(){
    delete info;                             //invoca il distruttore dell'oggetto di tipo T a cui punta info
}
template <class T>
const T& DeepPtr<T>::operator*() const{
    return info;
}
template <class T>
bool DeepPtr<T>::operator==(const DeepPtr<T>& a) const{
    return *info==*(a.info);
}

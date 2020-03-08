//
//  Node3Dnd.h.h
//  ttcr
//
//  Created by Bernard Giroux on 18-10-20.
//  Copyright © 2018 Bernard Giroux. All rights reserved.
//

#ifndef Node3Dnd_h
#define Node3Dnd_h

#include "Node3Dn.h"


// for temporary dynamic nodes

namespace ttcr {
    
    template<typename T1, typename T2>
    class Node3Dnd : public Node3Dn<T1,T2> {
    public:
        Node3Dnd() : Node3Dn<T1,T2>(1) {}
        
        virtual ~Node3Dnd() {}
        
        Node3Dnd(const T1 t, const T1 xx, const T1 yy, const T1 zz, const size_t nt,
                 const size_t i) : Node3Dn<T1,T2>(t, xx, yy, zz, 1, 0) {}

        Node3Dnd(const T1 t, const sxyz<T1>& s, const size_t nt,
                 const size_t i) : Node3Dn<T1,T2>(t, s, 1, 0) {}
        
        Node3Dnd(const Node3Dnd<T1,T2>& node) :
        Node3Dn<T1,T2>(node.tt[0], node.x, node.y, node.z, 1, 0)
        {
            this->gridIndex = node.gridIndex;
            this->owners = node.owners;
            this->slowness = node.slowness;
            this->primary = node.primary;
        }
        
        T1 getTT(const size_t n) const { return this->tt[0]; }
        void setTT(const T1 t, const size_t n ) { this->tt[0] = t; }
        
    };
    
    template<typename T1, typename T2>
    std::ostream& operator<< (std::ostream& os, const Node3Dnd<T1, T2> &n) {
        os << n.getX() << ' ' << n.getY() << ' ' << n.getZ();
        return os;
    }

    template<typename T1, typename T2>
    sxyz<T1> operator-(const Node3Dnd<T1,T2>& lhs, const Node3Dnd<T1,T2>& rhs) {
        return sxyz<T1>( lhs.getX()-rhs.getX(), lhs.getY()-rhs.getY(), lhs.getZ()-rhs.getZ() );
    }
    
    template<typename T1, typename T2>
    sxyz<T1> operator-(const sxyz<T1>& lhs, const Node3Dnd<T1,T2>& rhs) {
        return sxyz<T1>( lhs.x-rhs.getX(), lhs.y-rhs.getY(), lhs.z-rhs.getZ() );
    }
    
    template<typename T1, typename T2>
    sxyz<T1> operator-(const Node3Dnd<T1,T2>& lhs, const sxyz<T1>& rhs) {
        return sxyz<T1>( lhs.getX()-rhs.x, lhs.getY()-rhs.y, lhs.getZ()-rhs.z );
    }

}

#endif /* Node3Dnd_h_h */

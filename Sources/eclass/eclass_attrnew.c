/*
 * CicmWrapper
 *
 * A wrapper for Pure Data
 *
 * Copyright (C) 2013 Pierre Guillot, CICM - Université Paris 8
 * All rights reserved.
 *
 * Website  : http://www.mshparisnord.fr/HoaLibrary/
 * Contacts : cicm.mshparisnord@gmail.com
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published
 * by the Free Software Foundation; either version 2 of the License.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include "eclass.h"

//! Allocate the memory and intializa an new attribute for an eclass (You should prefer to use the MACROS)
/*
 \ @memberof        eattr
 \ @param c         The eclass pointer
 \ @param attrname  The attribute name
 \ @param type      The attribute type
 \ @param size      The attribute size
 \ @param maxsize   The attribute max size
 \ @param maxsize   The attribute flags
 \ @param offset    The attribute bit offset in the object structure
 \ @return          Nothing
*/
void eclass_new_attr_typed(t_eclass* c, char* attrname, char* type, long size, long maxsize, long flags, long offset)
{
    int i;
    char getattr[256];
    if(size < 1)
        return;
    for(i = 0; i < c->c_nattr; i++)
    {
        if(c->c_attr[i].name == gensym(attrname))
            return ;
    }
    
    c->c_attr = (t_eattr *)realloc(c->c_attr, (c->c_nattr + 1) * sizeof(t_eattr));
    if(c->c_attr)
    {
        c->c_attr[c->c_nattr].name = gensym(attrname);
        c->c_attr[c->c_nattr].type = gensym(type);
        c->c_attr[c->c_nattr].category = c->c_class.c_name;
        c->c_attr[c->c_nattr].label = gensym("");
        c->c_attr[c->c_nattr].style = gensym("entry");
        c->c_attr[c->c_nattr].order = c->c_nattr+1;
        c->c_attr[c->c_nattr].save  = 0;
        c->c_attr[c->c_nattr].paint = 0;
        c->c_attr[c->c_nattr].invisible = 0;
        c->c_attr[c->c_nattr].flags     = flags;
        c->c_attr[c->c_nattr].offset    = offset;
        c->c_attr[c->c_nattr].size      = size;
        c->c_attr[c->c_nattr].sizemax   = maxsize;
        c->c_attr[c->c_nattr].getter    = NULL;
        c->c_attr[c->c_nattr].setter    = NULL;
        c->c_attr[c->c_nattr].clipped   = 0;
        c->c_attr[c->c_nattr].minimum   = 0;
        c->c_attr[c->c_nattr].maximum   = 1;
        c->c_attr[c->c_nattr].step      = 1;
        c->c_attr[c->c_nattr].defvals   = gensym("");
        c->c_attr[c->c_nattr].itemslist = NULL;
        c->c_attr[c->c_nattr].itemssize = 0;
        class_addmethod((t_class *)c, (t_method)eclass_attr_setter, gensym(attrname), A_GIMME, 0);
        sprintf(getattr, "get%s", attrname);
        class_addmethod((t_class *)c, (t_method)eclass_attr_getter, gensym(getattr), A_GIMME, 0);
        c->c_nattr++;
    }
}


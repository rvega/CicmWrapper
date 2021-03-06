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

#ifndef DEF_EPD
#define DEF_EPD

#define cicm_post() erouter_add_libary(gensym("CICM"), "CICM Libraries by Pierre Guillot", "© 2013 - 2014  CICM | Paris 8 University", "Version 0.2")
#define hoa_post() erouter_add_libary(gensym("HOA"), "HOA Library by Julien Colafrancesco, Pierre Guillot & Eliott Paris", "© 2012 - 2014  CICM | Paris 8 University", "Version 1.1")
#include "eclass/eclass.h"

#endif
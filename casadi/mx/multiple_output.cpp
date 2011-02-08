/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "multiple_output.hpp"
#include "../fx/fx_internal.hpp"
#include "../stl_vector_tools.hpp"

using namespace std;

namespace CasADi{

MultipleOutput::MultipleOutput(int n_out){
  children_.resize(n_out, 0);
}

MultipleOutput::~MultipleOutput(){
}

OutputNode::OutputNode(const MX& parent, int i_out) : parent_(parent), i_out_(i_out){
  // Get the node of the parent
  MultipleOutput* p = dynamic_cast<MultipleOutput*>(parent_.get());
  casadi_assert(p!=0);
  
  // Save a pointer to the object
  casadi_assert(p->children_.size()>i_out);
  casadi_assert(p->children_[i_out] == 0);
  p->children_[i_out] = this;
}

OutputNode::~OutputNode(){
  // Get the node of the parent
  MultipleOutput* p = static_cast<MultipleOutput*>(parent_.get());
  
  // Remove the parent from the parent
  casadi_assert(p->children_[i_out_] == this);
  p->children_[i_out_] = 0;
}
  

} // namespace CasADi

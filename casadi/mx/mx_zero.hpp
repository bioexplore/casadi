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

#ifndef MX_ZERO_HPP
#define MX_ZERO_HPP

#include "mx_node.hpp"

namespace CasADi{

/** \brief Represents an MX that is only composed of a constant.
	\author Joel Andersson 
	\date 2010

	A regular user is not supposed to work with this Node class.
	This user can call MX(double) directly, or even rely on implicit typecasting.
	\sa zeros , ones
*/
class MXZero : public MXNode{
  public:

    /** \brief  Constructor */
    MXZero(int n, int m);

    /** \brief  Clone function */
    virtual MXZero* clone() const;

    /** \brief  Print */
    virtual void print(std::ostream &stream, const std::vector<std::string>& args) const;

    /** \brief  Evaluate the function and store the result in the node */
    virtual void evaluate(const VDptr& input, Dptr& output, const VVDptr& fwdSeed, VDptr& fwdSens, const VDptr& adjSeed, VVDptr& adjSens, int nfwd, int nadj);

    /** \brief  Indicate that the node is constant */
    virtual bool isConstant() const;

};

} // namespace CasADi


#endif // MX_ZERO_HPP

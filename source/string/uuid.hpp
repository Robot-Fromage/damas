/*
*   Damas
*__________________
* @file         uuid.hpp
* @author       Clement Berthaud
* @brief        This file provides declaration for weak UUID functions.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
/////////////////////////////////////////////////////
// Weak UUID
/// @fn         GenerateWeakUUID()
/// @brief      Generate a weak UUID.
/// @details    Weak UUID is an UUID that is pseudo random but with no guarantee to be unique at all. This it can be suitable for light uses.
std::string GenerateWeakUUID( uint8 iLen );

DAMAS_NAMESPACE_END


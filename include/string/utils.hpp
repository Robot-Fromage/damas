/*
*   Damas
*__________________
* @file         utils.hpp
* @author       Clement Berthaud
* @brief        This file provides string utility tools.
* @copyright    Copyright 2021 Clément Berthaud
* @license      Please refer to LICENSE.md
*/
#pragma once
#include "core/core.hpp"

DAMAS_NAMESPACE_BEGIN
void ReplaceAllOccurences( std::string& iStr, const std::string& iFrom, const std::string& iTo );
size_t LevenshteinDistance( const char* iA, size_t iLenA, const char* iB, size_t iLenB );
DAMAS_NAMESPACE_END


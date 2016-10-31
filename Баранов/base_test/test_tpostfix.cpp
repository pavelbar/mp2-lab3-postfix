#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
    string expression = "2+2";
    ASSERT_NO_THROW(TPostfix postfix(expression));
}


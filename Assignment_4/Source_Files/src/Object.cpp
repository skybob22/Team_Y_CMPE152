#include "Object.h"

namespace custOp {
        Object operator+(Object lhs, Object rhs) {
        double lval = castObjTo<double>(lhs);
        double rval = castObjTo<double>(rhs);
        double res = lval + rval;

        if (lhs.is<double>() || rhs.is<double>()) {
            return res;
        } else {
            return static_cast<int>(res);
        }
    }

    Object operator-(Object lhs, Object rhs) {
        double lval = castObjTo<double>(lhs);
        double rval = castObjTo<double>(rhs);
        double res = lval - rval;

        if (lhs.is<double>() || rhs.is<double>()) {
            return res;
        } else {
            return static_cast<int>(res);
        }
    }

    Object operator*(Object lhs, Object rhs) {
        double lval = castObjTo<double>(lhs);
        double rval = castObjTo<double>(rhs);
        double res = lval * rval;

        if (lhs.is<double>() || rhs.is<double>()) {
            return res;
        } else {
            return static_cast<int>(res);
        }
    }

    Object operator/(Object lhs, Object rhs) {
        double lval = castObjTo<double>(lhs);
        double rval = castObjTo<double>(rhs);
        double res = lval / rval;

        if (lhs.is<double>() || rhs.is<double>()) {
            return res;
        } else {
            return static_cast<int>(res);
        }
    }

    Object operator&&(Object lhs, Object rhs) {
        if (!lhs.is<bool>() || !rhs.is<bool>()) {
            return false;
        }
        return (lhs.as<bool>() && rhs.as<bool>());
    }

    Object operator||(Object lhs, Object rhs) {
        if (!lhs.is<bool>() || !rhs.is<bool>()) {
            return false;
        }
        return (lhs.as<bool>() && rhs.as<bool>());
    }

//Only works for ints, doubles, and bools
    bool operator==(Object lhs, Object rhs) {
        return (castObjTo<double>(lhs) == castObjTo<double>(rhs));
    }

    bool operator!=(Object lhs, Object rhs) {
        return !(lhs == rhs);
    }

    bool operator>(Object lhs, Object rhs) {
        return (castObjTo<double>(lhs) > castObjTo<double>(rhs));
    }

    bool operator>=(Object lhs, Object rhs) {
        return (lhs > rhs) || (lhs == rhs);
    }

    bool operator<(Object lhs, Object rhs) {
        return (castObjTo<double>(lhs) < castObjTo<double>(rhs));
    }

    bool operator<=(Object lhs, Object rhs) {
        return (lhs < rhs) || (lhs == rhs);
    }
}
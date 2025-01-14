// SPDX-FileCopyrightText: 2021 heersin <teablearcher@gmail.com>
// SPDX-License-Identifier: LGPL-3.0-only

#include <rz_il/rzil_opcodes.h>
#include <rz_il/rzil_vm.h>

void *rz_il_handler_b0(RzILVM *vm, RzILOp *op, RzILOpArgType *type) {
	rz_return_val_if_fail(vm && op && type, NULL);

	RzILBool *ret = rz_il_bool_new(false);
	*type = RZIL_OP_ARG_BOOL;
	return ret;
}

void *rz_il_handler_b1(RzILVM *vm, RzILOp *op, RzILOpArgType *type) {
	rz_return_val_if_fail(vm && op && type, NULL);

	RzILBool *ret = rz_il_bool_new(true);
	*type = RZIL_OP_ARG_BOOL;
	return ret;
}

void *rz_il_handler_and_(RzILVM *vm, RzILOp *op, RzILOpArgType *type) {
	rz_return_val_if_fail(vm && op && type, NULL);

	RzILOpAnd_ *op_and_ = op->op.and_;
	RzILBool *x = rz_il_evaluate_bool(vm, op_and_->x, type);
	RzILBool *y = rz_il_evaluate_bool(vm, op_and_->y, type);

	RzILBool *result = rz_il_bool_and(x, y);
	rz_il_bool_free(x);
	rz_il_bool_free(y);

	*type = RZIL_OP_ARG_BOOL;
	return result;
}

void *rz_il_handler_or_(RzILVM *vm, RzILOp *op, RzILOpArgType *type) {
	rz_return_val_if_fail(vm && op && type, NULL);

	RzILOpOr_ *op_or_ = op->op.or_;
	RzILBool *x = rz_il_evaluate_bool(vm, op_or_->x, type);
	RzILBool *y = rz_il_evaluate_bool(vm, op_or_->y, type);

	RzILBool *result = rz_il_bool_or(x, y);
	rz_il_bool_free(x);
	rz_il_bool_free(y);

	*type = RZIL_OP_ARG_BOOL;
	return result;
}

void *rz_il_handler_inv(RzILVM *vm, RzILOp *op, RzILOpArgType *type) {
	rz_return_val_if_fail(vm && op && type, NULL);

	RzILOpInv *op_inv = op->op.inv;
	RzILBool *x = rz_il_evaluate_bool(vm, op_inv->x, type);
	RzILBool *result = rz_il_bool_not(x);
	rz_il_bool_free(x);

	return result;
}

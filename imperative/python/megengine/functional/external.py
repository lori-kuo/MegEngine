# -*- coding: utf-8 -*-
# MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
#
# Copyright (c) 2014-2021 Megvii Inc. All rights reserved.
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# pylint: disable=redefined-builtin
from typing import Sequence

from ..core._imperative_rt.core2 import apply
from ..core.ops import builtin


def tensorrt_runtime_opr(inputs, *, data: bytes = None):
    # empty model will give None result
    if data is None:
        return None
    op = builtin.TensorRTRuntime(data, len(data))
    # return sequence of outputs
    return apply(op, *inputs)

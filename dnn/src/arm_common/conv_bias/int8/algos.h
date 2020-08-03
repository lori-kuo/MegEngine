/**
 * \file dnn/src/arm_common/conv_bias/int8/algos.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 */

#pragma once

#include "src/arm_common/conv_bias/opr_impl.h"

namespace megdnn {
namespace arm_common {

class ConvBiasImpl::AlgoS8DirectStride1 final : public AlgoBase {

public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8STRD1"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;
    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;

    bool is_preferred(const NCBKernSizeParam& param) const override;

    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoS8DirectStride2 final : public AlgoBase {

public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8STRD2"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;

    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoS8DirectNCHW44 final : public AlgoBase {
public:
    AlgoS8DirectNCHW44() {}
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8_NCHW44_DIRECT"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;
    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    bool is_preferred(const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoS8DirectNCHWNCHW44 final : public AlgoBase {
public:
    AlgoS8DirectNCHWNCHW44() {}
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8_CONV_NCHW_NCHW44"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;
    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    bool is_preferred(const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoS8ChanWiseStride1NCHW44 final : public AlgoBase {
public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8_CHAN_WISE_STRD1_NCHW44"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;
    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoS8ChanWiseStride2NCHW44 final : public AlgoBase {
public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "S8_CHAN_WISE_STRD2_NCHW44"; }
    bool usable(const NCBKernSizeParam& param,
                AlgoSelectionStrategy algo_selection_strategy) const override;
    size_t get_workspace(const NCBKernSizeParam& param) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

#if __ARM_FEATURE_DOTPROD

class ConvBiasImpl::AlgoDotS8DirectNCHWNCHW44 final : public AlgoBase {
public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "ARMDOTS8_NCHW_NCHW44"; }
    bool usable(const NCBKernSizeParam&,
                AlgoSelectionStrategy algo_selection_strategy) const override;

    size_t get_workspace(const NCBKernSizeParam&) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoDotS8DirectStride1 final : public AlgoBase {

public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "ARMDOTS8STRD1"; }
    bool usable(const NCBKernSizeParam&,
                AlgoSelectionStrategy algo_selection_strategy) const override;

    size_t get_workspace(const NCBKernSizeParam&) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoDotS8DirectStride2 final : public AlgoBase {

public:
    bool is_reproducible() const override { return true; }
    const char* name() const override { return "ARMDOTS8STRD2"; }

    bool usable(const NCBKernSizeParam&,
                AlgoSelectionStrategy algo_selection_strategy) const override;

    size_t get_workspace(const NCBKernSizeParam&) const override;
    virtual SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;
    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};

class ConvBiasImpl::AlgoDotS8Direct_NCHW44 final : public AlgoBase {
public:
    AlgoDotS8Direct_NCHW44() {}

    bool is_reproducible() const override { return true; }
    const char* name() const override { return "ARMDOTS8DIRECT_NCHW44"; }
    bool usable(const NCBKernSizeParam&,
                AlgoSelectionStrategy algo_selection_strategy) const override;

    size_t get_workspace(const NCBKernSizeParam&) const override;

    SmallVector<NCBKern> dispatch_kerns(
            const NCBKernSizeParam& param) const override;

    bool is_preferred(const NCBKernSizeParam& param) const override;

    ConvAlgoTypePack get_algo_type() const override {
        return {AlgoDataType::QINT8X8X32, AlgoCategory::DIRECT};
    }
};
#endif

class ConvBiasImpl::AlgoS8WinogradF23_8x8 final : public AlgoBase {
public:
    AlgoS8WinogradF23_8x8(fallback::MatrixMulImpl::AlgoBase* matmul_algo,
                          uint32_t tile_size)
            : m_matmul_algo{matmul_algo}, m_tile_size{tile_size} {}
    const char* name() const override {
        if (m_name.empty()) {
            m_name = ConvBiasImpl::algo_name<ConvBias::WinogradParam>(
                    m_matmul_algo->name(), {8, 2, m_tile_size});
        }
        return m_name.c_str();
    }
    MEGDNN_WINOGRAD_ALGO_FUN_DECLARE(AlgoDataType::QINT8X8X32);
};

//=======================input int8 compute fp32 output int8============
class ConvBiasImpl::AlgoS8CF32WinogradF23_4x4_NCHW44 final : public AlgoBase {
public:
    AlgoS8CF32WinogradF23_4x4_NCHW44(
            fallback::MatrixMulImpl::AlgoBase* matmul_algo, uint32_t tile_size)
            : m_matmul_algo{matmul_algo}, m_tile_size{tile_size} {}
    const char* name() const override {
        if (m_name.empty()) {
            m_name = ConvBiasImpl::algo_name<ConvBias::WinogradParam>(
                    m_matmul_algo->name(), {4, 2, m_tile_size},
                    param::ConvBias::Format::NCHW44);
        }
        return m_name.c_str();
    }
    MEGDNN_WINOGRAD_ALGO_FUN_DECLARE(AlgoDataType::QINT8X8X32);
};

//=======================input int8 compute int16 output int8============
class ConvBiasImpl::AlgoS8WinogradF23_8x8_NCHW44 final : public AlgoBase {
public:
    AlgoS8WinogradF23_8x8_NCHW44(fallback::MatrixMulImpl::AlgoBase* matmul_algo,
                                 uint32_t tile_size)
            : m_matmul_algo{matmul_algo}, m_tile_size{tile_size} {}
    const char* name() const override {
        if (m_name.empty()) {
            m_name = ConvBiasImpl::algo_name<ConvBias::WinogradParam>(
                    m_matmul_algo->name(), {8, 2, m_tile_size},
                    param::ConvBias::Format::NCHW44);
        }
        return m_name.c_str();
    }

    MEGDNN_WINOGRAD_ALGO_FUN_DECLARE(AlgoDataType::QINT8X8X32);
};

}  // namespace arm_common
}  // namespace megdnn

// vim: syntax=cpp.doxygen

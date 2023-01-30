#pragma once

#define IT_SET_PREDICATION			0x20
#define IT_DRAW_INDEX_2				0x27
#define IT_CONTEXT_CONTROL			0x28
#define IT_INDEX_TYPE				0x2A
#define IT_DRAW_INDEX_AUTO			0x2D
#define IT_DRAW_INDEX_IMMD			0x2E
#define IT_NUM_INSTANCES			0x2F
#define IT_INDIRECT_BUFFER_PRIV		0x32
#define IT_STRMOUT_BUFFER_UPDATE	0x34
#define IT_MEM_SEMAPHORE			0x39
#define IT_WAIT_REG_MEM				0x3C
#define IT_MEM_WRITE				0x3D
#define IT_SURFACE_SYNC				0x43
#define IT_EVENT_WRITE				0x46

#define IT_LOAD_CONFIG_REG			0x60
#define IT_LOAD_CONTEXT_REG			0x61
#define IT_LOAD_ALU_CONST			0x62
#define IT_LOAD_BOOL_CONST			0x63 // not used?
#define IT_LOAD_LOOP_CONST			0x64
#define IT_LOAD_RESOURCE			0x65
#define IT_LOAD_SAMPLER				0x66

#define IT_SET_CONFIG_REG			0x68
#define IT_SET_CONTEXT_REG			0x69
#define IT_SET_ALU_CONST			0x6A
#define IT_SET_LOOP_CONST			0x6C
#define IT_SET_RESOURCE				0x6D
#define IT_SET_SAMPLER				0x6E
#define IT_SET_CTL_CONST			0x6F
#define IT_STRMOUT_BASE_UPDATE		0x72
#define IT_SET_ALL_CONTEXTS			0x74

#define LATTE_REG_BASE_CONFIG		0x2000
#define LATTE_REG_BASE_CONTEXT		0xA000
#define LATTE_REG_BASE_ALU_CONST	0xC000
#define LATTE_REG_BASE_LOOP_CONST	0xF880
#define LATTE_REG_BASE_RESOURCE		0xE000
#define LATTE_REG_BASE_SAMPLER		0xF000

// emulator only
#define IT_HLE_COPY_SURFACE_NEW					0xEE
#define IT_HLE_SYNC_ASYNC_OPERATIONS			0xEF
#define IT_HLE_REQUEST_SWAP_BUFFERS				0xF0
#define IT_HLE_WAIT_FOR_FLIP					0xF1
#define IT_HLE_BOTTOM_OF_PIPE_CB				0xF2
#define IT_HLE_COPY_COLORBUFFER_TO_SCANBUFFER	0xF3
#define IT_HLE_FIFO_WRAP_AROUND					0xF4
#define IT_HLE_CLEAR_COLOR_DEPTH_STENCIL		0xF5
#define IT_HLE_SAMPLE_TIMER						0xF7
#define IT_HLE_TRIGGER_SCANBUFFER_SWAP			0xF8
#define IT_HLE_SPECIAL_STATE					0xF9
#define IT_HLE_BEGIN_OCCLUSION_QUERY			0xFA
#define IT_HLE_END_OCCLUSION_QUERY				0xFB
#define IT_HLE_SET_CB_RETIREMENT_TIMESTAMP		0xFD

#define pm4HeaderType3(__itCode, __dataDWordCount) (0xC0000000|((uint32)(__itCode)<<8)|((uint32)((__dataDWordCount)-1)<<16))
#define pm4HeaderType2Filler() (0x80000000)

#pragma once

// minigbm can't safely access lingbm_mesa, since gbm.h is exist in both minigbm and libgbm_mesa
// project and will cause conflict

struct gbm_ops {
	uint32_t (*get_gbm_format)(uint32_t drm_format);

	void *(*dev_create)(int fd);

	void (*dev_destroy)(void *gbm_ptr);

	// ALLOCATOR ONLY
	int (*alloc)(void *gbm_ptr, uint32_t width, uint32_t height, uint32_t drm_format,
		     bool use_scanout, bool force_linear, int *out_fd, uint32_t *out_stride,
		     uint64_t *out_modifier, uint32_t *out_map_stride);

	// MAPPER ONLY
	void *(*import)(void *gbm_ptr, int buf_fd, uint32_t width, uint32_t height, uint32_t stride,
			uint64_t modifier, uint32_t drm_format);

	void (*free)(void *gbm_bo_ptr);

	void (*map)(void *gbm_bo_ptr, int w, int h, void **addr, void **map_data);

	void (*unmap)(void *gbm_bo_ptr, void *map_data);
};

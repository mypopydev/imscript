// data structure to store the state of a window
struct FTR {
	// visible state
	int w, h, max_w, max_h;
	unsigned char *rgb;
	int stop_loop;
	int changed;

	void *userdata; // not touched by the library

	// hidden implementation details
	char pad[100];
};

// type of a handler function
typedef void (*ftr_event_handler_t)(struct FTR*,int,int,int,int);

// window management
struct FTR ftr_new_window(int w, int h);
struct FTR ftr_new_window_with_image_uint8_rgb(unsigned char *i, int w, int h);
void ftr_fork_window_with_image_uint8_rgb(unsigned char *i, int w, int h);
void ftr_change_title(struct FTR *f, char *title);
void ftr_close(struct FTR *f);

// blocking calls
void ftr_wait_for_mouse_click(struct FTR *f, int *x, int *y, int *b, int *m);
void ftr_wait_for_key_depress(struct FTR *f, int *x, int *y, int *k, int *m);

// event loop
int ftr_loop_run(struct FTR *f); // returns when the loop is finished
void ftr_loop_fork(struct FTR *f); // returns immediately, forks a new process
int ftr_set_handler(struct FTR *f, char *id, ftr_event_handler_t e);
ftr_event_handler_t ftr_get_handler(struct FTR *f, char *id);

// default and example handlers
void ftr_handler_exit_on_ESC(struct FTR*,int,int,int,int);
void ftr_handler_toggle_idle(struct FTR*,int,int,int,int);
void ftr_handler_stop_loop(struct FTR*,int,int,int,int);
void ftr_handler_dummy(struct FTR*,int,int,int,int);

// convenience functions
//void ftr_fork_window_with_rgba32_image(unsigned char *buf, int w, int h);
//void ftr_fork_window_with_rgb32_image(unsigned char *buf, int w, int h);
//void ftr_fork_window_with_f32_image(float *buf, int w, int h);
//void ftr_fork_window_with_f32_image_vec(float *buf, int w, int h, int pd);

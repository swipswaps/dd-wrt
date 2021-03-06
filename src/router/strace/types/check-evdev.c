/* Generated by ./types/gen.sh from ./types/evdev.h; do not edit. */
#include "defs.h"
#include "static_assert.h"
#include "types/evdev.h"

#ifdef HAVE_STRUCT_INPUT_ABSINFO
# ifdef HAVE_STRUCT_INPUT_ABSINFO_RESOLUTION
static_assert(sizeof(struct input_absinfo) == sizeof(struct_input_absinfo),
      "struct input_absinfo size mismatch, please update the decoder or fix the kernel");
# else
static_assert(sizeof(struct input_absinfo) <= offsetof(struct_input_absinfo, resolution),
"struct input_absinfo size mismatch, please update the decoder or fix the kernel");
# endif /* HAVE_STRUCT_INPUT_ABSINFO_RESOLUTION */
#endif /* HAVE_STRUCT_INPUT_ABSINFO */

#ifdef HAVE_STRUCT_INPUT_KEYMAP_ENTRY
# ifdef HAVE_STRUCT_INPUT_KEYMAP_ENTRY_SCANCODE
static_assert(sizeof(struct input_keymap_entry) == sizeof(struct_input_keymap_entry),
      "struct input_keymap_entry size mismatch, please update the decoder or fix the kernel");
# else
static_assert(sizeof(struct input_keymap_entry) <= offsetof(struct_input_keymap_entry, scancode),
"struct input_keymap_entry size mismatch, please update the decoder or fix the kernel");
# endif /* HAVE_STRUCT_INPUT_KEYMAP_ENTRY_SCANCODE */
#endif /* HAVE_STRUCT_INPUT_KEYMAP_ENTRY */

#ifdef HAVE_STRUCT_INPUT_MASK
# ifdef HAVE_STRUCT_INPUT_MASK_CODES_PTR
static_assert(sizeof(struct input_mask) == sizeof(struct_input_mask),
      "struct input_mask size mismatch, please update the decoder or fix the kernel");
# else
static_assert(sizeof(struct input_mask) <= offsetof(struct_input_mask, codes_ptr),
"struct input_mask size mismatch, please update the decoder or fix the kernel");
# endif /* HAVE_STRUCT_INPUT_MASK_CODES_PTR */
#endif /* HAVE_STRUCT_INPUT_MASK */

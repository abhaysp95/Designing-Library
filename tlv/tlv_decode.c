#include <stdio.h>
#include <string.h>

// TODO: make the same example but with using types from <stdint.h>

void decode_tlv(char *tlv_ptr);

int get_unit_tlv_size(int type) {
  return 5; // for now, sending constant: 5 (for TLV132)
}

typedef struct interface {
  char ipv4[4];
  char mask;
} ip_interface;

int main(void) { return 0; }

// TLV = Type Length Value
void decode_tlv(char *tlv_ptr) {
  int tlv_type = (int)*tlv_ptr; // read TLV type, say TLV132
  tlv_ptr++;
  int data_length = (int)*tlv_ptr;
  int unit_tlv_size = get_unit_tlv_size(tlv_type);
  tlv_ptr++;
  int data_blocks_size = data_length / unit_tlv_size;
  ip_interface interfaces[data_blocks_size];

  switch (tlv_type) {
  case 132: {
    for (int i = 0; i < data_blocks_size; i++) {
#if 0
	  // the below is arch dependent, as unsigned int type changes depending on machine architecture, so you can't be sure that if unsigned int is 4 byte on your machine, it's same for somebody else's machine or vice-versa
		  unsigned int ip_addr = *((unsigned int*)tlv_ptr);
#endif
      memcpy(interfaces[i].ipv4, tlv_ptr,
             unit_tlv_size); // architecture agnostic, just copy the constant
                             // length of bytes
      tlv_ptr += unit_tlv_size;
      interfaces[i].mask = *tlv_ptr;
    }
    break;
  }
  default:
    // ... skip tlv type, if not recognized
    tlv_ptr += data_blocks_size;
  }
}

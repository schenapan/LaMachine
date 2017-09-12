#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "custom_typedef.h"


class CEngine {
public:
    CEngine(unsigned short i_flash_ptr_seq, const sItemTbl *ip_items_table);

    void SetDirectorySequence(unsigned short i_flash_ptr_seq);

    sItem *GetItem(unsigned char i_uid[UUID_TAG_SIZE]);

    bool IsSequenceValid(sSeq *p_in_seq, sSequence **op_seq_result);

private:
    unsigned short flash_ptr_seq;
    sItemTbl *p_items_tbl;
};

#endif // ENGINE_HPP

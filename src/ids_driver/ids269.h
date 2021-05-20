//
// Created by Maxim Zakharov on 19.05.2021.
//

#ifndef IDS269_H
#define IDS269_H

enum ids269_regs {

    IDS269_GLOBAL_SET = 0x86,
//     TMP108_CONFIGURATION = 0x01,
//     TMP108_T_LOW = 0x02,
//     TMP108_T_HIGH = 0x3,
};

int ids269_initialize_button(void);

int ids269_initialize_proximity(void);

int ids269_read_counts_button(void);

int ids269_read_counts_proximity(void);

#endif
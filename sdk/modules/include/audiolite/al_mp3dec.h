/****************************************************************************
 * modules/include/audiolite/al_mp3dec.h
 *
 *   Copyright 2023 Sony Semiconductor Solutions Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __INCLUDE_AUDIOLITE_MP3DEC_H
#define __INCLUDE_AUDIOLITE_MP3DEC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <audiolite/al_worker.h>
#include <audiolite/al_decoder.h>
#include <audiolite/al_memalloc.h>

/****************************************************************************
 * Class Definitions
 ****************************************************************************/

/****************************************************************************
 * class: audiolite_mp3dec
 ****************************************************************************/

class audiolite_mp3dec : public audiolite_decoder
{
  private:
    audiolite_mempoolapbuf *_omempool;
    audiolite_worker _worker;
    audiolite_workermemq _inq;
    audiolite_workermemq _outq;
    bool _frame_eof;

    static int handle_mesage(al_comm_msghdr_t hdr,
                             al_comm_msgopt_t *opt, void *arg);

  protected:
    void decode_runner();

  public:
    audiolite_mp3dec();
    ~audiolite_mp3dec();

    int start_decode();
    int stop_decode();
    int pause_decode() { return OK; };
    int resume_decode() { return OK; };

    void set_outputmempool(audiolite_mempoolapbuf *pool)
    {
      _omempool = pool;
    }
};

#endif /* __INCLUDE_AUDIOLITE_MP3DEC_H */

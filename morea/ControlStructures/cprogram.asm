000003ED  C744241C34120000  mov dword [esp+0x1c],0x1234
000003F5  C744241800000000  mov dword [esp+0x18],0x0
000003FD  EB0D              jmp short 0x40c
000003FF  8B442418          mov eax,[esp+0x18]
00000403  0144241C          add [esp+0x1c],eax
00000407  8344241801        add dword [esp+0x18],byte +0x1
0000040C  837C241809        cmp dword [esp+0x18],byte +0x9
00000411  7EEC              jng 0x3ff
00000413  B810850408        mov eax,0x8048510
00000418  8B54241C          mov edx,[esp+0x1c]
0000041C  89542404          mov [esp+0x4],edx
00000420  890424            mov [esp],eax
00000423  E8D8FEFFFF        call dword 0x300
00000428  C744241C45230000  mov dword [esp+0x1c],0x2345


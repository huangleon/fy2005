// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��ש���̲ݡ��Ͷ���û��ʲô������ʮ�ɷ�Բ�ĵط��Ե��ر��Э��������Ҳ
��С����������������������Զ������˺���˶����Ĺ���ͤ��ֻ��������˸�
�٣�ȴʱ������ִ���еĹٱ�Ѳ�߶�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "east" : __DIR__"cxs3",
          "west" : AREA_WOLFMOUNT"yinroad1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

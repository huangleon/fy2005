// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�е�����");
        set("long", @LONG
���������ͥ������ͥ�������Ĺ���͸������������յú�����������ĵ�
�Ʊȱ��ߵͣ������µİ��������������ӿ���ƺ��������������Ĵ�ŵ���ʯ����
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tzdx",
  "east" : __DIR__"zx",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("item_desc", ([
                "����": "������ӿ�����ţ���ɫ�ĺ�ˮ�·�����е�Ѫ�ء�\n",
                "river": "������ӿ�����ţ���ɫ�ĺ�ˮ�·�����е�Ѫ�ء�\n",
        ]) );
        set("resource/water",1);
        set("liquid/name","��ˮ");
        set("liquid/type", "water");

        set("indoors", "cave");
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

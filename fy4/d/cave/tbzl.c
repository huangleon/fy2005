// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����챱���ţ����Ǻܿ������д����е���Ϊ�ֲ������Σ�����û��ʲô��
�ߣ���ֻ��һ�����ڵ�һ�˶����ɳ�ӣ��Ͷ��������Ա������õĻ�ɳ����˵��ɳ
Ҳ����Ѱ��֮����Ǵ�����ר��ǧ������������ɳ����Ѱ����ɰ��Ҫ������࣬
�����˱�������ɳ�������ؿڣ�������Ѫ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "north" : __DIR__"qszl",
  "south" : __DIR__"tbzm",
]));
        set("objects", ([
        __DIR__"npc/guard5": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",0);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
        replace_program(ROOM);
}

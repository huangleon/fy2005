// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽׯ��Ժ");
        set("long", @LONG
����Ļ���������Ժ����Ȼ��������ϰ�书�ġ�Ժ�����ǵ����ż���һ�ߴ�ϸ
��ľ׮������һ����б��Ϊ���أ��пڶ��Ź֡���һ����һ��������һ�����뽣��
δ�γ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"center",
  "east" : __DIR__"playground",
  "north" : __DIR__"kitchen",
  "south" : __DIR__"bathroom",
]));
	set("outdoors","wanmei");
        set("item_desc", ([
                "�пڶ�": "
���пڶ�һ�����Ǹ�������������\n",
                "���뽣": "
�����뽣�Ѿ�������ľ׮���Ҳ�β����ˣ���\n",
        ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	object blood;
	if(!arg || (arg != "���뽣" && arg != "sword")) return 0;
	write("���þ�ȫ������������һ������\n");
	write("������������������۵ÿ�����Ѫ������\n");
	this_player()->receive_damage("kee",50);
	blood= new(__DIR__"obj/blood");
	blood->move(this_object());
	return 1;

}

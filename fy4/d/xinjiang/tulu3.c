/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "��·");
        set("long", @LONG
��ԭ�ϵ�һ���������۵���·������һ��ĬĬ��Ϫ�����ңɣ֣ţң����峺��
Ϫˮ��ʹ�˸е�һ��������Ϣ����ΧȺɽ�������ˮ���ѣ����������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu2",
  "south" : __DIR__"chairong",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
*/
        set("item_desc", ([
                "river": "���峺��Ϫ�������滹��С�㣨������裩Ү����\n",
                "Ϫ��": "���峺��Ϫ�������滹��С�㣨������裩Ү����\n"

        ]) );
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","�峺��Ϫˮ");
        set("liquid/container", "Ϫ��");
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_catch","catch");
}

int do_catch(string arg)
{
	object me;
	me=this_player();
	if(random(me->query("combat_exp")+1000)<50000)
	{
	if(me->max_food_capacity()>(int)me->query("food"))
	{
		me->add("food",15);
		return notify_fail("��һ���֣�ץסһ��С����������У�������
��������ζ������������е������Ⱦͺ�ඣ�����\n");
	}
	else
	return notify_fail("�����������ץ��ץ�����ʲôҲûץ����\n");
	}
	else
	return notify_fail("�����������ץ��ץ�����ʲôҲûץ����\n");
}

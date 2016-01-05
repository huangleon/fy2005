//mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
һ·�ֻ��������������š���ǰ��Ȼ���ʡ�һ��׳�۵��䵱���ͳ�������ǰ��
���������嶥�ˣ����䵱ɽ������. ͭ���̽�Ľ����Ϊͭ��������ṹ����
�������������Լ����ۡ����������������޵����αϱ�����ÿ������֮����˿�Ϸ죬
�����˹�����֮�ۣ���Ȼ��ɡ�����Ƿɾ٣����������������������������
��������ڹ��������۾����������㣬����Ρΰ������˱����Ľ�ͯ��Ů����
�翡�ǣ����Ķ��ţ�������������ʿ�������ң����ƶ��ˡ�
LONG
        );
        set("exits", ([
         "northdown" : __DIR__"fourgate",
        "southup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}

void init()
{
add_action("do_mobai", "mobai");
}

int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N�ϵع�������۾���ǰ���˸�ͷ��\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N���ϵ�ɱ��֮���ƺ����ˡ� \n" , who);
	add("number",1);
	if((int) query("number") >	random(40) + 20 )
	{
    message_vision( HIY "\n\n$N������ǰһ�����������ƺ�����һ�£�������\n\n"NOR,who);
    if ( !objectp(who = present("master zhenwu", this_object())) )
		{
        who = new(__DIR__"npc/zhenwu");
		who->move(this_object());
		}
	}	
	return 1;
}

void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master zhenwu", this_object())) )
destruct(obj);
}

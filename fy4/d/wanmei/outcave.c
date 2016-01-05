inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "�ٺ�ɽ��");
        set("long", @LONG
������ˮ�鲻ʱ�ؽ���ɽ�������²������꣬����������ɽ���ںܰ�������Լ
���ɿ�������ռ�ܴ�������ǰ��ȥ������ǰ���м�����С�Ķ��ֱ�ͨ������
ɽ���С��������ڶ��ڼ��䣬���ڶ���������ס�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"waterfall",
	]));
        set("objects", ([
                "/obj/money/silver" :1,
                        ]) );
	set("frozen",3);
        set("item_desc", ([
                "����": "
���ǰѺ��������������򣩣�����û�취����ɽ���С�\n",
        ]) );

	set("coor/x",50);
	set("coor/y",110);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("do_pour", "pour");
}
int do_pour(string arg)
{
	object me;
	object con;
	me = this_player();
	if(!arg) return 0;
	if(!objectp(con=present(arg, me)))
	return 0;
	if(!con->query("liquid"))
	return 0;
	if(!con->query("liquid/remaining"))
	return notify_fail( con->name() + "�ǿյġ�\n");
	con->add("liquid/remaining", -1);
	message_vision("$N����" + con->name() + "����һЩ" +
	con->query("liquid/name")  + "�ں����ϡ�\n",me);
	if(con->query("liquid/name") == "��ˮ")
	{
	tell_object(me,"����������һ�㣡��\n");
	add("frozen",-1);
	}
	if( query("frozen") <= 0 )
	{
	tell_object(me,"�������ڻ�����һ��С��������\n");
	if(!query("exits/north"))
		set("exits/north",__DIR__"leftcave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"Ʈ������ˮ��գ�ۼ䶳�ɱ��飬�����ط�ס�˶��ڣ���\n",
                this_object() );
                delete("exits/north");
		set("frozen",10+random(5));
}


inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "�м�С��");
        set("long", @LONG
���ں�С�����ͷ�����ɽ��롣��һ�����������������Լ�ĵ�ˮ����̧ͷ
��ȥ��ˮ�ǴӶ����������ġ��ٲ������������֮��Ȼ����ϡ�ġ�¡¡��������
����һ�ɰ����ڳ���Ŷ��ڡ������ϻ��Ǻ����ܲ���
LONG
        );
	set("frozen",3);
        set("item_desc", ([
                "����": "
���ǰѺ��������������򣩣�����û�취����ɽ���С�\n",
        ]) );
        set("objects", ([
                __DIR__"obj/blackthorn" :1,
                __DIR__"obj/silk_cloth" :1,
                        ]) );
	set("coor/x",40);
	set("coor/y",120);
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
	if(!query("exits/south"))
		set("exits/south",__DIR__"rightcave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"Ʈ������ˮ��գ�ۼ䶳�ɱ��飬�����ط�ס�˶��ڣ���\n",
                this_object() );
                delete("exits/south");
		set("frozen",10+random(5));
}

void reset(){
        object item;
        ::reset();
      
	if(!present("blackthorn sword", this_object())){
		item = new(__DIR__"obj/blackthorn");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        if(!present("silk cloth", this_object())){
		item = new(__DIR__"obj/silk_cloth");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        return;
}       
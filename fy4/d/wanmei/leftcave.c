inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "���С��");
        set("long", @LONG
�������̧ͷ��ȥ���ڰ�����ϡ����ɽ��������͹��ƽ�������������ٽ�
֯�ɵĳ�Ѩ��Ҳ��֪����ι̶�������ģ��պ���һֻС���Ѩ�зɳ����ض���
����һ�ܣ������������˻�ȥ���������Ǻ�����
LONG
        );
	set("frozen",3);
        set("item_desc", ([
                "����": "
���ǰѺ��������������򣩣�����û�취����ɽ���С�\n",
        ]) );
        set("objects", ([
                __DIR__"obj/icy_boot" :1,
                __DIR__"obj/icy_cloth" :1,
                __DIR__"obj/icy_girth" :1,
                __DIR__"obj/icy_ribbon" :1,

                        ]) );
	set("coor/x",50);
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
	if(!query("exits/west"))
		set("exits/west",__DIR__"centercave");
	call_out("close_path",10);		
	}
	return 1;
}

void close_path()
{
        if( !query("exits/west") ) return;
        message("vision",
"Ʈ������ˮ��գ�ۼ䶳�ɱ��飬�����ط�ס�˶��ڣ���\n",
                this_object() );
                delete("exits/west");
		set("frozen",10+random(5));
}

void reset(){
        object item;
        ::reset();
      
	if(!present("icy boots", this_object())){
		item = new(__DIR__"obj/icy_boot");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        if(!present("icy ribbon", this_object())){
		item = new(__DIR__"obj/icy_ribbon");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        if(!present("icy girth", this_object())){
		item = new(__DIR__"obj/icy_girth");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        if(!present("icy cloth", this_object())){
		item = new(__DIR__"obj/icy_cloth");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        return;
}       
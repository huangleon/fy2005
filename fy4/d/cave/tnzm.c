// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����ĵ���͹����ƽ�����ܸ��·�����߷��˼����Ի�����Ȼ����ȱ������
���������˾��������ĳ���ʵ��ïʢ����ʯ·�������ϱ�չ����������������ͷ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tt",
  "south" : __DIR__"tnzl",
]));
        set("objects", ([
        __DIR__"obj/flowerpot": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-6);
	set("coor/z",0);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("flowerpot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bloodflower");
                item->move(con);
                item = new(__DIR__"obj/bloodflower");
                item->move(con);
        }
}


int valid_leave(object obj, string dir){
	object ma;
	if(dir == "north"){
		if( !obj->query("m_killer/ëս") || !obj->query("m_killer/ëҰ") ){
			return notify_fail("��̽ͷ̽�Ե���ǰ�濴�˿�,����ԥԥ��ͣס�˽Ų���\n");
		}
	}	
	return 1;
}
